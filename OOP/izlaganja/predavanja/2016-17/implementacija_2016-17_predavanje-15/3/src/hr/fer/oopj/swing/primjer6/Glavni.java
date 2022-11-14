package hr.fer.oopj.swing.primjer6;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

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
		JLabel labela2 = new JLabel("Unesite neki tekst:");
		JTextField unosTeksta = new JTextField();
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

		gumb.addActionListener( e -> {
			System.out.println(e.getSource());
			String uneseno = unosTeksta.getText();
			unosTeksta.setText("Duljina unesenog teksta je bila: " + uneseno.length());
		} );

//		gumb.addActionListener(new ActionListener() {
//			@Override
//			public void actionPerformed(ActionEvent e) {
//				System.out.println(e.getSource());
//			}
//		});
//		
		this.addWindowListener(new WindowListener() {
			
			@Override
			public void windowOpened(WindowEvent e) {
				System.out.println("otvoren");
			}
			
			@Override
			public void windowIconified(WindowEvent e) {
				// TODO Auto-generated method stub
				
			}
			
			@Override
			public void windowDeiconified(WindowEvent e) {
				// TODO Auto-generated method stub
				
			}
			
			@Override
			public void windowDeactivated(WindowEvent e) {
				System.out.println("deaktiviran");
			}
			
			@Override
			public void windowClosing(WindowEvent e) {
				System.out.println("bit ce zatvoren");
			}
			
			@Override
			public void windowClosed(WindowEvent e) {
				System.out.println("zatvoren");
			}
			
			@Override
			public void windowActivated(WindowEvent e) {
				System.out.println("aktiviran");
			}
		});
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(() -> {
			new Glavni().setVisible(true);
		});
	}
	
}
