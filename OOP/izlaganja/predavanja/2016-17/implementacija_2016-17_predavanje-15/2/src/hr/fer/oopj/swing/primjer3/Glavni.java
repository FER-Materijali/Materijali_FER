package hr.fer.oopj.swing.primjer3;

import java.awt.Color;
import java.awt.Container;

import javax.swing.JFrame;
import javax.swing.JLabel;
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
		cp.setLayout(null);
		
		JLabel labela = new JLabel("Naslov");
		
		cp.add(labela);
		
		labela.setSize(labela.getPreferredSize());
		labela.setOpaque(true);
		labela.setBackground(Color.YELLOW);
		labela.setLocation((getWidth()-labela.getWidth())/2, 0);
		
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(() -> {
			new Glavni().setVisible(true);
		});
	}
	
}
