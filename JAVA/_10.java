// 10. Write a java Thread program using Thread Priority for 5 processes and execute the priority order
// among the process.

class ThreadPriority implements Runnable {
    int n;

    ThreadPriority(int n) {
        this.n = n;
    }

    public void run() {
        System.out.println(Thread.currentThread().getName() + " is running");
    }
}

public class _10 {
    public static void main(String[] args) {
        Thread t1 = new Thread(new ThreadPriority(1));
        Thread t2 = new Thread(new ThreadPriority(2));
        Thread t3 = new Thread(new ThreadPriority(3));
        Thread t4 = new Thread(new ThreadPriority(4));
        Thread t5 = new Thread(new ThreadPriority(5));

        t1.setPriority(1);
        t2.setPriority(2);
        t3.setPriority(3);
        t4.setPriority(4);
        t5.setPriority(5);

        t1.start();
        t2.start();
        t3.start();
        t4.start();
        t5.start();
    }
}
