// Writeaprogram thatasks theuserforanumberandoutputs thenumbersquaredthat is entered

String input = "";
bool done = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Enter a number:");
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
      done = true;
    } else {
      input += c;  //input = input + c
    }
  }
  
  if (done) {
    int num = input.toInt();
    int square = num * num;
    Serial.print("Square of ");
    Serial.print(num);
    Serial.print(" is ");
    Serial.println(square);
    
    input = "";
    done = false;
    Serial.println("Enter a number:");
  }
}