#include <LiquidCrystal_I2C.h>

// Define pins
const int downButton = 2;
const int selectButton = 3;
const int upButton = 4;
const int ledPin = 13;
/* DOWN BUTTON */
int downButtonState = 0;
int lastDownButtonState = 0;
bool downButtonPressed = false;
/* SELECT BUTTON */
int selectButtonState = 0;
int lastSelectButtonState = 0;
bool selectButtonPressed = false;
/* UP BUTTON */
int upButtonState = 0;
int lastUpButtonState = 0;
bool upButtonPressed = false;

String course[] = {"Creative Computing", "Psychology", "Cyber Security"};
String year[] = {"Year 1", "Year 2", "Year 3"};
String group[] = {"Group 1", "Group 2", "Group 3"};

int selectedCourseIndex = 0;
int selectedYearIndex = 0;
int selectedGroupIndex = 0;

enum SelectionState { COURSE, YEAR, GROUP, DONE };
SelectionState currentState = COURSE;

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  displayCourse();

  // Initialize buttons as input
  pinMode(downButton, INPUT);
  pinMode(selectButton, INPUT);
  pinMode(upButton, INPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  switch (currentState) {
    case COURSE:
      theButton(course, selectedCourseIndex, displayCourse);
      break;
    case YEAR:
      theButton(year, selectedYearIndex, displayYear);
      break;
    case GROUP:
      theButton(group, selectedGroupIndex, displayGroup);
      break;
    case DONE:
      displayAnswers();
      // delay(5000);
      restartFunc();
      break;
  }
}

void displayCourse() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Select course:");
  for (int i = 0; i < 3; i++) {
    lcd.setCursor(0, i + 1);
    if (i == selectedCourseIndex) {
      lcd.print("> ");
    } else {
      lcd.print(" ");
    }
    lcd.print(course[i]);
  }
}

void displayYear() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Select year:");
  for (int i = 0; i < 3; i++) {
    lcd.setCursor(0, i + 1);
    if (i == selectedYearIndex) {
      lcd.print("> ");
    } else {
      lcd.print(" ");
    }
    lcd.print(year[i]);
  }
}

void displayGroup() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Select group:");
  for (int i = 0; i < 3; i++) {
    lcd.setCursor(0, i + 1);
    if (i == selectedGroupIndex) {
      lcd.print("> ");
    } else {
      lcd.print(" ");
    }
    lcd.print(group[i]);
  }
}

void displayAnswers() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Selected answers:");
  lcd.setCursor(0, 1);
  lcd.print(course[selectedCourseIndex]);
  lcd.setCursor(0, 2);
  lcd.print(year[selectedYearIndex]);
  lcd.setCursor(0, 3);
  lcd.print(group[selectedGroupIndex]);

  if (course[selectedCourseIndex] == "Psychology" &&
      year[selectedYearIndex] == "Year 2" &&
      group[selectedGroupIndex] == "Group 2") {
        digitalWrite(ledPin, HIGH);
        delay(700);
        digitalWrite(ledPin, LOW);
        delay(700);
        digitalWrite(ledPin, HIGH);
        delay(700);
        digitalWrite(ledPin, LOW);
        delay(700);
        digitalWrite(ledPin, HIGH);
        delay(3000);
        digitalWrite(ledPin, LOW);
      } else {
        digitalWrite(ledPin, LOW);
      }
}

void restartFunc() {
  selectedCourseIndex = 0;
  selectedYearIndex = 0;
  selectedGroupIndex = 0;
  currentState = COURSE;
  displayCourse();
}

void theButton(String options[], int &selectedIndex, void (*displayFunction)()) {

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
    selectedIndex = (selectedIndex + 1) % 3;
    displayFunction();
    downButtonPressed = false;
    delay(300);
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
    selectButtonPressed = false;
    delay(300);
    switch (currentState) {
      case COURSE:
        currentState = YEAR;
        displayYear();
        break;
      case YEAR:
        currentState = GROUP;
        displayGroup();
        break;
      case GROUP:
        currentState = DONE;
        displayAnswers();
        break;
      case DONE:
        // Do nothing
        break;
    }
  }

  /* ---- UP BUTTON ---- */
  upButtonState = digitalRead(upButton);
  // check if button is pressed and not pressed before
  if (upButtonState == HIGH && lastUpButtonState == LOW) {
    upButtonPressed = true;
  }
  // update lastButtonState
  lastUpButtonState = upButtonState;
  // if the button has been pressed, do something
  if (upButtonPressed) {
    selectedIndex = (selectedIndex - 1 + 3) % 3;
    displayFunction();
    upButtonPressed = false;
    delay(300);
  }

}
