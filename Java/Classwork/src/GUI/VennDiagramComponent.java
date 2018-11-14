package GUI;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Ellipse2D;

import javax.swing.JComponent;

public class VennDiagramComponent extends JComponent 
{
	public void paintComponent(Graphics g)
	{
		Graphics2D g2 = (Graphics2D)g;
		g2.setColor(new Color(0, 100, 200, 200)); // can create color instantly
		Ellipse2D disk1 = new Ellipse2D.Double(10, 20, 150, 150);
		g2.fill(disk1);
		
		g2.setColor(new Color(155, 225, 100, 200));
		Ellipse2D disk2 = new Ellipse2D.Double(100, 20, 150, 150);
		g2.fill(disk2);
	}
	
	@Override
	public Dimension getPreferredSize()
	{
		int width = 260;
		int height = 10 + 10 + 200;
		return new Dimension(width, height);
	}
}
