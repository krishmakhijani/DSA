// Write a java program in which thread sleep for 6 sec in the loop in reverse order from 5 to 1 and change
// the name of thread.

class ThreadNameChanger implements Runnable {
    public void run() {
        for (int i = 5; i > 0; i--) {
            try {
                Thread.sleep(6);
                Thread.currentThread().setName("ThreadNameChanger");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class _4 {
    public static void main(String[] args) {
        Thread t1 = new Thread(new ThreadNameChanger());
        t1.start();
        System.out.println(t1.getName());
    }
}

