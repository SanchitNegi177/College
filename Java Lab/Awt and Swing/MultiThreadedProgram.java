public class MultiThreadedProgram {
    public static void main(String[] args) {
        MyRunnable t = new MyRunnable();

        Thread thread1 = new Thread(t, "Thread 1");
        Thread thread2 = new Thread(t, "Thread 2");

        thread1.start();
        thread2.start();
    }
}

class MyRunnable implements Runnable {
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println(Thread.currentThread().getName() + " running :" + i);
            try {
                Thread.sleep(1000);
            } catch (Exception e) {
                System.out.print(e);
            }
        }
    }
}
