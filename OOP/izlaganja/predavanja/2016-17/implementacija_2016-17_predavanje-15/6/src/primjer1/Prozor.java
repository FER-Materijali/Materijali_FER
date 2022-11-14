package primjer1;

import java.awt.BorderLayout;
import java.awt.Container;

import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.ListModel;
import javax.swing.SwingUtilities;
import javax.swing.WindowConstants;
import javax.swing.event.ListDataListener;

public class Prozor extends JFrame {

	public Prozor() {
		setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
		setSize(500, 500);
		initGUI();
	}

	private void initGUI() {
		Container cp = getContentPane();
		
		cp.setLayout(new BorderLayout());

		ModelPodataka model = new ModelPodataka();
		
		JList<Integer> pogled = new JList<>(model);
		cp.add(pogled, BorderLayout.CENTER);
	}

	private static class ModelPodataka implements ListModel<Integer> {

		@Override
		public int getSize() {
			return 3;
		}

		@Override
		public Integer getElementAt(int index) {
			switch(index) {
			case 0: return 15;
			case 1: return 17;
			case 2: return 28;
			}
			return null;
		}

		@Override
		public void addListDataListener(ListDataListener l) {
		}

		@Override
		public void removeListDataListener(ListDataListener l) {
		}
		
	}
	
	
	
	public static void main(String[] args) {
		SwingUtilities.invokeLater(()->{
			new Prozor().setVisible(true);
		});
	}
}
