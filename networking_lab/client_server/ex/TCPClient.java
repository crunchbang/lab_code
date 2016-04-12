import java.net.*;
import java.lang.*;
import java.io.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class TCPClient {
    JTextArea ta;
    JTextField tb;
    JPanel panel;
    JButton open, send;
    JFileChooser fc;
    PrintWriter writer;
    BufferedReader reader;

    public static void main(String[] args) {
        new TCPClient().go();
    }

    void go() {
        JFrame frame = new JFrame("Client");
        panel = new JPanel();
        ta = new JTextArea(20, 20);
        ta.setEditable(false);
        tb = new JTextField(20);
        send = new JButton("Send");
        open = new JButton("Open");
        fc = new JFileChooser();
        send.addActionListener(new SendListener());
        open.addActionListener(new SendListener());
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
        panel.add(ta);
        panel.add(tb);
        panel.add(send);
        panel.add(open);
        frame.getContentPane().add(panel);
        frame.setSize(300, 300);
        frame.setVisible(true);
        setUpNetworking();

    }

    void setUpNetworking() {
        Socket socket;
        try {
            socket = new Socket("127.0.0.1", 6000);
            System.out.println("Connection Established");
            reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            writer = new PrintWriter(socket.getOutputStream());
            
            Thread t = new Thread(new ServerHandler());
            t.start();


        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    class SendListener implements ActionListener {
        public void actionPerformed(ActionEvent ae) {
            if (ae.getSource() == send) {
                String msg = tb.getText();
                ta.setText(ta.getText() + "\n" + msg);
                writer.println(msg);
                writer.flush();
                System.out.println("Sent:" + msg);
            } else if (ae.getSource() == open) {
                int returnVal = fc.showOpenDialog(null);
                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    System.out.println("File:" + fc.getSelectedFile());
                    System.out.println("FileName:" + fc.getSelectedFile().getName());
                    ImageIcon image = new ImageIcon(fc.getSelectedFile().toString());
                    JLabel label = new JLabel("", image, JLabel.CENTER);
                    panel.add(label);
                }

            }
        }
    }

    public class ServerHandler implements Runnable {
        public void run() {
            try {
                String msg;
                while ((msg = reader.readLine()) != null) {
                    System.out.println("Received:" + msg);
                    ta.setText(ta.getText() + "\n" + msg);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

}


