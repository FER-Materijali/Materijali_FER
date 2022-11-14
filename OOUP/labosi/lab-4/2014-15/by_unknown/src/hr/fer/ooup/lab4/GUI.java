package hr.fer.ooup.lab4;

import hr.fer.ooup.lab4.composite.CompositeShape;
import hr.fer.ooup.lab4.graphics.GraphicalObject;
import hr.fer.ooup.lab4.graphics.LineSegment;
import hr.fer.ooup.lab4.graphics.Oval;
import hr.fer.ooup.lab4.listener.DocumentModelListener;
import hr.fer.ooup.lab4.render.G2DRendererImpl;
import hr.fer.ooup.lab4.render.SVGRendererImpl;
import hr.fer.ooup.lab4.state.AddShapeState;
import hr.fer.ooup.lab4.state.EraserState;
import hr.fer.ooup.lab4.state.IdleState;
import hr.fer.ooup.lab4.state.SelectShapeState;
import hr.fer.ooup.lab4.state.State;

import java.awt.BorderLayout;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.ActionEvent;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Stack;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.JComponent;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JToolBar;
import javax.swing.SwingUtilities;

/**
 * 
 * @author hendrix
 *
 */
public class GUI extends JFrame {

	private static final long serialVersionUID = 1L;
	
	private DocumentModel model;
	private Canvas canvas;
	private State currentState;
	private Map<String, GraphicalObject> prototypes;
	
	public GUI(List<GraphicalObject> objects) {
		model = new DocumentModel();
		currentState = new IdleState();
		prototypes = new HashMap<String, GraphicalObject>();
		initGUI(objects);
	}
	
	private void initGUI(List<GraphicalObject> objects) {
		addComponents(objects);
		addToolbar(objects);
		addListeners();
		
		setSize(500, 500);
		setLocationRelativeTo(null);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
	}
	
	private void addComponents(List<GraphicalObject> objects) {
		//add canvas
		canvas = new Canvas();
		add(canvas, BorderLayout.CENTER);
		
		//add prototypes which are used to load objects from file
		for (GraphicalObject go : objects) {
			prototypes.put(go.getShapeID(), go);
		}
		GraphicalObject compositePrototype = new CompositeShape();
		prototypes.put(compositePrototype.getShapeID(), compositePrototype);
	}
	
	private void addListeners() {
		
		model.addDocumentModelListener(new DocumentModelListener() {
			@Override
			public void documentChanged() {
				canvas.repaint();
			}
		});
		
		canvas.addKeyListener(new KeyAdapter() {
			@Override
			public void keyPressed(KeyEvent e) {
				if(e.getKeyCode() == KeyEvent.VK_ESCAPE) {
					currentState.onLeaving();
					currentState = new IdleState();
				} else {
					currentState.keyPressed(e.getKeyCode());
				}
			}
		});
		
		canvas.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				currentState.mouseDown(e.getPoint(), e.isShiftDown(), e.isControlDown());
			}
			
