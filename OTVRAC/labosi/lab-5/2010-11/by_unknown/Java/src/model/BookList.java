package model;

import java.util.Iterator;
import java.util.Vector;

public class BookList {
	private Vector<Book> books = new Vector<Book>();

	public void add(Book book) {
		books.add(book);
	}

	public void remove(Book book) {
		books.remove(book);
	}

	public Iterator<Book> books() {
		return books.iterator();
	}
}
