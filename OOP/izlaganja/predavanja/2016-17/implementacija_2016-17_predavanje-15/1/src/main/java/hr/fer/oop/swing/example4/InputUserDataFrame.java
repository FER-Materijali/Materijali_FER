package hr.fer.oop.swing.example4;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;

public class InputUserDataFrame extends JFrame {

	private static final long serialVersionUID = 1L;
	
	private InputUserDataPanel userDataPanel;

	public static void main(String[] args) {
		SwingUtilities.invokeLater(() -> {
			new InputUserDataFrame().setVisible(true);
		});
	}

	public InputUserDataFrame() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 500, 400);

		initGUI();
	}

	private void initGUI() {
		Container cp = getContentPane();
		
		cp.setLayout(new BorderLayout());

		userDataPanel = new InputUserDataPanel();
		cp.add(userDataPanel, BorderLayout.CENTER);

		// buttons
		JPanel buttonsPanel = new JPanel();
		cp.add(buttonsPanel, BorderLayout.SOUTH);

		JPanel buttonsGridPanel = new JPanel();
		buttonsGridPanel.setLayout(new GridLayout(1, 2, 10, 0));
		buttonsPanel.add(buttonsGridPanel);

		JButton btnOK = new JButton("U redu");
		buttonsGridPanel.add(btnOK);

		JButton btnCancel = new JButton("Odustani");
		buttonsGridPanel.add(btnCancel);

		// actions
		btnOK.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				UserData data = userDataPanel.getUserData();

				System.out.println(data);
			}
		});

		btnCancel.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
				// ako želimo ugasiti samo prozor, a ne čitavu aplikaciju
				// dispose();
			}
		});
	}

}
