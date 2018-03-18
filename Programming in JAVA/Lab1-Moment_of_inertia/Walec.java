public class Walec extends PunktMaterialny {
	
	//POLA
	private double promien;
	private double wysokosc;
	
	//KONSTRUKTORY
	public Walec() { //konstruktor domyœlny
		super();
		promien = 1;
		wysokosc = 1;
	}
	public Walec(double masa, double promien, double wysokosc) { //konstruktor z parametrami i kontrol¹ wartoœci
		super(masa);
		zmienPromien(promien);
		zmienWysokosc(wysokosc);
	}
	public Walec(Walec W) { //konstruktor kopiuj¹cy
		super(W);
		promien = W.promien;
		wysokosc = W.wysokosc;
	}
	
	//AKCESORY
	public double obliczPromien() { //akcesor zwracaj¹cy promieñ walca
		return promien;
	}
	@Override
	public boolean zmienPromien(double promien) { //akcesor zmieniaj¹cy promieñ walca
		if (promien < 0) {
			//jeœli podana zostanie ujemny promieñ, zostanie wyœwietlony b³¹d
			System.out.println("B£¥D! - Ujemna wartoœæ promienia dla " + this);
			//funkcja nie zmieni aktualnej wartoœci i zwróci wartoœæ false
			return false;
		}
		//jeœli podany promieñ jest prawid³owy
		else this.promien = promien;
		return true;
	}
	public double obliczWysokosc() { //akcesor zwracaj¹cy wysokoœæ walca
		return wysokosc;
	}
	@Override
	public boolean zmienWysokosc(double wysokosc) { //akcesor zmieniaj¹cy wysokoœæ walca
		if (wysokosc < 0) {
			//jeœli podana zostanie ujemna wysokoœæ, zostanie wyœwietlony b³¹d
			System.out.println("B£¥D! - Ujemna wartoœæ wysokoœci dla " + this);
			//funkcja nie zmieni aktualnej wartoœci i zwróci wartoœæ false
			return false;
		}
		//jeœli podana wysokoœæ jest prawid³owa
		else this.wysokosc = wysokosc;
		return true;
	}
	
	//METODY
	@Override
	public double GMomentBezwladnosci() {
		return 0.5*obliczMase()*promien*promien; //wartoœæ g³ównego momentu bezw³adnoœci walca
	}
	@Override
	public String toString() {
		return "Walec"; //krótki opis klasy
	}
	@Override
	protected String _opis() { //dodatkowe dane do opisu walca
		return ", promieniu " + obliczPromien() + " i wysokoœci " + obliczWysokosc();
	}
}
