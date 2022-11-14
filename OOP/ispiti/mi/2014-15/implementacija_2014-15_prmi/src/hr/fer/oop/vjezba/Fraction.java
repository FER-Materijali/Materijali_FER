package hr.fer.oop.vjezba;

/**
 * Second task from midterm exam
 * 
 * @author KarloVrbic
 * @version 1.0
 */
public class Fraction {

	private int numerator;
	private int denominator;
	
	/**
	 * Default constructor that creates fraction 0/1.
	 */
	public Fraction(){
		this.numerator = 0;
		this.denominator = 1;
	}
	
	/**
	 * Constructor that makes a whole number(denominator is 1).
	 * @param numerator Numerator of a fraction
	 */
	public Fraction(int numerator){
		this.numerator = numerator;
		this.denominator = 1;
	}
	
	/**
	 * Constructor for two arguments
	 * @param numerator Numerator of a fraction
	 * @param denominator Denominator of a fraction
	 */
	public Fraction(int numerator, int denominator) {
		if(denominator == 0)
			throw new IllegalArgumentException("Invalid denominator");
		this.numerator = numerator;
		this.denominator = denominator;
		this.fix();
	}

	/**
	 * Main method used for testing purposes
	 * @param args Not used
	 */
	public static void main1(String[] args) {
		Fraction num1 = new Fraction(5, 4);
		Fraction num2 = new Fraction(-8, 9);
		Fraction result = new Fraction();
		
		result = num1.add(num2);
		System.out.println(num1.toString() + " + " + num2.toString() + " = " + result.toString() + "," + result.toDouble());
		
		result = num1.subtract(num2);
		System.out.println(num1.toString() + " - " + num2.toString() + " = " + result.toString() + "," + result.toDouble());

		
		result = num1.multiply(num2);
		System.out.println(num1.toString() + " * " + num2.toString() + " = " + result.toString() + "," + result.toDouble());
		
		result = num1.divide(num2);
		System.out.println(num1.toString() + " / " + num2.toString() + " = " + result.toString() + "," + result.toDouble());
	}
	
	/**
	 * Method used for inputing new numerator
	 * @param numerator Numerator of a fraction
	 */
	public void setNumerator(int numerator){
		this.numerator = numerator;
	}
	
	/**
	 * Method used for inputing new denominator
	 * @param denominator Denominator of a fraction
	 */
	public void setDenominator(int denominator){
		if(denominator == 0)
			throw new IllegalArgumentException("Invalid denominator");
		this.denominator = denominator;
		this.fix();
	}
	
	/**
	 * Method used to "fix" fraction in a way that it always have negative number in numerator if it is negative fraction and
	 * if fraction has both numerator or denominator negative this method makes them both positive
	 */
	private void fix(){
		if((this.numerator < 0 && this.denominator < 0) || this.denominator < 0){
			this.numerator = -this.numerator;
			this.denominator = -this.denominator;
		}
	}
	
	/**
	 * Static method which determines which argument is greater
	 * @param first Any integer value
	 * @param second Any integer value
	 * @return Greatest of the two arguments
	 */
	private static int max(int first, int second){
		if(first >= second)
			return first;
		else
			return second;
	}
	
	/**
	 * Method that uses Euclids algorithm for greatest common divisor
	 * @param first Any integer value
	 * @param second Any integer value
	 * @return Greatest common divisor
	 */
	private static int gcd(int first, int second){
		if(second == 0)
			return first;

		return Fraction.gcd(second, first % second); 
	}
	
	/**
	 * Method that calculates least common multiple
	 * @param first Any integer value
	 * @param second Any integer value
	 * @return Least common multiple
	 */
	private static int commonDivider(int first, int second){
		return Math.abs(first) * Math.abs(second) / Fraction.gcd(first, second);
	}
	
	/**
	 * Method that changes fraction to reciprocal fraction of itself
	 * @return Reciprocal fraction of itself
	 */
	public Fraction reciprocal(){
		int tmp = this.numerator;
		this.numerator = this.denominator;
		this.denominator = tmp;
		
		return this;
	}
	
	/**
	 * Method that reduces fraction
	 * @return Reduced fraction
	 */
	public Fraction reduce(){
		for(int i = Fraction.max(this.numerator, this.denominator); i > 1; i--)
			if(this.numerator % i == 0 && this.denominator % i == 0){
				this.numerator /= i;
				this.denominator /= i;
			}
		
		return this;
				
	}
	
	/**
	 * Method used for adding two fractions
	 * @param that Addend fraction
	 * @return Sum fraction
	 */
	public Fraction add(Fraction that){
		Fraction result = new Fraction();
		result.denominator = this.denominator * that.denominator;
		
		result.denominator = Fraction.commonDivider(this.denominator, that.denominator);
		result.numerator = (result.denominator / this.denominator) * this.numerator + (result.denominator / that.denominator) * that.numerator;
		result.reduce();
		
		return result;
	}
	
	/**
	 * Method used for subtracting two fractions
	 * @param that Subtrahend fraction
	 * @return Difference fraction
	 */
	public Fraction subtract(Fraction that){
		Fraction result = new Fraction();
		result.denominator = this.denominator * that.denominator;
		
		result.denominator = Fraction.commonDivider(this.denominator, that.denominator);
		result.numerator = (result.denominator / this.denominator) * this.numerator - (result.denominator / that.denominator) * that.numerator;
		result.reduce();
		
		return result;
	}
	
	/**
	 * Method used for multiplying two fractions
	 * @param that Multiplier fraction
	 * @return Product fraction
	 */
	public Fraction multiply(Fraction that){
		Fraction result = new Fraction();
		
		result.numerator = this.numerator * that.numerator;
		result.denominator = this.denominator * that.denominator;
		result.reduce();
		
		return result;
	}
	
	/**
	 * Method used for dividing two fractions
	 * @param that Divisor fraction
	 * @return Quotient fraction
	 */
	public Fraction divide(Fraction that){
		Fraction result = new Fraction();

		result = this.multiply(that.reciprocal());
		
		return result;
	}
	
	/**
	 * Converting to string("numerator/denominator")
	 * @return String value of fraction
	 */
	@Override
	public String toString(){
		return Integer.toString(this.numerator) + "/" + Integer.toString(this.denominator);
	}
	
	/**
	 * Converting to Double
	 * @return Double value of fraction
	 */
	public Double toDouble(){
		return (double)this.numerator / this.denominator;
	}
}
