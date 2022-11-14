package hr.fer.oop.lambda.example2;

import java.util.List;
import java.util.function.Predicate;

import hr.fer.oop.lambda.Car;
import hr.fer.oop.lambda.CarCatalog;
import hr.fer.oop.lambda.CarType;

public class Main {

	public static void main(String[] args) {
		List<Car> cars = CarCatalog.loadCars();
		System.out.println("Cheap cars:");
		printCars(cars, new CheapCarPredicate());	
		System.out.println("Diesel cars:");
		printCars(cars, new DieselCarPredicate());

		// Objekt definiramo kao primjerak anonimnog razreda i referencu odmah dajemo kao argument metode...
		printCars(cars, new Predicate<Car>() {			
			public boolean test(Car car) {
				return car.getType()==CarType.ELECTRIC && car.getPrice()<127_537;
			}
		});

		// Još jedan primjer definiranja objekta preko anonimnog razreda:
		printCars(cars, new Predicate<Car>() {			
			public boolean test(Car car) {
				return car.getType()==CarType.DIESEL;
			}
		});
		// Još jedan primjer definiranja objekta preko anonimnog razreda:
		printCars(cars, new Predicate<Car>() {			
			public boolean test(Car car) {
				return car.getPower() > 20;
			}
		});

		// Stvaranje primjerka anonimnog razreda nije niša posebno: referencu možemo pohraniti i u lokalnu varijablu  pa kasnije koristiti...
		Predicate<Car> test0 = new Predicate<Car>() {
			@Override
			public boolean test(Car t) {
				return Car.isElectric(t);
			}
		};

		// Umjesto "opširne" sintakse za definiranje primjerka anonimnog razreda, isti možemo definirati sintaksnom
		// pokratom poznatom pod nazivom "lambda-izraz", kako je prikazano u nastavku.
		Predicate<Car> test0a = t -> Car.isElectric(t);
		
		// A sve ovo možemo još pokratiti pisanjem takozvanog "method-handle"-a:
		Predicate<Car> test0b = Car::isElectric;

		// Ako u for-petlji koja se izvodi puno puta trebamo objekt kojem ćemo delegirati određen zadatak,
		// taj je objekt dobro stvoriti jednom izvan petlje for, a ne svaki puta unutar iteracije petlje 
		// stvarati novi objekt.
		Predicate<Car> test1 = car -> car.getType()==CarType.ELECTRIC && car.getPrice()<127_537;
		for(int i = 0; i < 1_000_000; i++) {
			printCars(cars, test1);
		}

		// Još jedan primjer definiranja objekta lambda izrazom:
		printCars(cars, car -> car.getType()==CarType.ELECTRIC && car.getPrice()<127_537);

		// Još jedan primjer definiranja objekta lambda izrazom, gdje sada dajemo kompletno tijelo
		// metode; stoga započinjemo i završavamo vitičastim zagradama, i metoda mora preko return
		// vratiti rezultat.
		printCars(cars, car -> {
			boolean jeLiDizelas = car.getType() == CarType.DIESEL;
			boolean jeLiJeftin = car.getPrice() < 127_537;
			return jeLiDizelas && jeLiJeftin;
		});

		// Sada smo apstrahirali i testiranje prihvatljivosti i obradu, kao dvije nezavisne strategije;
		// svaka je definirana svojim sučeljem. U pozivima metode umjesto sintakse stvaranja primjerka
		// anonimnog razreda, objekte definiramo:
		// 1) lambda izrazima:
		processCars(cars, c->c.getType()==CarType.DIESEL, c->System.out.println(c));
		// 2) "method-handle"-ovima:
		processCars(cars, Car::isElectric, System.out::println);
	}

	// Općenitija metoda za ispis automobila koje prihvati strategija:
	private static void printCars(Iterable<Car> cars, Predicate<Car> predicate) {
		for(Car car : cars){
			if (predicate.test(car)){
				System.out.println(car);
			}
		}		
	}

	// Sučelje koje opisuje neku proizvolju obradu automobila:
	interface Obrada {
		void obradi(Car c);
	}
	
	// Još općenitija metoda za obradu automobila (u popisu argumenata metode druga strategija) koje prihvaća ispitni predikat (u popisu argumenata metode prva strategija):
	private static void processCars(Iterable<Car> cars, Predicate<Car> predicate, Obrada o) {
		for(Car car : cars){
			if (predicate.test(car)){
				o.obradi(car);
			}
		}		
	}

}
