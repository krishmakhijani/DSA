// 6. Write a java program to solve printer synchronization problem in which all the jobs must be completed
// in order.

class Printer implements Runnable {
    public void run() {
        for (int i = 1; i <= 10; i++) {
            System.out.println("Printing: " + i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class _6 {
    public static void main(String[] args) {
        Thread t1 = new Thread(new Printer());
        Thread t2 = new Thread(new Printer());
        Thread t3 = new Thread(new Printer());

        t1.start();
        t2.start();
        t3.start();
    }
}