import java.util.Scanner;
public class AddingMatrix 
{
    public static void main(String args[])
    {
        Scanner obj=new Scanner(System.in);

        System.out.println("Enter order of matrix N x N ");
        int n=obj.nextInt();
        int arr1[][]=new int[n][n];
        int arr2[][]=new int[n][n];
        int ans[][]=new int[n][n];
        
        System.out.println("Enter elements in 1st "+n+" x "+n+" matrix");
        for(int i=0;i<n;i++)                // Taking input in 1st matrix
        for(int j=0;j<n;j++)
        arr1[i][j]=obj.nextInt();
        
        System.out.println("Enter elements in 2nd "+n+" x "+n+" matrix");
        for(int i=0;i<n;i++)                // Taking input in 2nd matrix
        for(int j=0;j<n;j++)
        arr2[i][j]=obj.nextInt();
        
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)            // Adding matrix
        ans[i][j]=arr1[i][j]+arr2[i][j];
        
        System.out.println("Resultant matrix ");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)            // Displaying resultant matrix
                System.out.print(ans[i][j]+" ");
            System.out.println();
        }
        obj.close();
    }
}
