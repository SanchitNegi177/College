import java.awt.*;
import java.awt.event.*;

public class AWTJAVA extends Frame 
// public class AWTJAVA extends Frame implements ActionListener
 {
    private Label lblCount;
    private TextField tfCount;
    private Button btnCount;
    private int count = 0;

    public AWTJAVA() 
    {
        setLayout(new FlowLayout());
        lblCount = new Label("Counter");
        add(lblCount);
        tfCount = new TextField("0", 10);
        tfCount.setEditable(false);
        add(tfCount);
        btnCount = new Button("Count");
        add(btnCount);
        // btnCount.addActionListener(this);

        btnCount.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                ++count;
                tfCount.setText(count + "");
            }
        });

        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                dispose(); // Dispose of the frame
                System.exit(0); // Exit the application
            }
        });

        
        setTitle("AWT Counter");
        setSize(250, 100);
        setVisible(true);
    }

    // public void actionPerformed(ActionEvent evt) 
    // {
    //     ++count;
    //     tfCount.setText(count + "");
    // }

    public static void main(String[] args) 
    {
        new AWTJAVA();
    }
}


// import javax.swing.*;
// import java.awt.*;
// import java.awt.event.*;

// public class AWTJAVA extends JFrame {
//     private JLabel lblCount;
//     private JTextField tfCount;
//     private JButton btnCount;
//     private int count = 0;

//     public AWTJAVA() {
//         setLayout(new FlowLayout());

//         lblCount = new JLabel("Counter");
//         add(lblCount);

//         tfCount = new JTextField("0", 10);
//         tfCount.setEditable(false);
//         add(tfCount);

//         btnCount = new JButton("Count");
//         add(btnCount);

//         btnCount.addActionListener(evt -> {
//             ++count;
//             tfCount.setText(Integer.toString(count));
//         });

//         setTitle("Swing Counter");
//         setSize(250, 100);
//         setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//         setVisible(true);
//     }

//     public static void main(String[] args) {
//         new AWTJAVA();
//     }
// }
