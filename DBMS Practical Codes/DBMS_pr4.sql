-- C:\Users\bsais>mysql -u root -p
-- Enter password: ********

-- A PL/SQL block of code (Use of Control structure and Exception handling)

CREATE DATABASE plsql_demo;
USE plsql_demo;

-- 1.Student Attendance
CREATE TABLE Stud (
    Roll INT PRIMARY KEY,
    Att DEC(5,2),
    Status CHAR(2)
);

INSERT INTO Stud VALUES (1, 80, NULL);
INSERT INTO Stud VALUES (2, 70, NULL);
INSERT INTO Stud VALUES (3, 90, NULL);
DELIMITER $$

CREATE PROCEDURE check_term_proc(IN v_roll INT)
BEGIN
  DECLARE v_att INT;

  SELECT Att INTO v_att
  FROM Stud
  WHERE Roll = v_roll;

  IF v_att < 75 THEN
    UPDATE Stud SET Status='D' WHERE Roll=v_roll;
    SELECT 'Term not granted' AS result_msg;
  ELSE
    UPDATE Stud SET Status='ND' WHERE Roll=v_roll;
    SELECT 'Term granted' AS result_msg;
  END IF;

END$$
DELIMITER ;
CALL check_term_proc(1);

-- 2.Bank withdrawl
CREATE TABLE account_master (
    acc_no INT PRIMARY KEY,
    balance DEC(10,2)
);

INSERT INTO account_master VALUES (101, 10000);
INSERT INTO account_master VALUES (102, 5000);
INSERT INTO account_master VALUES (103, 2000);

DELIMITER $$

CREATE PROCEDURE withdraw_amount1(
    IN v_acc_no INT,
    IN v_withdraw DECIMAL(10,2)
)
BEGIN
    DECLARE v_balance DECIMAL(10,2);

    -- Get current balance
    SELECT balance INTO v_balance
    FROM account_master
    WHERE acc_no = v_acc_no;

    -- Check for insufficient balance
    IF v_withdraw > v_balance THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Error: Withdrawal exceeds current balance!';
    ELSE
        -- Update balance
        UPDATE account_master
        SET balance = balance - v_withdraw
        WHERE acc_no = v_acc_no;

        -- Return message using local variable
        SELECT CONCAT('Withdrawal successful. Remaining balance: ', v_balance - v_withdraw) AS result_msg;
    END IF;
END$$

DELIMITER ;

CALL withdraw_amount1(101, 2000);


-- 3.Library Borrower & Fine
CREATE TABLE Borrower (
    Roll_no INT,
    Name VARCHAR(50),
    Date_of_Issue DATE,
    Name_of_Book VARCHAR(50),
    Status CHAR(1)  -- 'I' = Issued, 'R' = Returned
);

CREATE TABLE Fine (
    Roll_no INT,
    Date_of_Fine DATE,
    Amt DEC(10,2)
);

INSERT INTO Borrower VALUES (1,'Sudhir',CURDATE(),'Data Science','I');
INSERT INTO Borrower VALUES (2,'Rahul',CURDATE(),'AI Basics','I');
INSERT INTO Borrower VALUES (3,'Divya',CURDATE(),'Python','I');

DELIMITER $$
CREATE PROCEDURE return_book(
    IN v_roll INT,
    IN v_book VARCHAR(50)
)
BEGIN
    DECLARE v_date_issue DATE;
    DECLARE v_status CHAR(1);
    DECLARE v_days INT;
    DECLARE v_fine_amt DECIMAL(10,2);
    DECLARE book_not_issued CONDITION FOR SQLSTATE '45000';

    SELECT Date_of_Issue, Status INTO v_date_issue, v_status
    FROM Borrower
    WHERE Roll_no = v_roll AND Name_of_Book = v_book;

    IF v_status <> 'I' THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Error: Book is not currently issued!';
    END IF;

    SET v_days = DATEDIFF(CURDATE(), v_date_issue);

    IF v_days BETWEEN 15 AND 30 THEN
        SET v_fine_amt = v_days * 5;
    ELSEIF v_days > 30 THEN
        SET v_fine_amt = v_days * 50;
    ELSE
        SET v_fine_amt = v_days * 5;
    END IF;

    -- Insert fine if applicable
    IF v_fine_amt > 0 THEN
        INSERT INTO Fine(Roll_no, Date_of_Fine, Amt)
        VALUES(v_roll, CURDATE(), v_fine_amt);
    END IF;

    UPDATE Borrower
    SET Status='R'
    WHERE Roll_no=v_roll AND Name_of_Book=v_book;

    SELECT CONCAT('Book returned successfully. Fine amount: ', v_fine_amt) AS result_msg;
END$$

DELIMITER ;

-- Disable safe update mode temporarily
SET SQL_SAFE_UPDATES = 0;

-- Call procedure
CALL return_book(2, 'AI Basics');

-- Re-enable safe update mode if desired
SET SQL_SAFE_UPDATES = 1;


-- https://chatgpt.com/share/6915489c-5668-8002-bf0d-93211add19e6