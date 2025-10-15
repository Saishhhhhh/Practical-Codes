-- C:\Users\bsais>mysql -u root -p
-- Enter password: ********


CREATE DATABASE bank_demo;
USE bank_demo;

CREATE TABLE cust_mstr (
  cust_no INT PRIMARY KEY,
  fname VARCHAR(50),
  lname VARCHAR(50)
);

CREATE TABLE add_dets (
  code_no INT,
  add1 VARCHAR(100),
  add2 VARCHAR(100),
  state VARCHAR(50),
  city VARCHAR(50),
  pincode VARCHAR(10),
  FOREIGN KEY (code_no) REFERENCES cust_mstr(cust_no)
);
INSERT INTO cust_mstr VALUES (1,'xyz','pqr');
INSERT INTO cust_mstr VALUES (2,'Sudhir','Sudhir');

INSERT INTO add_dets VALUES (1,'Street1','Lane1','MH','Pune','411044');
INSERT INTO add_dets VALUES (2,'Street2','Lane2','MH','Nigdi','411045');

-- Retrieve the address of customer Fname as 'xyz' and Lname as 'pqr'
SELECT a.add1,a.add2,a.state,a.city,a.pincode
FROM cust_mstr c
JOIN add_dets a ON c.cust_no=a.code_no
WHERE c.fname='xyz' AND c.lname='pqr';


CREATE TABLE acc_fd_cust_dets (
  code_no INT,
  acc_fd_no INT,
  PRIMARY KEY(code_no,acc_fd_no)
);

CREATE TABLE fd_dets (
  fd_sr_no INT PRIMARY KEY,
  amt DECIMAL(10,2)
);

INSERT INTO acc_fd_cust_dets VALUES (1,101);
INSERT INTO acc_fd_cust_dets VALUES (2,102);

INSERT INTO fd_dets VALUES (101,7000);
INSERT INTO fd_dets VALUES (102,4000);

-- List the customer holding fixed deposit of amount more than 5000
SELECT c.fname,c.lname,f.amt
FROM cust_mstr c
JOIN acc_fd_cust_dets a ON c.cust_no=a.code_no
JOIN fd_dets f ON a.acc_fd_no=f.fd_sr_no
WHERE f.amt>5000;

CREATE TABLE emp_mstr (
  emp_no INT PRIMARY KEY,
  f_name VARCHAR(50),
  l_name VARCHAR(50),
  m_name VARCHAR(50),
  dept VARCHAR(50),
  desg VARCHAR(50),
  branch_no INT
);

CREATE TABLE branch_mstr (
  b_no INT PRIMARY KEY,
  name VARCHAR(50)
);
INSERT INTO branch_mstr VALUES (11,'Akurdi');
INSERT INTO branch_mstr VALUES (12,'Nigdi');

INSERT INTO emp_mstr VALUES (1001,'Ravi','Patil','A','IT','Manager',11);
INSERT INTO emp_mstr VALUES (1002,'Sarthak','Joshi','B','HR','Executive',12);

-- List the employee details along with branch names to which they belong

SELECT e.*,b.name AS branch_name
FROM emp_mstr e
JOIN branch_mstr b ON e.branch_no=b.b_no;

CREATE TABLE cntc_dets (
  code_no INT,
  cntc_type VARCHAR(50),
  cntc_data VARCHAR(100)
);
INSERT INTO cntc_dets VALUES (1001,'Mobile','9999999999');
INSERT INTO cntc_dets VALUES (1002,'Email','abc@gmail.com');
-- List the employee details along with contact details using left outer join & right join

SELECT e.*,c.cntc_type,c.cntc_data
FROM emp_mstr e
LEFT JOIN cntc_dets c ON e.emp_no=c.code_no;

CREATE TABLE branch (
  branch_id INT PRIMARY KEY,
  pincode VARCHAR(10)
);
INSERT INTO branch VALUES (1,'411044');
-- List the customer who do not have bank branches in their vicinity.
SELECT c.cust_no,c.fname,c.lname
FROM cust_mstr c
JOIN add_dets a ON c.cust_no=a.code_no
WHERE a.pincode NOT IN (SELECT pincode FROM branch);

CREATE TABLE borrower (
  cust_name VARCHAR(50),
  loan_no INT
);

CREATE TABLE depositor (
  cust_name VARCHAR(50),
  acc_no INT
);
INSERT INTO borrower VALUES ('Sudhir',201);
INSERT INTO depositor VALUES ('Sudhir',301);


CREATE VIEW borrower_view AS
SELECT cust_name,loan_no FROM borrower;
select *from borrower_view;
INSERT INTO borrower_view VALUES ('Rahul',202);
UPDATE borrower_view SET loan_no=203 WHERE cust_name='Rahul';
DELETE FROM borrower_view WHERE cust_name='Rahul';

-- View joining borrower & depositor
CREATE VIEW borrow_deposit_view AS
SELECT b.cust_name,d.acc_no FROM borrower b JOIN depositor d ON b.cust_name=d.cust_name;

select *from borrow_deposit_view;
