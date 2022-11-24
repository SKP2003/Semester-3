import java.util.*;
 class Employee
{
	int salary, hours;
	void getInfo()
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter Salary: $");
		salary = sc.nextInt();
		System.out.print("Enter number of hours of work per day: ");
		hours = sc.nextInt();
	}
	void AddSal()
	{
		if(salary<500)
		salary+=10;
	}
	void AddWork()
	{
		if(hours>6)
			salary+=5;
	}
	void Display()
	{
		System.out.print("Final Salary: $" + salary);
	}
}
 public class Pr4a
{
	public static void main(String[] args) 
	{
		Employee e = new Employee();
		e.getInfo();
		e.AddSal();
		e.AddWork();
		e.Display();
	}
}