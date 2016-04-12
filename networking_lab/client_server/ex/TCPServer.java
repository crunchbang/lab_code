import java.net.*;
import java.lang.*;
import java.io.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class TCPServer {
    JTextArea ta;
    JTextField tb;
    PrintWriter writer;
    BufferedReader reader;

    public static void main(String[] args) {
        new TCPServer().go();
    }

    void go() {
        JFrame frame = new JFrame("Server");
        JPanel panel = new JPanel();
        ta = new JTextArea(20, 20);
        ta.setEditable(false);
        tb = new JTextField(20);
        Button send = new Button("Send");
        send.addActionListener(new SendListener());
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
        panel.add(ta);
        panel.add(tb);
        panel.add(send);
        frame.getContentPane().add(panel);
        frame.setSize(300, 300);
        frame.setVisible(true);
        setUpNetworking();

    }

    void setUpNetworking() {
        try {
            ServerSocket servSocket = new ServerSocket(6000);
            System.out.println("Initialized at 5000");
            while (true) {
                System.out.println("Waiting for Connection");
                Socket socket = servSocket.accept();
                System.out.println("Connection Established");
                reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                writer = new PrintWriter(socket.getOutputStream());

                Thread t = new Thread(new ClientHandler());
                t.start();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }


    }

    class SendListener implements ActionListener {
        public void actionPerformed(ActionEvent ae) {
            String msg = tb.getText();
            ta.setText(ta.getText() + "\n" + msg);
            writer.println(msg);
            writer.flush();
            System.out.println("Sent:" + msg);
        }
    }

    public class ClientHandler implements Runnable {
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


