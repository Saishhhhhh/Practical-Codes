# --------------------------------------------
# Title: Implement MySQL Database Connectivity using Python
# Objective: Perform Database Navigation Operations (Add, Edit, Delete, Display)
# --------------------------------------------
# pip install mysql-connector-python
import mysql.connector
from mysql.connector import Error

def connect_to_mysql():
    """Establish connection with MySQL database."""
    try:
        connection = mysql.connector.connect(
            host='localhost',
            database='testDB',    # Change to your database name
            user='root',          # MySQL username (change according to username)
            password='password'   # MySQL password (change according to password)
        )
        if connection.is_connected():
            return connection
    except Error as e:
        print("Error connecting to MySQL:", e)
        return None


def add_employee(name, age, department):
    """Insert a new employee record."""
    connection = connect_to_mysql()
    if connection:
        cursor = connection.cursor()
        try:
            query = "INSERT INTO employees (name, age, department) VALUES (%s, %s, %s)"
            cursor.execute(query, (name, age, department))
            connection.commit()
            print(f"Employee '{name}' added successfully.")
        except Error as e:
            print("Failed to add employee:", e)
        finally:
            cursor.close()
            connection.close()


def display_employees():
    """Fetch and display all employee records."""
    connection = connect_to_mysql()
    if connection:
        cursor = connection.cursor()
        try:
            cursor.execute("SELECT * FROM employees")
            records = cursor.fetchall()
            if not records:
                print("\nNo employees found.")
            else:
                print("\nEmployees List:")
                for row in records:
                    print(f"ID: {row[0]}, Name: {row[1]}, Age: {row[2]}, Department: {row[3]}")
        except Error as e:
            print("Failed to fetch employees:", e)
        finally:
            cursor.close()
            connection.close()


def edit_employee(emp_id, new_name=None, new_age=None, new_department=None):
    """Edit existing employee record."""
    connection = connect_to_mysql()
    if connection:
        cursor = connection.cursor()
        try:
            if new_name:
                cursor.execute("UPDATE employees SET name = %s WHERE id = %s", (new_name, emp_id))
            if new_age:
                cursor.execute("UPDATE employees SET age = %s WHERE id = %s", (new_age, emp_id))
            if new_department:
                cursor.execute("UPDATE employees SET department = %s WHERE id = %s", (new_department, emp_id))
            connection.commit()
            print(f"Employee ID {emp_id} updated successfully.")
        except Error as e:
            print("Failed to update employee:", e)
        finally:
            cursor.close()
            connection.close()


def delete_employee(emp_id):
    """Delete an employee record."""
    connection = connect_to_mysql()
    if connection:
        cursor = connection.cursor()
        try:
            cursor.execute("DELETE FROM employees WHERE id = %s", (emp_id,))
            connection.commit()
            print(f"Employee ID {emp_id} deleted successfully.")
        except Error as e:
            print("Failed to delete employee:", e)
        finally:
            cursor.close()
            connection.close()


def show_menu():
    """Display the menu and take user input for operations."""
    while True:
        print("\n--- Employee Database Operations ---")
        print("1. Add Employee")
        print("2. Display All Employees")
        print("3. Edit Employee")
        print("4. Delete Employee")
        print("5. Exit")

        choice = input("Enter your choice: ")

        if choice == "1":
            name = input("Enter employee name: ")
            age = int(input("Enter employee age: "))
            department = input("Enter employee department: ")
            add_employee(name, age, department)

        elif choice == "2":
            display_employees()

        elif choice == "3":
            emp_id = int(input("Enter employee ID to edit: "))
            new_name = input("Enter new name (leave blank to keep existing): ").strip()
            new_age_input = input("Enter new age (leave blank to keep existing): ").strip()
            new_department = input("Enter new department (leave blank to keep existing): ").strip()

            new_age = int(new_age_input) if new_age_input else None
            edit_employee(emp_id,
                          new_name if new_name else None,
                          new_age,
                          new_department if new_department else None)

        elif choice == "4":
            emp_id = int(input("Enter employee ID to delete: "))
            delete_employee(emp_id)

        elif choice == "5":
            print("Exiting program.")
            break

        else:
            print("Invalid choice. Please try again.")


if __name__ == "__main__":
    show_menu()

# https://chatgpt.com/share/69154dbd-44f0-8002-bcaf-967eb0472f3d