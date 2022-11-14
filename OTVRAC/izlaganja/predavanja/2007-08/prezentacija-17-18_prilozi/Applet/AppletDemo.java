import java.applet.Applet;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;

public class AppletDemo extends Applet
{
	int brojKvadratica, delay;
    public void init() {
		setForeground (Color.red); 
		brojKvadratica=Integer.parseInt(getParameter("BrojKvadratica"));
		delay=Integer.parseInt(getParameter("Delay"));
		System.out.println("numK="+brojKvadratica+" delay="+delay);
    }
    public void start() {}
    public void stop() {}
    public void destroy() {}
	public void paint(Graphics g)
	{
		int a=10; int b=20; int h=30; int v=40;
		for (int i=1;i<brojKvadratica;i++){
			g.drawRect(a+i,b+i,h+i,v+i);
			try{	   
				Thread.sleep(delay);
			}catch(Exception e){}
		}
	}
}