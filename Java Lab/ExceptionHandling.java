import java.util.Scanner;

class OddException extends Exception 
{
    // int num;
    // OddException(int n)
    // {
    //     num=n;
    // }
    // public String toString()
    // {
        //     return "Odd number: "+num;
        // }
    OddException(String s)
    {
        super(s);
    }
}
    
public class ExceptionHandling 
{
    public static boolean check(int num)
    {
        if(num%2==0)
            return true;
        else
            return false;
    }
        
    public static void main(String [] args) 
    {
        System.out.println("Enter the Number");
        Scanner obj=new Scanner(System.in);
        int a=obj.nextInt();
        try
        {
            if(check(a))
            {
                System.out.println("Number is even");
            }
            else
            {
                throw new OddException("Number is off");
                // throw new Exception("Number is odd");
                // throw new Exception();
            }
        }
        catch(Exception e)
        {
            System.out.println(e);
            // System.out.println("Number is odd");
        }
        finally
        {
            System.out.println("End of program");
        }
        System.out.println("BYE");
        
    }
}