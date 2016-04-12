import java.io.*;
import java.io.Console;
import java.io.IOException;
import java.util.Arrays;

class TestInput {
    public static void main(String args[]) {
        Console c = System.console();
        if (c == null) {
            System.err.println("Error");
            System.exit(1);
        }
    String login = c.readLine("Enter your username:");
    System.out.println("username " + login);
    }

}


