package prvi0910;

public class IntegerExpressionConstant implements IntegerExpression {

	private int value;
	
	public IntegerExpressionConstant(int value) {
		// TODO Auto-generated constructor stub
		this.value=value;
	}
	
	@Override
	public int value() {
		// TODO Auto-generated method stub
		return value;
	}

}
