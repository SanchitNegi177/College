import java.io.File;
import java.util.Scanner;
public class ExceptionPositiveNumber 
{
    public static boolean check(String s)
    {
        File f=new File(s);
        if(f.exists())
            return true;
        else
            return false;
        
    }
    public static void main(String [] args)
    {
        System.out.println("Enter the Number");
        Scanner obj=new Scanner(System.in);
        int n=obj.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++)
        arr[i]=obj.nextInt();
        
        try
        {
            for(int i=0;i<n;i++)
            {
                if(arr[i]>=0)
                    throw new Exception("Positive number detected");
            }
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
        finally
        {
            System.out.println("End of program");
        }
    }
}