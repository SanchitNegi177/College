import java.util.Scanner;
public class DiamondShape 
{
    public static void main(String args[])
    {
        Scanner obj=new Scanner(System.in);
        int n=obj.nextInt();
        int sp=n;
        for(int i=1;i<=n;i++)                           // Upper 
        {
            for(int space=1;space<=sp;space++)
            {
                System.out.print(" ");
            }
            sp--;
            for(int j=1;j<=i;j++)
            {
                System.out.print("* ");
            }
            System.out.println();

        }

        sp=2;
        for(int i=n-1;i>=1;i--)                           // Lower
        {
            for(int space=1;space<=sp;space++)
            {
                System.out.print(" ");
            }
            sp++;
            for(int j=1;j<=i;j++)
            {
                System.out.print("* ");
            }
            System.out.println();
        }
        obj.close();
    }
}
