public class Pret extends PunktMaterialny {
	
	//POLA
	private double promien;
	private double dlugosc;
	
	//KONSTRUKTORY
	public Pret() { //konstruktor domyœlny
		super();
		promien = 1;
		dlugosc = 1;
	}
	public Pret(double masa, double promien, double dlugosc) { //konstruktor z parametrami i kontrol¹ wartoœci
		super(masa);
		zmienPromien(promien);
		zmienDlugosc(dlugosc);
	}
	public Pret(Pret P) { //konstruktor kopiuj¹cy
		super(P);
		promien = P.promien;
		dlugosc = P.dlugosc;
	}
	
	//AKCESORY
	public double obliczPromien() { //akcesor zwracaj¹cy promieñ prêta
		return promien;
	}
	@Override
	public boolean zmienPromien(double promien) { //akcesor zmieniaj¹cy promieñ prêta
		if (promien < 0) {
			//jeœli podany zostanie ujemny promieñ, zostanie wyœwietlony b³¹d
			System.out.println("B£¥D! - Ujemna wartoœæ promienia dla " + this);
			//funkcja nie zmieni aktualnej wartoœci i zwróci wartoœæ false
			return false;
		}
		//jeœli podany promieñ jest prawid³owy
		else this.promien = promien;
		return true;
	}
	public double obliczDlugosc() { //akcesor zwracaj¹cy d³ugoœæ prêta
		return dlugosc;
	}
	@Override
	public boolean zmienDlugosc(double dlugosc) { //akcesor zmieniaj¹cy d³ugoœæ prêta
		if (dlugosc < 0) {
			//jeœli podana zostanie ujemna d³ugoœæ, zostanie wyœwietlony b³¹d
			System.out.println("B£¥D! - Ujemna wartoœæ dlugosci dla " + this);
			//funkcja nie zmieni aktualnej wartoœci i zwróci wartoœæ false
			return false;
		}
		//jeœli podana d³ugoœæ jest prawid³owa
		else this.dlugosc = dlugosc;
		return true;
	}
	
	//METODY
	@Override
	public double GMomentBezwladnosci() {
		return obliczMase()/12.0*promien*promien; //wartoœæ g³ównego momentu bezw³adnoœci prêta
	}
	@Override
	public String toString() {
		return "Prêt"; //krótki opis klasy
	}
	@Override
	protected String _opis() { //dodatkowe dane do opisu prêta
		return ", promieniu " + obliczPromien() + " i d³ugoœci " + obliczDlugosc();
	}
}
