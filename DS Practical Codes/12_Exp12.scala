# Lab Assignment 13
# Title: Big Data Analytics
# PROBLEM STATEMENT: Simple Scala Program using Apache Spark Framework
// ---------------- INSTALLATION STEPS ----------------

// 1. Install Java (JDK 17 or above)
// Check Java installation:
    // java -version

// 2. Install Scala
// Check Scala installation:
    // scala -version

// 3. Install Apache Spark
// Download Spark from:
    // https://spark.apache.org/downloads.html

// 4. Set Environment Variables
// Add Scala, Java, and Spark bin folders to PATH

// ---------------- RUN COMMANDS ----------------

// Compile Scala Program:
    // scalac filename.scala

// Run Scala Program:
    // scala filename

// ---------------------------------------------------

# import Spark libraries
import org.apache.spark.sql.SparkSession

object HelloSpark {

  def main(args: Array[String]): Unit = {

    // Create Spark Session
    val spark = SparkSession.builder()
      .appName("Hello Spark")
      .master("local[*]")
      .getOrCreate()

    // Sample Data
    val data = Seq(
      ("Laukik", 21),
      ("Nikhil", 22),
      ("Sakshi", 20)
    )

    // Convert data into DataFrame
    val df = spark.createDataFrame(data)
      .toDF("Name", "Age")

    // Display DataFrame
    println("Student Data:")

    df.show()

    // Stop Spark Session
    spark.stop()
  }
}