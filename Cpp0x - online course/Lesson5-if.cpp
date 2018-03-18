#include <iostream>
int main()
{
    int wiek;
    std::cin >> wiek;

    if(wiek<18)
    std::cout << "Nie jestes pelnoletni" << std::endl;
    else std::cout << "Jestes pelnoletni" << std::endl;

    std::cout << "Koniec" << std::endl;

    return 0;
}
