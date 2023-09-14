// Create a java program for the following
// Use ThreadA to find number of digits present in the string k and store into variable de, finally
// print the value of dc(output format: ThreadA:digitscount).
// Use ThreadB to find number of alphabetic present in the string k and store into variable cc, finally
// print the value of cc(output format: ThreadB: digitscount).

class ThreadA implements Runnable {
    String k;
    int dc;

    ThreadA(String k) {
        this.k = k;
    }

    public void run() {
        for (int i = 0; i < k.length(); i++) {
            if (Character.isDigit(k.charAt(i))) {
                dc++;
            }
        }
        System.out.println("ThreadA: " + dc);
    }
}

class ThreadB implements Runnable {
    String k;
    int cc;

    ThreadB(String k) {
        this.k = k;
    }

    public void run() {
        for (int i = 0; i < k.length(); i++) {
            if (Character.isAlphabetic(k.charAt(i))) {
                cc++;
            }
        }
        System.out.println("ThreadB: " + cc);
    }
}

public class _7 {
    public static void main(String[] args) {
        String k = "Hello123";
        Thread t1 = new Thread(new ThreadA(k));
        Thread t2 = new Thread(new ThreadB(k));

        t1.start();
        t2.start();
    }
}
