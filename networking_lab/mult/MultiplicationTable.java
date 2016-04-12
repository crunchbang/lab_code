
class MultiplicationTable {
    public MultiplicationTable mult;
    public static void main(String[] args) {
        new MultiplicationTable().go();
    }

    void go() {
        mult = new MultiplicationTable();
        int i = 6;
        for (int j = 0; j < 4; ++j) {
            Thread t = new Thread(new PrintTable(i+j));
            t.start();
            try {
                Thread.currentThread().sleep(100);
            } catch(Exception e) {}
        }
    }

    public synchronized void showTable(int num) {
        for (int i = 1; i <= 5; ++i)
            System.out.println(num + "*" + i + "=" + num*i);
    }

    public class PrintTable implements Runnable {
        int num;

        PrintTable(int num) {
            this.num = num;
        }

        public void run() {
            mult.showTable(num);
        }

    }
}

