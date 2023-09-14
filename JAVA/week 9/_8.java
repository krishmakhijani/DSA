// 8. Write a java program that handles all mouse events and shows the event name at the
// center of the window when mouse event is fired (Use Adapter classes and applet).

import java.awt.*;
import java.awt.event.*;
import java.applet.*;

public class _8{
    public static void main(String[] args) {
        Frame f = new Frame("Mouse Events");
        f.setSize(400, 400);
        f.setLayout(null);
        f.setVisible(true);

        Label l = new Label();
        l.setBounds(50, 50, 100, 20);
        f.add(l);

        f.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                l.setText("Mouse Clicked");
            }

            public void mouseEntered(MouseEvent e) {
                l.setText("Mouse Entered");
            }

            public void mouseExited(MouseEvent e) {
                l.setText("Mouse Exited");
            }

            public void mousePressed(MouseEvent e) {
                l.setText("Mouse Pressed");
            }

            public void mouseReleased(MouseEvent e) {
                l.setText("Mouse Released");
            }
        });
    }
}