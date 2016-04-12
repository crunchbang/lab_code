import java.net.*;
import java.io.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class SimpleChatClientA {
    JTextArea incoming;
    JTextField outgoing;
    BufferedReader reader;
    PrintWriter writer;
    Socket sock;

    public static void main(String[] args) {
        SimpleChatClientA client = new SimpleChatClientA();
        client.go();
    }

    public void go() {
        JFrame frame = new JFrame("Incredibly simple Chat Client");
        JPanel panel = new JPanel();
        outgoing = new JTextField(20);
        incoming = new JTextArea(15, 50);
        JButton send = new JButton("Send");
        send.addActionListener(new SendButtonListener());
        panel.add(incoming);
        panel.add(outgoing);
        panel.add(send);

        frame.getContentPane().add(BorderLayout.CENTER, panel);
        setUpNetworking();

        Thread readerThread = new Thread(new IncomingReader());
        readerThread.start();

        frame.setSize(500, 500);
        frame.setVisible(true);
    }

    public void setUpNetworking() {
        try {
            sock = new Socket("127.0.0.1", 5000);
            InputStreamReader stream = new InputStreamReader(sock.getInputStream());
            reader = new BufferedReader(stream);
            writer = new PrintWriter(sock.getOutputStream());
            System.out.println("Connection Established");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public class IncomingReader implements Runnable {
        public void run() {
            try {
                String msg;
                while ((msg = reader.readLine()) != null) {
                    System.out.println("read " + msg);
                    incoming.append("\n" + msg);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public class SendButtonListener implements ActionListener {
        public void actionPerformed(ActionEvent ae) {
            try {
                writer.println(outgoing.getText());
                writer.flush();
            } catch (Exception e) {
                e.printStackTrace();
            }
            outgoing.setText("");
            outgoing.requestFocus();

        }
    }
}



