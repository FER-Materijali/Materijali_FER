package hr.fer.oopj.swing.primjer5;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
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
		
		JLabel labela1 = new JLabel("Naslov");
		JLabel labela2 = new JLabel("Unesite ime i prezime:");
		JTextField unosTeksta = new JTextField("Bok!");
		JButton gumb = new JButton("OK");
		
		labela1.setOpaque(true);
		labela1.setBackground(Color.YELLOW);
		labela2.setOpaque(true);
		labela2.setBackground(Color.GREEN);

		cp.add(labela1, BorderLayout.PAGE_START);
		labela1.setHorizontalAlignment(SwingConstants.CENTER);
		
		cp.add(labela2, BorderLayout.LINE_START);
		
		cp.add(unosTeksta, BorderLayout.CENTER);
		
		JPanel panel = new JPanel();
		panel.setOpaque(true);
		panel.setBackground(new Color(255,128,56));
		panel.add(gumb);
		
		cp.add(panel, BorderLayout.PAGE_END);
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(() -> {
			new Glavni().setVisible(true);
		});
	}
	
}
