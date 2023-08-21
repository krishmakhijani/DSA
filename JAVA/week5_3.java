//Write a Java program (using function) to print the even numbers from a given list.

public class week5_3 {
    public static void main(String[] args) {
        int[] list = {1,2,3,4,5,6,7,8,9,10};
        printEven(list);
    }
    public static void printEven(int[] list) {
        for (int i = 0; i < list.length; i++) {
            if (list[i] % 2 == 0) {
                System.out.println(list[i]);
            }
        }
    }
}
