// Write a Java program using function to print all Possible Combinations from the three
// Digits

public class week5_9{
    public static void main(String[] args) {
        int[] list = {1,2,3};
        printCombinations(list);
    }
    public static void printCombinations(int[] list) {
        for (int i = 0; i < list.length; i++) {
            for (int j = 0; j < list.length ; j++) {
                for (int k = 0; k < list.length; k++) {
                    System.out.println(list[i] + "" + list[j] + "" + list[k]);
                }
            }
        }
    }
}