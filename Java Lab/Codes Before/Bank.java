import java.util.Scanner;
public class Bank 
{
    private String name;
    private String accountType;
    private String accountNo;
    private double balance;

    Bank()
    {
        name="";
        accountType="";
        accountNo="";
        balance=0.0;
    }
    Bank(String name,String accountType,String accountNo,double balance)
    {
        this.name=name;
        this.accountType=accountType;
        this.accountNo=accountNo;
        this.balance=balance;
    }
    public void depositMoney(long money)
    {
        balance+=money;
    }
    public void withdrawMoney(long money)
    {
        if(balance>=money)
            balance-=money;
        else
            System.out.println("Insufficient Balance");

    }
    public void displayDetails()
    {
        System.out.println("Name Of Customer: "+name);
        System.out.println("Account Type: "+accountType);
        System.out.println("Account No.: "+accountNo);
        System.out.println("Balance: "+balance);
    }
    public static void main(String args[])
    {
        Scanner obj=new Scanner(System.in);
        
        System.out.println("Enter customer name");
        String name=obj.nextLine();
        System.out.println("Enter Account Type");
        String accountType=obj.nextLine();
        System.out.println("Enter Account Number");
        String accountNo=obj.nextLine();
        System.out.println("Enter Balance");
        double balance=obj.nextDouble();

        Bank cus1=new Bank(name,accountType,accountNo,balance);
        
        cus1.depositMoney(5000);  //Deposit money
        cus1.withdrawMoney(1000); //Withdraw money
        cus1.displayDetails();  //Customer Details

        obj.close();
    }
}
