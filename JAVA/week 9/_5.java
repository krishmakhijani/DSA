// 5. Implement Employment registration form using SWING components.

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class _5{
    _5(){
        JFrame f = new JFrame("Employment Registration Form");
        JLabel l1, l2, l3, l4, l5, l6, l7, l8, l9, l10;
        JTextField t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
        JButton b1, b2;
        JRadioButton r1, r2;
        JComboBox c1, c2, c3;
        String[] day = new String[31];
        String[] month = new String[12];
        String[] year = new String[100];
        for(int i = 0; i < 31; i++){
            day[i] = Integer.toString(i + 1);
        }
        for(int i = 0; i < 12; i++){
            month[i] = Integer.toString(i + 1);
        }
        for(int i = 0; i < 100; i++){
            year[i] = Integer.toString(2020 - i);
        }
        l1 = new JLabel("Name");
        l1.setBounds(50, 50, 100, 30);
        t1 = new JTextField();
        t1.setBounds(200, 50, 200, 30);
        l2 = new JLabel("Father's Name");
        l2.setBounds(50, 100, 100, 30);
        t2 = new JTextField();
        t2.setBounds(200, 100, 200, 30);
        l3 = new JLabel("Mother's Name");
        l3.setBounds(50, 150, 100, 30);
        t3 = new JTextField();
        t3.setBounds(200, 150, 200, 30);
        l4 = new JLabel("Address");
        l4.setBounds(50, 200, 100, 30);
        t4 = new JTextField();
        t4.setBounds(200, 200, 200, 30);
        l5 = new JLabel("Phone Number");
        l5.setBounds(50, 250, 100, 30);
        t5 = new JTextField();
        t5.setBounds(200, 250, 200, 30);
        l6 = new JLabel("Email");
        l6.setBounds(50, 300, 100, 30);

        t6 = new JTextField();
        t6.setBounds(200, 300, 200, 30);
        l7 = new JLabel("Date of Birth");
        l7.setBounds(50, 350, 100, 30);
        c1 = new JComboBox(day);
        c1.setBounds(200, 350, 50, 30);
        c2 = new JComboBox(month);
        c2.setBounds(250, 350, 50, 30);
        c3 = new JComboBox(year);

        c3.setBounds(300, 350, 50, 30);

    }

    public static void main(String[] args) {
        new _5();
    }
}