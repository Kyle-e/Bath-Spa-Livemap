#include <LiquidCrystal_I2C.h>
#include <ThreeWire.h>
#include <RtcDS1302.h>  // Rtc by Makuna

// Define pins
const int downButton = 2;
const int selectButton = 3;
const int upButton = 4;
// RTC: 6, 7, 8
const int ledPin1 = 13;
const int ledPin2 = 12;
const int ledPin3 = 11;
const int ledPin4 = 10;
const int ledPin5 = 9;
const int ledPin6 = 5;
// const int ledPin7 = MISSING PIN

// BUTTON STATES (DOWN)
int downButtonState = 0;
int lastDownButtonState = 0;
bool downButtonPressed = false;
// SELECT
int selectButtonState = 0;
int lastSelectButtonState = 0;
bool selectButtonPressed = false;
// UP
int upButtonState = 0;
int lastUpButtonState = 0;
bool upButtonPressed = false;

// INITIALIZE
LiquidCrystal_I2C lcd(0x27, 20, 4);

// INITIALIZE DS1302 RTC
ThreeWire myWire(7, 6, 8); // DAT, CLK, RST
RtcDS1302<ThreeWire> Rtc(myWire);

// OPTIONS STORED IN ARRAYS, VARIABLE FOR SELECTED INDEX
String course[] = {"Creative Computing", "Psychology", "Cyber Security"};
String year[] = {"Year 1", "Year 2", "Year 3"};
String group[] = {"Group 1", "Group 2", "Group 3"};
int selectedCourseIndex = 0;
int selectedYearIndex = 0;
int selectedGroupIndex = 0;

// STATE VARIABLE TO TRACK SELECTION
enum SelectionState { COURSE, YEAR, GROUP, DONE };
SelectionState currentState = COURSE;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  displayCourse();

  // Initialize buttons as input
  pinMode(downButton, INPUT);
  pinMode(selectButton, INPUT);
  pinMode(upButton, INPUT);

  // Initialize LED pin as output
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  // Blink LED upon start to ensure it works
  digitalWrite(ledPin1, HIGH); 
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  delay(500);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);

  // Initialize RTC
  Rtc.Begin();

  // SET CURRENT DATE AND TIME FROM MONITOR (ONCE THEN COMMENT OUT)
  RtcDateTime currentTime = RtcDateTime(__DATE__, __TIME__);
  Rtc.SetDateTime(currentTime);
  // UNCOMMENT THE LINES ABOVE TO SET TIME, THEN COMMENT AFTER UPLOADING
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
      delay(10000);  // Delay for 10 seconds
      resetSelection();
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

// ROOM LED PINS

void roomF01() {
  digitalWrite(ledPin1, HIGH);
  delay(500);
  digitalWrite(ledPin1, LOW);
  }
void roomF02() {
  digitalWrite(ledPin2, HIGH);
  delay(500);
  digitalWrite(ledPin2, LOW);
  }
void roomF03() {
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin3, LOW);
  }
void roomF04() {
  digitalWrite(ledPin4, HIGH);
  delay(500);
  digitalWrite(ledPin4, LOW);
  }
void roomF05() {
  digitalWrite(ledPin5, HIGH);
  delay(500);
  digitalWrite(ledPin5, LOW);
  }
void roomF06() {
  digitalWrite(ledPin6, HIGH);
  delay(500);
  digitalWrite(ledPin6, LOW);
  }
void roomF07() {
  // digitalWrite(ledPin7, HIGH);
  delay(500);
  // igitalWrite(ledPin7, LOW);
  }

/* -------------------------------------------- CREATIVE COMPUTING, YEAR 1 -------------------------------------------- */
//    MODULES
// YEAR 1
void ideationUXDesign() {
  lcd.setCursor(0, 1);
  lcd.print("Ideation & UX Design");
  }
void creativeCoding() {
  lcd.setCursor(0, 1);
  lcd.print("Creative Coding");
  }
void webDevI() {
  lcd.setCursor(0, 1);
  lcd.print("Web Dev I");
  }
// YEAR 2
void creativeIndustryChallenge() {
  lcd.setCursor(0, 1);
  lcd.print("Creative Industry Challenge");
  }
void smartphoneApps() {
  lcd.setCursor(0, 1);
  lcd.print("Smartphone Apps");
  }
