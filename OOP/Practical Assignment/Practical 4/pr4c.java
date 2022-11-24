import java.util.*;
 class Complex
{
	private float real;
	private float img;
	Complex()
	{
		real = 1;
		img = 1;
	}
	Complex(int r,int i)
	{
		real = r;
		img = i;
	}
	public Complex Addition(Complex c1, Complex c2)
	{
		Complex c = new Complex();
		c.real = c1.real+c2.real;
		c.img = c1.img + c2.img;
		return c;
	}
	public Complex Subtraction(Complex c1,Complex c2)
	{
		Complex c = new Complex();
		c.real = c1.real-c2.real;
		c.img = c1.img-c2.img;
		return c;
	}
	public void Display()
	{
		if(img>0)
		{
			System.out.println("Result: "+real+" + "+img+"i");
		}
		else	
		{
			System.out.println("Result: "+real+" "+img+"i");
		}
	}
}
 class pr4c
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		int n1,n2,n3,n4;
		System.out.print("Enter 4 Values: ");
		n1 = scan.nextInt();
		n2 = scan.nextInt();
		n3 = scan.nextInt();
		n4 = scan.nextInt();
		Complex c1 = new Complex(n1,n2);
		Complex c2 = new Complex(n3,n4);
		Complex c3 = c1.Addition(c1,c2);
		c3.Display();
		Complex c4 = c1.Subtraction(c1,c2);
		c4.Display();
	}
}