import java.io.*;
import java.util.*;
import java.net.*;

class SimpleChatServer {
    ArrayList<PrintWriter> clientOutputStreams;

    public static void main(String[] args) {
        SimpleChatServer server = new SimpleChatServer();
        server.go();
    }

    public void go() {
        clientOutputStreams = new ArrayList<PrintWriter>();
        PrintWriter writer;
        try {
            ServerSocket servSoc = new ServerSocket(5000);
            Socket soc;
            while (true) {
                System.out.println("Waiting for connection");
                soc = servSoc.accept();
                writer = new PrintWriter(soc.getOutputStream());
                clientOutputStreams.add(writer);
                informAllClients("Client Added");
                Thread t = new Thread(new ClientHandler(soc));
                t.start();
            }
        } catch(Exception e) {
            e.printStackTrace();
        }
    }

    public class ClientHandler implements Runnable {
        BufferedReader reader;
        Socket soc;
        
        ClientHandler(Socket clientSoc) {
            try {
                soc = clientSoc;
                InputStreamReader stream = new InputStreamReader(soc.getInputStream());
                reader = new BufferedReader(stream);
                System.out.println("Connection Established");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        public void run() {
            String msg;
            try {
                while((msg = reader.readLine()) != null) {
                    System.out.println("Read " + msg);
                    informAllClients(msg);
                }
            } catch(Exception e) {
                e.printStackTrace();
            }
        }
    }

    public void informAllClients(String message) {
        Iterator<PrintWriter> it = clientOutputStreams.iterator();
        try {
            while (it.hasNext()) {
                PrintWriter wr = it.next();
                wr.println(message);
                wr.flush();
            }
            System.out.println("Sent to all");
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
