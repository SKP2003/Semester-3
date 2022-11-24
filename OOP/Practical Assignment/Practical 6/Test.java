import java.util.*;
class Student
{
    String name;
    String Roll_no;
    int mark1,mark2,mark3;
    public int total()
    {
        return mark1+mark2+mark3;
    }
}

class Percentage extends Student
{
    float percentage;
    
    public void Getter()
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Name: ");
        name = scan.nextLine();
        System.out.println("Enter Roll_no: ");
        Roll_no = scan.nextLine();
        System.out.print("Enter DSA Marks: ");
        mark1 = scan.nextInt();
        System.out.print("Enter OOP Marks: ");
        mark2 =  scan.nextInt();
        System.out.println("Enter DC Matks: ");
        mark3 = scan.nextInt();
        percent();
    }

    public float percent()
    {
        int total = total();
        percentage = total*100/300;
        return percentage; 
    }
}

class Grade extends Percentage
{
    public void PrintGrade()
    {
        Getter();
        if(percentage>=90)
        {
            System.out.println("Grade: A+");
        }
        else if(percentage>=80  && percentage<90)
        {
            System.out.println("Grade: A");
        }
        else if(percentage>=70 && percentage<80)
        {
            System.out.println("Grade: B+");
        }
        else if(percentage>=60 && percentage<70)
        {
            System.out.println("Grade: B");
        }
        else if(percentage>=50 && percentage<60)
        {
            System.out.println("Grade: C+");
        }
        else if(percentage>=40 && percentage<50)
        {
            System.out.println("Grade: C");
        }
        else
        {
            System.out.println("IF");
        }
    }
}

class Test 
{
    public static void main(String[] args) 
    {
        Grade g1 = new Grade();
        g1.PrintGrade();     
    }
}