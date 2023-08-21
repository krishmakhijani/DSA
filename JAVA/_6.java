// Write a JAVA program to check the validity of password input by
// users.
// Validation :
// ● At least 1 letter between [a-z] and 1 letter between [A-Z].
// ● At least 1 number between [0-9].

// ● At least 1 character from [$#@].
// ● Minimum length 6 characters.
// ● Maximum length 16 characters.

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class _6 {
    public static void check(){
        Scanner sc = new Scanner(System.in);
        System.out.println("ENTER THE PASSWORD :");
        String n = sc.nextLine();
        String regex = "^(?=.*[0-9])"
                       + "(?=.*[a-z])(?=.*[A-Z])"
                       + "(?=.*[@#$%^&+=])"
                       + "(?=\\S+$).{8,20}$";
        Pattern p = Pattern.compile(regex);
        Matcher m = p.matcher(n);
        if (m.matches()) {
            System.out.println("VALID PASSWORD");
        }
        else {
            System.out.println("INVALID PASSWORD");
        }
        sc.close();
    }
    public static void main(String[] args) {
        check();
    }
    
}