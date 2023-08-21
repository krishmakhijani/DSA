// Write a Java program using function to count unique values in an array of 15 elements.

public class week5_10 {
    public static void main(String[] args) {
        int[] list = {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5};
        System.out.println("The number of unique values in the array is: " + countUnique(list));
    }
    public static int countUnique(int[] list) {
        int count = 0;
        for (int i = 0; i < list.length; i++) {
            boolean flag = true;
            for (int j = 0; j < i; j++) {
                if (list[i] == list[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                count++;
            }
        }
        return count;
    }
    
}
