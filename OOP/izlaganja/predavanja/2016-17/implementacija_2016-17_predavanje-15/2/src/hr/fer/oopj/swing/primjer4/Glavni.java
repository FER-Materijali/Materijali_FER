package hr.fer.oopj.swing.primjer4;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import javax.swing.SwingUtilities;
import javax.swing.WindowConstants;

public class Glavni extends JFrame {

	private static final long serialVersionUID = 1L;

	public Glavni() {
		setSize(400, 300);
		setLocation(200, 100);
		setTitle("Moj prvi prozor!");
		setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
		
		initGUI();
	}
	
	private void initGUI() {
		Container cp = getContentPane();
		cp.setLayout(new BorderLayout());
		
		JLabel labela = new JLabel("Naslov");
		
		cp.add(labela, BorderLayout.PAGE_START);
		
		labela.setOpaque(true);
		labela.setHorizontalAlignment(SwingConstants.CENTER);
		labela.setBackground(Color.YELLOW);
		
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(() -> {
			new Glavni().setVisible(true);
		});
	}
	
}
