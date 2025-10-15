import java.net.*;  
import java.util.Scanner;  
  
public class _12_DNSLookup1 {  
    public static void main(String[] args) {  
        Scanner scanner = new Scanner(System.in);  
        int choice = 0;  
        System.out.println("===== DNS Lookup Tool =====");  
        do {  
            System.out.println("\nMenu:");  
            System.out.println("1. Find IP address from URL");  
            System.out.println("2. Find URL (hostname) from IP address");  
            System.out.println("3. Exit");  
            System.out.print("Enter your choice (1-3): ");  
            if (scanner.hasNextInt()) {  
                choice = scanner.nextInt();  
                scanner.nextLine();  // consume newline  
            } else {  
                System.out.println("Invalid input! Please enter a number between 1 and 3.");  
                scanner.nextLine();  // clear invalid input  
                continue;  
            }  
            try {  
                switch (choice) {  
                    case 1:  
                        System.out.print("Enter URL (e.g., www.google.com): ");  
                        String url = scanner.nextLine().trim();  
                        if (url.isEmpty()) {  
                            System.out.println("URL cannot be empty.");  
                            break;  
                        }  
                        InetAddress inetAddress = InetAddress.getByName(url);  
                        System.out.println("Host Name: " + inetAddress.getHostName());  
                        System.out.println("IP Address: " + inetAddress.getHostAddress());  
                        break;  
                    case 2:  
                        System.out.print("Enter IP address (e.g., 142.250.183.132): ");  
                        String ip = scanner.nextLine().trim();  
                        if (ip.isEmpty()) {  
                            System.out.println("IP address cannot be empty.");  
                            break;  
                        }  
                        InetAddress inetAddressByIP = InetAddress.getByName(ip);  
                        String hostName = inetAddressByIP.getHostName();  
  
                        if (hostName.equals(ip)) {  
                            System.out.println("No hostname found for IP " + ip + ". Reverse DNS lookup failed.");
                        } else {  
                            System.out.println("Hostname for IP " + ip + " is: " + hostName);  
                        }  
                        break;  
                    case 3:  
                        System.out.println("Exiting DNS Lookup Tool. Goodbye!");  
                        break;  
                    default:  
                        System.out.println("Invalid choice! Please select between 1 and 3.");  
                        break;  
                }  
            } catch (UnknownHostException e) {  
                System.out.println("Lookup failed: " + e.getMessage());  
            }  
  
        } while (choice != 3);  
        scanner.close();  
    }  
}  

//to run (run both commands)
//javac _12_DNSLookup1.java
//java _12_DNSLookup1 

//Note: keep the file name and the public class name similar to each other