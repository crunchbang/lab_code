import java.rmi.*;

public interface RemoteOct extends Remote {
    public String intToOct(int n) throws RemoteException;
}
