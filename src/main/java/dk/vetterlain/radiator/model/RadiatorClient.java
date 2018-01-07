package dk.vetterlain.radiator.model;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author joacim og zaeem
 */
public class RadiatorClient extends Thread {

    private Socket CLIENTSOCKET;
    private PrintWriter writer;
    public boolean isRunning = true;

    public RadiatorClient(String host, int port) {
        CLIENTSOCKET = new Socket();
        try {
            CLIENTSOCKET.connect(new InetSocketAddress(host, port));
            writer = new PrintWriter(CLIENTSOCKET.getOutputStream(), true);
        } catch (IOException ex) {
            ex.printStackTrace();
            System.out.println("exception!");
            isRunning = false;
        }

    }

    @Override
    public void run() {
        while (isRunning) {
        }
    }

    public void sendMessage(String message) {
        try {
            writer.println(message);
            writer.flush();
            CLIENTSOCKET.close();
            isRunning = false;
        } catch (IOException ex) {
            Logger.getLogger(RadiatorClient.class.getName()).log(Level.SEVERE, null, ex);
        }

    }
//
//    public String readMessage() throws IOException {
//        InputStream input = CLIENTSOCKET.getInputStream();
//        BufferedReader reader = new BufferedReader(new InputStreamReader(input));
//        return reader.readLine();
//    }
}
