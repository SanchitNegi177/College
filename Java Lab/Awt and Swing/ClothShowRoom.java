import java.util.Scanner;
public class ClothShowRoom {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Purchase Amount ");
        double amt = sc.nextDouble();
        System.out.println("Enter discount type:M for Mill / H for Handloom ? ");
        char s = sc.next().charAt(0);

        double discount = 0.0;

        switch (s) {
            case 'M':
                if (amt <= 101 && amt <= 200)
                    discount = 0.05 * amt;
                else if (amt <= 201 && amt <= 300)
                    discount = 0.75 * amt;
                else
                    discount = 0.1 * amt;

                break;

            case 'H':
                if (amt <= 100)
                    discount = 0.05 * amt;
                else if (amt <= 101 && amt <= 200)
                    discount = 0.75 * amt;
                else if (amt <= 201 && amt <= 300)
                    discount = 0.1 * amt;
                else
                    discount = 0.15 * amt;

                break;

            default:
                System.out.println("Invalid Input");
                break;
        }

        System.out.println("Amount: " + amt);
        System.out.println("Discount type (" + s + "): " + discount);
        System.out.println("Net Payable Amount: " + (amt - discount));
        sc.close();
    }
}
