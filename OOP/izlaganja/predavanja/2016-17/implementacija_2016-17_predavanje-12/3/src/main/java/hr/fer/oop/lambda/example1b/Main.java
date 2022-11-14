package hr.fer.oop.lambda.example1b;

import java.util.List;

import hr.fer.oop.lambda.Car;
import hr.fer.oop.lambda.CarCatalog;
import hr.fer.oop.lambda.CarType;

public class Main {

	public static interface Prihvatljivo {
		boolean testiraj(Car car);
	}
	
	public static class Dizelasi implements Prihvatljivo {
		@Override
		public boolean testiraj(Car car) {
			return car.getType() == CarType.DIESEL;
		}
	}
	
	public static class Benzinci implements Prihvatljivo {
		@Override
		public boolean testiraj(Car car) {
			return car.getType() == CarType.PETROL;
		}
	}

	public static class ElektrSkuplji100000 implements Prihvatljivo {
		@Override
		public boolean testiraj(Car car) {
			return car.getType() == CarType.ELECTRIC && car.getPrice() > 100_000;
		}
	}
	

	public static void main(String[] args) {
		List<Car> cars = CarCatalog.loadCars();
		if(args.length!=1) return;
		
		if(args[0].equals("dizel")) {
			printCars(cars, new Dizelasi());		
		} else {
			printCars(cars, new Benzinci());
		}
	}
	
	private static void printCars(Iterable<Car> cars, Prihvatljivo tester) {
		for(Car car : cars){
			if (tester.testiraj(car)){
				System.out.println(car);
			}
		}		
	}
}
