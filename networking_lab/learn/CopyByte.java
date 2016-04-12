/* ByteStreams
 * InputStream & OutputStream
 * FileInputStream & FileOutputStream
 */
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

class CopyByte {
    public static void main(String args[]) throws IOException {
        FileInputStream in = null;
        FileOutputStream out = null;

        try {
            in = new FileInputStream("xanadu.txt");
            out = new FileOutputStream("outagain.txt");
            int c;

            while((c = in.read()) != -1) {
                out.write(c);
            }
        } catch(Exception e) {
            System.out.println(e);
        } finally {
            if (in != null)
                in.close();
            if (out != null)
                out.close();
        }
    }
}
        

