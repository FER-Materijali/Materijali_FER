package hr.fer.oop.primjeri.p005;

public interface Memory {
	public Object getFromLocation(int address);
	public void storeAtLocation(int address,Object object);
}
