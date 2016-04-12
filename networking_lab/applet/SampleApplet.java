import java.applet.*;
import java.awt.*;
import java.awt.event.*;

/*
 * <applet code="SampleApplet" height="300" width="300"></applet>
 */

public class SampleApplet extends Applet implements ActionListener {
    TextArea ta;
    Button button;
    
    public void init() {
        setLayout(new BorderLayout());
        ta = new TextArea(20, 20);
        ta.setEditable(false);
        button = new Button("Submit");
        add(BorderLayout.NORTH, ta);
        add(BorderLayout.SOUTH, button);
        button.addActionListener(this);

    }

    public void actionPerformed(ActionEvent ae) {
        ta.setText("Clicked");
    }
}
