using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    // WZORZEC PROJEKTOWY - Singleto - pojedyncza instancja klasy

    public class Singleto
    {
        private static Singleto instance;

        private Singleto()
        {

        }

        public static Singleto GetInstance()
        {
            if (instance == null)
            {
                instance = new Singleto();
            }
            return instance;
        }
    }
}
