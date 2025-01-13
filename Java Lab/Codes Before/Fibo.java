import java.util.Scanner;

public class Fibo {
    public static void main(String args[]) 
    {
        Scanner obj = new Scanner(System.in);
        int n = obj.nextInt();
        int first = 0, second = 1;
        if (n > 0) 
        {
            System.out.print(first + " ");
            n--;
        }
        if (n > 0) 
        {
            System.out.print(second + " ");
            n--;
        }
        while (n > 0) 
        {
            int third = first + second;
            first = second;
            second = third;
            System.out.print(third + " ");
            n--;
        }
        obj.close();
    }
}
