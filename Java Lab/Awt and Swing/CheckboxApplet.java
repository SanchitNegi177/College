import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class CheckboxApplet extends JFrame implements ItemListener {
    JLabel l1, l2, l3, l4;
    JCheckBox winXP, winVista, solaris, mac;

    public CheckboxApplet() {
        // Set the layout and window title
        setLayout(new FlowLayout());
        setTitle("Checkbox Example");

        // Initialize checkboxes
        winXP = new JCheckBox("Windows XP");
        winVista = new JCheckBox("Windows Vista");
        solaris = new JCheckBox("Solaris");
        mac = new JCheckBox("Mac OS");

        // Add checkboxes to the frame
        add(winXP);
        add(winVista);
        add(solaris);
        add(mac);

        // Initialize labels
        l1 = new JLabel("XP: " + winXP.isSelected());
        l2 = new JLabel("Vista: " + winVista.isSelected());
        l3 = new JLabel("Solaris: " + solaris.isSelected());
        l4 = new JLabel("MAC: " + mac.isSelected());

        // Add labels to the frame
        add(l1);
        add(l2);
        add(l3);
        add(l4);

        // Register item listeners
        winXP.addItemListener(this);
        winVista.addItemListener(this);
        solaris.addItemListener(this);
        mac.addItemListener(this);

        // Frame settings
        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void itemStateChanged(ItemEvent ie) {
        // Update label texts based on checkbox states
        l1.setText("XP: " + winXP.isSelected()+"\t");
        l2.setText("Vista: " + winVista.isSelected()+"\t");
        l3.setText("Solaris: " + solaris.isSelected()+"\t");
        l4.setText("MAC: " + mac.isSelected()+"\t");
        // repaint();
    }
    // public void actionPerformed(ActionEvent ie) {
    //     // Update label texts based on checkbox states
    //     l1.setText("XP: " + winXP.isSelected()+"\t");
    //     l2.setText("Vista: " + winVista.isSelected()+"\t");
    //     l3.setText("Solaris: " + solaris.isSelected()+"\t");
    //     l4.setText("MAC: " + mac.isSelected()+"\t");
    //     // repaint();
    // }

    public static void main(String[] args) {
        // Run the application
        new CheckboxApplet();
    }
}
