package hr.fer.oop.primjeri.p004;

public class Main {
	
	public static void main(String[] args){
		
		Stack<Integer> stack = new Stack<>();
		
		System.out.println(stack.isEmpty());
		
		stack.push(1);
		stack.push(2);
		stack.push(3);
		stack.push(5);
		stack.push(4);
		stack.push(5);
		
		stack.pop();
		stack.pop();
		
		stack.push(10);
		stack.push(11);
		
		System.out.println(stack.isEmpty());
		System.out.println(stack.getSize());
		
		for(Integer num : stack){
			System.out.println(num);
		}
	}
}
