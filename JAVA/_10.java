// Write a JAVA program to construct the following pattern, using a
// nested loop number.
// Expected Output:
// 999999999
// 88888888
// 7777777
// 666666
// 55555
// 4444
// 333
// 22
// 1

import java.util.Scanner;
public class _10 {
    
    public static void check(){
        Scanner sc = new Scanner(System.in);
        System.out.println("ENTER THE NUMBER :");
        int n = sc.nextInt();
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= i; j++) {
                System.out.print(i);
            }
            System.out.println("");
        }
        sc.close();
    }
    public static void main(String[] args) {
        check();
    }
}
