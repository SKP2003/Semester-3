import java.util.*;

class pr52
{
	public static void main(String a[])
	{
		Scanner sc = new Scanner(System.in);

		String s = sc.nextLine();
		int n=s.length();
		int sen=0;
		int word=1;
		int freq[] = new int[n];

		for(int i=0;i<n;i++)
		{
			if(s.charAt(i)=='.' || s.charAt(i)=='?')
				sen++;
			if(s.charAt(i)==' ')
				word++;
            if(s.charAt(i)!=' ' && s.charAt(i)!='.')
                ch++;
		}
		System.out.println("No of sentence:- "+sen);
		System.out.println("No of Words:- "+word);
		System.out.println("No of Characters:- "+(n-(sen+word)));

		char str[] = s.toCharArray();

		for(int i=0;i<n;i++)
		{
			freq[i]=1;

			for(int j=i+1;j<n;j++)
			{
				if(str[i]==str[j])
				{
					freq[i]++;

					str[j]='0';
				}
			}
		}

		for(int i=0;i<n;i++)
		{
			if(str[i]!=' ' && str[i]!='0')
			{
				System.out.println(str[i]+" Occuress "+freq[i]+" Times");
			}
		}
		System.out.println("Enter word to search");
		String find = sc.nextLine();

		int loc = s.indexOf(find);
		if(loc!=-1)
		{
			System.out.println(find+"Found at location:- "+loc);
		}
		else
		{
			System.out.println("Inappropriate Word: "+find);
		}

		//System.out.println(n);
	}
}