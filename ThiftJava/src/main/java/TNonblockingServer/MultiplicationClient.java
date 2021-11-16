/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package TNonblockingServer;

/**
 *
 * @author lap14784
 */
import java.util.ArrayList;
import java.util.Random;
import org.apache.thrift.TException;
import org.apache.thrift.protocol.TBinaryProtocol;
import org.apache.thrift.protocol.TProtocol;
import org.apache.thrift.transport.TSocket;
import org.apache.thrift.transport.layered.TFramedTransport;

class RunThreadClient implements Runnable {

    MultiplicationService.Client _client = null;

    public RunThreadClient(MultiplicationService.Client client) {
        this._client = client;
    }

    @Override
    public void run() {
        Random rand = new Random();
        int num1 = 1;//rand.nextInt((100) + 1);
        int num2 = 2;
        rand.nextInt((100) + 1);

        System.out.println("Send multiplycation request to server... ");

        int result;
        if (this._client != null) {
            try {
                for (int i = 1; i <49; i++) {
                    result = this._client.multiply(i, i);
                    System.out.println(String.format("Server has response. Result is %d", result));
                }

            } catch (TException ex) {
                java.util.logging.Logger.getLogger(RunThreadClient.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
            }
        } else {
            System.out.println(String.format("Client null"));
        }
    }

}

public class MultiplicationClient {

    public static void main(String[] args) throws InterruptedException {

        try {
            ArrayList<TFramedTransport> listTransport = new ArrayList<>();
            ArrayList<Thread> listThread = new ArrayList<>();
            for (int i = 0; i < 10; i++) {
                listTransport.add(new TFramedTransport(new TSocket("localhost", 1234)));
                TProtocol protocol = new TBinaryProtocol(listTransport.get(i));
                MultiplicationService.Client client = new MultiplicationService.Client(protocol);
                listThread.add(new Thread(new RunThreadClient(client)));
            }
            for (TFramedTransport trans : listTransport) {
                trans.open();
            }
            for (Thread thread : listThread) {
                thread.start();
            }
            int i = 0;
            for (Thread thread : listThread) {
                thread.join();
                System.out.println(String.format("Thread %d", i));
                i += 1;
            }
            for (TFramedTransport trans : listTransport) {
                trans.close();
            }

        } catch (TException x) {
            x.printStackTrace();
        }
    }
}
