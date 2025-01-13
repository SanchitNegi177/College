import java.util.Scanner;
public class FloyedTriangle 
{
    public static void main(String args[])
    {
        Scanner obj = new Scanner(System.in);
        System.out.println("Enter the no. of rows : ");
        int n=obj.nextInt();
        int val=1;
        System.out.println("Floyed Triangle with "+ n +" rows : ");
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                System.out.print((val++) + " ");
            }
            System.out.println();
        }
        obj.close();
            
    }
}
