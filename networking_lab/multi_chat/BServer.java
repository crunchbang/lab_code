import java.io.*;
import java.util.*;
import java.net.*;

public class BServer {
    ArrayList<PrintWriter> writers;
    ServerSocket servSoc;
    int i;

    public static void main(String[] args) {
        new BServer().go();
    }

    void go() {
        i = 0;
        writers = new ArrayList<PrintWriter>();

        try {
            servSoc = new ServerSocket(5000);
            Thread t = new Thread(new HandleClient());
            t.start();
        } catch(Exception e) {
            e.printStackTrace();
        }

    }

    void broadcastMessage(String msg) {
        try {
            Iterator<PrintWriter> it = writers.iterator();
            PrintWriter wr;
            System.out.println("Broadcast");
            while(it.hasNext()) {
                wr = it.next();
                wr.println(msg);
                wr.flush();
            }
        } catch(Exception e) {
            e.printStackTrace();
        }
    }

    public class HandleClient implements Runnable {
        BufferedReader reader;

        public void run() {
            try {
                while(true) {
                    Socket socket = servSoc.accept();
                    System.out.println("Connection Accepted");
                    writers.add(new PrintWriter(socket.getOutputStream()));
                    reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                    Thread t = new Thread(new HandleClientMessage(reader));
                    t.start();
                }
            } catch(Exception e) {
                e.printStackTrace();
            }
        }
    }

    public class HandleClientMessage implements Runnable {
        BufferedReader reader;
        String msg;

        HandleClientMessage(BufferedReader reader) {
            this.reader = reader;
        }
        public void run() {
            try {
                while (true) {
                    msg = reader.readLine();
                    if (msg != null) {
                        System.out.print("Message:");
                        System.out.println(msg);
                        broadcastMessage(msg);
                    }
                }
            } catch(Exception e) {
                e.printStackTrace();
            }
        }
    }
}
