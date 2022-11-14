package hr.fer.ooup.lab3.editor;

import hr.fer.ooup.lab3.editor.factory.plugin.Plugin;
import hr.fer.ooup.lab3.editor.iterator.Iterator;
import hr.fer.ooup.lab3.editor.observer.clipboard.ClipboardObserver;
import hr.fer.ooup.lab3.editor.observer.clipboard.ClipboardStack;
import hr.fer.ooup.lab3.editor.observer.cursor.CursorObserver;
import hr.fer.ooup.lab3.editor.observer.stack.StackObserver;
import hr.fer.ooup.lab3.editor.observer.text.TextObserver;
import hr.fer.ooup.lab3.editor.singleton.UndoManger;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.FontFormatException;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GraphicsEnvironment;
import java.awt.RenderingHints;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.font.LineMetrics;
import java.awt.geom.Rectangle2D;
import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.net.URLClassLoader;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.jar.JarEntry;
import java.util.jar.JarFile;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JToolBar;
import javax.swing.KeyStroke;
import javax.swing.SwingUtilities;
import javax.swing.Timer;

/**
 * 
 * @author hendrix
 *
 */
public class TextEditor extends JFrame {

	private static final long serialVersionUID = 1L;
	private static final int MARGIN = 5;
	private static final int LINE_INDENT = 20;
	private static final String PATH_TO_PLUGINS = "plugins/";

	private JPanel textEditorPanel;
	private JScrollPane scrollPane;
	private StatusLabel statusLabel;
	
	private TextEditorModel model;
	private ClipboardStack clipboard;
	private UndoManger undoManager;
	private Map<String, Plugin> extensions;
	
	private Path openedFilePath;
	
	private boolean drawCursor;
	
	public TextEditor() {
		clipboard = new ClipboardStack();
		undoManager = UndoManger.getInstance();
		extensions = new HashMap<String, Plugin>();
		drawCursor = true;
		initTextEditorModel("some random text");
		initGUI();
	}
	
	private void initGUI() {
		
		createActions();
		createMenuBar();
		createToolbar();
		addComponents();
		addListeners();
		
		pack();
		
		setSize(800, 700);
		setTitle("Simple Text Editor");
		setLocationRelativeTo(null);
		setFocusTraversalKeysEnabled(false);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
	}
	
	private void addComponents() {
		textEditorPanel = new TextEditorPanel();
		textEditorPanel.setBackground(new Color(39, 40, 34));
		textEditorPanel.setForeground(Color.WHITE);
		
		try {
			Font menlo = Font.createFont(Font.TRUETYPE_FONT, new File("font/Menlo.ttf")).deriveFont(14f);
			GraphicsEnvironment ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
			ge.registerFont(menlo);
			textEditorPanel.setFont(menlo);
		} catch (FontFormatException |IOException e1) {
			//do nothing, it doesn't matter
		}
		
		scrollPane = new JScrollPane();
		scrollPane.setViewportView(textEditorPanel);
		scrollPane.getActionMap().put("unitScrollRight", new AbstractAction(){

			private static final long serialVersionUID = 1L;

			@Override
			    public void actionPerformed(ActionEvent e) {}
		});
			
		scrollPane.getActionMap().put("unitScrollDown", new AbstractAction(){

			private static final long serialVersionUID = 1L;

			@Override
			    public void actionPerformed(ActionEvent e) {}}
		);
		
		scrollPane.getActionMap().put("unitScrollUp", new AbstractAction(){

			private static final long serialVersionUID = 1L;

			@Override
			    public void actionPerformed(ActionEvent e) {}}
		);
		
		scrollPane.getActionMap().put("unitScrollLeft", new AbstractAction(){

			private static final long serialVersionUID = 1L;

			@Override
			    public void actionPerformed(ActionEvent e) {}}
		);
		
		add(scrollPane, BorderLayout.CENTER);
		
		statusLabel = new StatusLabel();
		model.addCursorObserver(statusLabel);
		model.addTextObserver(statusLabel);
		add(statusLabel, BorderLayout.SOUTH);
	}
	
