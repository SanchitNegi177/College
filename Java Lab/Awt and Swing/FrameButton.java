import javax.swing.*;
import java.awt.*;

public class FrameButton 
{    public static void main(String[] args) 
    {
        JFrame frame = new JFrame("Button Example");
        frame.setSize(300, 200);
        frame.setLayout(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        JButton button = new JButton("Click Me");
        button.setBounds(50, 50, 100, 30);
        frame.add(button,BorderLayout.CENTER);
        
        frame.setVisible(true);
    }
}
