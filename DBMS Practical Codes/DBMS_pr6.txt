-- C:\Users\bsais>mysql -u root -p
-- Enter password: ********

-- PL/SQL code block using Cursors (All types: Implicit, Explicit,Cursor FOR Loop, Parameterized Cursor)

CREATE DATABASE college_bank;
USE college_bank;

-- 1: Implicit Cursor(Activate Inactive Accounts)
CREATE TABLE accounts(
    acc_no INT PRIMARY KEY,
    acc_status VARCHAR(10),
    last_transaction DATE
);

INSERT INTO accounts VALUES
(101, 'Inactive', '2024-08-01'),
(102, 'Active', '2025-03-10'),
(103, 'Inactive', '2023-06-10'),
(104, 'Inactive', '2024-09-01');
DELIMITER $$

CREATE PROCEDURE ActivateAccounts()
BEGIN
    DECLARE rows_affected INT DEFAULT 0;

    UPDATE accounts SET acc_status = 'Active' WHERE acc_status='Inactive' AND last_transaction <= DATE_SUB(CURDATE(), INTERVAL 365 DAY);

    SET rows_affected = ROW_COUNT();

    IF rows_affected > 0 THEN
        SELECT CONCAT(rows_affected, ' accounts activated') AS Message;
    ELSE
        SELECT 'No accounts were activated' AS Message;
    END IF;
END$$
DELIMITER ;
SET SQL_SAFE_UPDATES = 0;
CALL ActivateAccounts();
SET SQL_SAFE_UPDATES = 1;

-- 2.Explicit Cursor – Salary Increment
CREATE TABLE emp(
    e_no INT PRIMARY KEY,
    salary DECIMAL(10,2)
);
CREATE TABLE increment_salary(
    e_no INT,
    salary DECIMAL(10,2)
);
INSERT INTO emp VALUES
(1, 20000),
(2, 40000),
(3, 30000),
(4, 50000);

DELIMITER $$

CREATE PROCEDURE IncreaseSalary()
BEGIN
    DECLARE done INT DEFAULT FALSE;
    DECLARE v_e_no INT;
    DECLARE v_salary DECIMAL(10,2);
    DECLARE avg_salary DECIMAL(10,2);

    DECLARE cur CURSOR FOR SELECT e_no, salary FROM emp;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

    SELECT AVG(salary) INTO avg_salary FROM emp;
    OPEN cur;
    read_loop: LOOP
        FETCH cur INTO v_e_no, v_salary;
        IF done THEN
            LEAVE read_loop;
        END IF;

        IF v_salary < avg_salary THEN
            UPDATE emp SET salary = salary * 1.10 WHERE e_no = v_e_no;
            INSERT INTO increment_salary VALUES(v_e_no, v_salary * 1.10);
        END IF;
    END LOOP;

    CLOSE cur;
END$$
DELIMITER ;
SET SQL_SAFE_UPDATES = 0;
CALL IncreaseSalary();
SELECT * FROM emp;
SELECT * FROM increment_salary;
SET SQL_SAFE_UPDATES = 1;

-- 3&6 Cursor FOR Loop – Detain Students
CREATE TABLE stud21(
    roll INT PRIMARY KEY,
    att DECIMAL(5,2),
    status VARCHAR(1)
);

CREATE TABLE d_stud(
    roll INT,
    att DECIMAL(5,2)
);

INSERT INTO stud21 VALUES
(1, 80, 'P'),
(2, 70, 'P'),
(3, 60, 'P'),
(4, 90, 'P');

DELIMITER $$
CREATE PROCEDURE DetainStudents()
BEGIN
    DECLARE done INT DEFAULT FALSE;
    DECLARE v_roll INT;
    DECLARE v_att DECIMAL(5,2);

    DECLARE cur CURSOR FOR SELECT roll, att FROM stud21;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

    OPEN cur;

    read_loop: LOOP
        FETCH cur INTO v_roll, v_att;
        IF done THEN
            LEAVE read_loop;
        END IF;

        IF v_att < 75 THEN
            UPDATE stud21 SET status='D' WHERE roll = v_roll;
            INSERT INTO d_stud VALUES(v_roll, v_att);
        END IF;
    END LOOP;

    CLOSE cur;
END$$
DELIMITER ;
SET SQL_SAFE_UPDATES = 0;
CALL DetainStudents();
SELECT * FROM stud21;
SELECT * FROM d_stud;
SET SQL_SAFE_UPDATES = 1;

-- 4.Parameterized Cursor – Merge Tables
CREATE TABLE N_RollCall(roll INT PRIMARY KEY, name VARCHAR(50));
CREATE TABLE O_RollCall(roll INT PRIMARY KEY, name VARCHAR(50));


INSERT INTO N_RollCall VALUES (1,'Sudhir'),(2,'Saish'),(3,'Ayyub');
INSERT INTO O_RollCall VALUES (2,'Ayushi'),(4,'Divya');

DELIMITER $$
CREATE PROCEDURE MergeRollCall()
BEGIN
    DECLARE done INT DEFAULT FALSE;
    DECLARE v_roll INT;
    DECLARE v_name VARCHAR(50);

    DECLARE cur CURSOR FOR SELECT roll, name FROM N_RollCall;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

    OPEN cur;
    read_loop: LOOP
        FETCH cur INTO v_roll, v_name;
        IF done THEN
            LEAVE read_loop;
        END IF;

        IF NOT EXISTS (SELECT 1 FROM O_RollCall WHERE roll = v_roll) THEN
            INSERT INTO O_RollCall VALUES(v_roll, v_name);
        END IF;
    END LOOP;
    CLOSE cur;
