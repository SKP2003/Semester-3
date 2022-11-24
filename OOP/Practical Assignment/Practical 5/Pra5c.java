import java.util.*;

public class Pra5c
{
        public static void main(String ar[])
    {
       
        Scanner sc=new Scanner(System.in);

        System.out.print("Enter a String: ");
        String str = sc.nextLine();
        str=str.trim();
        str=str.replaceAll("\\s+"," ");
        int l=str.length();
       
        if(str.charAt(l-1)=='.'&&l<=80)
        {
            str=str.substring(0,l-1)+" ";
            int i,j,c=0,temp;
            String temp1;
            String a[]=str.split(" ");
            int b[]=new int[a.length];
            for(i=0;i<a.length;i++)
            {
                b[i]=a[i].length();
                a[i]=Character.toUpperCase(a[i].charAt(0))+a[i].substring(1);
            }
           
            for(i=0;i<b.length;i++)
            {
                for(j=0;j<b.length-1;j++)
                {
                    if(b[j]<b[j+1])
                    {
                        temp=b[j];
                        b[j]=b[j+1];
                        b[j+1]=temp;
                        temp1=a[j];
                        a[j]=a[j+1];
                        a[j+1]=temp1;
                    }  
                }
            }
           
            for(i=0;i<a.length-1;i++)
            {
                if(a[i].length()==a[i+1].length())
                {
                    if(a[i].compareTo(a[i+1])>0)
                    {
                        temp1=a[i];
                        a[i]=a[i+1];
                        a[i+1]=temp1;
                    }
                }
            }
            String st="";  
           
            for(i=0;i<a.length;i++)
            {
                st=st+a[i]+" ";
            }
        st=st.substring(0,l-1)+'.';
       
        System.out.println(st);
        }
    }
}
