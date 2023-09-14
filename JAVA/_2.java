// 2. Write a java program for to solve producer consumer problem in which a producer produce a value and
// consumer consume the value before producer generate the next value.

class Producer implements Runnable {
    public void run() {
        while (true) {
            int random = (int) (Math.random() * 100);
            System.out.println("Produced: " + random);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class Consumer implements Runnable {
    public void run() {
        while (true) {
            int random = (int) (Math.random() * 100);
            System.out.println("Consumed: " + random);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class _2 {
    public static void main(String[] args) {
        Thread t1 = new Thread(new Producer());
        Thread t2 = new Thread(new Consumer());

        t1.start();
        t2.start();
    }
}

