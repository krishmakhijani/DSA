// Write a JAVA program to convert month name to a number of days.

import java.util.Scanner;

public class _8 {
    
    public static void check(){
        Scanner sc = new Scanner(System.in);
        System.out.println("ENTER THE MONTH NAME :");
        String n = sc.nextLine();
        if (n.equalsIgnoreCase("January")) {
            System.out.println("31");
        }
        else if (n.equalsIgnoreCase("February")) {
            System.out.println("28");
        }
        else if (n.equalsIgnoreCase("March")) {
            System.out.println("31");
        }
        else if (n.equalsIgnoreCase("April")) {
            System.out.println("30");
        }
        else if (n.equalsIgnoreCase("May")) {
            System.out.println("31");
        }
        else if (n.equalsIgnoreCase("June")) {
            System.out.println("30");
        }
        else if (n.equalsIgnoreCase("July")) {
            System.out.println("31");
        }
        else if (n.equalsIgnoreCase("August")) {
            System.out.println("31");
        }
        else if (n.equalsIgnoreCase("September")) {
            System.out.println("30");
        }
        else if (n.equalsIgnoreCase("October")) {
            System.out.println("31");
        }
        else if (n.equalsIgnoreCase("November")) {
            System.out.println("30");
        }
        else if (n.equalsIgnoreCase("December")) {
            System.out.println("31");
        }
        else {
            System.out.println("INVALID MONTH NAME");
        }
        sc.close();
    }
    public static void main(String[] args) {
        check();
    }
}
