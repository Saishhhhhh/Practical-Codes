// Lab Practical 8
// Write a program that asks the user for a number and outputs the number squared that is entered.

//In C++ For Arduino Uno

String inputString = "";
int num = 0;
bool inputComplete = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Enter a number:");
}

void loop() {
  // Read input from Serial Monitor
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      inputComplete = true;
      break;
    } else {
      inputString += inChar;
    }
  }

  // Once input is complete, convert to number and square it
  if (inputComplete) {
    num = inputString.toInt(); // Convert string to integer
    int sq = num * num;

    Serial.print("The square of ");
    Serial.print(num);
    Serial.print(" is: ");
    Serial.println(sq);

    // Reset for next input
    inputString = "";
    inputComplete = false;
    Serial.println("Enter another number:");
  }
}

// 🖥️ How to Use:

// Upload the code to your Arduino board.

// Open the Serial Monitor (Ctrl+Shift+M in Arduino IDE).

// Set baud rate to 9600 and choose "Newline" in line ending.

// Type a number and press Enter.

// It will show the square and ask again.


//In Python For Raspberry Pi

num = int(input("Enter the number: "))
sq = num * num
print("The square of", num, "is:", sq)

//✅ 2. Save the File
// Save this code in a .py file. For example:

// nano square.py

// Paste the code inside, press Ctrl + X, then Y, and hit Enter to save.

// ✅ 3. Run the Code
// Now, in the terminal, run it like this:

// python3 square.py

// When prompted, type a number and hit Enter, and it’ll print the square.