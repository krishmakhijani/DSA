// Write a JAVA program that accepts a word from the user and reverse
// it.

import java.util.Scanner;

class _4 {
    public static void check(){
        Scanner sc = new Scanner(System.in);
        System.out.println("ENTER THE WORD :");
        String n = sc.nextLine();
        String rev = "";
        for (int i = n.length()-1; i >= 0; i--) {
            rev = rev + n.charAt(i);
        }
        System.out.println(rev);
        sc.close();
    }
    public static void main(String[] args) {
        check();
    }
    
}