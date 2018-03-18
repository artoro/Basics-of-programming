public class Kula extends PunktMaterialny {
	
	//POLA
	private double promien;
	
	//KONSTRUKTORY
	public Kula() { //konstruktor domy�lny
		super();
		promien = 1;
	}
	public Kula(double masa, double promien) { //konstruktor z parametrami i kontrol� warto�ci
		super(masa);
		zmienPromien(promien);
	}
	public Kula(Kula K) { //konstruktor kopiuj�cy
		super(K);
		promien = K.promien;
	}
	
	//AKCESORY
	public double obliczPromien() { //akcesor zwracaj�cy promie� kuli
		return promien;
	}
	@Override
	public boolean zmienPromien(double promien) { //akcesor zmieniaj�cy promie� kuli
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
	
	//METODY
	@Override
	public double GMomentBezwladnosci() {
		return 2.0/3.0*obliczMase()*promien*promien; //warto�� g��wnego momentu bezw�adno�ci kuli
	}
	@Override
	public String toString() {
		return "Kula"; //kr�tki opis klasy
	}
	@Override
	protected String _opis() { //dodatkowe dane do opisu kuli
		return " i promieniu " + obliczPromien();
	}
}
