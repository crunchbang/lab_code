/* CharacterStream
 * Reader & Writer
 * FileReader & FileWriter
 */
import java.io.FileReader;
import java.io.FileWriter;;
import java.io.IOException;

class CopyCharacter {
    public static void main(String args[]) throws IOException {
        FileReader in = null;
        FileWriter out = null;

        try {
            in = new FileReader("xanadu.txt");
            out = new FileWriter("outagain.txt");
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
        

