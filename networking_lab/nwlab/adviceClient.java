import java.net.*;
import java.io.*;

class adviceClient {

    void go() {
        try {
            System.out.println("Connecting to Server on 5000");
            Socket socket = new Socket("127.0.0.1", 5000);
            InputStreamReader stream = new InputStreamReader(socket.getInputStream());
            BufferedReader reader = new BufferedReader(stream);
            String advice = reader.readLine();
            System.out.println("Client:" + advice);
            reader.close();
        } catch(Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        adviceClient client = new adviceClient();
        client.go();
    }
}
