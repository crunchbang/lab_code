
class Mult {

    public static void main(String[] args) {
        new Mult().go();
    }

    void go() {
        for (int i = 1; i < 5; ++i) {
            Thread t = new Thread(new HandleTable(i+5));
            t.start();
            try {
                Thread.currentThread().sleep(100);
            } catch(Exception e) {
                e.printStackTrace();
            }
        }
    }

    public static synchronized void showTable(int n) {
        for (int i = 1; i <= 10; ++i)
            System.out.println(n + " * " + i + " = " + n*i);
    }
}

class HandleTable implements Runnable {
    int n;
    HandleTable(int n) {
        this.n = n;
    }
    public void run() {
        Mult.showTable(n);
    }
}
