import java.util.Random;
import java.io.*;

public class KlasaTestowa {

	public static void main(String[] args) throws IOException {
		
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in)); //wej�cie z klawiatury
		PunktMaterialny P = new PunktMaterialny(); //obiekt na superklas� lub jedn� z klas pochodnych
		int menu; //obs�uga menu
		double we; //zmienna na warto�� wpisan� z klawiatury
		Random rand = new Random(); //zmienna losowa dla opcji testowania programu
		
		//PROGRAM
		System.out.println("Witaj w programie obliczaj�cym momenty bezw�adno�ci bry�.");
		while(true) { //niesko�czona p�tla
			
			//MENU
			System.out.println("------------------------------");
			System.out.println("Menu:   [1] Punkt Materialny   [2] Walec   [3] Kula   [4] Pr�t   [5] Test programu   [0] Wyj�cie");
			menu = (int)Double.parseDouble(in.readLine());
			
			//WYB�R OPCJI Z MENU
			switch(menu) {
			
			case 0: //zako�czenie programu
				System.out.println("Koniec programu.");
				return;
				
			case 1: //punkt materialny
				P = new PunktMaterialny();
				do { //p�tla wykonywana dopuki nie zostanie wprowadzona prawid�owa masa
					System.out.print("Podaj mas� punktu materialnego ");
					we = Double.parseDouble(in.readLine());
				} while (!P.zmienMase(we)); 
				break;
				
			case 2: //walec
				P = new Walec();
				do { //p�tla wykonywana dopuki nie zostanie wprowadzona prawid�owa masa
					System.out.print("Podaj mas� walca ");
					we = Double.parseDouble(in.readLine());
				} while (!P.zmienMase(we));
				do { //p�tla wykonywana dopuki nie zostanie wprowadzona prawid�owy promie�
					System.out.print("Podaj promie� walca ");
					we = Double.parseDouble(in.readLine());
				} while (!P.zmienPromien(we));
				do { //p�tla wykonywana dopuki nie zostanie wprowadzona prawid�owa wysoko��
					System.out.print("Podaj wysoko�� walca ");
					we = Double.parseDouble(in.readLine());
				} while (!P.zmienWysokosc(we));
				break;
				
			case 3: //kula
				P = new Kula();
				do { //p�tla wykonywana dopuki nie zostanie wprowadzona prawid�owa masa
					System.out.print("Podaj mas� kuli ");
					we = Double.parseDouble(in.readLine());
				} while (!P.zmienMase(we));
				do { //p�tla wykonywana dopuki nie zostanie wprowadzona prawid�owy promie�
					System.out.print("Podaj promie� kuli ");
					we = Double.parseDouble(in.readLine());
				} while (!P.zmienPromien(we));
				break;
				
			case 4: //pr�t
				P = new Pret();
				do { //p�tla wykonywana dopuki nie zostanie wprowadzona prawid�owa masa
					System.out.print("Podaj mas� pr�ta ");
					we = Double.parseDouble(in.readLine());
				} while (!P.zmienMase(we));
				do { //p�tla wykonywana dopuki nie zostanie wprowadzona prawid�owy promie�
					System.out.print("Podaj promie� pr�ta ");
					we = Double.parseDouble(in.readLine());
				} while (!P.zmienPromien(we));
				do { //p�tla wykonywana dopuki nie zostanie wprowadzona prawid�owa d�ugo��
					System.out.print("Podaj d�ugo�� pr�ta ");
					we = Double.parseDouble(in.readLine());
				} while (!P.zmienDlugosc(we));
				break;
				
			case 5: //test programu - wymagania zawarte w punkcie 2.3
				//stworzenie obiekt�w klas pochodnych za pomoc� konstruktor�w z parametrami
				Walec W = new Walec(1+rand.nextInt(9),1+rand.nextInt(9),1+rand.nextInt(9));
				Kula K = new Kula(1+rand.nextInt(9),1+rand.nextInt(9));
				Pret Pr = new Pret(1+rand.nextInt(9),1+rand.nextInt(9),1+rand.nextInt(9));
				//wy�wietlenie na konsoli informacji zawieraj�cej opis, dane i warto�ci moment�w bezw�adno�ci
				//dla wszystkich obiekt�w
				System.out.println("1.) " + W.opis(0));
				System.out.println("2.) " + K.opis(0));
				System.out.println("3.) " + Pr.opis(0) + "\n");
				//stworzenie tablicy obiekt�w r�nych klas pochodnych
				PunktMaterialny tab[] = new PunktMaterialny[3];
				tab[0] = new Walec(1+rand.nextInt(9),1+rand.nextInt(9),1+rand.nextInt(9));
				tab[1] = new Kula(1+rand.nextInt(9),1+rand.nextInt(9));
				tab[2] = new Pret(1+rand.nextInt(9),1+rand.nextInt(9),1+rand.nextInt(9));
				//wy�wietlenie na konsoli informacji zawieraj�cej opis, dane i warto�ci g��wnych moment�w bezw�adno�ci
				//dla wszystkich obiekt�w w tablicy z wykorzystaniem p�tli
				for (int i=0; i<3; i++) System.out.println("tab[" + i + "] " + tab[i].opis(0));
				//wy�wietlenie warto�ci moment�w bezw�adno�ci wzgl�dem nowej osi oddalonej o t� sam� odleg�o��
				//dla wszystkich obiekt�w w tablicy z wykorzystaniem p�tli
				double os = 1+rand.nextInt(9);
				System.out.println("\nWzgl�dem nowej osi bezw�adno�ci odleg�ej o " + os + " :");
				for (int i=0; i<3; i++)
					System.out.println("tab[" + i + "] " + tab[i] + " ma moment bezw�adno�ci r�wny " + tab[i].MomentBezwladnosci(os));
				continue;
				
			default: //w przypadku podania b��dnego numeru
				System.out.println("Nie ma opcji o numerze " + menu);
				continue;
			}
			
			//podanie odleg�o�ci osi, wzgl�dem kt�rej ma zosta� obliczony moment bezw�adno�ci
			System.out.print("Podaj odleg�o�� osi ");
			we = Double.parseDouble(in.readLine());
			
			System.out.println(P.opis(we)); //wypisanie opisu obiektu
		}
	}

}