public class Kula extends PunktMaterialny {
	
	//POLA
	private double promien;
	
	//KONSTRUKTORY
	public Kula() { //konstruktor domyœlny
		super();
		promien = 1;
	}
	public Kula(double masa, double promien) { //konstruktor z parametrami i kontrol¹ wartoœci
		super(masa);
		zmienPromien(promien);
	}
	public Kula(Kula K) { //konstruktor kopiuj¹cy
		super(K);
		promien = K.promien;
	}
	
	//AKCESORY
	public double obliczPromien() { //akcesor zwracaj¹cy promieñ kuli
		return promien;
	}
	@Override
	public boolean zmienPromien(double promien) { //akcesor zmieniaj¹cy promieñ kuli
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
	
	//METODY
	@Override
	public double GMomentBezwladnosci() {
		return 2.0/3.0*obliczMase()*promien*promien; //wartoœæ g³ównego momentu bezw³adnoœci kuli
	}
	@Override
	public String toString() {
		return "Kula"; //krótki opis klasy
	}
	@Override
	protected String _opis() { //dodatkowe dane do opisu kuli
		return " i promieniu " + obliczPromien();
	}
}
