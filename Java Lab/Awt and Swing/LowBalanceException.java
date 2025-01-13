import java.util.Scanner;
public class LowBalanceException {
    private String name;
    private double balance;

    LowBalanceException() {
        name = "";
        balance = 0.0;
    }

    LowBalanceException(String name, double balance) {
        this.name = name;
        this.balance = balance;
    }

    public void depositMoney(double money) {
        balance += money;
    }

    public void withdrawMoney(double money) throws Exception {
        if (balance >= money)
            balance -= money;
        else
            throw new Exception("LowBalanceException");
    }

    public void displayDetails() {
        System.out.println("Name Of Customer: " + name);
        System.out.println("Balance: " + balance);
    }

    public static void main(String[] args) {
        Scanner obj = new Scanner(System.in);
        System.out.println("Enter Name");
        String name = obj.nextLine();
        System.out.println("Enter Balance");
        double bal = obj.nextDouble();

        LowBalanceException ob = new LowBalanceException(name, bal);
        try {
            ob.withdrawMoney(10000);
        } catch (Exception e) {
            System.out.println(e);
        }

        ob.displayDetails();

    }
}