void emergingTechnologies() {
  lcd.setCursor(0, 1);
  lcd.print("Emerging Technologies");
  }
// YEAR 3
void physicalComputing() {
  lcd.setCursor(0, 1);
  lcd.print("Physical Computing");
  }
void creativeIncubator(){
  lcd.setCursor(0, 1);
  lcd.print("Creative Incubator");
  }
void tomorrowsWeb() {
  lcd.setCursor(0, 1);
  lcd.print("Tomorrow's Web");
  }
//    TUTORS
void mrIftikhar() {
  lcd.setCursor(0, 2);
  lcd.print("Mr. Iftikhar");
  }
void msMary() {
  lcd.setCursor(0, 2);
  lcd.print("Ms. Mary");
  }
void msRafia() {
  lcd.setCursor(0, 2);
  lcd.print("Ms. Rafia");
  }
void mrUsman() {
  lcd.setCursor(0, 2);
  lcd.print("Mr. Usman");
  }
void msArshiya() {
  lcd.setCursor(0, 2);
  lcd.print("Ms. Arshiya");
  }
void msAnmol() {
  lcd.setCursor(0, 2);
  lcd.print("Ms. Anmol");
  }


/* -------------------------------------------- PSYCHOLOGY -------------------------------------------- */
//    MODULES
// YEAR 1
void debatesInPsy() {
  lcd.setCursor(0, 1);
  lcd.print("Debates in Psychology");
  }
void OBM() {
  lcd.setCursor(0, 1);
  lcd.print("OBM");
  }
void individualDifferences() {
  lcd.setCursor(0, 1);
  lcd.print("Individual Differences");
  }
// YEAR 2
void clinicalPsychology() {
  lcd.setCursor(0, 1);
  lcd.print("Clinical Psychology");
  }
void bioSocialPsychology() {
  lcd.setCursor(0, 1);
  lcd.print("Bio & Social Psychology");
  }
void CABP() {
  lcd.setCursor(0, 1);
  lcd.print("CABP");
  }
// YEAR 3
void workInterventions() {
  lcd.setCursor(0, 1);
  lcd.print("Work Interventions");
  }
void dissertationII() {
  lcd.setCursor(0, 1);
  lcd.print("Dissertation 2");
  }
void advancedTopicsPsychology() {
  lcd.setCursor(0, 1);
  lcd.print("Advanced Topics in Psy");
  }
//    TUTORS
void mrAbel() {
  lcd.setCursor(0, 2);
  lcd.print("Mr. Abel");
  }
void drRabia() {
  lcd.setCursor(0, 2);
  lcd.print("Dr. Rabia");
  }
void drWaheed() {
  lcd.setCursor(0, 2);
  lcd.print("Dr. Waheed");
  }
void msAngeleena() {
  lcd.setCursor(0, 2);
  lcd.print("Ms. Angeleena");
  }
void mrsSaima() {
  lcd.setCursor(0, 2);
  lcd.print("Mrs. Saima");
  }

/* -------------------------------------------- PSYCHOLOGY -------------------------------------------- */
// MODULES
// YEAR 1
void databases() {
  lcd.setCursor(0, 1);
  lcd.print("Databases");
}
void digitalForensics() {
  lcd.setCursor(0, 1);
  lcd.print("Digital Forensics");
}
// TUTORS
void drLiju() {
  lcd.setCursor(0, 2);
  lcd.print("Dr. Liju");
}
void drDanish() {
  lcd.setCursor(0, 2);
  lcd.print("Dr. Danish");
}







// GET DATE AND TIME
  RtcDateTime now = Rtc.GetDateTime();
  // int dayOfWeek = now.DayOfWeek();
  // int hour = now.Hour();
  //int minute = now.Minute();
  int dayOfWeek = 4;
  int hour = 14;
  int minute = 22;

// MISC. FUNCTIONS
void breakTime() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(dayOfWeekToString(dayOfWeek));
  lcd.print(", ");
  lcd.print(hour);
  lcd.print(":");
  minuteFix();
  lcd.setCursor(0, 1);
  lcd.print("Breaktime");
}

void minuteFix() {
  // ADD 0 BEFORE SINGLE DIGIT MINUTE
  if (minute >= 0 && minute <= 9) {
    lcd.print("0");
    lcd.print(minute);
    } else {
    lcd.print(minute);
 }
}

