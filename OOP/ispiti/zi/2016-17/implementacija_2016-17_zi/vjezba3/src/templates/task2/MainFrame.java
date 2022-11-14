package templates.task2;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.ActionListener;

import javax.swing.ButtonGroup;
import javax.swing.ButtonModel;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JToggleButton;
import javax.swing.SwingConstants;
import javax.swing.SwingUtilities;
import javax.swing.WindowConstants;

public class MainFrame extends JFrame {

	private static final long serialVersionUID = 1L;

	public MainFrame() {
		setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
		
		initGUI();
		
		pack();
	}

	private void initGUI() {
		Container cp = getContentPane();
		cp.setLayout(new BorderLayout());
		
		JPanel[] topDown = new JPanel[] {
			new JPanel(new GridLayout(1, 0)),
			new JPanel(new GridLayout(1, 0))
		};
		
		JPanel[] leftRight = new JPanel[] {
			new JPanel(new GridLayout(0, 1)),
			new JPanel(new GridLayout(0, 1))
		};
		
		// U zadatku pise da se koristi JTextField - moze i to;
		// ja sam ovdje odabrao JLabel...
		JLabel rezultat = new JLabel("");
		rezultat.setHorizontalAlignment(SwingConstants.CENTER);
		rezultat.setFont(rezultat.getFont().deriveFont(64f));
		
		cp.add(topDown[0], BorderLayout.PAGE_START);
		cp.add(topDown[1], BorderLayout.PAGE_END);
		cp.add(leftRight[0], BorderLayout.LINE_START);
		cp.add(leftRight[1], BorderLayout.LINE_END);
		cp.add(rezultat, BorderLayout.CENTER);
		
		ButtonGroup horizBg = new ButtonGroup();
		ButtonGroup vertBg = new ButtonGroup();
		
		ActionListener al = e -> {
			ButtonModel m1 = horizBg.getSelection();
			ButtonModel m2 = vertBg.getSelection();
			if(m1!=null && m2!=null) {
				int rez = Integer.parseInt(m1.getActionCommand())*Integer.parseInt(m2.getActionCommand());
				rezultat.setText(String.valueOf(rez));
			}
		};
		
		createButtons(horizBg, topDown, al);
		createButtons(vertBg, leftRight, al);
	}

	private void createButtons(ButtonGroup bg, JPanel[] panels, ActionListener al) {
		for(int i = 1; i <= 10; i++) {
			String text = String.valueOf(i);
			JToggleButton b1 = new JToggleButton(text);
			b1.getModel().setActionCommand(text);
			b1.getModel().addActionListener(al);
			
			JToggleButton b2 = new JToggleButton(text);
			b2.setModel(b1.getModel());

			bg.add(b1);

			panels[0].add(b1);
			panels[1].add(b2);
		}
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(()->{
			new MainFrame().setVisible(true);
		});
	}
}
