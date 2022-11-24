import java.util.*;

class pr5a
{
public void reverse(String s)
{
int len=s.length();
String rev="";

for(int i=len-1;i>=0;i--)
{
char c;
c=s.charAt(i);
rev+=c;
}
System.out.println("Before Reverse: "+s);
System.out.println("After Reverse: "+rev);
}

public void Replace(String s)
{
System.out.println("Before Replace: "+s);
System.out.println("After Replace: "+s.replace("Ni","Ab"));
}

public void Present(String s)
{
System.out.print("String Contains Uni & rma: ");
if(s.contains("rma") && s.contains("Uni"))
{
System.out.println("Yes");
}
else
{
System.out.println("No");
}
}


public void BufferPre(StringBuffer s1)
{
System.out.println("\n");
System.out.print("StringBuffer Contains Uni & rma: ");
if(s1.indexOf("Uni")!=-1 && s1.indexOf("rma")!=-1)
{
System.out.println("Yes");
}
else
{
System.out.println("No");
}
}
public void BufferRep(StringBuffer s1)
{
int n=s1.indexOf("N");
int n1=s1.indexOf("i");
System.out.println("After Replace: "+s1.replace(n,n1+1,"Ab"));
}
// As StringBuffer are Mutable the Reverse of StringBuffer will be the Replaced StringBuffer
public void BufferRev(StringBuffer s1)
{
System.out.println("Before Reverse: "+s1);
System.out.println("Reverse StringBuffer: "+s1.reverse());
}
public static void main(String args[])
{
String str = "Nirma University";

pr5a pr = new pr5a();
pr.reverse(str);
pr.Replace(str);
pr.Present(str);


StringBuffer str1 = new StringBuffer("Nirma University");
pr.BufferPre(str1);
pr.BufferRep(str1);
pr.BufferRev(str1);

}
}