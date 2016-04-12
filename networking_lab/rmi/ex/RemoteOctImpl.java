import java.rmi.*;
import java.rmi.server.*;

public class RemoteOctImpl extends UnicastRemoteObject implements RemoteOct {
    public RemoteOctImpl() throws RemoteException {}

    public String intToOct(int n) {
        return Integer.toOctalString(n);
    }

    public static void main(String[] args) {
        try {
            RemoteOct rem = new RemoteOctImpl();
            Naming.rebind("RemoteOct", rem);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
