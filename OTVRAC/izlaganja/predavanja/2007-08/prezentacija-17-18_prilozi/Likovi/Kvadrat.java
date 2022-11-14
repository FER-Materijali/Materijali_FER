public class Kvadrat extends Pravokutnik
{
	public Kvadrat(String redak)
	{
		super(redak+" "+redak);
	}
	
	public String toString()
	{
		return "Kvadrat, a="+a+"\t\t\t";
	}
}
