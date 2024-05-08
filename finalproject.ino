#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <DS1302.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

const int ledPin = 13;
const int upButton = 2;
const int downButton = 3;
const int selectButton = 4;

/* DOWN BUTTON */
int downButtonState = 0;
int lastDownButtonState = 0;
bool downButtonPressed = false;
/* SELECT BUTTON */
int selectButtonState = 0;
int lastSelectButtonState = 0;
bool selectButtonPressed = false;

int cursorPosition = 0;
int selectedCourse = 0;

String course[] = {"Creative Computing", "Psychology", "Cyber Security"};
String year[] = {"Year 1", "Year 2", "Year 3"};
String group[] = {"Group 1", "Group 2"};

DS1302 rtc(5, 6, 7);

void setup() {
  lcd.init();
  lcd.backlight();

  displayAnswerChoices();
}

void loop() {
  theButton();
}


void displayAnswerChoices() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Select answer:");
  for (int i = 0; i < 3; i++) {
    lcd.setCursor(0, i + 1);
    if (i == selectedCourse) {
      lcd.print("> ");
    } else {
      lcd.print("  ");
    }
    lcd.print(course[i]);
  }
}

void theButton() {
  /* ---- DOWN BUTTON ---- */
  downButtonState = digitalRead(downButton);

  // check if the button is pressed and was not pressed previously
  if (downButtonState == HIGH && lastDownButtonState == LOW) {
    downButtonPressed = true;
  }
  // update lastButtonState
  lastDownButtonState = downButtonState;


  // if the button has been pressed, do something
  if (downButtonPressed) {
    /* INSERT DOWN FUNCTION HERE */
    selectedCourse++;
    if (selectedCourse > 2) {
      selectedCourse = 0; // Loop back to the first choice
    }
    Serial.println("Down button");

    // set back to false to prevent multiple executions
    downButtonPressed = false;
    delay(500);
  }


  /* ---- SELECT BUTTON ---- */
  selectButtonState = digitalRead(selectButton);

  // check if button is pressed and not pressed before
  if (selectButtonState == HIGH && lastSelectButtonState == LOW) {
    selectButtonPressed = true;
  }
  // update lastButtonState
  lastSelectButtonState = selectButtonState;


  // if the button has been pressed, do something
  if (selectButtonPressed) {
    /* INSERT SELECT FUNCTION HERE */
    lcd.print("Selected answer: ");
    lcd.println(group[selectedCourse]);
    // Reset selected answer for next question
    selectedCourse = 0;
    delay(1000); // Button debounce delay

    // set back to false to prevent multiple executions
    selectButtonPressed = false;
    delay(500);
  }
}

void selectLayout1() {
  lcd.setCursor(0, 0);
  lcd.print("Select course:");
  lcd.setCursor(0, 1);
  lcd.print("> Creative Computing");
  lcd.setCursor(0, 2);
  lcd.print("> Psychology");
  lcd.setCursor(0, 3);
  lcd.print("> Cyber Security");
  lcd.setCursor(0, 1);
  lcd.blink();

  delay(5000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Select year:");
  lcd.setCursor(0, 1);
  lcd.print("> Year 1");
  lcd.setCursor(0, 2);
  lcd.print("> Year 2");
  lcd.setCursor(0, 3);
  lcd.print("> Year 3");
  lcd.setCursor(0, 1);
  lcd.blink();

  delay(5000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Select group:");
  lcd.setCursor(0, 1);
  lcd.print("> Group 1");
  lcd.setCursor(0, 2);
  lcd.print("> Group 2");
  lcd.setCursor(0, 1);
  lcd.blink();
  delay(5000);

  selectLayout1();
}
void mainMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Select course:");
  lcd.setCursor(0, 1);
  lcd.print("> " + course[cursorPosition]);
  lcd.blink();
}



/* void classLED() {
  Time t = rtc.time(); // Get current time
  int currentHour = t.hr;

  if (selectedCourse == "Creative Computing" && selectedYear == "Year 3" && selectedGroup == "Group 2" && currentHour >= 9 && currentHour <= 11) {
    digitalWrite(ledPin, HIGH);
  }
} */
