import java.util.TimerTask;

public class SimTask extends TimerTask
{
	private SpringApplet app;
	private SimEngine sim;
	
	public SimTask(SpringApplet _app, SimEngine _sim) {
		app = _app;
		sim = _sim;
	}
	
	@Override
	public void run() {
		sim.step(0.06);
		app.repaint();
	}

}
