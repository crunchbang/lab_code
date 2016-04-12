import java.rmi.*;

public class MyRemoteClient {
    public static void main(String[] args) {
        new MyRemoteClient().go();
    }

    public void go() {
        try {
            MyRemoteAdd service = (MyRemoteAdd)Naming.lookup("rmi://127.0.0.1/RemoteAdd");
            int x = service.add(1,2);
            System.out.println(x);
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}
