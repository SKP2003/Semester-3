import java.util.*;
 class Employee
{
	int salary, hours;
	Employee()
	{
		getInfo();
		AddSal();
		AddWork();
		Display();
	}
	Employee(int s, int h)
	{
		salary = s;
		hours = h;
		AddSal();
		AddWork();
		Display();
	}
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
		System.out.println("Final Salary: $" + salary);
	}
	public static void main(String[] args)
	{
		Employee e1 = new Employee();
		Employee e2 = new Employee(900,9);
	}
}