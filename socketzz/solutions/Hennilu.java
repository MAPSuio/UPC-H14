// @EXPECTED_RESULTS@: CORRECT

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;
import java.util.*;
import java.io.*;

/**
 * Should do:
 * 1. Sends a message to the server
 * 2. Receives the message and decodes it
 * 3. Prints the message
 */
public class Hennilu {
    private static final int PACKET_SIZE = 256;
    private static final int PORT        = 3950;
    private static final int PADDING     = 4;
    private static final int BYTE        = 8;
    private static final String HOST     = "localhost";
    private static Scanner stdin;

    public static void main(String[] args) {
        System.out.println("Hello, world!");
        byte length;
        byte type;
        byte input1;
        byte input2;

        DatagramSocket socket = null;

        /* Whole lotta shit happens here */
        try {
            length = 0x04; // Bogus data
            type   = 0x02; // Bogus data

            stdin = new Scanner(System.in);

            System.out.print("input1: ");
            input1 = getInput();
            System.out.print("input2: ");
            input2 = getInput();

            /* Create the host */
            InetAddress serverIP = InetAddress.getByName(HOST);

            /* Make the socket */
            socket = new DatagramSocket();
            
            /* Test the socket -- REMOVE -- */
            byte[] data = {length, type, input1, input2};
            DatagramPacket packet = new DatagramPacket(data, data.length, serverIP, PORT);
            System.out.println("PACKET INPUT1 SENT: " + (int) data[2]);
            System.out.println("PACKET INPUT2 SENT: " + (int) data[3]);

            /* Ship it! */
            socket.send(packet);

            /* Set a timeout to 5 seconds */
            socket.setSoTimeout(5000);

            /* Prep the receive of a packet */
            packet.setData(new byte[PACKET_SIZE]);

            /* Await response */
            socket.receive(packet);

            /* Decode and print the response */
            System.out.println("Response form server using method1: " + method1(packet));
            System.out.println("Response form server using method2: " + method2(packet));

        } catch(IOException scn) {
            System.out.println("Scanner exception!");
            scn.printStackTrace();
        } catch (Exception networkException) {
            System.out.println("Failed network exception!");
            networkException.printStackTrace();
        } finally {
            if (socket != null) {
                socket.close();
            }
        }
    }

    /**
     * Takes in a packet and uses substrings to return a string
     * @return A new string containing only the hash
     */
    public static String method1(DatagramPacket packet) {
        String encodedData = new String(packet.getData());
        return encodedData.substring(PADDING);
    }

    /**
     * Takes in a packet and uses iterative adding to return a string
     * @return A new string containing only the hash
     */
    public static String method2(DatagramPacket packet) {
        byte[] tester = packet.getData();
        byte[] byteResult = new byte[PACKET_SIZE - PADDING];
        int byteCounter = 0;

        for (int i = PADDING; i < tester.length; i++) {
            byteResult[byteCounter++] += tester[i];
        }
        return new String(byteResult);

    }

    /**
     * Reads in input1 and input2 required to send a valid message to the server
     * @return
     * @throws IOException
     */
    public static byte getInput() throws IOException {
        int input = stdin.nextInt();
        stdin.nextLine();
        return (byte) input;
    }
}
