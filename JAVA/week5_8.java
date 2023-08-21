// Write a Java program using function to count the number of each character of a given
// text/string.

public class week5_8 {
    public static void main(String[] args) {
        String str = "Hello World";
        System.out.println("Original String: " + str);
        System.out.println("Mirror Image: " + mirror(str));
    }

    public static String mirror(String str) {
        String mirror = "";
        for (int i = str.length() - 1; i >= 0; i--) {
            mirror += str.charAt(i);
        }
        return mirror;
    }
    
}