END$$
DELIMITER ;
SET SQL_SAFE_UPDATES = 0;
CALL MergeRollCall();
SELECT * FROM O_RollCall;
SET SQL_SAFE_UPDATES = 1;

-- 5: Parameterized Cursor – Department Average Salary
CREATE TABLE emp_dept(
    e_no INT PRIMARY KEY,
    d_no INT,
    salary DECIMAL(10,2)
);

CREATE TABLE dept_salary(
    d_no INT PRIMARY KEY,
    avg_salary DECIMAL(10,2)
);

INSERT INTO emp_dept VALUES
(1,101,20000),(2,101,25000),(3,102,30000),(4,102,40000);

DELIMITER $$

CREATE PROCEDURE DeptAvgSalary()
BEGIN
    DECLARE done INT DEFAULT FALSE;
    DECLARE v_dno INT;

    DECLARE cur CURSOR FOR SELECT DISTINCT d_no FROM emp_dept;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

    OPEN cur;
    read_loop: LOOP
        FETCH cur INTO v_dno;
        IF done THEN
            LEAVE read_loop;
        END IF;

        INSERT INTO dept_salary(d_no, avg_salary)
        SELECT v_dno, AVG(salary) FROM emp_dept WHERE d_no = v_dno;
    END LOOP;

    CLOSE cur;
END$$

DELIMITER ;
SET SQL_SAFE_UPDATES = 0;
CALL DeptAvgSalary();
SELECT * FROM dept_salary;
SET SQL_SAFE_UPDATES = 1;

-- -- ---------------------------------------------------------------
-- -- 5: Parameterized Cursor – Department Average Salary
-- -- ---------------------------------------------------------------
-- -- This program calculates the average salary for a given department (passed as a parameter)
-- -- using a parameterized cursor in MySQL stored procedure.
-- -- ---------------------------------------------------------------

-- -- Step 1: Create employee table (employee number, department number, salary)
-- CREATE TABLE emp_dept(
--     e_no INT PRIMARY KEY,
--     d_no INT,
--     salary DECIMAL(10,2)
-- );

-- -- Step 2: Create department salary table to store computed average salaries
-- CREATE TABLE dept_salary(
--     d_no INT PRIMARY KEY,
--     avg_salary DECIMAL(10,2)
-- );

-- -- Step 3: Insert sample employee data
-- INSERT INTO emp_dept VALUES
-- (1,101,20000),
-- (2,101,25000),
-- (3,102,30000),
-- (4,102,40000);

-- -- Step 4: Create stored procedure using a PARAMETERIZED CURSOR
-- DELIMITER $$

-- CREATE PROCEDURE DeptAvgSalary(IN p_dno INT)   -- 'p_dno' is an input parameter (department number)
-- BEGIN
--     -- Declare variables
--     DECLARE done INT DEFAULT FALSE;            -- Flag to check when cursor reading is complete
--     DECLARE v_e_no INT;                        -- Variable to hold employee number
--     DECLARE v_salary DECIMAL(10,2);            -- Variable to hold salary of employee
--     DECLARE v_total DECIMAL(10,2) DEFAULT 0;   -- Variable to accumulate total salary
--     DECLARE v_count INT DEFAULT 0;             -- Variable to count number of employees
--     DECLARE v_avg DECIMAL(10,2);               -- Variable to store computed average

--     -- Step 4.1: Declare PARAMETERIZED cursor that selects employees of a specific department
--     DECLARE cur CURSOR FOR 
--         SELECT e_no, salary FROM emp_dept WHERE d_no = p_dno;

--     -- Step 4.2: Declare handler to detect when no more rows are left in cursor
--     DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

--     -- Step 4.3: Open cursor
--     OPEN cur;

--     -- Step 4.4: Start reading each record one by one
--     read_loop: LOOP
--         FETCH cur INTO v_e_no, v_salary;       -- Fetch data from cursor into variables
--         IF done THEN                           -- When cursor reaches end, exit loop
--             LEAVE read_loop;
--         END IF;

--         -- Add salary to total and increment count
--         SET v_total = v_total + v_salary;
--         SET v_count = v_count + 1;
--     END LOOP;

--     -- Step 4.5: Close cursor
--     CLOSE cur;

--     -- Step 4.6: Calculate average if employees exist in department
--     IF v_count > 0 THEN
--         SET v_avg = v_total / v_count;

--         -- Step 4.7: Insert computed average into dept_salary table
--         INSERT INTO dept_salary (d_no, avg_salary)
--         VALUES (p_dno, v_avg);
--     END IF;
-- END$$

-- DELIMITER ;

-- -- Step 5: Disable safe updates temporarily
-- SET SQL_SAFE_UPDATES = 0;

-- -- Step 6: Call procedure for specific departments
-- CALL DeptAvgSalary(101);
-- CALL DeptAvgSalary(102);

-- -- Step 7: Display computed results
-- SELECT * FROM dept_salary;

-- -- Step 8: Re-enable safe updates
-- SET SQL_SAFE_UPDATES = 1;

-- https://chatgpt.com/share/69154cb0-9dfc-8002-904c-424706b99300