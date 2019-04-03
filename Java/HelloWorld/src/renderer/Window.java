package renderer;

import javax.swing.*;
import java.awt.Graphics;

public class Window {
	JFrame mainFrame;
	
	public Window(int width, int height) {
		mainFrame = new JFrame();
		mainFrame.setSize(width, height);
		mainFrame.setLayout(null);
	}
	
	public void run() {
		mainFrame.setVisible(true);
	}
}
