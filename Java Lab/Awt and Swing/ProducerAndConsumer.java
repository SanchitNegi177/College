
//A Correct Implementation of Producer and Consumer problem
class Q extends Thread
{
    int value;
    boolean isValueAvailable = false;

    // Producer will call this method to produce a value
    public synchronized void produce(int value) throws InterruptedException 
    {
        // Wait until the consumer consumes the current value
        while (isValueAvailable) 
        {
            wait();
        }
        this.value = value;
        System.out.println(Thread.currentThread().getName()+" "+ value);
        isValueAvailable = true;
        // Notify the consumer thread that a value has been produced
        notify();
    }

    // Consumer will call this method to consume a value
    public synchronized void consume() // throws InterruptedException
    {
        // Wait until the producer provides a new value
        try{
            while (!isValueAvailable) 
            {
                wait();
            }
        }
        catch(Exception e)
        {}

        System.out.println(Thread.currentThread().getName()+" "+ value);
        isValueAvailable = false;
        // Notify the producer thread that the value has been consumed
        notify();
        // return value;
    }
}

class Producer extends Thread 
{
    Q sharedValue;

    public Producer(Q sharedValue) 
    {
        this.sharedValue = sharedValue;
    }

    public void run()  
    {
        int value = 0;
        try 
        {
            while (true) 
            {
                sharedValue.produce(value++);
                Thread.sleep(2000); // Simulate time taken to produce
            }
        } 
        catch (InterruptedException e) 
        {
            Thread.currentThread().interrupt();
        }
    }
}

class Consumer extends Thread 
{
    Q sharedValue;

    public Consumer(Q sharedValue) 
    {
        this.sharedValue = sharedValue;
    }

    public void run() 
    {
        try 
        {
            while (true)
            {
                sharedValue.consume();
                Thread.sleep(2000); // Simulate time taken to consume
            }
        } 
        catch (InterruptedException e) 
        {
            Thread.currentThread().interrupt();
        }
    }
}

public class ProducerAndConsumer 
{
    public static void main(String[] args) 
    {
        Q sharedValue = new Q();

        Producer producer = new Producer(sharedValue);
        Consumer consumer = new Consumer(sharedValue);
        // Starting both the thread
        producer.setName("Producer");
        consumer.setName("Consumer");
        producer.start();
        consumer.start();
    }
}