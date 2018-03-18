public class Walec extends PunktMaterialny {
	
	//POLA
	private double promien;
	private double wysokosc;
	
	//KONSTRUKTORY
	public Walec() { //konstruktor domy�lny
		super();
		promien = 1;
		wysokosc = 1;
	}
	public Walec(double masa, double promien, double wysokosc) { //konstruktor z parametrami i kontrol� warto�ci
		super(masa);
		zmienPromien(promien);
		zmienWysokosc(wysokosc);
	}
	public Walec(Walec W) { //konstruktor kopiuj�cy
		super(W);
		promien = W.promien;
		wysokosc = W.wysokosc;
	}
	
	//AKCESORY
	public double obliczPromien() { //akcesor zwracaj�cy promie� walca
		return promien;
	}
	@Override
	public boolean zmienPromien(double promien) { //akcesor zmieniaj�cy promie� walca
		if (promien < 0) {
			//je�li podana zostanie ujemny promie�, zostanie wy�wietlony b��d
			System.out.println("B��D! - Ujemna warto�� promienia dla " + this);
			//funkcja nie zmieni aktualnej warto�ci i zwr�ci warto�� false
			return false;
		}
		//je�li podany promie� jest prawid�owy
		else this.promien = promien;
		return true;
	}
	public double obliczWysokosc() { //akcesor zwracaj�cy wysoko�� walca
		return wysokosc;
	}
	@Override
	public boolean zmienWysokosc(double wysokosc) { //akcesor zmieniaj�cy wysoko�� walca
		if (wysokosc < 0) {
			//je�li podana zostanie ujemna wysoko��, zostanie wy�wietlony b��d
			System.out.println("B��D! - Ujemna warto�� wysoko�ci dla " + this);
			//funkcja nie zmieni aktualnej warto�ci i zwr�ci warto�� false
			return false;
		}
		//je�li podana wysoko�� jest prawid�owa
		else this.wysokosc = wysokosc;
		return true;
	}
	
	//METODY
	@Override
	public double GMomentBezwladnosci() {
		return 0.5*obliczMase()*promien*promien; //warto�� g��wnego momentu bezw�adno�ci walca
	}
	@Override
	public String toString() {
		return "Walec"; //kr�tki opis klasy
	}
	@Override
	protected String _opis() { //dodatkowe dane do opisu walca
		return ", promieniu " + obliczPromien() + " i wysoko�ci " + obliczWysokosc();
	}
}
