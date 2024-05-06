#include <LiquidCrystal_I2C.h>

// Define pins
const int downButton = 2;
const int selectButton = 3;
/* DOWN BUTTON */
int downButtonState = 0;
int lastDownButtonState = 0;
bool downButtonPressed = false;
/* SELECT BUTTON */
int selectButtonState = 0;
int lastSelectButtonState = 0;
bool selectButtonPressed = false;

// unsigned long lastDebounceTime = 0;
// unsigned long debounceDelay = 50;

String courses[] = {"Creative Computing", "Psychology", "Cyber Security"};
int selectedCourseIndex = 0;

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  Serial.begin(9600);
  // lcd.init();
  // lcd.backlight();

  Serial.println("Initializing serial monitor...");
  // Initialize buttons as input
  pinMode(downButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT);
  // pinMode(selectButton, INPUT);
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
    Serial.print("Down button has been pressed\n");

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
    Serial.print("Select button has been pressed\n");

    // set back to false to prevent multiple executions
    selectButtonPressed = false;
    delay(500);
  }
}
