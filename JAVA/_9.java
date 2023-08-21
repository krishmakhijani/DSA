// //Write a JAVA program to sum of two given integers. However, if the
// sum is between 105 to 200 it will return 200.

import java.util.Scanner;
public class _9 {
    
    public static void check(){
        Scanner sc = new Scanner(System.in);
        System.out.println("ENTER THE FIRST NUMBER :");
        int n = sc.nextInt();
        System.out.println("ENTER THE SECOND NUMBER :");
        int n1 = sc.nextInt();
        int sum = n + n1;
        if (sum>=105&&sum<=200) {
            System.out.println("200");
        }
        else {
            System.out.println(sum);
        }
        sc.close();
    }
    public static void main(String[] args) {
        check();
    }
}
