// 10. Implement java MVC to display Employee details.

import java.util.Scanner;

class Employee {
    private int id;
    private String name;
    private String branch;

    public Employee() {
        this.id = 0;
        this.name = "";
        this.branch = "";
    }

    public Employee(int id, String name, String branch) {
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

class EmployeeView {
    public void printEmployeeDetails(Employee employee) {
        System.out.println("Employee: ");
        System.out.println("Name: " + employee.getName());
        System.out.println("ID: " + employee.getId());
        System.out.println("Branch: " + employee.getBranch());
    }
}

class EmployeeController {
    private Employee model;
    private EmployeeView view;

    public EmployeeController(Employee model, EmployeeView view) {
        this.model = model;
        this.view = view;
    }

    public void setEmployeeName(String name) {
        model.setName(name);
    }

    public String getEmployeeName() {
        return model.getName();
    }

    public void setEmployeeId(int id) {
        model.setId(id);
    }

    public int getEmployeeId() {
        return model.getId();
    }

    public void setEmployeeBranch(String branch) {
        model.setBranch(branch);
    }

    public String getEmployeeBranch() {
        return model.getBranch();
    }

    public void updateView() {
        view.printEmployeeDetails(model);
    }
}


