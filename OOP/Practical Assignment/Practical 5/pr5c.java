import java.util.*;

class pr5c
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		String str;
		int words=1,sen=0;
		System.out.println("Enter a String of Maximum 80 Characters");
		str = scan.nextLine();
		int n = str.length();
		if(n>=81)
		{
			System.out.println("String Length is Greater than 80");
			System.exit(0);
		}
		str = str.replaceAll("\\s+"," ");
		System.out.println(str);
		
		String strarr[] = str.split(" ");
		int strl[] = new int[(strarr.length)];
		
		
	}
}