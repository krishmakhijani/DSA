//Write a Java program (using function) to check if two strings are rotationally equivalent.



public class week5_2 {
    public static void main(String[] args) {
        String str1 = "Hello";
        String str2 = "lloHe";
        System.out.println(isRotation(str1, str2));
    }

    public static boolean isRotation(String str1, String str2) {
        if (str1.length() != str2.length()) {
            return false;
        }
        String str3 = str1 + str1;
        return str3.contains(str2);
    }
}
