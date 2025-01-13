import java.io.File;
import java.util.Scanner;
public class ExceptionFileNotFound 
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
        String s=obj.nextLine();
        try
        {
            if(check(s))
            {
                System.out.println("File exists");
            }
            else
            {
                throw new Exception("File do not exist");
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