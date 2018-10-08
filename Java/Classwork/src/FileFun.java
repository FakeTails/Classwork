import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class FileFun {

	public static void main(String[] args)
	{
		try
		{
			FileInputStream inFile = new FileInputStream("src/input.txt"); // read input from a file
			Scanner keyboard = new Scanner(inFile);	// using keyboard to get input from the next string.
			System.out.print(keyboard.next()); // print
			
			FileOutputStream outFile = new FileOutputStream("src/output.txt"); // saving files into a file.
			PrintWriter outPrinter = new PrintWriter(outFile); // a print writer to print into the file.
			
			outPrinter.println(keyboard.next()); // write something to file.
			outPrinter.flush(); 				 // saves into file
			
			inFile.close();	
			outFile.close();
		}
		catch (Exception e)
		{
			System.out.print(e.getClass() + " " + e.getMessage());
		}
		
	}
}