package prvi0910;

import java.util.ArrayList;
import java.util.List;

public class IntegerExpressionProduct implements IntegerExpression {

	private List<IntegerExpression> l;

	public IntegerExpressionProduct() {
		super();
		this.l = new ArrayList();
	}

	public void addChild(IntegerExpression exp) {
		l.add(exp);
	}

	public void removeChild(IntegerExpression exp) {
		l.remove(exp);
	}

	public IntegerExpression getChild(int i) {
		return l.get(i);
	}

	@Override
	public int value() {
		// TODO Auto-generated method stub
		int prod = 1;
		for (IntegerExpression i : l) {
			prod *= i.value();
		}
		return prod;
	}

}
