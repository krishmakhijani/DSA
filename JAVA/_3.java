// Write a java program in which thread sleep for 5 sec and change the name of thread.

class ThreadNameChanger implements Runnable {
    public void run() {
        try {
            Thread.sleep(5);
            Thread.currentThread().setName("ThreadNameChanger");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class _3 {
    public static void main(String[] args) {
        Thread t1 = new Thread(new ThreadNameChanger());
        t1.start();
        System.out.println(t1.getName());
    }
}
