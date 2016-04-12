
import java.net.*;
import java.io.*;

class TCPClient {
    public static void main(String[] args) throws IOException {
        System.out.println("Client Started");
        Socket socket = null;
        PrintWriter toServ = null;
        try {
            socket = new Socket(InetAddress.getLocalHost(), 2000);
            toServ = new PrintWriter(socket.getOutputStream(), true);
        }
        catch (IOException e) {
            System.out.println("Exception: " + e);
        }
        BufferedReader fromUser = new BufferedReader(new FileReader("test.txt"));
        String msg;
        while ((msg = fromUser.readLine()) != null) {
            toServ.println(msg);
            toServ.flush();
        }
        toServ.println("E");
        toServ.flush();

        toServ.close();
        socket.close();

    }
}
