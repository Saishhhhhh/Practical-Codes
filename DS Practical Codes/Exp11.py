# %% [markdown]
# Title: Big Data Analytics (Impala)

# %% [markdown]
# PROBLEM STATEMENT:
# Create databases and tables, insert small amounts of data, and run simple queries using 
# Impala

# %%
import sqlite3

# %%
conn = sqlite3.connect('student_db.db')
cursor = conn.cursor()

# %%
cursor.execute("""
CREATE TABLE IF NOT EXISTS students (
    id INTEGER,
    name TEXT,
    age INTEGER
)
""")
conn.commit()

# %%
cursor.execute("INSERT INTO students VALUES (1, 'Laukik', 21)")
cursor.execute("INSERT INTO students VALUES (2, 'Nikhil', 22)")
cursor.execute("INSERT INTO students VALUES (3, 'Sakshi', 20)")
conn.commit()

# %%
# View all records
print("All Records:\n")
cursor.execute("SELECT * FROM students")

rows = cursor.fetchall()

for row in rows:
    print(row)

# %%
cursor.execute("SELECT * FROM students WHERE age > 20")
filtered_rows = cursor.fetchall()

print("\nStudents with age > 20:\n")

for row in filtered_rows:
    print(row)


# %%
cursor.execute("SELECT COUNT(*) FROM students")

print("\nTotal Records:", cursor.fetchone()[0])



# %%
# Close connection
conn.close()


