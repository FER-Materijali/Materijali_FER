package hr.fer.oop.swing.example3;

import java.awt.BorderLayout;
import java.awt.Container;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.SwingUtilities;

public class EnterNameFrame extends JFrame {

	private static final long serialVersionUID = 1L;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		SwingUtilities.invokeLater(() -> {
			new EnterNameFrame().setVisible(true);
		});
	}

	/**
	 * Create the frame.
	 */
	public EnterNameFrame() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(10, 10, 500, 200); // postavljanje lokacije i veličine

		initGUI();
		
		pack(); // slaganje komponenti na najmanje prostora
	}

	private void initGUI() {
		
		Container cp = getContentPane();
		
		// Kod prozora, contentPane je primjerak JPanela; castam jer
		// on nudi metodu za postavljanje okvira koju općeniti Container ne
		// nudi; da bi mi bila vidljiva - moram castati:
		((JPanel)cp).setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));

		JLabel lblTitle = new JLabel("Naslov");
		lblTitle.setHorizontalAlignment(SwingConstants.CENTER);
		cp.add(lblTitle, BorderLayout.PAGE_START);

		JLabel lblName = new JLabel("Unesite ime i prezime:");
		cp.add(lblName, BorderLayout.LINE_START);

		JTextField tfInput = new JTextField();
		cp.add(tfInput, BorderLayout.CENTER);
		tfInput.setColumns(10);

		JPanel southPanel = new JPanel();
		cp.add(southPanel, BorderLayout.PAGE_END);

		JButton btnOK = new JButton("OK");
		southPanel.add(btnOK);
	}
}
