// 7. Draw a chessboard in java applet.

import java.awt.*;
import java.applet.*;

public class _7 extends Applet {
    public void paint(Graphics g) {
        int x = 0, y = 0;
        for (int i = 0; i < 8; i++) {
            x = 20;
            for (int j = 0; j < 8; j++) {
                if ((i + j) % 2 == 0)
                    g.setColor(Color.white);
                else
                    g.setColor(Color.black);
                g.fillRect(x, y, 20, 20);
                x += 20;
            }
            y += 20;
        }
    }
}

