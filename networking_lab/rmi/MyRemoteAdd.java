import java.rmi.*;

public interface MyRemoteAdd extends Remote {
    public int add(int a, int b) throws RemoteException;
}
