import java.io.*;

class FileTest {
    public static void main(String[] args) {
        try {
            FileInputStream fin = new FileInputStream("x.jpg");
            FileOutputStream fout = new FileOutputStream("two.txt");
            int c;

            while ((c=fin.read())!=-1) fout.write(c);
        } catch(Exception e) {}

    }
}

