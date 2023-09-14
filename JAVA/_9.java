// Write java program using sleep method of Thread class where the new class thread created from the
// previous class is implemented by using sleep method for 10,20,50,70,100 n

class ThreadSleep implements Runnable {
    int n;

    ThreadSleep(int n) {
        this.n = n;
    }

    public void run() {
        try {
            Thread.sleep(n);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class _4 {
    public static void main(String[] args) {
        Thread t1 = new Thread(new ThreadSleep(10));
        Thread t2 = new Thread(new ThreadSleep(20));
        Thread t3 = new Thread(new ThreadSleep(50));
        Thread t4 = new Thread(new ThreadSleep(70));
        Thread t5 = new Thread(new ThreadSleep(100));

        t1.start();
        t2.start();
        t3.start();
        t4.start();
        t5.start();
    }
}

