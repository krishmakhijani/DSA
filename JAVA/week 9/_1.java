// 1. Write a java program using swing by inheritance.

import javax.swing.*;

class SwingInheritance extends JFrame {
    SwingInheritance() {
        JButton b = new JButton("Click");
        b.setBounds(130, 100, 100, 40);
        add(b);
        setSize(400, 500);
        setLayout(null);
        setVisible(true);
    }

    public static void main(String[] args) {
        new SwingInheritance();
    }
}