			@Override
			public void mouseReleased(MouseEvent e) {
				currentState.mouseUp(e.getPoint(), e.isShiftDown(), e.isControlDown());
			}
		});
		
		canvas.addMouseMotionListener(new MouseAdapter() {
			@Override
			public void mouseDragged(MouseEvent e) {
				currentState.mouseDragged(e.getPoint());
			}
		});
	}
	
	private Action selectAction = new AbstractAction() {
		
		private static final long serialVersionUID = 1L;

		@Override
		public void actionPerformed(ActionEvent e) {
			currentState.onLeaving();
			currentState = new SelectShapeState(model);
		}
	};
	
	private Action eraserAction = new AbstractAction() {

		private static final long serialVersionUID = 1L;

		@Override
		public void actionPerformed(ActionEvent e) {
			currentState.onLeaving();
			currentState = new EraserState(model);
		}
	};
	
	private Action svgExportAction = new AbstractAction() {
	
		private static final long serialVersionUID = 1L;

		@Override
		public void actionPerformed(ActionEvent e) {
			JFileChooser fc = new JFileChooser();
			fc.setDialogTitle("SVG export");
			if(fc.showSaveDialog(GUI.this) != JFileChooser.APPROVE_OPTION) {
				return;
			}
			String path = fc.getSelectedFile().getPath();
			if(!path.endsWith(".svg")) {
				path += ".svg";
			}
			
			SVGRendererImpl svgRenderer = new SVGRendererImpl(path);
			List<GraphicalObject> objects = model.list();
			for (GraphicalObject go : objects) {
				go.render(svgRenderer);
			}
			
			try {
				svgRenderer.close();
				JOptionPane.showMessageDialog(GUI.this, "SVG file successfully generated.", "INFO", JOptionPane.INFORMATION_MESSAGE);
			} catch (IOException e1) {
				JOptionPane.showMessageDialog(GUI.this, "While exporting to file " + path + ": " + e1, "ERROR", JOptionPane.ERROR_MESSAGE);
				return;
			}
		}
	};
	
	private Action saveAction = new AbstractAction() {

		private static final long serialVersionUID = 1L;

		@Override
		public void actionPerformed(ActionEvent e) {
			JFileChooser fc = new JFileChooser();
			fc.setDialogTitle("Save");
			if(fc.showSaveDialog(GUI.this) != JFileChooser.APPROVE_OPTION) {
				return;
			}
			String path = fc.getSelectedFile().getPath();
			if(!path.endsWith(".ooup")) {
				path += ".ooup";
			}
			
			List<GraphicalObject> objects = model.list();
			List<String> rows = new ArrayList<String>();
			for (GraphicalObject go : objects) {
				go.save(rows);
			}
			
			try {
				FileWriter fw = new FileWriter(new File(path));
				for (String row : rows) {
					fw.write(row);
					fw.write("\n");
				}
				fw.flush();
				fw.close();
				JOptionPane.showMessageDialog(GUI.this, "File successfully generated.", "INFO", JOptionPane.INFORMATION_MESSAGE);
			} catch (IOException e1) {
				JOptionPane.showMessageDialog(GUI.this, "While writing to file " + path + ": " + e1, "ERROR", JOptionPane.ERROR_MESSAGE);
				return;
			}
		}
	};
	
	private Action loadAction = new AbstractAction() {

		private static final long serialVersionUID = 1L;

		@Override
		public void actionPerformed(ActionEvent e) {
			JFileChooser fc = new JFileChooser();
			fc.setDialogTitle("Load");
			if(fc.showOpenDialog(GUI.this) != JFileChooser.APPROVE_OPTION) {
				return;
			}
			File file = fc.getSelectedFile();
			
			
			try {
				List<String> lines = Files.readAllLines(file.toPath(), StandardCharsets.UTF_8);
				Stack<GraphicalObject> objects = new Stack<GraphicalObject>();
				GraphicalObject go = null;
				String shapeId = null;
				int index = -1;
				
				boolean error = false;
				String errorMessage = null;
				
				for (String line : lines) {
					if(line.startsWith("@")) {
						index = line.indexOf(' ');
						if(index != -1) {
							shapeId = line.substring(0, index);
							go = prototypes.get(shapeId);
							if(go != null) {
								go.duplicate().load(objects, line.substring(index + 1));
							} else {
								error = true;
								errorMessage = "Unknown shape: " + shapeId;
								break;
							}
						} else {
							error = true;
							errorMessage = "File malformated in line: " + line;
							break;
						}
					} else {
						error = true;
						errorMessage = "File malformated in line: " + line;
						break;
					}
				}
				
				if(!error) {
					for (GraphicalObject graphicalObject : objects) {
						model.addGraphicalObject(graphicalObject);
					}
				} else {
					JOptionPane.showMessageDialog(GUI.this, errorMessage, "ERROR", JOptionPane.ERROR_MESSAGE);
				}
			} catch (IOException e1) {
				JOptionPane.showMessageDialog(GUI.this, "While reading file " + file.getName() + ": " + e1, "ERROR", JOptionPane.ERROR_MESSAGE);
				return;
			}
		}
	};
	
	private void addToolbar(List<GraphicalObject> objects) {
		JToolBar toolbar = new JToolBar();
		
		loadAction.putValue(Action.NAME, "Učitaj");
		toolbar.add(loadAction);
		
		saveAction.putValue(Action.NAME, "Pohrani");
		toolbar.add(saveAction);
		
		svgExportAction.putValue(Action.NAME, "SVG export");
		toolbar.add(svgExportAction);
		
		for (GraphicalObject go : objects) {
			Action action = new CanvasAction(go);
			action.putValue(Action.NAME, go.getShapeName());
			toolbar.add(action);
		}
		
		selectAction.putValue(Action.NAME, "Selektiraj");
		toolbar.add(selectAction);
		
		eraserAction.putValue(Action.NAME, "Brisalo");
		toolbar.add(eraserAction);
		
		toolbar.setFloatable(false);
		add(toolbar, BorderLayout.NORTH);
	}
	
	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			@Override
			public void run() {
				List<GraphicalObject> objects = new ArrayList<GraphicalObject>();
				objects.add(new LineSegment());
				objects.add(new Oval());
				new GUI(objects).setVisible(true);
			}
		});
	}
	
	private class CanvasAction extends AbstractAction {

		private static final long serialVersionUID = 1L;
		
		private GraphicalObject go;
		
		public CanvasAction(GraphicalObject go) {
			this.go = go;
		}
		
		@Override
		public void actionPerformed(ActionEvent e) {
			currentState.onLeaving();
			currentState = new AddShapeState(model, go);
		}
	}
	
	private class Canvas extends JComponent {

		private static final long serialVersionUID = 1L;
		
		public Canvas() {
			setFocusable(true);
			requestFocusInWindow();
		}
		
		@Override
		protected void paintComponent(Graphics g) {
			super.paintComponent(g);
			G2DRendererImpl renderer = new G2DRendererImpl((Graphics2D)g);
			List<GraphicalObject> objects = model.list();
			for (GraphicalObject go : objects) {
				go.render(renderer);
				currentState.afterDraw(renderer, go);
			}
			currentState.afterDraw(renderer);
			requestFocusInWindow();
		}
	}
}
