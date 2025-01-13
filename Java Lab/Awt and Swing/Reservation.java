
class Reserve implements Runnable 
{ 

    
    // available berths are 1
    int available = 1;
    int wanted;

    // accept wanted berths at runtime Reserve (int i)
    Reserve(int i) 
    {
        this.wanted = i;
    }

    public synchronized void run() 
    {
        //display available berths 
        System.out.println ("Number of berths available: "+ this.available); 
        //if available berths more than wanted betrhs
        if ( this.available >= this.wanted) 
        { 
            //get the name of the passenger
            String name = Thread.currentThread().getName(); 
            System.out.println (this.wanted + " berths alloted to: "+ name); 
            try
            { 
                Thread.sleep (1000); 
                this.available = this.available - this.wanted; 
                //update the no.of available berths
            } 
            catch (InterruptedException ie){ } 
        }
        else
        { 
            System.out.println ("Sorry, no berths available"); 
        } 
    }
}


public class Reservation 
{
    public static void main(String args[]) {
        Reserve obj = new Reserve(1);
        Thread t1 = new Thread(obj,"First Person");
        Thread t2 = new Thread(obj,"Second Person");
        t1.start();
        t2.start();
    }
}
