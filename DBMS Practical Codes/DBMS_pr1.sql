-- C:\Users\bsais>mysql -u root -p
-- Enter password: ********

CREATE DATABASE Bank;
use bank;

CREATE TABLE Branch (
  branch_name VARCHAR(50) PRIMARY KEY,
  branch_city VARCHAR(50) NOT NULL,
  assets DECIMAL(15,2) CHECK (assets >= 0)
);

CREATE TABLE Customer (
  cust_name VARCHAR(50) PRIMARY KEY,
  cust_street VARCHAR(100) NOT NULL,
  cust_city VARCHAR(50) NOT NULL
);

CREATE TABLE Account (acc_no INT PRIMARY KEY,
  branch_name VARCHAR(50) NOT NULL,
  balance DECIMAL(12,2) CHECK (balance >= 0),
  FOREIGN KEY (branch_name) REFERENCES Branch(branch_name)
);

CREATE TABLE Depositor (
  cust_name VARCHAR(50),
  acc_no INT,
  PRIMARY KEY (cust_name, acc_no),
  FOREIGN KEY (cust_name) REFERENCES Customer(cust_name),
  FOREIGN KEY (acc_no) REFERENCES Account(acc_no)
);

CREATE TABLE Loan (
  loan_no INT PRIMARY KEY,
  branch_name VARCHAR(50) NOT NULL,
  amount DECIMAL(12,2) CHECK (amount > 0),
  FOREIGN KEY (branch_name) REFERENCES Branch(branch_name)
);

CREATE TABLE Borrower (
  cust_name VARCHAR(50),
  loan_no INT,
  PRIMARY KEY (cust_name, loan_no),
  FOREIGN KEY (cust_name) REFERENCES Customer(cust_name),
  FOREIGN KEY (loan_no) REFERENCES Loan(loan_no)
);

INSERT INTO Branch VALUES ('Akurdi','Pune',500000);
INSERT INTO Branch VALUES ('Nigdi','Pune',400000);

INSERT INTO Account VALUES (101,'Akurdi',15000);
INSERT INTO Account VALUES (102,'Akurdi',8000);
INSERT INTO Account VALUES (103,'Nigdi',12000);

INSERT INTO Customer VALUES ('Ravi','MG Road','Pune');
INSERT INTO Customer VALUES ('Anita','FC Road','Pune');
INSERT INTO Customer VALUES ('Sanjay','Main Street','Mumbai');

INSERT INTO Depositor VALUES ('Ravi',101);
INSERT INTO Depositor VALUES ('Anita',102);

INSERT INTO Loan VALUES (201,'Akurdi',15000);
INSERT INTO Loan VALUES (202,'Akurdi',10000);
INSERT INTO Loan VALUES (203,'Nigdi',18000);

INSERT INTO Borrower VALUES ('Ravi',201);
INSERT INTO Borrower VALUES ('Sanjay',203);

-- Q1. Find the names of all branches in loan relation.
SELECT DISTINCT branch_name FROM Loan;

-- Q2 Loan numbers at Akurdi with amount > 12000
SELECT loan_no FROM Loan WHERE branch_name='Akurdi' AND amount>12000;

-- Q3 Customers with loan (name, loan_no, amount)
SELECT B.cust_name, L.loan_no, L.amount FROM Borrower B JOIN Loan L ON B.loan_no=L.loan_no;

-- Q4 Customers with loan from Akurdi in alphabetical order
SELECT DISTINCT B.cust_name FROM Borrower B JOIN Loan L ON B.loan_no=L.loan_no WHERE L.branch_name='Akurdi' ORDER BY B.cust_name;

-- Q5 Customers who have account or loan or both
SELECT cust_name FROM Depositor UNION SELECT cust_name FROM Borrower;

-- Q6 Customers with both account and loan
SELECT DISTINCT D.cust_name FROM Depositor D JOIN Borrower B ON D.cust_name=B.cust_name;

-- Q7 Customers with account but no loan	
SELECT cust_name FROM Depositor WHERE cust_name NOT IN (SELECT cust_name FROM Borrower);

-- Q8 Average account balance at Akurdi	
SELECT AVG(balance) AS avg_balance FROM Account WHERE branch_name='Akurdi';

-- Q9 Average account balance at each branch	
SELECT branch_name, AVG(balance) AS avg_balance FROM Account GROUP BY branch_name;

-- Q10 No. of depositors at each branch
SELECT A.branch_name, COUNT(DISTINCT D.cust_name) AS no_of_depositors FROM Account A JOIN Depositor D ON A.acc_no=D.acc_no GROUP BY A.branch_name;

-- Q11 Branches where avg balance > 12000	
SELECT branch_name FROM Account GROUP BY branch_name HAVING AVG(balance)>12000;

-- Q12 Number of tuples in customer
SELECT COUNT(*) AS total_customers FROM Customer;
    
-- Q13 Total loan amount given by bank	
SELECT SUM(amount) AS total_loan FROM Loan;

-- Q14 Delete all loans with amount between 1300 & 1500	
DELETE FROM Loan WHERE amount BETWEEN 1300 AND 1500;

-- Q15 Delete all tuples at branches located in Nigdi	
DELETE FROM Branch WHERE branch_city='Nigdi'; 

-- Q16 Create synonym for customer as cust 
SELECT * FROM Customer AS cust;

-- Q17 Create sequence roll_seq & use in student table
CREATE TABLE Student (
  roll_no INT AUTO_INCREMENT PRIMARY KEY,
  name VARCHAR(50)
);

INSERT INTO Student (name) VALUES ('Ravi');
INSERT INTO Student (name) VALUES ('Anita');
INSERT INTO Student (name) VALUES ('Sanjay');
SELECT * FROM Student;



