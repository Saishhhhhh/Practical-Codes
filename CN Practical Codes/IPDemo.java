import java.net.*;
import java.util.*;

public class IPDemo {
    public static void main(String[] args) {
        Scanner ch = new Scanner(System.in); // Scanner to read user input
        System.out.print("1. Enter Host Name\n2. Enter IP Address\nChoice = "); 
        int choice = ch.nextInt(); // Read user's choice (1 or 2)
        ch.nextLine(); // Consume leftover newline after nextInt()

        String host;
        System.out.println(); // Print a blank line

        try {
            if (choice == 1) {
                System.out.print("Enter host name: ");
                host = ch.nextLine(); // Read host name (e.g., google.com)

                InetAddress address = InetAddress.getByName(host); // Resolve hostname to IP
                System.out.println("IP Address: " + address.getHostAddress()); // Print resolved IP
                System.out.println("Host Name : " + address.getHostName()); // Print hostname
                System.out.println("Host + IP : " + address.toString()); // Print full info
            } else if (choice == 2) {
                System.out.print("Enter IP address: ");
                host = ch.nextLine(); // Read IP address (e.g., 8.8.8.8)

                InetAddress address = InetAddress.getByName(host); // Resolve IP to hostname
                System.out.println("Host Name : " + address.getHostName()); // Print hostname
                System.out.println("IP Address: " + address.getHostAddress()); // Print IP address
                System.out.println("Host + IP : " + address.toString()); // Full info
            } else {
                System.out.println("Invalid choice. Please enter 1 or 2."); // Invalid input handling
            }
        } catch (UnknownHostException ex) { // Handles cases where lookup fails
            System.out.println("Could not find: " + ex.getMessage());
        }

        ch.close(); // Close scanner
    }
}

//to run (run both commands)
//javac IPDemo.java   // Compiles the program
//java IPDemo         // Runs the program

//Note: keep the file name and the public class name similar to each other

//Example inputs:
//1
//google.com

//2
//8.8.8.8