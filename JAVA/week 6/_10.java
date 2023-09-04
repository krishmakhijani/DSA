// Create two different packages to compute bubblesort and selection sort. Write a Java
// program to implement sorting functions in a single class.

import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;

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

class Person {
    String name;
    int age;

    Person(String name, int age) {
        this.name = name;
        this.age = age;

    }

    public void print() {
        System.out.println("Name: " + name + " Age: " + age);
    }
}

interface Resizable {
    public void resizeWidth(int width);
    public void resizeHeight(int height);
}

class Rectangle implements Resizable {
    int width;
    int height;

    Rectangle(int width, int height) {
        this.width = width;
        this.height = height;
    }

    public void resizeWidth(int width) {
        this.width = width;
    }

    public void resizeHeight(int height) {
        this.height = height;
    }

    public void print() {
        System.out.println("Width: " + width + " Height: " + height);
    }
}

public class _10 {
    public static void main(String[] args) {
        Rectangle r = new Rectangle(10, 20);
        r.print();
        r.resizeWidth(30);
        r.resizeHeight(40);
        r.print();
    }
}