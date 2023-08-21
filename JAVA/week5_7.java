// Write a Java program using function that will return true if the two given integer values are
// equal or their sum or difference is 5.

public class week5_7{
    public static void main(String[] args) {
        int num1 = 5;
        int num2 = 5;
        if (isEqual(num1, num2)) {
            System.out.println("The two numbers are equal");
        } else {
            System.out.println("The two numbers are not equal");
        }
    }
    public static boolean isEqual(int num1, int num2) {
        boolean flag = false;
        if (num1 == num2) {
            flag = true;
        } else if (num1 + num2 == 5) {
            flag = true;
        } else if (num1 - num2 == 5) {
            flag = true;
        }
        return flag;
    }

}