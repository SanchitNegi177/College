import java.awt.*;
import java.awt.event.*;

class Ques27 extends Frame 
{
    Label l1, l2, l3;
    TextField t1, t2;
    Button b1;

    public Ques27() 
    {
        setTitle("Login Page");
        setSize(400, 400);
        setLayout(new FlowLayout(FlowLayout.CENTER, 100, 20));
        setBackground(Color.cyan); 

        l1 = new Label("Enter the User ID");
        l2 = new Label("Enter your password");
        l3 = new Label();
        t1 = new TextField(20);
        t2 = new TextField(20);
        t2.setEchoChar('*');
        b1 = new Button("Log in");
        b1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String user = t1.getText();
                String pass = t2.getText();
                if (user.equals("Sid") && pass.equals("123")) 
                {
                    l3.setText("Welcome " + user);
                    setBackground(Color.GREEN);
                    }
                    else
                    {
                        l3.setText("Wrong User or password");
                        setBackground(Color.CYAN);
                        
                }
            }
        });

        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        setVisible(true);
        // b1.setBackground(Color.decode("#90EE90"));
        add(l1);
        add(t1);
        add(l2);
        add(t2);
        add(b1);
        add(l3); // Add l3 to the frame
    }

    public static void main(String[] args) {
        Ques27 q = new Ques27();
        System.out.println("********************************************************************************");
        System.out.println("Implemented by- Siddhartha Tomar \t RollNumber- 57 \t CS4(A2)");
        System.out.println("********************************************************************************");
    }
}
