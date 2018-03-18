public class Vector2D
{
	public double x;
	public double y;
	
	public Vector2D()
	{
		x = 0;
		y = 0;
	}
	
	public Vector2D(double x, double y) 
	{
		this.x = x;
		this.y = y;
	}

	public Vector2D add(Vector2D v)
	{
		return new Vector2D(x+v.x, y+v.y);
	}

	public Vector2D multiplyFactor(double d) {
		return new Vector2D(x*d, y*d);
	}

	public Vector2D sub(Vector2D v) {
		return new Vector2D(x-v.x, y-v.y);
	}

	public Vector2D norm() { //tworzy wersor
		Vector2D result = new Vector2D(x, y);
		if (x<0) result.x = -result.x;
		if (y<0) result.y = -result.y;
		return result;
	}

	public double length() {
		return Math.sqrt(x*x+y*y);
	}
}
