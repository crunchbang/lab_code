
import java.net.*;
import java.io.*;

class TCPServer {
    public static void main(String[] args) throws IOException {
        System.out.println("Server Started");
        ServerSocket servSocket = null;

        try {
            servSocket = new ServerSocket(2000);
        }
        catch (IOException e) {
            System.out.println("Exception: " + e);
        }
        Socket socket = servSocket.accept();
        BufferedReader bufReader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        String inp;
        while (!(inp = bufReader.readLine()).equals("E") ) {
            System.out.println(inp);
            String rev;
            String[] words = inp.split("\\W");
            for (int i = 0; i < words.length; ++i) {
                rev = new StringBuffer(words[i]).reverse().toString();
                System.out.println("#" + words[i]);
                if (words[i].length() > 0 && rev.equals(words[i])) {
                    System.out.println("PALINDROME:" + rev);
                }
            }

        }

        bufReader.close();
        socket.close();
        servSocket.close();
    }
}
