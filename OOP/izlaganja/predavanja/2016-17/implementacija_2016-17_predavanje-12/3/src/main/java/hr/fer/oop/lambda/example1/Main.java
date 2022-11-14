package hr.fer.oop.lambda.example1;

import java.util.List;

import hr.fer.oop.lambda.Car;
import hr.fer.oop.lambda.CarCatalog;
import hr.fer.oop.lambda.CarType;

public class Main {

	public static void main(String[] args) {
		List<Car> cars = CarCatalog.loadCars();
		if(args.length!=1) return;
		
		if(args[0].equals("dizel")) {
			printDieselCars(cars);		
		} else {
			printPetrolCars(cars);
		}
	}
	
	private static void printDieselCars(Iterable<Car> cars) {
		for(Car car : cars){
			if (car.getType() == CarType.DIESEL){
				System.out.println(car);
			}
		}		
	}
	
	private static void printPetrolCars(Iterable<Car> cars) {
		for(Car car : cars){
			if (car.getType() == CarType.PETROL){
				System.out.println(car);
			}
		}		
	}
}
