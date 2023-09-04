// Write a Java program to create a class called Shape with methods called getPerimeter() and
// getArea(). Create a subclass called Circle that overrides the getPerimeter() and getArea()
// methods to calculate the area and perimeter of a circle.

class Shape {
    public double getPerimeter() {
        return 0;
    }

    public double getArea() {
        return 0;
    }
}

class Circle extends Shape {
    double radius;

    Circle(double radius) {
        this.radius = radius;
    }

    public double getPerimeter() {
        return 2 * Math.PI * radius;
    }

    public double getArea() {
        return Math.PI * Math.pow(radius, 2);
    }
}

public class _5 {
    public static void main(String[] args) {
        Circle c = new Circle(10);
        System.out.println(c.getPerimeter());
        System.out.println(c.getArea());
    }
}