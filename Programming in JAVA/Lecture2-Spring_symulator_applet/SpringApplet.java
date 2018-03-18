import java.awt.Button;
import java.awt.FlowLayout;
import java.awt.Graphics;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.util.Timer;

import javax.swing.JApplet; //dziedziczenie po JApplet, nie zawiera main (jest on juz gdzies wczesniej)

public class SpringApplet extends JApplet implements MouseListener, MouseMotionListener  //implements dodaje interfejsy
{
	private static final long serialVersionUID = 1L; //wymagane przez JApplet
	private double a;
	private Button resetBtn;
	private Button startBtn;
	private TextField masaField;
	private Timer timer;
	private SimTask simTask;
	private SimEngine simEngine;
	private boolean picked;
	private int scale;
	
	@Override
	public void init() {
		super.init();
		a=10;
		scale = 100;
		
		//MYSZ
		this.addMouseListener(this); //wlacza obsluge myszy dla naszego appleta
		this.addMouseMotionListener(this); 
		picked = false;
		
		//GUI
		this.setLayout(new FlowLayout()); //tworzy gorne menu, w ktorym bedzie przycisk
		resetBtn = new Button("Reset"); 
		startBtn = new Button("Start");
		masaField = new TextField("1.0");
		
		this.add(resetBtn);
		this.add(startBtn);
		this.add(masaField);
		//resetBtn.addActionListener(this);
		//startBtn.addActionListener(this);
		
		//Silnik symulacji
		simEngine = new SimEngine(new Vector2D(1,0), new Vector2D(), 1.0, 1.0, 10.0, 1.0, 9.81);
		
		//Timer
		timer = new Timer();
		simTask = new SimTask(this, simEngine);
		//timer.scheduleAtFixedRate(simTask, 0, 60); //obiekt, start, co ile milisekund
		
		//Wektory
		Vector2D v1 = new Vector2D(1.0, 1.0);
		Vector2D v2 = new Vector2D(2.0, 3.0);
		Vector2D v3 = v1.add(v2);
	}
	@Override
	public void paint(Graphics g) {
		super.paint(g);
		
		g.drawLine((int)(scale*simEngine.getP1().x), (int)(scale*simEngine.getP1().y), (int)(scale*simEngine.getP2().x), (int)(scale*simEngine.getP2().y)); //rysuje okrag o poczatku w pkt. 20+a, 20 i rozmiarze 50, 50
		g.drawOval((int)(scale*simEngine.getP2().x)-10, (int)(scale*simEngine.getP2().y)-10, 20, 20);
	}
	@Override
	public void mouseClicked(MouseEvent arg0) {
		// TODO Auto-generated method stub
		System.out.println("Clicked");
	}
	@Override
	public void mouseEntered(MouseEvent arg0) {
		// TODO Auto-generated method stub
		System.out.println("Entered");
	}
	@Override
	public void mouseExited(MouseEvent arg0) {
		// TODO Auto-generated method stub
		System.out.println("Exited");
	}
	@Override
	public void mousePressed(MouseEvent e) {
		if (e.getX() > (int)(scale*simEngine.getP2().x)-10 && e.getX() < (int)(scale*simEngine.getP2().x)+10)
			if (e.getX() > (int)(scale*simEngine.getP2().x)-10 && e.getX() < (int)(scale*simEngine.getP2().x)+10)
				picked = true;
				else picked = false;
		
		System.out.println("Pressed");
	}
	@Override
	public void mouseReleased(MouseEvent arg0) {
		if (picked) {
			picked = false;
			timer.scheduleAtFixedRate(simTask, 0, 60); //obiekt, start, co ile milisekund
		}
		
		System.out.println("Released");
	}
	@Override
	public void mouseDragged(MouseEvent e) {
		if (picked) {
			Vector2D p = new Vector2D(e.getX(), e.getY());
			simEngine.setP2(p);
		}
		System.out.println("Dragged");
	}
	@Override
	public void mouseMoved(MouseEvent m) {
		// TODO Auto-generated method stub
		System.out.println("Moved x=" + m.getX() + " y=" + m.getY());
	}
	
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == resetBtn)
		{
			System.out.println("Reset");
		}
		else if(e.getSource() == startBtn)
		{
			double b = Double.parseDouble(masaField.getText());
			System.out.println("Start " + b);
		}
	}
}
