import java.net.*;

/**
 * Should do:
 * 1. Sends a message to the server
 * 2. Receives the message and decodes it
 * 3. Prints the message
 */
public class hennilu {
    private static final int PACKET_SIZE = 256;
    private static final int PORT        = 3950;
    private static final String HOST     = "localhost";

    public static void main(String[] args) {
        System.out.println("Hello, world!");

        DatagramSocket socket = null;

        try {
            /* Create the host */
            InetAddress serverIP = InetAddress.getByName(HOST);

            /* Make the socket */
            socket = new DatagramSocket();

            /* Test the socket -- REMOVE -- */
            byte[] data = "Hello Server".getBytes();
            DatagramPacket packet = new DatagramPacket(data, data.length, serverIP, PORT);

            /* Ship it! */
            socket.send(packet);

            /* Set a timeout to 5 seconds */
            socket.setSoTimeout(5000);

            /* Prep the receive of a packet */
            packet.setData(new byte[PACKET_SIZE]);

            /* Await response */
            socket.receive(packet);

            /* Decode and print the response */
            System.out.println("Response form server: " + new String(packet.getData()).reverse());

        } catch (Exception dgramException) {
            System.out.println("Failed datagram exception!");
            dgramException.printStackTrace();
        } finally {
            if (socket != null) {
                socket.close();
            }
        }
    }

    public static String decode(String msg) {
        if (msg != null && !msg.equals("")) {
            return msg;
        }
    }
}
