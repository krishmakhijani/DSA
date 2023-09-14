
// Create two objects threadobj1 and threadobj2 for the class UserThreadPriority. Set the name of
// threadobj1 as "ThreadA" and threadobj2 as "ThreadB". Get a String and a Character from the user and
// assign into UserThreadPriority class variable k and c respectively. Call the start method for the thread
// objects threadobj1 and threadobj2.

class UserThreadPriority implements Runnable {
    String k;
    char c;

    UserThreadPriority(String k, char c) {
        this.k = k;
        this.c = c;
    }

    public void run() {
        for (int i = 0; i < k.length(); i++) {
            if (k.charAt(i) == c) {
                System.out.println("Thread: " + Thread.currentThread().getName() + " found " + c + " at index " + i);
            }
        }
    }
}

public class _8 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String k = sc.nextLine();
        System.out.print("Enter a character: ");
        char c = sc.next().charAt(0);
        sc.close();

        Thread threadobj1 = new Thread(new UserThreadPriority(k, c));
        Thread threadobj2 = new Thread(new UserThreadPriority(k, c));

        threadobj1.setName("ThreadA");
        threadobj2.setName("ThreadB");

        threadobj1.start();
        threadobj2.start();
    }
}
