import java.util.Scanner;
class p2b
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int n;
        System.out.print("Enter Value: ");
        n=sc.nextInt(); 
        for(int i=1;i<=n;i++)
        {
    
            if(i%3==0 && i%5==0)
            {
                System.out.println(i+"-BizzFizz");
            }
            else if(i%3==0)
            {
                System.out.println(i+"-Bizz");
            }
            else if(i%5==0)
            {
                System.out.println(i+"-Fizz");
            }
            else
            {
                System.out.println(i);
            }
        }
    }
}