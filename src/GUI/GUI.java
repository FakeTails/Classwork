package GUI;

import java.awt.Color;
import java.awt.Cursor;

import javax.swing.*;

public class GUI 
{
	public static void main(String[] args)
	{
		JFrame window = new JFrame("Venn Diagram"); 

		// create text at top
		JTextField subtitle = new JTextField("Steven bittner is a Venn Diagram.");
		subtitle.setEnabled(false); // not required for this.
		subtitle.setHorizontalAlignment(JTextField.CENTER);
		window.add(subtitle); // always have to add a feature.
		
		// create button at the bottom
		
		// create drawing
		
		
		
		window.setSize(300, 300); // always set these features 
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
		window.setVisible(true);
	}
}
