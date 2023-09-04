// Write a Java program to create an interface Resizable with methods resizeWidth(int width)
// and resizeHeight(int height) that allow an object to be resized. Create a class Rectangle
// that implements the Resizable interface and implements the resize methods.

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

public class _7 {
    public static void main(String[] args) {
        Rectangle r = new Rectangle(10, 20);
        r.print();
        r.resizeWidth(30);
        r.resizeHeight(40);
        r.print();
    }
}