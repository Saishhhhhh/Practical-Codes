// Write a program to implement MySQL/Oracle database connectivity with any front end language to
// implement Database navigation operations (add, delete, edit etc.)

import java.sql.*;
import java.util.Scanner;

public class EmployeeDatabase {
    private static final String URL = "jdbc:mysql://localhost:3306/testDB";
    private static final String USER = "root";
    private static final String PASSWORD = "password";

    public static Connection connectToMySQL() {
        try {
            // Load MySQL JDBC driver
            Class.forName("com.mysql.cj.jdbc.Driver");
            // Establish connection
            return DriverManager.getConnection(URL, USER, PASSWORD);
        } catch (ClassNotFoundException e) {
            System.out.println("MySQL JDBC Driver not found.");
            return null;
        } catch (SQLException e) {
            System.out.println("Error connecting to database: " + e.getMessage());
            return null;
        }
    }

    public static void addEmployee(String name, int age, String department) {
        String sql = "INSERT INTO employees (name, age, department) VALUES (?, ?, ?)";
        try (Connection conn = connectToMySQL(); PreparedStatement pstmt = conn.prepareStatement(sql)) {
            if (conn == null) return;
            pstmt.setString(1, name);
            pstmt.setInt(2, age);
            pstmt.setString(3, department);
            pstmt.executeUpdate();

            System.out.println("Employee '" + name + "' added successfully.");
        } catch (SQLException e) {
            System.out.println("Failed to add employee: " + e.getMessage());
        }
    }

    public static void displayEmployees() {
        String sql = "SELECT * FROM employees";
        try (Connection conn = connectToMySQL(); Statement stmt = conn.createStatement()) {
            if (conn == null) return;
            ResultSet rs = stmt.executeQuery(sql);
            System.out.println("\nEmployees List:");
            while (rs.next()) {
                System.out.printf("ID: %d, Name: %s, Age: %d, Department: %s%n",
                        rs.getInt("id"), rs.getString("name"), rs.getInt("age"), rs.getString("department"));
            }
        } catch (SQLException e) {
            System.out.println("Failed to fetch employees: " + e.getMessage());
        }
    }

    public static void editEmployee(int employeeId, String newName, Integer newAge, String newDepartment) {
        try (Connection conn = connectToMySQL()) {
            if (conn == null) return;

            if (newName != null) {
                String sql = "UPDATE employees SET name = ? WHERE id = ?";
                try (PreparedStatement pstmt = conn.prepareStatement(sql)) {
                    pstmt.setString(1, newName);
                    pstmt.setInt(2, employeeId);
                    pstmt.executeUpdate();
                }
            }

            if (newAge != null) {
                String sql = "UPDATE employees SET age = ? WHERE id = ?";
                try (PreparedStatement pstmt = conn.prepareStatement(sql)) {
                    pstmt.setInt(1, newAge);
                    pstmt.setInt(2, employeeId);
                    pstmt.executeUpdate();
                }
            }

            if (newDepartment != null) {
                String sql = "UPDATE employees SET department = ? WHERE id = ?";
                try (PreparedStatement pstmt = conn.prepareStatement(sql)) {
                    pstmt.setString(1, newDepartment);
                    pstmt.setInt(2, employeeId);
                    pstmt.executeUpdate();
                }
            }

            System.out.println("Employee ID " + employeeId + " updated successfully.");
        } catch (SQLException e) {
            System.out.println("Failed to update employee: " + e.getMessage());
        }
    }

    public static void deleteEmployee(int employeeId) {
        String sql = "DELETE FROM employees WHERE id = ?";
        try (Connection conn = connectToMySQL(); PreparedStatement pstmt = conn.prepareStatement(sql)) {
            if (conn == null) return;
            pstmt.setInt(1, employeeId);
            pstmt.executeUpdate();
            System.out.println("Employee ID " + employeeId + " deleted successfully.");
        } catch (SQLException e) {
            System.out.println("Failed to delete employee: " + e.getMessage());
        }
    }

