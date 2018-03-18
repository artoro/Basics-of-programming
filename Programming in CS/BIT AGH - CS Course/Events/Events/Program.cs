using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Events
{
    //delegacja pośredniczy w komunikacji między eventami a klasami
    //
    public delegate void ActionPerformed(int a);

    public class MyEventArgs : EventArgs
    {
        public int MyProperty { get; set; }
    }

    class Program
    {
        public static event ActionPerformed OnActionPerformed;
        public static event EventHandler OnEventPerformed;
        public static event EventHandler<MyEventArgs> OnEventPerformedArgs;

        static void Main(string[] args)
        {
            ActionPerformed del1;

            del1 = new ActionPerformed(Calculate);
            del1(6);
            del1 = new ActionPerformed((x) => Console.WriteLine("x=" + x));
            del1(8);

            OnActionPerformed += del1; //przy każdym wywołaniu eventu, wywoływana jest delegata
            del1(10);
            OnActionPerformed -= del1;

            AddEvent aEv = new AddEvent();
            //MyEventArgs args = new MyEventArgs();
            //args.MyProperty = 6;
            OnEventPerformedArgs(null, new MyEventArgs() { MyProperty = 6 });


            Console.ReadKey();
        }

        static void Calculate(int x)
        {
            Console.WriteLine("x=" + x);
        }
    }
}
