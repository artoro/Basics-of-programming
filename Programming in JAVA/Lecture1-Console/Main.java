
public class Main {

	public static void main(String[] args) {
		int a = 1; // lub Integer
		double b = 3.14; // lub Double
		float c = 3.14f; // rzutowanie: (float) 3.14
		String d = "abcd";
		Double e = Double.parseDouble("3.141592") + 1;
		
		Triangle tr = new Triangle(); // trzeba inicjowaæ przed uruchomieniem, obiekty s¹ dynamiczne

		System.out.println("test " + a); //wyœwietlanie tekstu w konsoli
		System.out.println("Nasz trójk¹t " + tr.a + " " + tr.h + " " + tr.area()); //dostêp do pól publicznych objektu
	}

}
