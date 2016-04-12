import java.net.*;
import java.io.*;

class AdviceServer {
    public String[] adviceList = { "Advice A", "Advice B", "Advice C" };

    void go() {
        try {
            ServerSocket servSocket = new ServerSocket(5000);
            while(true) {
                System.out.println("Listening on port 5000");
                Socket clientSocket = servSocket.accept();
                System.out.println("Accepted Connection on port 5000");
                PrintWriter writer = new PrintWriter(clientSocket.getOutputStream());
                String advice = getAdvice();
                writer.println(advice);
                writer.close();
                System.out.println("Connection closed on port 5000");
            }
        } catch(Exception e) {
            e.printStackTrace();
        }
    }

    String getAdvice() {
        int random = (int) (Math.random() * adviceList.length);
        return adviceList[random];
    }

    public static void main(String[] args) {
        AdviceServer adServ = new AdviceServer();
        adServ.go();
    }
}

