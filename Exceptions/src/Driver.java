import java.util.Scanner;

public class Driver 
{
	
	public static void main(String[] args)
	{
		Driver d = new Driver();
		
		int userInput;
		
		Scanner keyboard = new Scanner(System.in);
		
		while (true)
		{
			try
			{
				userInput = d.getIntFromUser(keyboard);	
			}
			catch (NonPositiveIntegerException e)
			{
				System.out.println("Non negative input.");
			}
			catch (Exception e)
			{
				System.out.println(e.getMessage());
				 break;
			}
			finally // delimiter that goes whether or not something breaks;
			{
				System.out.println("-----");
			}
		}
	}
	
	public int getIntFromUser(Scanner keyboard) throws NonPositiveIntegerException
	{
		System.out.print("Enter a non-negative integer: ");
		int input = keyboard.nextInt();
		this.checkNonNegative(input);
		return 0;
	}
	
	private void checkNonNegative(int input) throws NonPositiveIntegerException
	{
		if (input < 0)
		{
			throw new NonPositiveIntegerException(""+input);
		}
	}
}
