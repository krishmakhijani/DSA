// Write a Java function (using function) that checks whether a passed string is palindrome or
// not.

public class week5_4{
    public static void main(String[] args) {
        String str = "madam";
        if (isPalindrome(str))
            System.out.println("Yes");
        else
            System.out.println("No");
    }
    static boolean isPalindrome(String str){
        int i = 0, j = str.length() - 1;
        while (i < j) {
            if (str.charAt(i) != str.charAt(j))
                return false;
            i++;
            j--;
        }
        return true; 
    }
}
