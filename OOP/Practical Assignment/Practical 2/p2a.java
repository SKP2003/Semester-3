public class p2a
{
    public static void main(String args[]) {
        int n=59;
        int f1=n/10;
        int l=n%10;
        int sum=f1+l;
        int mul=f1*l;
        int ans=sum+mul;
        System.out.println(ans);
        if(ans==n)
        {
            System.out.println("It is a special number");
        }
        else
        {
            System.out.println("It is not a special number");
        }
    }
}
