import java.util.*;
public class Pravokutnik extends Lik
{
	double a,b;
	public Pravokutnik(String redak)
	{
		Vector args=new Vector();
		args=parsiraj(redak,2);
		this.a=((Double)(args.get(0))).doubleValue();
		this.b=((Double)(args.get(1))).doubleValue();
	}
	
	double izracunajPovrsinu()
	{
		return a*b;
	}
	public String toString()
	{
		return "Pravokutnik, a="+a+", b="+b +"\t";
	}
}
