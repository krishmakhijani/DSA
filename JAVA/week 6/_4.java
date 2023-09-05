// Write a Java program to create a class called Employee with methods called work() and
// getSalary(). Create a subclass called HRManager that overrides the work() method and
// adds a new method called addEmployee().

class Employee {
    public void work() {
        System.out.println("Employee is working");
    }

    public void getSalary() {
        System.out.println("Employee salary is 1000");
    }
}

class HRManager extends Employee {
    public void work() {
        System.out.println("HRManager is working");
    }

    public void addEmployee() {
        System.out.println("HRManager is adding employee");
    }
}

public class _4 {
    public static void main(String[] args) {
        Employee employee = new Employee();
        employee.work();
        employee.getSalary();

        HRManager hrManager = new HRManager();
        hrManager.work();
        hrManager.getSalary();
        hrManager.addEmployee();
    }
}