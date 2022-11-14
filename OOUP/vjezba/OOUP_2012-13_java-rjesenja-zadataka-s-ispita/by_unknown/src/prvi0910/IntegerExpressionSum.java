package prvi0910;

import java.util.ArrayList;
import java.util.List;

public class IntegerExpressionSum implements IntegerExpression {

	private List<IntegerExpression> l;
	
	public IntegerExpressionSum() {
		super();
		this.l = new ArrayList();
	}
	
	public void addChild(IntegerExpression exp){
		l.add(exp);
	}
	
	public void removeChild(IntegerExpression exp){
		l.remove(exp);
	}
	
	public IntegerExpression getChild(int i){
		return l.get(i);
	}
	
	@Override
	public int value() {
		// TODO Auto-generated method stub
		int sum=0;
		for (IntegerExpression i:l){
			sum+=i.value();
		}
		return sum;
	}

}
