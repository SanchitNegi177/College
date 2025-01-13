class Account {
    private int balance;

    public Account() {
        balance = 500;
    }

    // Method to deposit money into the account
    public synchronized void deposit(int amount) 
    {
        System.out.println("Depositing: " + amount);
        balance += amount;
        System.out.println("Balance after deposit: " + balance);
        notify(); // Notify any waiting threads that balance has been updated
    }

    // Method to withdraw money from the account
    public synchronized void withdraw(int amount) 
    {
        if (amount <= balance) 
        {
            System.out.println("Amount Withdrawn: " + amount);
            System.out.println(Thread.currentThread().getName());

            try 
            {
                Thread.sleep(1000);
            } 
            catch (InterruptedException ex) 
            {
                System.out.println("InterruptedException occurred: " + ex);
            }
            balance -= amount;
            System.out.println("Balance remaining: " + balance);
        } 
        else 
        {
            System.out.println("Balance not enough to withdraw");
        }
    }

    public int getBalance() {
        return balance;
    }
}

class Amtthread implements Runnable 
{
    Account obj;
    int amount;
    
    public Amtthread(Account a, int amount) {
        obj = a;
        this.amount = amount;
    }
    
    public void run() {
        obj.withdraw(amount);
    }
}


class DepositThread implements Runnable 
{
    private Account account;
    private int amount;

    public DepositThread(Account account, int amount) {
        this.account = account;
        this.amount = amount;
    }

    @Override
    public void run() {
        account.deposit(amount);
    }
}

public class Withdraw_sync {
    public static void main(String[] args) {
        Account account = new Account();

        // Creating withdrawal threads
        Amtthread withdrawalThread1 = new Amtthread(account, 200);  // First thread will withdraw 200
        Amtthread withdrawalThread2 = new Amtthread(account, 300);  // Second thread will withdraw 300

        // Creating deposit thread
        DepositThread depositThread = new DepositThread(account, 400);

        // Creating and starting threads
        Thread thread1 = new Thread(withdrawalThread1, "ABC");
        Thread thread2 = new Thread(withdrawalThread2, "XTZ");
        Thread depositThread1 = new Thread(depositThread, "DepositThread");

        thread1.start();
        thread2.start();
        depositThread1.start();
    }
}
