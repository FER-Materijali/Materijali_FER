package primjer6;

import java.awt.BorderLayout;
import java.awt.Container;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import javax.swing.AbstractListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.JSplitPane;
import javax.swing.ListModel;
import javax.swing.SwingUtilities;
import javax.swing.WindowConstants;
import javax.swing.event.ListDataEvent;
import javax.swing.event.ListDataListener;

public class Prozor extends JFrame {

	private Random rnd = new Random();
	
	public Prozor() {
		setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
		setSize(500, 500);
		initGUI();
	}

	private void initGUI() {
		Container cp = getContentPane();
		
		cp.setLayout(new BorderLayout());

		ModelPodataka model = new ModelPodataka();
		
		JList<Integer> pogled1 = new JList<>(model);
		JList<Integer> pogled2 = new JList<>(model);
		pogled2.setSelectionModel(pogled1.getSelectionModel());
		
		JSplitPane jsp = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, new JScrollPane(pogled1), new JScrollPane(pogled2));
		
		cp.add(jsp, BorderLayout.CENTER);
		
		JButton gumb = new JButton("Dodaj random broj!");
		cp.add(gumb, BorderLayout.PAGE_END);
		
		gumb.addActionListener(e->{
			model.dodajNaKraj(rnd.nextInt());
		});
		
		final BrojElemenata<Integer> be = new BrojElemenata<>(model);
		cp.add(be, BorderLayout.PAGE_START);
				
	}

	private static class BrojElemenata<E> extends JLabel {
		private ListModel<E> model;
		private ListDataListener listener = new ListDataListener() {
			
			@Override
			public void intervalRemoved(ListDataEvent e) {
				azuriraj();
			}
			
			@Override
			public void intervalAdded(ListDataEvent e) {
				azuriraj();
			}
			
			@Override
			public void contentsChanged(ListDataEvent e) {
				azuriraj();
			}
		};
		
		public BrojElemenata(ListModel<E> model) {
			super();
			this.model = model;
			this.model.addListDataListener(listener);
			azuriraj();
		}

		private void azuriraj() {
			setText("Broj elemenata je: " + model.getSize());
		}
		
		
	}
	
	private static class ModelPodataka extends AbstractListModel<Integer> {

		private List<Integer> podatci = new ArrayList<>();
		
		public ModelPodataka() {
			podatci.add(15);
			podatci.add(17);
			podatci.add(28);
		}
		
		public void dodajNaKraj(Integer element) {
			podatci.add(element);
			int pozicija = podatci.size()-1;
			this.fireIntervalAdded(this, pozicija, pozicija);
		}

		@Override
		public int getSize() {
			return podatci.size();
		}

		@Override
		public Integer getElementAt(int index) {
			return podatci.get(index);
		}
	}
	
	
	
	public static void main(String[] args) {
		SwingUtilities.invokeLater(()->{
			new Prozor().setVisible(true);
		});
	}
}
