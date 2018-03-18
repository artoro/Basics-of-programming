
public class Triangle {
	//POLA DANYCH
		public float a;
		public float h;

		private float S;
		protected float P;

		//KONSTRUKTOR
		public Triangle()
		{
			a = 1;
			h = 1;
		}

		public Triangle(float podstawa, float wysokosc) //konstruktor z parametrami
		{
			a = podstawa;
			h = wysokosc;
			P = a * h * 0.5f;
		}

		//METODY
		public float area()
		{
			return P;
		}

		//AKCESORY
		public void setA(float podstawa)
		{
			if (podstawa > 0)
				a = podstawa;
			else
				a = 1;
		}
		
		public float getA()
		{
			return a;
		}

		public void setH(float h)
		{
			if (h > 0)
				this.h = h;
			else
				this.h = 1;
		}

		@Override
		public String toString() 
		{
			return "Trójk¹t o podstawie " + a + " i wysokoœci " + h;
		}
}