	private void addListeners() {
		Timer timer = new Timer(600, new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				textEditorPanel.revalidate();
				textEditorPanel.repaint();
			}
		});
		timer.start();
		
		textEditorPanel.addKeyListener(new KeyAdapter() {
			@Override
			public void keyPressed(KeyEvent e) {
				drawCursor = true;
				switch (e.getKeyCode()) {
				case KeyEvent.VK_LEFT:
					if(e.isShiftDown()) {
						model.addSelectionOnLeft();
					} else {
						model.moveCursorLeft();
						model.setSelectionRange(null);
					}
					break;

				case KeyEvent.VK_RIGHT:
					if(e.isShiftDown()) {
						model.addSelectionRight();
					} else {
						model.moveCursorRight();
						model.setSelectionRange(null);
					}
					break;
					
				case KeyEvent.VK_UP:
					if(e.isShiftDown()) {
						model.addSelectionUp();
					} else {
						model.moveCursorUp();
						model.setSelectionRange(null);
					}
					break;
					
				case KeyEvent.VK_DOWN:
					if(e.isShiftDown()) {
						model.addSelectionDown();
					} else {
						model.moveCursorDown();
						model.setSelectionRange(null);
					}
					break;
					
				case KeyEvent.VK_BACK_SPACE:
					if(model.hasSelection()) {
						model.deleteRange();
					} else {
						model.deleteBefore();
					}
					break;
					
				case KeyEvent.VK_DELETE:
					if(model.hasSelection()) {
						model.deleteRange();
					} else {
						model.deleteAfter();
					}
					break;
					
				default:
					if(!e.isActionKey() && !e.isMetaDown() && e.getKeyCode() != KeyEvent.VK_SHIFT && e.getKeyCode() != KeyEvent.VK_ALT 
							&& e.getKeyCode() != KeyEvent.VK_ALT_GRAPH && !e.isControlDown() && e.getKeyCode() != KeyEvent.VK_ESCAPE) {
						model.insert(e.getKeyChar());
					}
					break;
				}
			}
		});
	}
	
	private void initTextEditorModel(String text) {
		model = new TextEditorModel(text);
		
		//dodajemo observera
		model.addCursorObserver(new CursorObserver() {
			@Override
			public void updateCursorLocation(Location loc) {
				textEditorPanel.revalidate();
				textEditorPanel.repaint();
			}
		});
		
		model.addTextObserver(new TextObserver() {
			@Override
			public void updateText() {
				textEditorPanel.revalidate();
				textEditorPanel.repaint();
			}
		});
		
		if(statusLabel != null) {
			model.addCursorObserver(statusLabel);
			model.addTextObserver(statusLabel);
		}
	}
	
	private Action openAction = new AbstractAction() {

		private static final long serialVersionUID = 1L;

		@Override
		public void actionPerformed(ActionEvent e) {
			JFileChooser fc = new JFileChooser();
			fc.setDialogTitle("Open file");
			if(fc.showOpenDialog(TextEditor.this) != JFileChooser.APPROVE_OPTION) {
				return;
			}
			
			File file = fc.getSelectedFile();
			Path filePath = file.toPath();
			
			if(!Files.isReadable(filePath)) {
				JOptionPane.showMessageDialog(TextEditor.this, "Could not open file " + file.getName(), "ERROR", JOptionPane.ERROR_MESSAGE);
				return;
			}
			
			byte[] bytes = null;
			try {
				bytes = Files.readAllBytes(filePath);
			} catch (IOException e1) {
				JOptionPane.showMessageDialog(TextEditor.this, "While reading file " + file.getName() + ":" + e1.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
				return;
			}
			
			initTextEditorModel(new String(bytes, StandardCharsets.UTF_8));
			openedFilePath = filePath;
		}
	};
	
	private Action saveAction = new AbstractAction() {

		private static final long serialVersionUID = 1L;

		@Override
		public void actionPerformed(ActionEvent e) {
			if(openedFilePath == null) {
				JFileChooser fc = new JFileChooser();
				fc.setDialogTitle("Save file");
				if(fc.showSaveDialog(TextEditor.this) != JFileChooser.APPROVE_OPTION) {
					JOptionPane.showMessageDialog(TextEditor.this, "Changes are not saved!", "WARNING", JOptionPane.WARNING_MESSAGE);
					return;
				}
				openedFilePath = fc.getSelectedFile().toPath();
			}
			
			StringBuilder sb = new StringBuilder();
			Iterator<String> iterator = model.allLines();
			while(iterator.hasNext()) {
				sb.append(iterator.next()).append(System.lineSeparator());
			}
			
			byte[] text = sb.toString().getBytes(StandardCharsets.UTF_8);
			
			try {
				Files.write(openedFilePath, text);
			} catch (IOException e1) {
				JOptionPane.showMessageDialog(TextEditor.this, "While writing to file " + openedFilePath.toFile().getName() + ":" + e1.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
				return;
			}
			
			JOptionPane.showMessageDialog(TextEditor.this, "File saved", "Info", JOptionPane.INFORMATION_MESSAGE);
		}
	};
	
	private Action exitAction = new AbstractAction() {

		private static final long serialVersionUID = 1L;

		@Override
		public void actionPerformed(ActionEvent e) {
			System.exit(0);
		}
	};
	
	private UndoAction undoAction = new UndoAction();
	
	private RedoAction redoAction = new RedoAction();
	
	private Action cutAction = new AbstractAction() {

		private static final long serialVersionUID = 1L;

		@Override
		public void actionPerformed(ActionEvent e) {
			clipboard.putText(model.getSelectionText());
			model.deleteRange();
			textEditorPanel.revalidate();
			textEditorPanel.repaint();
		}
	};
	
	private Action copyAction = new AbstractAction() {

		private static final long serialVersionUID = 1L;

		@Override
		public void actionPerformed(ActionEvent e) {
			clipboard.putText(model.getSelectionText());
		}
	};
	
	private PasteAction pasteAction = new PasteAction();
	
	private PasteAndTakeAction pasteAndTakeAction = new PasteAndTakeAction();
	
	private Action deleteSelectionAction = new AbstractAction() {

		private static final long serialVersionUID = 1L;

		@Override
		public void actionPerformed(ActionEvent e) {
			model.deleteRange();
		}
	};
	
	private Action clearDocumentAction = new AbstractAction() {

		private static final long serialVersionUID = 1L;

		@Override
		public void actionPerformed(ActionEvent e) {
			model.reset();
			textEditorPanel.revalidate();
			textEditorPanel.repaint();
		}
	};
	
	private Action cursorToStart = new AbstractAction() {

		private static final long serialVersionUID = 1L;

		@Override
		public void actionPerformed(ActionEvent e) {
			model.moveCursorToDocumentStart();
		}
	};
	
	private Action cursorToEnd = new AbstractAction() {

		private static final long serialVersionUID = 1L;

		@Override
		public void actionPerformed(ActionEvent e) {
			model.moveCursorToDocumentEnd();
		}
	};
	
	private void createActions() {
		openAction.putValue(Action.NAME, "Open");
		openAction.putValue(Action.ACCELERATOR_KEY, KeyStroke.getKeyStroke("control O"));
		openAction.putValue(Action.MNEMONIC_KEY, KeyEvent.VK_O);
		
		saveAction.putValue(Action.NAME, "Save");
		saveAction.putValue(Action.ACCELERATOR_KEY, KeyStroke.getKeyStroke("control S"));
		saveAction.putValue(Action.MNEMONIC_KEY, KeyEvent.VK_S);
		
		exitAction.putValue(Action.NAME, "Exit");
		
		undoAction.putValue(Action.NAME, "Undo");
		undoAction.putValue(Action.ACCELERATOR_KEY, KeyStroke.getKeyStroke("control Z"));
		undoAction.putValue(Action.MNEMONIC_KEY, KeyEvent.VK_Z);
		undoAction.setEnabled(false);
		undoManager.addUndoStackObserver(undoAction);
		
		redoAction.putValue(Action.NAME, "Redo");
		redoAction.putValue(Action.ACCELERATOR_KEY, KeyStroke.getKeyStroke("control Y"));
		redoAction.putValue(Action.MNEMONIC_KEY, KeyEvent.VK_Y);
		redoAction.setEnabled(false);
		undoManager.addRedoStackObserver(redoAction);
		
		cutAction.putValue(Action.NAME, "Cut");
		cutAction.putValue(Action.ACCELERATOR_KEY, KeyStroke.getKeyStroke("control X"));
		cutAction.putValue(Action.MNEMONIC_KEY, KeyEvent.VK_X);
		cutAction.setEnabled(false);
		
		copyAction.putValue(Action.NAME, "Copy");
		copyAction.putValue(Action.ACCELERATOR_KEY, KeyStroke.getKeyStroke("control C"));
		copyAction.putValue(Action.MNEMONIC_KEY, KeyEvent.VK_C);
		copyAction.setEnabled(false);
		
		pasteAction.putValue(Action.NAME, "Paste");
		pasteAction.putValue(Action.ACCELERATOR_KEY, KeyStroke.getKeyStroke("control V"));
		pasteAction.putValue(Action.MNEMONIC_KEY, KeyEvent.VK_V);
		pasteAction.setEnabled(false);
		clipboard.addClipboardObserver(pasteAction);
		
		pasteAndTakeAction.putValue(Action.NAME, "Paste and Take");
		pasteAndTakeAction.putValue(Action.ACCELERATOR_KEY, KeyStroke.getKeyStroke("control shift V"));
		pasteAndTakeAction.putValue(Action.MNEMONIC_KEY, KeyEvent.VK_V);
		pasteAndTakeAction.setEnabled(false);
		clipboard.addClipboardObserver(pasteAndTakeAction);
		
		deleteSelectionAction.putValue(Action.NAME, "Delete selection");
		deleteSelectionAction.setEnabled(false);
		
		clearDocumentAction.putValue(Action.NAME, "Clear document");
		
		cursorToStart.putValue(Action.NAME, "Cursor to document start");
		
		cursorToEnd.putValue(Action.NAME, "Cursor to document end");
	}
	
	private void createMenuBar() {
		JMenuBar menuBar = new JMenuBar();
		
		//FILE ITEM
		JMenu file = new JMenu("File");
		file.add(new JMenuItem(openAction));
		file.add(new JMenuItem(saveAction));
		file.addSeparator();
		file.add(new JMenuItem(exitAction));
		
		menuBar.add(file);
		//
		
		//EDIT ITEM
		JMenu edit = new JMenu("Edit");
		edit.add(new JMenuItem(undoAction));
		edit.add(new JMenuItem(redoAction));
		edit.add(new JMenuItem(cutAction));
		edit.add(new JMenuItem(copyAction));
		edit.add(new JMenuItem(pasteAction));
		edit.add(new JMenuItem(pasteAndTakeAction));
		edit.add(new JMenuItem(deleteSelectionAction));
		edit.add(new JMenuItem(clearDocumentAction));
		
		menuBar.add(edit);
		//
		
		//MOVE ITEM
		JMenu move = new JMenu("Move");
		move.add(new JMenuItem(cursorToStart));
		move.add(new JMenuItem(cursorToEnd));
		
		menuBar.add(move);
		//
		
		//PLUGINS
		List<Plugin> plugins = loadPlugins();
		if(!plugins.isEmpty()) {
			JMenu extensionsMenu = new JMenu("Extensions");
			for (Plugin plugin : plugins) {
				extensions.put(plugin.getName(), plugin);
				
				Action action = new AbstractAction() {

					private static final long serialVersionUID = 1L;

					@Override
					public void actionPerformed(ActionEvent e) {
						extensions.get(e.getActionCommand()).execute(model, undoManager, clipboard);
					}
				};
				
				action.putValue(Action.NAME, plugin.getName());
				action.putValue(Action.SHORT_DESCRIPTION, plugin.getDescription());
				
				extensionsMenu.add(new JMenuItem(action));
			}
			menuBar.add(extensionsMenu);
		}
		//
		
		setJMenuBar(menuBar);
	}
	
	@SuppressWarnings("unchecked")
	private List<Plugin> loadPlugins() {
		ClassLoader pluginsLoader = Plugin.class.getClassLoader();
		File pluginsDirectory = new File(PATH_TO_PLUGINS);
		if(!pluginsDirectory.isDirectory()) {
			return new ArrayList<Plugin>();
		}
		
		File[] jars = pluginsDirectory.listFiles();
		List<Plugin> plugins = new ArrayList<Plugin>();
		
		for (File file : jars) {
			if(file.getName().endsWith(".jar") && Files.isReadable(file.toPath())) {
				try {
					URLClassLoader urlClassLoader = new URLClassLoader(new URL[]{file.toURI().toURL()}, pluginsLoader);
					JarFile jarFile = new JarFile(file);
					Enumeration<JarEntry> enumeration = jarFile.entries();
					
					JarEntry entry = null;
					while(enumeration.hasMoreElements()) {
						entry = (JarEntry)enumeration.nextElement();
						if(entry.isDirectory() || !entry.getName().endsWith(".class")) {
							continue;
						}
						
						String className = entry.getName().substring(0, entry.getName().length() - 6);//-6 to remove ".class"
						className = className.replace('/', '.');
						plugins.add(((Class<Plugin>)urlClassLoader.loadClass(className)).newInstance());
					}
					
					urlClassLoader.close();
					jarFile.close();
				} catch (IOException | ClassNotFoundException e) {
					JOptionPane.showMessageDialog(TextEditor.this, e + " while loading plugins :" + e.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
					continue;
				} catch (InstantiationException | IllegalAccessException e) {
					continue;
				}
			}
		}
		
		return plugins;
	}
	
	private void createToolbar() {
		JToolBar toolBar = new JToolBar();
		toolBar.add(new JButton(undoAction));
		toolBar.add(new JButton(redoAction));
		toolBar.add(new JButton(cutAction));
		toolBar.add(new JButton(copyAction));
		toolBar.add(new JButton(pasteAction));
		toolBar.setFloatable(true);
		add(toolBar, BorderLayout.NORTH);
	}
	
	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			@Override
			public void run() {
				new TextEditor().setVisible(true);
			}
		});
	}
	
	class UndoAction extends AbstractAction implements StackObserver {

		private static final long serialVersionUID = 1L;

		@Override
		public void actionPerformed(ActionEvent e) {
			undoManager.undo();
			textEditorPanel.revalidate();
			textEditorPanel.repaint();
		}

		@Override
		public void stackEmpty() {
			undoAction.setEnabled(false);
		}

		@Override
		public void stackHasElements() {
			undoAction.setEnabled(true);
		}
		
	}
	
	class RedoAction extends AbstractAction implements StackObserver {

		private static final long serialVersionUID = 1L;

		@Override
		public void actionPerformed(ActionEvent e) {
			undoManager.redo();
			textEditorPanel.revalidate();
			textEditorPanel.repaint();
		}

		@Override
		public void stackEmpty() {
			redoAction.setEnabled(false);
		}

		@Override
		public void stackHasElements() {
			redoAction.setEnabled(true);
		}
		
	}
	
	class PasteAction extends AbstractAction implements ClipboardObserver {

		private static final long serialVersionUID = 1L;

		@Override
		public void actionPerformed(ActionEvent e) {
			model.insert(clipboard.getText());
			textEditorPanel.revalidate();
			textEditorPanel.repaint();
		}

		@Override
		public void updateClipboard() {
			if(clipboard.hasText()) {
				pasteAction.setEnabled(true);
			} else {
				pasteAction.setEnabled(false);
			}
		}
	}
	
	class PasteAndTakeAction extends AbstractAction implements ClipboardObserver {

		private static final long serialVersionUID = 1L;

		@Override
		public void actionPerformed(ActionEvent e) {
			model.insert(clipboard.removeText());
			textEditorPanel.revalidate();
			textEditorPanel.repaint();
		}

		@Override
		public void updateClipboard() {
			if(clipboard.hasText()) {
				pasteAndTakeAction.setEnabled(true);
			} else {
				pasteAndTakeAction.setEnabled(false);
			}
		}	
	}
	
	class TextEditorPanel extends JPanel {
	
		private static final long serialVersionUID = 1L;
		private int height = 300;
		private int width = 300;
		
		public TextEditorPanel() {
			this.setFocusable(true);
			this.requestFocusInWindow();
		}
		
		@Override
		protected void paintComponent(Graphics g) {
			this.requestFocusInWindow();
			super.paintComponent(g);
			Graphics2D g2d = (Graphics2D)g;
			FontMetrics fm = g2d.getFontMetrics();
			
			RenderingHints rh = new RenderingHints(
						RenderingHints.KEY_TEXT_ANTIALIASING,
						RenderingHints.VALUE_TEXT_ANTIALIAS_GASP);
			g2d.addRenderingHints(rh);
			
			if(model.hasSelection()) {
				cutAction.setEnabled(true);
				copyAction.setEnabled(true);
				deleteSelectionAction.setEnabled(true);
				
				LocationRange selection = model.getSelectionRange();
				int numOfLines = selection.getNumOfLinesInRange();
				
				Location start = selection.getStart();
				Location end = selection.getEnd();
				
				g2d.setColor(Color.BLUE);
				Rectangle2D rect = null;
				String line = null;
				
				if(numOfLines == 0) {
					line = model.getLine(start.getX());
					rect = fm.getStringBounds(line.substring(start.getY(), end.getY()), g2d);
					g2d.fillRect(MARGIN + fm.stringWidth(line.substring(0, start.getY())), 3 + start.getX() * LINE_INDENT, (int)rect.getWidth(), fm.getHeight());
				} else {
					line = model.getLine(start.getX());
					rect = fm.getStringBounds(line.substring(start.getY()), g2d);
					g2d.fillRect(MARGIN + fm.stringWidth(line.substring(0, start.getY())), 3 + start.getX() * LINE_INDENT, (int)rect.getWidth(), fm.getHeight());
					for (int i = start.getX() + 1; i < end.getX(); i++) {
						line = model.getLine(i);
						rect = fm.getStringBounds(line, g2d);
						g2d.fillRect(MARGIN, 3 + i * LINE_INDENT, (int)rect.getWidth(), fm.getHeight());
					}
					
					line = model.getLine(end.getX());
					rect = fm.getStringBounds(line.substring(0, end.getY()), g2d);
					g2d.fillRect(MARGIN, 3 + end.getX() * LINE_INDENT, (int)rect.getWidth(), fm.getHeight());
				}
				
				g2d.setColor(Color.WHITE);
			} else {
				cutAction.setEnabled(false);
				copyAction.setEnabled(false);
				deleteSelectionAction.setEnabled(false);
			}
			
			Iterator<String> iterator = model.allLines();
			String line = null;
			width = 0;
			int lineWidth = 0;
			int i;
			for (i = 0; iterator.hasNext(); i++) {
				line = iterator.next();
				lineWidth = (int)fm.getStringBounds(line, g2d).getWidth();
				if(lineWidth > width) {
					width = lineWidth;
				}
				
				g2d.drawString(line, MARGIN, i*LINE_INDENT + fm.getHeight());
			}
			
			height = i * LINE_INDENT + fm.getHeight();
			width += 3 * MARGIN;
			
			if(drawCursor) {
				Location cursorLocation = model.getCursorLocation();
				
				if(!model.getLines().isEmpty()) {
					line = model.getLine(cursorLocation.getX()).substring(0, cursorLocation.getY());
				} else {
					line = "";
				}
				
				LineMetrics lm = g2d.getFont().getLineMetrics(line, g2d.getFontRenderContext());
				
				int x1 = cursorLocation.getX() * LINE_INDENT + fm.getHeight();
				int y1 = fm.stringWidth(line) + MARGIN;
				
				int x2 = x1 - (int)lm.getHeight();
				int y2 = y1;
				
				g2d.drawLine(y1, x1, y2, x2);
				drawCursor = false;
			} else {
				drawCursor = true;
			}
		}
		
		@Override
		public Dimension getPreferredSize() {
			return new Dimension(width, height);
		}
	}
	
	class StatusLabel extends JLabel implements CursorObserver, TextObserver  {

		private static final long serialVersionUID = 1L;
		
		private Location cursorLocation;
		private int numOfLines;
		
		public StatusLabel() {
			this.cursorLocation = model.getCursorLocation();
			this.numOfLines = model.getLines().size();
			this.setText("Line " + (cursorLocation.getX() + 1) + ", Column "  + (cursorLocation.getY() + 1) + ", Number of lines " + numOfLines);
		}

		@Override
		public void updateText() {
			cursorLocation = model.getCursorLocation();
			numOfLines = model.getLines().size();
			this.setText("Line " + (cursorLocation.getX() + 1) + ", Column "  + (cursorLocation.getY() + 1) + ", Number of lines " + numOfLines);
		}

		@Override
		public void updateCursorLocation(Location loc) {
			cursorLocation = loc;
			numOfLines = model.getLines().size();
			this.setText("Line " + (cursorLocation.getX() + 1) + ", Column "  + (cursorLocation.getY() + 1) + ", Number of lines " + numOfLines);
		}
	}
}
