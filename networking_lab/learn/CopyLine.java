/* Line I/O
 * BufferedReader & PrintWriter
 */

/* Until now:
 * InputStream & OutputStream -> ByteStream 
 *                               FileInputStream 
 *                               FileOutputStream
 * Reader & Writer -> CharacterStream
 *                      FileReader
 *                      FileWriter
 */
import java.io.FileReader;
import java.io.FileWriter;;
import java.io.BufferedReader;;
import java.io.PrintWriter;;
import java.io.IOException;

class CopyLine {
    public static void main(String args[]) throws IOException {
        BufferedReader in = null;
        PrintWriter out = null;

        try {
            in = new BufferedReader(new FileReader("xanadu.txt"));
            out = new PrintWriter(new FileWriter("outline.txt"));

            String l;
            while((l = in.readLine()) != null) {
                out.println(l);
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
        

