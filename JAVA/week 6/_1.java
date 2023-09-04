//Write a Java program to create a class called "Person" with a name and age attribute. Create
// two instances of the "Person" class, set their attributes using the constructor, and print their
// name and age.

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

public class _1 {
    public static void main(String[] args) {
        Person p1 = new Person("John", 20);
        Person p2 = new Person("Doe", 30);
        p1.print();
        p2.print();
    }
}