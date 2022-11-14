package prvi0910;

public class IspitniProgram {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		IntegerExpression br1=new IntegerExpressionConstant(1);
		IntegerExpression br2=new IntegerExpressionConstant(2);
		IntegerExpression br3=new IntegerExpressionConstant(3);
		IntegerExpression br4=new IntegerExpressionConstant(4);
		
		IntegerExpressionSum suma12=new IntegerExpressionSum();
		suma12.addChild(br1);
		suma12.addChild(br2);
		
		IntegerExpressionProduct prod34=new IntegerExpressionProduct();
		prod34.addChild(br3);
		prod34.addChild(br4);
		
		IntegerExpressionSum theSum=new IntegerExpressionSum();
		theSum.addChild(suma12);
		theSum.addChild(prod34);
		
		System.out.println(suma12.value());
		System.out.println(prod34.value());
		System.out.println(theSum.value());
	}

}
