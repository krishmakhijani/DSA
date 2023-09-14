// 1. Write a java program that implements a multi-thread application that has three threads. First thread
// generates random integer every 1 second and if the value is even, second thread computes the square of
// the number and prints. If the value is odd, the third thread will print the value of cube of the number.




class Cube implements Runnable {
    public void run() {
        while (true) {
            int random = (int) (Math.random() * 100);
            if (random % 2 != 0) {
                System.out.println("Cube of " + random + " is " + random * random * random);
            }
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class RandomNumberGenerator implements Runnable {
    public void run() {
        while (true) {
            int random = (int) (Math.random() * 100);
            System.out.println("Random number: " + random);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class Square implements Runnable {
    public void run() {
        while (true) {
            int random = (int) (Math.random() * 100);
            if (random % 2 == 0) {
                System.out.println("Square of " + random + " is " + random * random);
            }
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class _1 {
    public static void main(String[] args) {
        Thread t1 = new Thread(new RandomNumberGenerator());
        Thread t2 = new Thread(new Square());
        Thread t3 = new Thread(new Cube());

        t1.start();
        t2.start();
        t3.start();
    }

}
