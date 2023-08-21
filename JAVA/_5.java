// Write a JAVA program that accepts a string and calculate the number
// of digits and letters.

import java.util.Scanner;
public class _5 {
    
    public static void check(){
        Scanner sc = new Scanner(System.in);
        System.out.println("ENTER THE STRING :");
        String n = sc.nextLine();
        int count = 0;
        int count1 = 0;
        for (int i = 0; i < n.length(); i++) {
            if (Character.isDigit(n.charAt(i))) {
                count++;
            }
            else if (Character.isLetter(n.charAt(i))) {
                count1++;
            }
        }
        System.out.println("NUMBER OF DIGITS : "+count);
        System.out.println("NUMBER OF LETTERS : "+count1);
        sc.close();
    }
    public static void main(String[] args) {
        check();
    }
}
