import java.util.Random;
import java.io.*;

public class KlasaTestowa {

	public static void main(String[] args) throws IOException {
		
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in)); //wejœcie z klawiatury
		PunktMaterialny P = new PunktMaterialny(); //obiekt na superklasê lub jedn¹ z klas pochodnych
		int menu; //obs³uga menu
		double we; //zmienna na wartoœæ wpisan¹ z klawiatury
		Random rand = new Random(); //zmienna losowa dla opcji testowania programu
		
		//PROGRAM
		System.out.println("Witaj w programie obliczaj¹cym momenty bezw³adnoœci bry³.");
		while(true) { //nieskoñczona pêtla
			
			//MENU
			System.out.println("------------------------------");
			System.out.println("Menu:   [1] Punkt Materialny   [2] Walec   [3] Kula   [4] Prêt   [5] Test programu   [0] Wyjœcie");
			menu = (int)Double.parseDouble(in.readLine());
			
			//WYBÓR OPCJI Z MENU
			switch(menu) {
			
			case 0: //zakoñczenie programu
				System.out.println("Koniec programu.");
				return;
				
			case 1: //punkt materialny
				P = new PunktMaterialny();
				do { //pêtla wykonywana dopuki nie zostanie wprowadzona prawid³owa masa
					System.out.print("Podaj masê punktu materialnego ");
					we = Double.parseDouble(in.readLine());
				} while (!P.zmienMase(we)); 
				break;
				
			case 2: //walec
				P = new Walec();
				do { //pêtla wykonywana dopuki nie zostanie wprowadzona prawid³owa masa
					System.out.print("Podaj masê walca ");
					we = Double.parseDouble(in.readLine());
				} while (!P.zmienMase(we));
				do { //pêtla wykonywana dopuki nie zostanie wprowadzona prawid³owy promieñ
					System.out.print("Podaj promieñ walca ");
					we = Double.parseDouble(in.readLine());
				} while (!P.zmienPromien(we));
				do { //pêtla wykonywana dopuki nie zostanie wprowadzona prawid³owa wysokoœæ
					System.out.print("Podaj wysokoœæ walca ");
					we = Double.parseDouble(in.readLine());
				} while (!P.zmienWysokosc(we));
				break;
				
			case 3: //kula
				P = new Kula();
				do { //pêtla wykonywana dopuki nie zostanie wprowadzona prawid³owa masa
					System.out.print("Podaj masê kuli ");
					we = Double.parseDouble(in.readLine());
				} while (!P.zmienMase(we));
				do { //pêtla wykonywana dopuki nie zostanie wprowadzona prawid³owy promieñ
					System.out.print("Podaj promieñ kuli ");
					we = Double.parseDouble(in.readLine());
				} while (!P.zmienPromien(we));
				break;
				
			case 4: //prêt
				P = new Pret();
				do { //pêtla wykonywana dopuki nie zostanie wprowadzona prawid³owa masa
					System.out.print("Podaj masê prêta ");
					we = Double.parseDouble(in.readLine());
				} while (!P.zmienMase(we));
				do { //pêtla wykonywana dopuki nie zostanie wprowadzona prawid³owy promieñ
					System.out.print("Podaj promieñ prêta ");
					we = Double.parseDouble(in.readLine());
				} while (!P.zmienPromien(we));
				do { //pêtla wykonywana dopuki nie zostanie wprowadzona prawid³owa d³ugoœæ
					System.out.print("Podaj d³ugoœæ prêta ");
					we = Double.parseDouble(in.readLine());
				} while (!P.zmienDlugosc(we));
				break;
				
			case 5: //test programu - wymagania zawarte w punkcie 2.3
				//stworzenie obiektów klas pochodnych za pomoc¹ konstruktorów z parametrami
				Walec W = new Walec(1+rand.nextInt(9),1+rand.nextInt(9),1+rand.nextInt(9));
				Kula K = new Kula(1+rand.nextInt(9),1+rand.nextInt(9));
				Pret Pr = new Pret(1+rand.nextInt(9),1+rand.nextInt(9),1+rand.nextInt(9));
				//wyœwietlenie na konsoli informacji zawieraj¹cej opis, dane i wartoœci momentów bezw³adnoœci
				//dla wszystkich obiektów
				System.out.println("1.) " + W.opis(0));
				System.out.println("2.) " + K.opis(0));
				System.out.println("3.) " + Pr.opis(0) + "\n");
				//stworzenie tablicy obiektów ró¿nych klas pochodnych
				PunktMaterialny tab[] = new PunktMaterialny[3];
				tab[0] = new Walec(1+rand.nextInt(9),1+rand.nextInt(9),1+rand.nextInt(9));
				tab[1] = new Kula(1+rand.nextInt(9),1+rand.nextInt(9));
				tab[2] = new Pret(1+rand.nextInt(9),1+rand.nextInt(9),1+rand.nextInt(9));
				//wyœwietlenie na konsoli informacji zawieraj¹cej opis, dane i wartoœci g³ównych momentów bezw³adnoœci
				//dla wszystkich obiektów w tablicy z wykorzystaniem pêtli
				for (int i=0; i<3; i++) System.out.println("tab[" + i + "] " + tab[i].opis(0));
				//wyœwietlenie wartoœci momentów bezw³adnoœci wzglêdem nowej osi oddalonej o t¹ sam¹ odleg³oœæ
				//dla wszystkich obiektów w tablicy z wykorzystaniem pêtli
				double os = 1+rand.nextInt(9);
				System.out.println("\nWzglêdem nowej osi bezw³adnoœci odleg³ej o " + os + " :");
				for (int i=0; i<3; i++)
					System.out.println("tab[" + i + "] " + tab[i] + " ma moment bezw³adnoœci równy " + tab[i].MomentBezwladnosci(os));
				continue;
				
			default: //w przypadku podania b³êdnego numeru
				System.out.println("Nie ma opcji o numerze " + menu);
				continue;
			}
			
			//podanie odleg³oœci osi, wzglêdem której ma zostaæ obliczony moment bezw³adnoœci
			System.out.print("Podaj odleg³oœæ osi ");
			we = Double.parseDouble(in.readLine());
			
			System.out.println(P.opis(we)); //wypisanie opisu obiektu
		}
	}

}