    public static void showMenu() {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("\n--- Employee Database Operations ---");
            System.out.println("1. Add Employee");
            System.out.println("2. Display All Employees");
            System.out.println("3. Edit Employee");
            System.out.println("4. Delete Employee");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");

            String choice = scanner.nextLine();

            switch (choice) {
                case "1":
                    System.out.print("Enter employee name: ");
                    String name = scanner.nextLine();
                    System.out.print("Enter employee age: ");
                    int age = Integer.parseInt(scanner.nextLine());
                    System.out.print("Enter employee department: ");
                    String department = scanner.nextLine();
                    addEmployee(name, age, department);
                    break;

                case "2":
                    displayEmployees();
                    break;

                case "3":
                    System.out.print("Enter employee ID to edit: ");
                    int editId = Integer.parseInt(scanner.nextLine());
                    System.out.print("Enter new name (leave blank to keep existing): ");
                    String newName = scanner.nextLine();
                    System.out.print("Enter new age (leave blank to keep existing): ");
                    String newAgeStr = scanner.nextLine();
                    System.out.print("Enter new department (leave blank to keep existing): ");
                    String newDepartment = scanner.nextLine();
                    Integer newAge = newAgeStr.isEmpty() ? null : Integer.parseInt(newAgeStr);
                    editEmployee(editId, newName.isEmpty() ? null : newName, newAge, newDepartment.isEmpty() ? null : newDepartment);
                    break;

                case "4":
                    System.out.print("Enter employee ID to delete: ");
                    int deleteId = Integer.parseInt(scanner.nextLine());
                    deleteEmployee(deleteId);
                    break;

                case "5":
                    System.out.println("Exiting program.");
                    scanner.close();
                    return;

                default:
                    System.out.println("Invalid choice, please try again.");
            }
        }
    }

    public static void main(String[] args) {
        showMenu();
    }
}


// javac -cp ".;mysql-connector-j-9.4.0.jar" EmployeeDatabase.java
// java -cp ".;mysql-connector-j-9.4.0.jar" EmployeeDatabase

// --- Employee Database Operations ---
// 1. Add Employee
// 2. Display All Employees
// 3. Edit Employee
// 4. Delete Employee
// 5. Exit
// Enter your choice: 1
// Enter employee name: Riya Sharma
// Enter employee age: 28
// Enter employee department: HR
// Employee 'Riya Sharma' added successfully.


// --- Employee Database Operations ---
// 1. Add Employee
// 2. Display All Employees
// 3. Edit Employee
// 4. Delete Employee
// 5. Exit
// Enter your choice: 1
// Enter employee name: Aarav Mehta
// Enter employee age: 32
// Enter employee department: IT
// Employee 'Aarav Mehta' added successfully.


// --- Employee Database Operations ---
// 1. Add Employee
// 2. Display All Employees
// 3. Edit Employee
// 4. Delete Employee
// 5. Exit
// Enter your choice: 2

// Employees List:
// ID: 1, Name: Riya Sharma, Age: 28, Department: HR
// ID: 2, Name: Aarav Mehta, Age: 32, Department: IT


// --- Employee Database Operations ---
// 1. Add Employee
// 2. Display All Employees
// 3. Edit Employee
// 4. Delete Employee
// 5. Exit
// Enter your choice: 3
// Enter employee ID to edit: 2
// Enter new name (leave blank to keep existing): Aarav M.
// Enter new age (leave blank to keep existing): 
// Enter new department (leave blank to keep existing): Finance
// Employee ID 2 updated successfully.


// --- Employee Database Operations ---
// 1. Add Employee
// 2. Display All Employees
// 3. Edit Employee
// 4. Delete Employee
// 5. Exit
// Enter your choice: 4
// Enter employee ID to delete: 1
// Employee ID 1 deleted successfully.


// --- Employee Database Operations ---
// 1. Add Employee
// 2. Display All Employees
// 3. Edit Employee
// 4. Delete Employee
// 5. Exit
// Enter your choice: 5
// Exiting program.
