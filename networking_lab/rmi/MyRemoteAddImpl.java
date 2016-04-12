import java.rmi.*;
import java.rmi.server.*;


public class MyRemoteAddImpl extends UnicastRemoteObject implements MyRemoteAdd {

    public MyRemoteAddImpl() throws RemoteException { }

    public int add(int a, int b) {
        return a+b;
    }

    public static void main(String[] args) {
        try {
            MyRemoteAdd remObj = new MyRemoteAddImpl();
            Naming.rebind("RemoteAdd", remObj);
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
