public class FormattedOutput {

	public static void main(String[] args)
	{
		double pi = 3.14159265359;
		double G = 6.67408e-11;
		String foo = "Hello World!!";
		
		System.out.printf("My data is %1s -- %s", pi, foo);
	}
}