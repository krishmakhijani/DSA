// Write a java program for multithread in which user thread and thread started from main method
// invoked at a time each thread sleep for 1 sec.

class UserThread implements Runnable {
    public void run() {
        try {
            Thread.sleep(1000);
            System.out.println("UserThread");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class _5 {
    public static void main(String[] args) {
        Thread t1 = new Thread(new UserThread());
        t1.start();
        try {
            Thread.sleep(1000);
            System.out.println("Main");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}