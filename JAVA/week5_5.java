//Write a Java function (using function) that checks whether a given number is prime or not

public class week5_5 {
    public static void main(String[] args) {
        int num = 29;
        if (isPrime(num)) {
            System.out.println(num + " is a prime number");
        } else {
            System.out.println(num + " is not a prime number");
        }
    }

    public static boolean isPrime(int num) {
        boolean flag = true;
        for (int i = 2; i <= num / 2; ++i) {
            // condition for nonprime number
            if (num % i == 0) {
                flag = false;
                break;
            }
        }
        return flag;
    }
    
}
