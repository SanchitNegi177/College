import java.util.Scanner;
public class NoMatchException {
    public static void main(String[] args) {
        System.out.println("Enter String");
        Scanner obj = new Scanner(System.in);
        String str = obj.nextLine();
        try {
            if (str.equalsIgnoreCase("India")) {
                System.out.println(str);
            } else {
                throw new Exception("NoMatchException");
            }
        } catch (Exception e) {
            System.out.println(e);
        }

        System.out.println("End of program");

    }
}