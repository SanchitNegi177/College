import java.awt.*;
import java.awt.event.*;

class Ques29 extends Frame implements ActionListener 
{

    Label lblCityName;
    TextField txtCityName;
    TextArea Ques29;
    Button btnAdd, btnExit;

    Ques29() 
    {
        setSize(400, 200);
        setTitle("City List");
        setLayout(new FlowLayout(FlowLayout.CENTER, 10, 10));

        lblCityName = new Label("City Name:");
        txtCityName = new TextField(20);
        add(lblCityName);
        add(txtCityName);
        Ques29 = new TextArea(5, 20);
        Ques29.setEditable(false); // Disable editing the list
        add(Ques29);
        // Panel btnPanel = new Panel(new GridLayout(1,2, 10, 10));
        btnAdd = new Button("Add >>");
        btnExit = new Button("Exit");
        // btnPanel.add(btnAdd);
        // btnPanel.add(btnExit);
        // add(btnPanel);
        add(btnAdd);
        add(btnExit);

        btnAdd.addActionListener(this);
        btnExit.addActionListener(this);
        setVisible(true);
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });
    }

    @Override
    public void actionPerformed(ActionEvent e) 
    {
        if (e.getSource() == btnAdd) 
        {
            String cityName = txtCityName.getText().trim();
            if (!cityName.isEmpty()) 
            {
                Ques29.append(cityName + "\n"); // Add city name to the list with a newline
                txtCityName.setText(""); // Clear the text field
            }
        } 
        else if (e.getSource() == btnExit) 
        {
            String text = Ques29.getText().trim();
            if(text.length()!=0)
            {
                int lastNewLine = text.lastIndexOf('\n');
                if (lastNewLine >= 0) 
                {
                    Ques29.setText(text.substring(0, lastNewLine)); // Remove the last city from the list
                }
            }
        }
    }

    public static void main(String[] args) {
        new Ques29();
        System.out.println("********************************************************************************");
        System.out.println("Implemented by- Siddhartha Tomar \t RollNumber- 57 \t CS4(A2)");
        System.out.println("********************************************************************************");
    }
}
