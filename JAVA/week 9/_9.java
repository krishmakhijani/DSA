// 9. Implement java MVC pattern application with Student object Model, Student View and
// StudentController.

import java.util.Scanner;

class Student {
    private int id;
    private String name;
    private String branch;

    public Student() {
        this.id = 0;
        this.name = "";
        this.branch = "";
    }

    public Student(int id, String name, String branch) {
        this.id = id;
        this.name = name;
        this.branch = branch;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setBranch(String branch) {
        this.branch = branch;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getId() {
        return this.id;
    }

    public String getBranch() {
        return this.branch;
    }

    public String getName() {
        return this.name;
    }
}

class StudentView {
    public void printStudentDetails(Student student) {
        System.out.println("Student: ");
        System.out.println("Name: " + student.getName());
        System.out.println("ID: " + student.getId());
        System.out.println("Branch: " + student.getBranch());
    }
}

class StudentController {
    private Student model;
    private StudentView view;

    public StudentController(Student model, StudentView view) {
        this.model = model;
        this.view = view;
    }

    public void setStudentName(String name) {
        this.model.setName(name);
    }

    public void setStudentId(int id) {
        this.model.setId(id);
    }

    public void setStudentBranch(String branch) {
        this.model.setBranch(branch);
    }

    public String getStudentName() {
        return this.model.getName();
    }

    public int getStudentId() {
        return this.model.getId();
    }

    public String getStudentBranch() {
        return this.model.getBranch();
    }

    public void updateView() {
        this.view.printStudentDetails(this.model);
    }
}

public class _9 {
    public static void main(String[] args) {
        Student model = new Student();
        StudentView view = new StudentView();
        StudentController controller = new StudentController(model, view);

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter student name: ");
        String name = sc.nextLine();
        controller.setStudentName(name);

        System.out.print("Enter student id: ");
        int id = sc.nextInt();
        controller.setStudentId(id);

        System.out.print("Enter student branch: ");
        String branch = sc.next();
        controller.setStudentBranch(branch);

        controller.updateView();
    }
}