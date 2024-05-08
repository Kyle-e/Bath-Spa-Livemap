#include <Wire.h> 
#include <LiquidCrystal_I2C.h> // Include the appropriate I2C LCD library

// Define pins for buttons and answer choices
const int upButton = 2;
const int downButton = 3;
const int submitButton = 4;

LiquidCrystal_I2C lcd(0x27, 20, 4);

// Define answer choices
String courses[] = {"Answer 1", "Answer 2", "Answer 3"};
int selectedCourseIndex = 0; // Variable to store the selected answer index

void setup() {
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  

  // Initialize buttons as inputs
  pinMode(upButton, INPUT);
  pinMode(downButton, INPUT);
  pinMode(submitButton, INPUT);
}

void loop() {

}

void mainMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Select answer:");
  for (int i = 0; i < 3; i++) {
    lcd.setCursor(0, i + 1);
    if (i == selectedCourseIndex) {
      lcd.print("> ");
    } else {
      lcd.print("  ");
    }
    lcd.print(courses[i]);
  }
}

void discarded() {
  // Read the state of each button
  int buttonUpState = digitalRead(upButton);
  int buttonDownState = digitalRead(downButton);
  int submitButtonState = digitalRead(submitButton);
  
  // Navigate through answer choices
  if (buttonUpState == LOW) {
    selectedCourseIndex--;
    if (selectedCourseIndex < 0) {
      selectedCourseIndex = 2; // Loop back to the last choice
    }
    mainMenu();
    delay(200); // Button debounce delay
  }
  if (buttonDownState == LOW) {
    selectedCourseIndex++;
    if (selectedCourseIndex > 2) {
      selectedCourseIndex = 0; // Loop back to the first choice
    }
    mainMenu();
    delay(200); // Button debounce delay
  }
  
  // Submit answer
  if (submitButtonState == LOW) {
    // Process the selected answer
    // For example, you can print it to serial monitor
    Serial.print("Selected answer: ");
    Serial.println(courses[selectedCourseIndex]);
    // Reset selected answer for next question
    selectedCourseIndex = 0;
    delay(1000); // Button debounce delay
  }
}
