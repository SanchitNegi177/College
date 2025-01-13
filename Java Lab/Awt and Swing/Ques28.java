import java.awt.*;
import java.awt.event.*;

public class Ques28 extends Frame implements ActionListener {
    Label countryLabel, capitalLabel, resultLabel;
    Choice countryChoice, capitalChoice;
    Button checkButton;
    String[] countries = { "India", "USA", "Japan", "Germany" };
    String[] capitals = { "New Delhi", "Washington D.C.", "Tokyo", "Berlin" };

    public Ques28() 
    {
        setTitle("Country Capital Quiz");
        setLayout(new FlowLayout(FlowLayout.CENTER,100,20));

        countryLabel = new Label("Select a country:");
        add(countryLabel);

        countryChoice = new Choice();
        for (String country : countries) 
        {
            countryChoice.add(country);
        }
        add(countryChoice);

        capitalLabel = new Label("Select its capital:");
        add(capitalLabel);

        capitalChoice = new Choice();
        for (String capital : capitals) 
        {
            capitalChoice.add(capital);
        }
        add(capitalChoice);

        checkButton = new Button("Check Answer");
        add(checkButton);

        resultLabel = new Label("");
        add(resultLabel);

        checkButton.addActionListener(this);

        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        setSize(300, 150);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) 
    {
        // resultLabel.setText("");
        String selectedCountry = countryChoice.getSelectedItem();
        String selectedCapital = capitalChoice.getSelectedItem();
        int index = -1;
        for (int i = 0; i < countries.length; i++) 
        {
            if (countries[i].equals(selectedCountry) ) 
            {
                index = i;
                break;
            }
        }
        if (capitals[index].equals(selectedCapital)) 
        {
            resultLabel.setText("Correct answer");
        } 
        else 
        {
            resultLabel.setText("Wrong answer. The correct answer is " + capitals[index]);
        }

    }

    public static void main(String[] args) {
        new Ques28();
        System.out.println("********************************************************************************");
        System.out.println("Implemented by- Siddhartha Tomar \t RollNumber- 57 \t CS4(A2)");
        System.out.println("********************************************************************************");
    }
}
