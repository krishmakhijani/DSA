// 2. Write a java program using swing with Action Listener.

import javax.swing.*;

class SwingActionListener extends JFrame {
    SwingActionListener() {
        JButton b = new JButton("Click");
        b.setBounds(130, 100, 100, 40);
        add(b);
        setSize(400, 500);
        setLayout(null);
        setVisible(true);
    }

    public static void main(String[] args) {
        new SwingActionListener();
    }
}