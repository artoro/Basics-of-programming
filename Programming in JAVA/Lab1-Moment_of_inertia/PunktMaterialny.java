public class PunktMaterialny {
	
	//POLA
	private double masa;
	
	//KONSTRUKTORY
	public PunktMaterialny() { //konstruktor domy�lny
		masa = 1;
	}
	public PunktMaterialny(double masa) { //konstruktor z parametrem i kontrol� warto�ci
		if (masa < 0) {
			System.out.println("B��D! - Ujemna warto�� masy punktu materialnego.");
			masa = 0;
		}
		else this.masa = masa;
	}
	public PunktMaterialny(PunktMaterialny P) { //konstruktor kopiuj�cy
		masa = P.masa;
	}
	
	//AKCESORY
	public double obliczMase() { //akcesor zwracaj�cy mas� punktu
		return masa;
	}
	public boolean zmienMase(double masa) { //akcesor zmieniaj�cy mas� punktu
		if (masa < 0) {
			//je�li podana zostanie ujemna masa, zostanie wy�wietlony b��d
			System.out.println("B��D! - Ujemna warto�� masy punktu materialnego.");
			//funkcja nie zmieni aktualnej warto�ci masy i zwr�ci warto�� false
			return false;
		}
		//je�li podana masa jest prawid�owa
		else this.masa = masa;
		return true;
	}
	//akcesory abstrakcyjne
	public boolean zmienPromien(double promien) { System.out.println("B�AD! - " + this + " nie ma promienia."); return false; }
	public boolean zmienWysokosc(double wysokosc) { System.out.println("B�AD! - " + this + " nie ma wysoko�ci."); return false; }
	public boolean zmienDlugosc(double dlugosc) { System.out.println("B�AD! - " + this + " nie ma d�ugo�ci."); return false; }
	
	//METODY
	public double GMomentBezwladnosci() {
		return 0; //warto�� g��wnego momentu bezw�adno�ci punktu materialnego
	}
	public double MomentBezwladnosci(double odleglosc) {
		//warto�� momentu bezw�adno�ci wzgl�dem nowej osi obliczona z twierdzenia Steinera
		return masa * odleglosc*odleglosc + GMomentBezwladnosci(); // I = m*r^2 + I0
	}
	
	@Override
	public String toString() {
		return "Punkt materialny"; //kr�tki opis klasy
	}
	public String opis(double os) { //d�ugi opis klasy
		String s = this + " o masie " + obliczMase() + _opis() +
				" ma g��wny moment bezw�adno�ci " + GMomentBezwladnosci();
		//je�li zosta�a podana niezerowa nowa o�, zostaje obliczony moment bezw�adno�ci wzgl�dem niej
		if (os != 0.) s += ", a wzgl�dem osi odleg�ej o " + os +
				" moment bezw��dno�ci wynosi " +  MomentBezwladnosci(os);
		return s;				
	}
	protected String _opis() { return ""; } //metoda abstrakcyjna na dodatkowe informacje o klasie
	
}