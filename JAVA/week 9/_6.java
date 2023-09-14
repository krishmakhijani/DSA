// 6. Write a java program to draw Oval, Rectangle, Line and fill the color in it.and display it
// on Applet.

import java.awt.*;
import java.applet.*;

public class _6 extends Applet {
    public void paint(Graphics g) {
        g.setColor(Color.red);
        g.drawLine(20, 30, 20, 300);
        g.drawRect(70, 100, 30, 30);
        g.fillRect(170, 100, 30, 30);
        g.drawOval(70, 200, 30, 30);

        g.setColor(Color.pink);
        g.fillOval(170, 200, 30, 30);
        g.drawArc(90, 150, 30, 30, 30, 270);
        g.fillArc(270, 150, 30, 30, 0, 180);
    }
}
