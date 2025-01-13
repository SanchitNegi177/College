import java.awt.*;
import java.awt.event.*;

public class ListExample extends Frame implements ActionListener, ItemListener {
    List itemList;
    Label selectedItemLabel;
    Button showButton;

    public ListExample() {
        // Set the layout and window title
        setLayout(new FlowLayout());
        setTitle("AWT List Example");

        // Initialize the List component
        itemList = new List(5, false); // 5 visible rows, single selection
        itemList.add("Item 1");
        itemList.add("Item 2");
        itemList.add("Item 3");
        itemList.add("Item 4");
        itemList.add("Item 5");

        // Initialize the Label to display selected item
        selectedItemLabel = new Label("Selected Item: None");

        // Initialize the Button
        showButton = new Button("Show Selected Item");
        
        // Add components to the frame
        add(itemList);
        add(showButton);
        add(selectedItemLabel);

        // Register listeners
        itemList.addItemListener(this);
        showButton.addActionListener(this);

        // Frame settings
        setSize(400, 300);
        setVisible(true);

        // Window close event
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });
    }

    @Override
    public void itemStateChanged(ItemEvent ie) {
        // Handle item selection changes
        String selectedItem = itemList.getSelectedItem();
        selectedItemLabel.setText("" + selectedItem);
    }

    @Override
    public void actionPerformed(ActionEvent ae) {
        // Handle button click
        String selectedItem = itemList.getSelectedItem();
        if (selectedItem != null) {
            selectedItemLabel.setText("Selected Item: " + selectedItem);
        } else {
            selectedItemLabel.setText("Selected Item: None");
        }
    }

    public static void main(String[] args) {
        // Run the application
        new ListExample();
    }
}
