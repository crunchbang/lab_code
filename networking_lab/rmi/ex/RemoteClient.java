import java.rmi.*;

public class RemoteClient {
    public static void main(String[] args) {
        new RemoteClient().go();
    }

    public void go() {
        try {
            RemoteOct service = (RemoteOct)Naming.lookup("rmi://127.0.0.1/RemoteOct");
            System.out.println("OCT:" + service.intToOct(8) + " " + service.intToOct(10));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