void displayAnswers() {

  // COURSE - CREATIVE COMPUTING
  if (course[selectedCourseIndex] == "Creative Computing") {
    // YEAR 1
    if (year[selectedYearIndex] == "Year 1") {
      // GROUP 1
      if (group[selectedGroupIndex] == "Group 1") {
        // MONDAY
        if (dayOfWeek == 1) {
          if ((hour == 9 && minute >= 30) || (hour > 9 && hour < 11)) {
            roomF04();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            ideationUXDesign();
            mrIftikhar();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour == 11 && minute >= 0 && minute < 15) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 15) || (hour > 11 && hour < 12) || (hour == 12 && minute <= 44)) {
            roomF04();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            creativeCoding();
            msMary();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 12:45]");
          }
          else if ((hour == 12 && minute >= 45) || (hour > 12 && hour < 14) || (hour == 14 && minute <= 30)) {
            breakTime();
          }
        }
        // WEDNESDAY
        else if (dayOfWeek == 3) {
          if ((hour == 9 && minute >= 30) || (hour > 9 && hour < 11)) {
            roomF04();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            ideationUXDesign();
            mrIftikhar();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour == 11 && minute >= 0 && minute <= 14) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 15) || (hour > 11 && hour < 12) || (hour == 12 && minute <= 44)) {
            roomF04();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            webDevI();
            msRafia();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 12:45]");
          }
          else if ((hour == 12 && minute >= 45) || (hour > 12 && hour < 14) || (hour == 14 && minute <= 30)) {
            breakTime();
          }
        }
        // THURSDAY
        else if (dayOfWeek == 4) {
          if ((hour == 9 && minute >= 30) || (hour > 9 && hour < 11)) {
            roomF04();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            webDevI();
            msRafia();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if ((hour >= 11 && hour < 13)) {
            breakTime();
          }
          else if ((hour >= 13 && hour < 14) || (hour == 14 && minute <= 30)) {
            roomF04();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            creativeCoding();
            msMary();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        }
      }
      // GROUP 2
      else if (group[selectedGroupIndex] == "Group 2") {
        // MONDAY
        if (dayOfWeek == 1) {
          if ((hour == 9 && minute >= 30) || (hour > 9 && hour < 11)) {
            roomF05();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            webDevI();
            msRafia();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if ((hour == 11 && minute >= 0) || (hour > 11 && hour < 12) || (hour == 12 && minute <= 59)) {
            breakTime();
          }
          else if ((hour == 13 && minute >= 0) || (hour > 13 && hour < 14) || (hour == 14 && minute <= 30)) {
            roomF04();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            creativeCoding();
            msMary();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        }
        // TUESDAY
        else if (dayOfWeek == 2) {
          if ((hour == 9 && minute >= 30) || (hour > 9 && hour < 11)) {
            roomF04();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            creativeCoding();
            msMary();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if ((hour == 11 && minute >= 0) || (hour > 11 && hour < 13)) {
            breakTime();
          }
          else if ((hour == 13 && minute >= 0) || (hour > 13 && hour < 14) || (hour == 14 && minute <= 30)) {
            roomF04();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            ideationUXDesign();
            mrIftikhar();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        }
        // THURSDAY
        else if (dayOfWeek == 4) {
          if ((hour == 9 && minute >= 30) || (hour > 9 && hour < 11) || (hour == 11 && minute <= 14)) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 15) || (hour > 11 && hour < 12) || (hour == 12 && minute <= 44)) {
            roomF04();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            ideationUXDesign();
            mrIftikhar();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 12:45]");
          }
          else if ((hour == 12 && minute >= 45) || (hour > 12 && hour < 13)) {
            breakTime();
          }
          else if ((hour == 13 && minute >= 0) || (hour > 13 && hour < 14) || (hour == 14 && minute <= 30)) {
            roomF05();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            webDevI();
            msRafia();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        }
      }
      // GROUP 3
      else if (group[selectedGroupIndex] == "Group 3") {
        // MONDAY
        if (dayOfWeek == 1) {
          if ((hour == 9 && minute >= 30) || (hour > 9 && hour < 11)) {
            roomF06();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            creativeCoding();
            msMary();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour == 11 && minute >= 0 && minute <= 14) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 15) || (hour == 12 && minute <= 44)) {
            roomF05();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            webDevI();
            msRafia();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 12:45]");
          }
          else if ((hour == 12 && minute >= 45) || (hour > 12 && hour < 14) || (hour == 14 && minute <= 30)) {
            breakTime();
          }
        }
        // WEDNESDAY
        else if (dayOfWeek == 3) {
          if ((hour == 9 && minute >= 30) || (hour > 9 && hour < 11) || (hour == 11 && minute <= 14)) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 15) || (hour > 11 && hour < 13)) {
            roomF05();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            creativeCoding();
            msMary();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 13:00]");
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            roomF04();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            ideationUXDesign();
            mrIftikhar();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");            
          }
        }
        // THURSDAY
        else if (dayOfWeek == 4) {
          if ((hour == 9 && minute >= 30) || (hour > 9 && hour < 11)) {
            roomF04();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            ideationUXDesign();
            mrIftikhar();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour == 11 && minute >= 0 && minute <= 14) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 15) || (hour == 12 && minute <= 44)) {
            roomF05();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            webDevI();
            msRafia();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 12:45]");
          }
          else if ((hour == 12 && minute >= 45) || (hour == 13) || (hour == 14 && minute <= 30)) {
            breakTime(); 
          }
        }
      }
    }
  } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(dayOfWeekToString(dayOfWeek));
      lcd.print(", ");
      lcd.print(hour);
      lcd.print(":");
      minuteFix();
      lcd.setCursor(0, 1);
      lcd.print("Error 609");
    }
}


  /*
  // Check if the specific combination is selected and it's Tuesday between 12:30 and 13:00
  if (course[selectedCourseIndex] == "Creative Computing" &&
      year[selectedYearIndex] == "Year 1" &&
      group[selectedGroupIndex] == "Group 1" &&
      dayOfWeek == 0 &&
      //(hour == 9 && minute >= 30) || (hour > 9 && hour < 11) || (hour == 11 && minute == 0)
      (hour == 16 && minute >= 40) || (hour > 16 && hour < 17) || (hour == 17 && minute == 0)
      ) {
          roomF01();
          lcd.clear();

        } 
        else if (hour == 11 && minute >= 0 && minute <= 15) {
            digitalWrite(ledPin2, HIGH); // Turn on the LED
            delay(500);
            digitalWrite(ledPin2, LOW);
          }
    */



