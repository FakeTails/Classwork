import java.io.PrintWriter;
import java.io.StringWriter;

public class StringBuffer {
	
	public static void main(String[] args)
	{
		StringWriter chars = new StringWriter(); // have to have this to use printwriter.
		//System.out.print("foo");
		
		PrintWriter myBuffer = new PrintWriter(chars);
		
		myBuffer.println("foo");			// puts into buffer
		System.out.print(chars);	// outputs what was in buffers
	}
}