package hr.fer.oop.swing.component;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;

import javax.swing.JComponent;

public class Drawing extends JComponent {

	private static final long serialVersionUID = 1L;
	
	private int radius;

	public Drawing(int radius) {
		this.radius = radius;
		// NAPOMENA: ova linija je bitna za LayoutManagere da znaju koliko je velika
		// komponenta
		setPreferredSize(new Dimension(radius * 2, radius * 2));
		setBackground(Color.ORANGE);
	}

	public void setRadius(int value) {
		radius = value;
		// NAPOMENA: promjena veličine komponente
		setPreferredSize(new Dimension(radius * 2, radius * 2));
		// NAPOMENA: Bez ove dvije linije se neće proračunati i povećati
		// invalidate();
		// getParent().validate();
		// NAPOMENA: ili možemo samo pozvati sljedeću metodu
		revalidate();
	}

	public int getRadius() {
		return radius;
	}

	@Override
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
		g.setColor(getBackground());
		g.fillRect(0, 0, getWidth(), getHeight());
		g.setColor(getForeground());
		g.drawOval(0, 0, radius * 2 - 1, radius * 2 - 1);
	}
}
