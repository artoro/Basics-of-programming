public class SimEngine
{
	//sta³e
	private double g; //przyspieszenie grawitacyjne
	
	//dane mechaniczne
	private Vector2D p1; //punkt zawieszenia
	private Vector2D p2; //po³o¿enie masy
	private double m; //masa
	private double k; //sztywnoœæ
	private double b; //t³umienie 
	private double l0; //d³ugoœæ swobodna sprê¿yny
	
	//dane kinematyczne
	private Vector2D v; //prêdkoœæ masy
	
	//KONSTRUKTORY
	public SimEngine(Vector2D _p1, Vector2D _p2, double _m, double _l0, double _k, double _b, double _g) {
		//parametry symulacji
		p1 = _p1;
		setP2(_p2);
		setM(_m);
		setL0(_l0);
		setK(_k);
		b = _b;
		g = _g;
		
		//parametry pocz¹tkowe
		p2 = p1.add(new Vector2D(0,l0)); //po³o¿enie masy poni¿ej punktu zawieszenia
		v = new Vector2D(0,0);
	}
	
	//AKCESORY
	public Vector2D getP1() {
		return p1;
	}
	
	public Vector2D getP2() {
		return p2;
	}

	public void setP2(Vector2D p2) {
		this.p2 = p2;
	}

	public double getM() {
		return m;
	}

	public void setM(double m) {
		this.m = (m>0)? m : 1.0;
	}

	public double getK() {
		return k;
	}

	public void setK(double k) {
		this.k = (k>0)? k : 1000.0;
	}

	public double getB() {
		return b;
	}

	public void setB(double b) {
		this.b = (b>0)? b : 0;
	}

	public double getL0() {
		return l0;
	}

	public void setL0(double l0) {
		this.l0 = (l0>0)? l0 : 1.0;
	}
	
	//METODY
	public void step(double dt) {
		Vector2D G = new Vector2D(0,m*g); //si³a grawitacji
		Vector2D Fb = v.multiplyFactor(-b); //si³a t³umienia
		double x = p1.sub(p2).length()-l0; //wychylenie z po³o¿enia równowagi
		Vector2D Fs = p1.sub(p2).norm().multiplyFactor(k*x); //si³a sprê¿ystoœci
		Vector2D Fn = G.sub(Fb).sub(Fs); //si³a wypadkowa (n - net force)
		Vector2D a = Fn.multiplyFactor(1.0/m); //przyspieszenie wypadkowe
		
		v = v.add(a.multiplyFactor(dt)); //uaktualnienie prêdkoœci
		p2 = p2.add(v.multiplyFactor(dt)); //uaktualnienie pozycji
	}
	
}