// REPLACE NUMBERS WITH DAYS OF THE WEEK FOR STRING USE
String dayOfWeekToString(int dayOfWeek) {
  switch(dayOfWeek) {
    case 0: return "Sunday";
    case 1: return "Monday";
    case 2: return "Tuesday";
    case 3: return "Wednesday";
    case 4: return "Thursday";
    case 5: return "Friday";
    case 6: return "Saturday";
    default: return "Unknown";
  }
}

void resetSelection() {
  selectedCourseIndex = 0;
  selectedYearIndex = 0;
  selectedGroupIndex = 0;
  currentState = COURSE;
  displayCourse();
}

void theButton(String options[], int &selectedIndex, void (*displayFunction)()) {
  // Down button
  downButtonState = digitalRead(downButton);
  if (downButtonState == HIGH && lastDownButtonState == LOW) {
    downButtonPressed = true;
  }
  lastDownButtonState = downButtonState;
  if (downButtonPressed) {
    selectedIndex = (selectedIndex + 1) % 3;
    displayFunction();
    downButtonPressed = false;
    delay(500);
  }

  // Up button
  upButtonState = digitalRead(upButton);
  if (upButtonState == HIGH && lastUpButtonState == LOW) {
    upButtonPressed = true;
  }
  lastUpButtonState = upButtonState;
  if (upButtonPressed) {
    selectedIndex = (selectedIndex - 1 + 3) % 3;
    displayFunction();
    upButtonPressed = false;
    delay(500);
  }

  // Select button
  selectButtonState = digitalRead(selectButton);
  if (selectButtonState == HIGH && lastSelectButtonState == LOW) {
    selectButtonPressed = true;
  }
  lastSelectButtonState = selectButtonState;
  if (selectButtonPressed) {
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
    selectButtonPressed = false;
    delay(500);
  }
}
