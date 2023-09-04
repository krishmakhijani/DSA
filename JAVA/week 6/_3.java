//Write a Java program to perform arithmetic operations using method overloading.
class Arithmetic {
    public int add(int a, int b) {
        return a + b;
    }

    public int add(int a, int b, int c) {
        return add(add(a, b), c);
    }

    public int add(int a, int b, int c, int d) {
        return add(add(a, b, c), d);
    }
}

public class _3 {
    public static void main(String[] args) {
        Arithmetic a = new Arithmetic();
        System.out.println(a.add(1, 2));
        System.out.println(a.add(1, 2, 3));
        System.out.println(a.add(1, 2, 3, 4));
    }
}