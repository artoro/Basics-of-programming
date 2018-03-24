#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_INPUT_SIZE 100
#define MAX_OPERATIONS 40

typedef enum { TRUE = 1, FALSE = 0 } bool;

typedef struct mat
{
    char sign;
    double value;
    struct mat *prev;
    struct mat *left;
    struct mat *right;
} Mat;
const Mat NEW_MAT = { '1', 0, NULL, NULL, NULL };

enum { E_INPUT_SIZE = 1, E_INPUT, E_MAX_OPERATIONS, E_FUNCTION, E_ADD_OPERARTON, E_NULL_OPERATION, E_ADDRESS, E_SIGN, E_MATH };
void mat_error(const char *log, int type)
{
    printf("Error - %s", log);
    exit(type);
}

bool is_num(char c)
{
    return ('0'<=c && c<='9') || c=='.';
}

bool is_sign(char c)
{
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='(' || c==')';
}

bool is_end(char c)
{
    return c=='\0' || c=='\n';
}

bool is_exit(char c)
{
    return c=='x';
}

enum { F_SIN, F_COS, F_TAN, F_EXP, F_LOG, F_ABS };
bool is_func(char input[], int size)
{
    const int num_of_fun = 6;
    const char fun[][3] = { "sin", "cos", "tan", "exp", "log", "abs" };
    int i;
    if (size > 2)
        for (i=0; i<num_of_fun; i++)
        {
            if (fun[i][0] == tolower(input[0]) && fun[i][1] == tolower(input[1]) && fun[i][2] == tolower(input[2]))
            {
                input[0] = i;
                return TRUE;
            }
        }
    return FALSE;
}

double calc_func(char func, double arg)
{
    switch (func)
    {
        case F_SIN: return sin(arg);
        case F_COS: return cos(arg);
        case F_TAN: return tan(arg);
        case F_EXP: return exp(arg);
        case F_LOG:
            if (arg<=0) mat_error("arg of log", E_MATH);
            return log(arg);
        case F_ABS: return abs(arg);
        default: mat_error("calculate function", E_FUNCTION);
    }
}

bool is_ordered(char prev, char next)
{
    switch (next)
    {
        case '-':
        case '+': return FALSE;
        case '/':
        case '*': return (prev == '+' || prev == '-');
        case '^':
        case '1': return (prev != '1');
        default:
            mat_error("unspecified order", E_SIGN);
    }
    return FALSE;
}

int expand_operation(char sign, Mat *(*active), Mat next[])
{
    next[0] = NEW_MAT;
    next[0].prev = (*active);
    (*active)->sign = sign;
    if ((*active)->right != NULL) mat_error("incorrect right", E_ADDRESS);
    (*active)->right = &next[0];
    (*active) = &next[0];
    return 1;
}

int insert_operation(char sign, Mat *(*active), Mat *(*root), Mat next[])
{
    if ((*active) != (*root) && !is_ordered((*active)->prev->sign, sign))
    {
        if ((*active)->prev == NULL) mat_error("prev is null", E_NULL_OPERATION);
        else (*active) = (*active)->prev;
        return insert_operation(sign, &(*active), &(*root), next);
    }
    next[0] = NEW_MAT;
    if ((*active) != (*root))
    {
        if ((*active)->prev == NULL) mat_error("prev is null", E_NULL_OPERATION);
        else if ((*active)->prev->right == (*active)) (*active)->prev->right = &next[0];
        else if ((*active)->prev->left == (*active)) (*active)->prev->left = &next[0];
        else mat_error("prev is incorrect", E_ADDRESS);
        next[0].prev = (*active)->prev;
    }
    else (*root) = &next[0];
    next[0].left = (*active);
    (*active)->prev = &next[0];
    (*active) = &next[0];
    return 1 + expand_operation(sign, &(*active), &next[1]);
}

int add_operation(char sign, Mat *(*active), Mat *(*root), Mat next[])
{
    if (is_ordered((*active)->sign, sign))
        return expand_operation(sign, &(*active), next);
    else
        return insert_operation(sign, &(*active), &(*root), next);
}

int get_end_bracket(char input[], int size)
{
    int i = 0;
    int bracket = 1;
    while (bracket != 0)
    {
        i++;
        if (i >= size) mat_error("brackets", E_INPUT);
        if (input[i] == ')') bracket--;
        else if (input[i] == '(') bracket++;
    }
    return i;
}

double get_value(Mat *operation)
{
    if (operation->sign == '1') return operation->value;
    else if (operation->right == NULL) mat_error("null operation", E_NULL_OPERATION);

    double right_value = get_value(operation->right);
    double left_value = (operation->left == NULL)? operation->value : get_value(operation->left);

    printf(" > %.3f %.3c %.3f \n", left_value, operation->sign, right_value);

    switch (operation->sign)
    {
    case '^':
        if (right_value == 0 && left_value == 0) mat_error("math: 0^0", E_MATH);
        return pow(left_value, right_value);
    case '*':
        return left_value * right_value;
    case '/':
        if (right_value == 0) mat_error("math: /0", E_MATH);
        return left_value / right_value;
    case '-':
        return left_value - right_value;
    case '+':
        return left_value + right_value;
    default:
        mat_error("sign", E_SIGN);
    }
}

double calculate(char *input, int size)
{
    Mat tree[MAX_OPERATIONS];
    Mat *root = &tree[0];
    Mat *active = &tree[0];
    *active = NEW_MAT;

    int i, t=1;
    for (i=0; i < size; i++)
    {
        if (is_num(input[i]))
        {
            active->value = atof(input+i);
            while (is_num(input[++i]));
            i--;
        }
        else if ('(' == input[i])
        {
            int start = i + 1;
            i += get_end_bracket(&input[i], size-i);
            active->value = calculate(&input[start], i-start);
        }
        else if (is_sign(input[i]))
        {
            t += add_operation(input[i], &active, &root, &tree[t]);
            if (t>=MAX_OPERATIONS) mat_error("max operation", E_MAX_OPERATIONS);
        }
        else if (is_func(&input[i], size-i))
        {
            char func = input[i];
            i += 3;
            int start = i + 1;
            i += get_end_bracket(&input[i], size-i);
            double argument = calculate(&input[start], i-start);
            active->value = calc_func(func, argument);
        }
        else if (is_end(input[i])) break;
        else if (is_exit(input[i])) exit(0);
        else mat_error("input", E_INPUT);
    }
    return get_value(root);
}

int main()
{
    printf("KALKULATOR\n----------\n");
    while(TRUE)
    {
        putchar(':');
        char input[MAX_INPUT_SIZE];
        if (fgets(input, sizeof input, stdin) == NULL || input[99] == '\n') mat_error("input", E_INPUT_SIZE);
        else
        {
            int i, size;
            for (i=0, size=0; i<sizeof input; i++, size++)
            {
                while (input[i] == ' ') i++;
                input[size] = input[i];
            }
            printf("= %.3f\n\n", calculate(input, size));
        }
    }
    return 0;
}
