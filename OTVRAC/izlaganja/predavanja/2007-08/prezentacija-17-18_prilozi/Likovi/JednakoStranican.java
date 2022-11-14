import java.lang.Math;

public class JednakoStranican extends Trokut
{
	public JednakoStranican(String redak)
	{
		super(redak+" "+redak+" "+redak);
	}
	
	double izracunajPovrsinu()
	{
		return a*a*Math.sqrt(3)/4;
	}
	public String toString()
	{
		return "Jednakostranican trokut, a="+a;
	}
}