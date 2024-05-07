#include <LiquidCrystal_I2C.h>

// Define pins
const int downButton = 2;
const int selectButton = 3;
const int upButton = 4;
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

// unsigned long lastDebounceTime = 0;
// unsigned long debounceDelay = 50;

String course[] = {"Creative Computing", "Psychology", "Cyber Security"};
String year[] = {"Year 1", "Year 2", "Year 3"};
String group[] = {"Group 1", "Group 2", "Group 3"};
int selectedCourseIndex = 0;

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  Serial.begin(9600);
  // lcd.init();
  // lcd.backlight();

  Serial.println("\nInitializing serial monitor...");
  // Initialize buttons as input
  pinMode(downButton, INPUT);
  pinMode(selectButton, INPUT);
  pinMode(upButton, INPUT);
}

void loop() {
  theButton();
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
    Serial.print("[FUNC] Down button executed.\n");

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
    Serial.print("[FUNC] Select button executed.\n");

    // set back to false to prevent multiple executions
    selectButtonPressed = false;
    delay(500);
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
    /* INSERT UP FUNCTION HERE */
    Serial.print("[FUNC] Up button executed.\n");

    // set back to false to prevent multiple executions
    upButtonPressed = false;
    delay(500);
  }

}
