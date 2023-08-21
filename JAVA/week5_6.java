// Write a Java program to find the digits which are absent in a given mobile number

public class week5_6 {
    public static void main(String[] args) {
        String number = "0123456789";
        String mobile = "0123456789";
        System.out.println("Absent digits: " + absentDigits(number, mobile));
    }
    public static String absentDigits(String number, String mobile) {
        String absent = "";
        for (int i = 0; i < number.length(); i++) {
            if (mobile.indexOf(number.charAt(i)) == -1) {
                absent += number.charAt(i);
            }
        }
        return absent;
    }
    
}
