
public class Sorter {
	public static void sort(Comparable[] array)
	{
		for (int i = 0; i < array.length; i++)
		{
			for (int j = i + 1; j < array.length; j++)
			{
				if (array[j].compareTo(array[i]) == 0)
				{
					swap(array, i, j);
				}
			}
		}
		
		for (int i = 0; i < array.length; i++)
		{
			if (i != array.length - 1)
			{
				System.out.print(array[i] + ", ");
			}
			else
			{
				System.out.println(array[i] + ".");
			}
			
		}
	}
	
	public static void swap(Comparable[] array, int i, int j)
	{
		Comparable temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}
