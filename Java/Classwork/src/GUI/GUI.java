package GUI;

import java.awt.*;
import javax.swing.*;

public class GUI 
{
	public static void main(String[] args)
	{
		JFrame window = new JFrame("Venn Diagram"); 

		// create text at top
		JTextField subtitle = new JTextField("Steven bittner is a Venn Diagram.");
		subtitle.setEnabled(false); // not required for this.
		subtitle.setHorizontalAlignment(JTextField.CENTER); // alignment for the text.
		window.add(subtitle, BorderLayout.NORTH); // always have to add a feature. overloaded.
		
		// create button at the bottom
		JButton button = new JButton("Close"); // button that has been overloaded with a name.
		window.add(button, BorderLayout.SOUTH); //overloaded add.
		
		// create drawing
		VennDiagramComponent venn = new VennDiagramComponent();
		window.add(venn, BorderLayout.CENTER); //overloaded add.
		
		//window.setSize(300, 300); // always set these features.
		window.pack();
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
		window.setVisible(true);
	}
}
