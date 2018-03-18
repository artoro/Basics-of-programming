public class Pret extends PunktMaterialny {
	
	//POLA
	private double promien;
	private double dlugosc;
	
	//KONSTRUKTORY
	public Pret() { //konstruktor domy�lny
		super();
		promien = 1;
		dlugosc = 1;
	}
	public Pret(double masa, double promien, double dlugosc) { //konstruktor z parametrami i kontrol� warto�ci
		super(masa);
		zmienPromien(promien);
		zmienDlugosc(dlugosc);
	}
	public Pret(Pret P) { //konstruktor kopiuj�cy
		super(P);
		promien = P.promien;
		dlugosc = P.dlugosc;
	}
	
	//AKCESORY
	public double obliczPromien() { //akcesor zwracaj�cy promie� pr�ta
		return promien;
	}
	@Override
	public boolean zmienPromien(double promien) { //akcesor zmieniaj�cy promie� pr�ta
		if (promien < 0) {
			//je�li podany zostanie ujemny promie�, zostanie wy�wietlony b��d
			System.out.println("B��D! - Ujemna warto�� promienia dla " + this);
			//funkcja nie zmieni aktualnej warto�ci i zwr�ci warto�� false
			return false;
		}
		//je�li podany promie� jest prawid�owy
		else this.promien = promien;
		return true;
	}
	public double obliczDlugosc() { //akcesor zwracaj�cy d�ugo�� pr�ta
		return dlugosc;
	}
	@Override
	public boolean zmienDlugosc(double dlugosc) { //akcesor zmieniaj�cy d�ugo�� pr�ta
		if (dlugosc < 0) {
			//je�li podana zostanie ujemna d�ugo��, zostanie wy�wietlony b��d
			System.out.println("B��D! - Ujemna warto�� dlugosci dla " + this);
			//funkcja nie zmieni aktualnej warto�ci i zwr�ci warto�� false
			return false;
		}
		//je�li podana d�ugo�� jest prawid�owa
		else this.dlugosc = dlugosc;
		return true;
	}
	
	//METODY
	@Override
	public double GMomentBezwladnosci() {
		return obliczMase()/12.0*promien*promien; //warto�� g��wnego momentu bezw�adno�ci pr�ta
	}
	@Override
	public String toString() {
		return "Pr�t"; //kr�tki opis klasy
	}
	@Override
	protected String _opis() { //dodatkowe dane do opisu pr�ta
		return ", promieniu " + obliczPromien() + " i d�ugo�ci " + obliczDlugosc();
	}
}
