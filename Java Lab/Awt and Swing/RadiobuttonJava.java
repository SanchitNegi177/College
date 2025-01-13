// import java.awt.*;
// import java.awt.event.*;
// import javax.swing.*;

// public class RadiobuttonJava extends JFrame implements ItemListener {
//     String msg = "";
//     JRadioButton winXP, winVista, solaris, mac;
//     ButtonGroup group;

//     public RadiobuttonJava() {
//         // Set the layout and window title
//         setLayout(new FlowLayout());
//         setTitle("Radio Button Example");

//         // Initialize radio buttons
//         winXP = new JRadioButton("Windows XP");
//         winVista = new JRadioButton("Windows Vista");
//         solaris = new JRadioButton("Solaris");
//         mac = new JRadioButton("Mac OS");

//         // Group the radio buttons to make them mutually exclusive
//         group = new ButtonGroup();
//         group.add(winXP);
//         group.add(winVista);
//         group.add(solaris);
//         group.add(mac);
        

//         // Add radio buttons to the frame
//         add(winXP);
//         add(winVista);
//         add(solaris);
//         add(mac);

//         // Register item listeners
//         winXP.addItemListener(this);
//         winVista.addItemListener(this);
//         solaris.addItemListener(this);
//         mac.addItemListener(this);

//         // Frame settings
//         setSize(300, 200);
//         setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//         setVisible(true);
//     }

//     public void itemStateChanged(ItemEvent ie) {
//         // Trigger a repaint when an item state changes
//         repaint();
//     }

//     // Display current state of the radio buttons.
//     public void paint(Graphics g) 
//     {
//         super.paint(g); // Call the superclass's paint method

//         msg = "Current state: ";
//         g.drawString(msg, 20, 100);
//         msg = " Windows XP: " + winXP.isSelected();
//         g.drawString(msg, 20, 120);
//         msg = " Windows Vista: " + winVista.isSelected();
//         g.drawString(msg, 20, 140);
//         msg = " Solaris: " + solaris.isSelected();
//         g.drawString(msg, 20, 160);
//         msg = " Mac OS: " + mac.isSelected();
//         g.drawString(msg, 20, 180);
//     }

//     public static void main(String[] args) {
//         // Run the application
//         new RadiobuttonJava();
//     }
// }


import java.awt.*;
import java.awt.event.*;

public class RadiobuttonJava extends Frame implements ItemListener {
    String msg = "";
    Checkbox winXP, winVista, solaris, mac;
    CheckboxGroup group;

    public RadiobuttonJava() {
        // Set the layout and window title
        setLayout(new FlowLayout());
        setTitle("Radio Button Example");

        // Initialize the CheckboxGroup
        group = new CheckboxGroup();

        // Initialize checkboxes with the CheckboxGroup to make them mutually exclusive
        winXP = new Checkbox("Windows XP", group, false);
        winVista = new Checkbox("Windows Vista", group, false);
        solaris = new Checkbox("Solaris", group, false);
        mac = new Checkbox("Mac OS", group, false);

        // Add checkboxes to the frame
        add(winXP);
        add(winVista);
        add(solaris);
        add(mac);

        // Register item listeners
        winXP.addItemListener(this);
        winVista.addItemListener(this);
        solaris.addItemListener(this);
        mac.addItemListener(this);

        // Frame settings
        setSize(300, 200);
        setVisible(true);

        // Window close event
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });
    }

    // public void itemStateChanged(ItemEvent ie) {
    //     // Trigger a repaint when an item state changes
    //     // repaint();
    // }

    // Display current state of the checkboxes.
    public void paint(Graphics g) {
        super.paint(g); // Call the superclass's paint method

        msg = "Current state: ";
        g.drawString(msg, 20, 100);
        msg = " Windows XP: " + winXP.getState();
        g.drawString(msg, 20, 120);
        msg = " Windows Vista: " + winVista.getState();
        g.drawString(msg, 20, 140);
        msg = " Solaris: " + solaris.getState();
        g.drawString(msg, 20, 160);
        msg = " Mac OS: " + mac.getState();
        g.drawString(msg, 20, 180);
    }

    public static void main(String[] args) {
        // Run the application
        new RadiobuttonJava();
    }
}
