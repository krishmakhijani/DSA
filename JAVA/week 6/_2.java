//Write a Java program to create class called "TrafficLight" with attributes for color and
// duration, and methods to change the color and check for red or green.

class TrafficLight {
    String color;
    int duration;

    TrafficLight(String color, int duration) {
        this.color = color;
        this.duration = duration;
    }

    public void changeColor(String color) {
        this.color = color;
    }

    public boolean isRed() {
        return color.equals("red");
    }

    public boolean isGreen() {
        return color.equals("green");
    }
}

public class _2 {
    public static void main(String[] args) {
        TrafficLight t1 = new TrafficLight("red", 10);
        TrafficLight t2 = new TrafficLight("green", 20);
        System.out.println(t1.isRed());
        System.out.println(t2.isGreen());
        t1.changeColor("green");
        System.out.println(t1.isGreen());
    }
}