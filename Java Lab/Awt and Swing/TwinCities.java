import java.awt.*; 
import java.awt.event.*; 
public class TwinCities extends Frame implements ActionListener 
{ 
List tl, gl, ml, al; // 4 lists to add to a container that implements card layout 
Button fb, lb, nb, pb; // 4 buttons to navigate the cards of the container 
CardLayout cl; 
Panel sp, bp; // 2 panels to add lists and buttons 
public TwinCities() 
{ 
super("Welcome"); // title to Frame 
 tl = new List(4); // instantiate list objects 
 gl = new List(4); 
 ml = new List(4); 
 al = new List(4); 
 
 // populate theaters list 
 tl.add("Sudersan complex"); 
 tl.add("Sandhya complex"); 
 tl.add("Odeon complex"); 
 tl.add("Ramakrishana Estate"); 
 tl.add("IMAX 70MM"); 
 tl.add("Surya 35MM"); 
 tl.add("Shanthi 70MM"); 
 // populate gardens list 
 gl.add("Indira Park"); 
 gl.add("Lumbibi Park"); 
 gl.add("Sanjivayya Park"); 
 gl.add("Zoo Park"); 
 gl.add("Public Gardens"); // populate monuments list 
 ml.add("Chiran Palace"); 
 ml.add("Falaknuma Palace"); 
 ml.add("Charminar"); 
 ml.add("QQ Tombs"); 
 ml.add("Golconda Fort"); 
 ml.add("Zuma Majid"); 
 // populate special attractions list 
 al.add("Birla Mandir"); 
 al.add("Planetorium"); 
 al.add("Hi-Tech city"); 
 al.add("Buddha Purnima"); 
 al.add("Ramoji Filmcity"); 
 al.add("Shilparamam"); 
 
 cl = new CardLayout(); // create a card layout object 
 sp = new Panel(); 
 // create a panel to add all the lists 
 sp.setLayout(cl); // set the layout to panel, sp 
 sp.add(tl, "t"); 
 // add lists to panel 
 sp.add(gl, "g"); 
 sp.add(ml, "m"); 
 // the string parameter is for show() later 
 sp.add(al, "a"); 
 // instantiate buttons 
 fb = new Button("First Button"); 
 lb = new Button("Last Button"); 
 nb = new Button("Next Button"); 
 pb = new Button("Previous Button"); 
 bp = new Panel() ; 
 // create a panel to add buttons 
 bp.setLayout(new GridLayout(1, 4)); // set layout to bp panel 
 bp.add(fb); 
 // add each button to panel 
 bp.add(nb); 
 bp.add(pb); 
 bp.add(lb); 
 fb.addActionListener(this); 
 // register the buttons with listener 
 nb.addActionListener(this); 
 pb.addActionListener(this); 
 lb.addActionListener(this); 
 add(bp, "South"); 
 // add panels to frame 
 add(sp, "Center"); 
 setSize(300, 300); 
 setVisible(true) ; 
} 
public void actionPerformed(ActionEvent e) 
{ 
String str = e.getActionCommand(); 
 if(str.equals("First Button")) 
 cl.first(sp) ; 
 else if(str.equals("Next Button")) 
 cl.next(sp); 
 else if(str.equals("Previous Button")) 
 cl.previous(sp); 
 else if(str.equals("Last Button")) 
 cl.last(sp); 
 
 } 
public static void main(String args[]) 
{ 
new TwinCities(); 
} 
}
