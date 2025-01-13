import java.util.Scanner; 
public class Calculator 
{
    public static void main(String args[])
    {
        Scanner obj = new Scanner(System.in);
        while(true)
        {
            System.out.print("Enter the first number: ");
            int a = obj.nextInt();
            System.out.print("Enter the operation to be done (+, -, *, /, %): ");
            char op = obj.next().charAt(0);
            System.out.print("Enter the other number: ");
            int b = obj.nextInt();
            switch(op)
            {
                case '+':
                    System.out.println(a + " + " + b + " = " + (a + b));
                    break;
                case '-':
                    System.out.println(a + " - " + b + " = " + (a - b));
                    break;
                case '*':
                    System.out.println(a + " * " + b + " = " + (a * b));
                    break;
                case '/':
                    if(b == 0)
                    {
                        System.out.println("Denominator must be a non-zero number.");
                        continue;
                    }
                    System.out.println(a + " / " + b + " = " + (a / b));

                    break;
                case '%':
                    System.out.println(a + " % " + b + " = " + (a%b));
                    break;
                default:
                    System.out.println("Invalid input.");
            }
            System.out.println("Quit (y/n)?");
            char ch = obj.next().charAt(0);
            if(ch == 'y')
            {
                System.out.println("Program terminated on user choice!");
                break;
            }
        }
        obj.close();
    }
}
