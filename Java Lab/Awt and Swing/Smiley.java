import java.awt.*;
import javax.swing.*;

public class Smiley extends JPanel 
{

    @Override
    public void paintComponent(Graphics g) 
    {
        super.paintComponent(g);
        g.setColor(Color.GREEN);
        g.fillOval(10, 10, 200, 200);

        // draw Eyes
        g.setColor(Color.BLACK);
        g.fillOval(55, 65, 30, 30);
        g.fillOval(135, 65, 30, 30);


        // draw Mouth
        g.fillOval(50, 110, 120, 60);

        // adding smile
        g.setColor(Color.GREEN);
        g.fillRect(50, 110, 120, 30);
        g.fillOval(50, 120, 120, 40);
        
        //body
        g.setColor(Color.BLACK);
        g.fillRect(105, 110, 10, 20);
        g.fillOval(102, 125, 25, 25);
        g.setColor(Color.GREEN);
        g.fillOval(102, 125, 15, 15);

    }

    public static void main(String[] args) {
        Smiley smily = new Smiley();
        JFrame app = new JFrame();
        app.add(smily);
        app.setSize(300, 300);
        app.setVisible(true);
    }
}