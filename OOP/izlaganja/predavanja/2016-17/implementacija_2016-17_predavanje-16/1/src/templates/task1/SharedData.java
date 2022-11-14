package templates.task1;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingDeque;
// Napomena o redovima:
// Koristimo li red ogranicenog kapaciteta, npr.:
// airQueue = new ArrayBlockingQueue<>(1);
// pretpostavljamo da samo ogranicen broj korisnika moze cekatim
// u prethodnom primjeru samo jedan moze cekati na ukljucenje u eter
// dok istovremeno spiker razgovara s drugim koji je vec u eteru;
// koristimo li red bez ogranicenja, vise onih koji su tocno odgovorili 
// na eliminacijsko pitanje moze cekati na ukljucenje u eteru dok istovemeno
// djelatnici koji su ih pitali mogu preuzeti ispitivanje novih pozivatelja;
// ovisno kako se shvati zadatak (i sto podrzava "fizicka" infrastruktura
// telefona/centrale, oba rjesenja (pa i neko trece) su moguca.
public class SharedData {
	int id = 0;
	// Google it up: "Java volatile keyword"
	private volatile boolean gameOver = false;
	private BlockingQueue<String> airQueue;
	private BlockingQueue<String> queue;

	public SharedData(int noOfEmployees){
		airQueue = new LinkedBlockingDeque<>();
		queue = new LinkedBlockingDeque<>();
		//airQueue = new ArrayBlockingQueue<>(1);
		//queue = new ArrayBlockingQueue<>(noOfEmployees);
	}
	
	//metoda nextId vraća sljedeći redni broj natjecatelja
	public synchronized int nextId(){
		++id;
		return id;
	}
	
	public boolean isGameOver() {
		return gameOver;
	}

	public void setGameOver(boolean gameOver) {
		this.gameOver = gameOver;
	}

	public BlockingQueue<String> getAirQueue() {
		return airQueue;
	}

	
	public BlockingQueue<String> getQueue() {
		return queue;
	}
}
