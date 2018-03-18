public class PunktMaterialny {
	
	//POLA
	private double masa;
	
	//KONSTRUKTORY
	public PunktMaterialny() { //konstruktor domyœlny
		masa = 1;
	}
	public PunktMaterialny(double masa) { //konstruktor z parametrem i kontrol¹ wartoœci
		if (masa < 0) {
			System.out.println("B£¥D! - Ujemna wartoœæ masy punktu materialnego.");
			masa = 0;
		}
		else this.masa = masa;
	}
	public PunktMaterialny(PunktMaterialny P) { //konstruktor kopiuj¹cy
		masa = P.masa;
	}
	
	//AKCESORY
	public double obliczMase() { //akcesor zwracaj¹cy masê punktu
		return masa;
	}
	public boolean zmienMase(double masa) { //akcesor zmieniaj¹cy masê punktu
		if (masa < 0) {
			//jeœli podana zostanie ujemna masa, zostanie wyœwietlony b³¹d
			System.out.println("B£¥D! - Ujemna wartoœæ masy punktu materialnego.");
			//funkcja nie zmieni aktualnej wartoœci masy i zwróci wartoœæ false
			return false;
		}
		//jeœli podana masa jest prawid³owa
		else this.masa = masa;
		return true;
	}
	//akcesory abstrakcyjne
	public boolean zmienPromien(double promien) { System.out.println("B£AD! - " + this + " nie ma promienia."); return false; }
	public boolean zmienWysokosc(double wysokosc) { System.out.println("B£AD! - " + this + " nie ma wysokoœci."); return false; }
	public boolean zmienDlugosc(double dlugosc) { System.out.println("B£AD! - " + this + " nie ma d³ugoœci."); return false; }
	
	//METODY
	public double GMomentBezwladnosci() {
		return 0; //wartoœæ g³ównego momentu bezw³adnoœci punktu materialnego
	}
	public double MomentBezwladnosci(double odleglosc) {
		//wartoœæ momentu bezw³adnoœci wzglêdem nowej osi obliczona z twierdzenia Steinera
		return masa * odleglosc*odleglosc + GMomentBezwladnosci(); // I = m*r^2 + I0
	}
	
	@Override
	public String toString() {
		return "Punkt materialny"; //krótki opis klasy
	}
	public String opis(double os) { //d³ugi opis klasy
		String s = this + " o masie " + obliczMase() + _opis() +
				" ma g³ówny moment bezw³adnoœci " + GMomentBezwladnosci();
		//jeœli zosta³a podana niezerowa nowa oœ, zostaje obliczony moment bezw³adnoœci wzglêdem niej
		if (os != 0.) s += ", a wzglêdem osi odleg³ej o " + os +
				" moment bezw³¹dnoœci wynosi " +  MomentBezwladnosci(os);
		return s;				
	}
	protected String _opis() { return ""; } //metoda abstrakcyjna na dodatkowe informacje o klasie
	
}