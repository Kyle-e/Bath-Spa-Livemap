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
const int ledPin7 = 1;

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
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  // Blink LED upon start to ensure it works
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
  digitalWrite(ledPin5, HIGH);
  digitalWrite(ledPin6, HIGH);
  digitalWrite(ledPin7, HIGH);
  delay(500);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  digitalWrite(ledPin5, LOW);
  digitalWrite(ledPin6, LOW);
  digitalWrite(ledPin7, LOW);
  delay(500);
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
  digitalWrite(ledPin5, HIGH);
  digitalWrite(ledPin6, HIGH);
  digitalWrite(ledPin7, HIGH);
  delay(500);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  digitalWrite(ledPin5, LOW);
  digitalWrite(ledPin6, LOW);
  digitalWrite(ledPin7, LOW);

  // Initialize RTC
  Rtc.Begin();

  // SET CURRENT DATE AND TIME FROM MONITOR (ONCE THEN COMMENT OUT)
  // RtcDateTime currentTime = RtcDateTime(__DATE__, __TIME__);
  // Rtc.SetDateTime(currentTime);
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
  delay(500);
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
  digitalWrite(ledPin7, HIGH);
  delay(500);
  digitalWrite(ledPin7, LOW);
}

/* -------------------------------------------- CREATIVE COMPUTING -------------------------------------------- */
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
void roomG06_tomorrowsWeb() {
  lcd.setCursor(0, 1);
  lcd.print("[G06] Tomorrow's Web");
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
  lcd.print("Debates in Psychol..");
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
void roomG06_clinicalPsychology() {
  lcd.setCursor(0, 1);
  lcd.print("[G06] Clinical Psy..");
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
void roomG06_dissertationII() {
  lcd.setCursor(0, 1);
  lcd.print("[G06] Dissertation 2");
}
void roomG06_advancedTopicsPsychology() {
  lcd.setCursor(0, 1);
  lcd.print("[G06] Adv. Psychol..");
}
//    TUTORS
void mrAbel() {
  lcd.setCursor(0, 2);
  lcd.print("Mr. Abel <3");
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

/* -------------------------------------------- CYBER SECURITY -------------------------------------------- */
//    MODULES
// YEAR 1
void databases() {
  lcd.setCursor(0, 1);
  lcd.print("Databases");
}
void digitalForensics() {
  lcd.setCursor(0, 1);
  lcd.print("Digital Forensics");
}
void roomG07_databases() {
  lcd.setCursor(0, 1);
  lcd.print("[G07] Databases");
}
void roomG05_webDevI() {
  lcd.setCursor(0, 1);
  lcd.print("[G05] Web Dev I");
}
void roomG05_databases() {
  lcd.setCursor(0, 1);
  lcd.print("[G05] Databases");
}
void roomG07_webDevI() {
  lcd.setCursor(0, 1);
  lcd.print("[G07] Web Dev I");
}
void roomG05_digitalForensics() {
  lcd.setCursor(0, 1);
  lcd.print("[G05] Digital Fore..");
}
void roomG06_databases() {
  lcd.setCursor(0, 1);
  lcd.print("[G06] Databases");
}
//    TUTORS
void drLiju() {
  lcd.setCursor(0, 2);
  lcd.print("Dr. Liju");
}
void mrDanish() {
  lcd.setCursor(0, 2);
  lcd.print("Mr. Danish");
}







// GET DATE AND TIME
  RtcDateTime now = Rtc.GetDateTime();
  // int dayOfWeek = now.DayOfWeek();
  // int hour = now.Hour();
  // int minute = now.Minute();
  int dayOfWeek = 1;
  int hour = 10;
  int minute = 41;

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
void weekAndHour() {
  lcd.setCursor(0, 0);
  lcd.print(dayOfWeekToString(dayOfWeek));
  lcd.print(", ");
  lcd.print(hour);
  lcd.print(":");
}

void displayAnswers() {
  // CREATIVE COMPUTING
  if (course[selectedCourseIndex] == "Creative Computing") {
    // YEAR 1
    if (year[selectedYearIndex] == "Year 1") {
      // GROUP 1
      if (group[selectedGroupIndex] == "Group 1") {
        // MONDAY
        if (dayOfWeek == 1) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            roomF04();
            lcd.clear();
            weekAndHour();
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
            weekAndHour();
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
            weekAndHour();
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
            weekAndHour();
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
            weekAndHour();
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
            weekAndHour();
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
            weekAndHour();
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
            weekAndHour();
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
            weekAndHour();
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
            weekAndHour();
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
            weekAndHour();
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
            weekAndHour();
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
            weekAndHour();
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
            weekAndHour();
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
            weekAndHour();
            minuteFix();
            creativeCoding();
            msMary();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 13:00]");
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            roomF04();
            lcd.clear();
            weekAndHour();
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
            weekAndHour();
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
            weekAndHour();
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
    // YEAR 2
    else if (year[selectedYearIndex] == "Year 2") {
      // GROUP 1
      if (group[selectedGroupIndex] == "Group 1") {
        // MONDAY
        if (dayOfWeek == 1) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            roomF07();
            lcd.clear();
            weekAndHour();
            minuteFix();
            creativeIndustryChallenge();
            mrUsman();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour >= 11 && hour < 13) {
            breakTime();
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            roomF05();
            lcd.clear();
            weekAndHour();
            minuteFix();
            smartphoneApps();
            msArshiya();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        }
        // WEDNESDAY
        else if (dayOfWeek == 3) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            roomF05();
            lcd.clear();
            weekAndHour();
            minuteFix();
            emergingTechnologies();
            msAnmol();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour >= 11 && hour < 13) {
            breakTime();
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            roomF05();
            lcd.clear();
            weekAndHour();
            minuteFix();
            emergingTechnologies();
            msAnmol();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        }
        // THURSDAY
        else if (dayOfWeek == 4) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            roomF07();
            lcd.clear();
            weekAndHour();
            minuteFix();
            creativeIndustryChallenge();
            mrUsman();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour == 11 && minute <= 14) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 15) || (hour <= 12 && minute <= 44)) {
            roomF06();
            lcd.clear();
            weekAndHour();
            minuteFix();
            smartphoneApps();
            msArshiya();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 12:45]");
          }
          else if ((hour == 12 && minute >= 45) || (hour == 13) || (hour == 14 && minute <= 30)) {
            breakTime();
          }
        }
      }
      // GROUP 2
      else if (group[selectedGroupIndex] == "Group 2") {
        // TUESDAY
        if (dayOfWeek == 2) {
          if ((hour == 9 && minute >= 30) || (hour == 10) || (hour == 11 && minute <= 14)) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 15) || (hour == 12 && minute <= 44)) {
            roomF04();
            lcd.clear();
            weekAndHour();
            minuteFix();
            emergingTechnologies();
            msAnmol();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 12:45]");
          }
          else if (hour == 12 && minute >= 45) {
            breakTime();
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            roomF05();
            lcd.clear();
            weekAndHour();
            minuteFix();
            smartphoneApps();
            msArshiya();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        }
        // WEDNESDAY
        else if (dayOfWeek == 3) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            roomF06();
            lcd.clear();
            weekAndHour();
            minuteFix();
            creativeIndustryChallenge();
            mrUsman();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour == 11 && minute <= 14) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 15) || (hour == 12 && minute <= 44)) {
            roomF06();
            lcd.clear();
            weekAndHour();
            minuteFix();
            emergingTechnologies();
            msAnmol();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 12:45]");
          }
          else if ((hour == 12 && minute >= 45) || (hour == 13) || (hour == 14 && minute <= 30)) {
            breakTime();
          }
        }
        // THURSDAY
        else if (dayOfWeek == 4) {
          if ((hour == 9 && minute >= 30) || (hour == 10) || (hour == 11 && minute <= 14)) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 15) || (hour == 12 && minute <= 44)) {
            roomF07();
            lcd.clear();
            weekAndHour();
            minuteFix();
            creativeIndustryChallenge();
            mrUsman();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 12:45]");
          }
          else if (hour == 12 && minute >= 45) {
            breakTime();
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            roomF07();
            lcd.clear();
            weekAndHour();
            minuteFix();
            smartphoneApps();
            msArshiya();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        }      
      }
      // GROUP 3
      else if (group[selectedGroupIndex] == "Group 3") {
        // MONDAY
        if (dayOfWeek == 1) {
          if ((hour == 9 && minute >= 30) || (hour == 10) || (hour == 11 && minute <= 14)) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 15) || (hour == 12 && minute <= 44)) {
            roomF07();
            lcd.clear();
            weekAndHour();
            minuteFix();
            creativeIndustryChallenge();
            mrUsman();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 12:45]");
          }
          else if (hour == 12 && minute >= 45) {
            breakTime();
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            roomF06();
            lcd.clear();
            weekAndHour();
            minuteFix();
            emergingTechnologies();
            msAnmol();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        } 
        // TUESDAY
        else if (dayOfWeek == 2) {
          if ((hour == 9 && minute >= 30) || (hour == 10) || (hour == 11 && minute <= 14)) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 15) || (hour == 12 && minute <= 44)) {
            roomF05();
            lcd.clear();
            weekAndHour();
            minuteFix();
            smartphoneApps();
            msArshiya();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 12:45]");
          }
          else if (hour == 12 && minute >= 45) {
            breakTime();
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            roomF06();
            lcd.clear();
            weekAndHour();
            minuteFix();
            emergingTechnologies();
            msAnmol();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        }
        // WEDNESDAY
        else if (dayOfWeek == 3) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            roomF07();
            lcd.clear();
            weekAndHour();
            minuteFix();
            creativeIndustryChallenge();
            mrUsman();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour == 11 && minute <= 14) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 15) || (hour == 12 && minute <= 44)) {
            roomF07();
            lcd.clear();
            weekAndHour();
            minuteFix();
            smartphoneApps();
            msArshiya();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 12:45]");
          }
          else if ((hour == 12 && minute >= 45) || (hour == 13) || (hour == 14 && minute <= 30)) {
            breakTime();
          }
        }
      }
    }
    // YEAR 3
    else if (year[selectedYearIndex] == "Year 3") {
      // GROUP 1
      if (group[selectedGroupIndex] == "Group 1") {
        // MONDAY
        if (dayOfWeek == 1) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            roomF03();
            lcd.clear();
            weekAndHour();
            minuteFix();
            physicalComputing();
            msAnmol();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour == 11 && minute <= 14) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 15) || (hour == 12 && minute <= 44)){
            roomF06();
            lcd.clear();
            weekAndHour();
            minuteFix();
            creativeIncubator();
            msArshiya();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 12:45]");
          }
          else if ((hour == 12 && minute <= 45) || (hour == 13) || (hour == 14 && minute <= 30)) {
            breakTime();
          }
        }
        // TUESDAY
        else if (dayOfWeek == 2) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            roomF05();
            lcd.clear();
            weekAndHour();
            minuteFix();
            physicalComputing();
            msAnmol();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour >= 11 && hour < 13) {
            breakTime();
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            roomF07();
            lcd.clear();
            weekAndHour();
            minuteFix();
            tomorrowsWeb();
            mrUsman();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        }
        // WEDNESDAY
        else if (dayOfWeek == 3) {
          if ((hour == 9 && minute >= 30) || (hour == 10) || (hour == 11 && minute <= 14)) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 15) || (hour == 12 && minute <= 44)) {
            lcd.clear();
            weekAndHour();
            minuteFix();
            roomG06_tomorrowsWeb();
            mrUsman();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 12:45]");
          }
          else if (hour == 12 && minute >= 45) {
            breakTime();
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            roomF06();
            lcd.clear();
            weekAndHour();
            minuteFix();
            creativeIncubator();
            msArshiya();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        }
      }
      // GROUP 2
      else if (group[selectedGroupIndex] == "Group 2") {
        // MONDAY
        if (dayOfWeek == 1) {
          if ((hour == 9 && minute >= 30) || (hour == 10) || (hour == 11 && minute <= 14)) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 15) || (hour == 12 && minute <= 44)) {
            roomF03();
            lcd.clear();
            weekAndHour();
            minuteFix();
            physicalComputing();
            msAnmol();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 12:45]");
          }
          else if ((hour == 12 && minute >= 45) || (hour < 13)) {
            breakTime();
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            roomF03();
            lcd.clear();
            weekAndHour();
            minuteFix();
            tomorrowsWeb();
            mrUsman();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        }
        // TUESDAY
        else if (dayOfWeek == 2) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            roomF07();
            lcd.clear();
            weekAndHour();
            minuteFix();
            creativeIncubator();
            msArshiya();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour == 11 && minute <= 14) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 15) || (hour == 12 && minute <= 44)) {
            roomF07();
            lcd.clear();
            weekAndHour();
            minuteFix();
            physicalComputing();
            msAnmol();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 12:45]");
          }
          else if ((hour == 12 && minute >= 45) || (hour == 13) || (hour == 14 && minute <= 30)) {
            breakTime();
          }
        }
        // WEDNESDAY
        else if (dayOfWeek == 3) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            roomF03();
            lcd.clear();
            weekAndHour();
            minuteFix();
            creativeIncubator();
            msArshiya();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour == 11 && hour < 13) {
            breakTime();
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            roomF07();
            lcd.clear();
            weekAndHour();
            minuteFix();
            tomorrowsWeb();
            mrUsman();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        } 
      }
    }  
  }
  // PSYCHOLOGY
  else if (course[selectedCourseIndex] == "Psychology") {
    // YEAR 1
    if (year[selectedYearIndex] == "Year 1") {
      // GROUP 1
      if (group[selectedGroupIndex] == "Group 1") {
        // MONDAY
        if (dayOfWeek == 1) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            roomF01();
            lcd.clear();
            weekAndHour();
            minuteFix();
            debatesInPsy();
            mrAbel();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour == 11 && minute >= 0 && minute <= 29) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 30) || (hour > 11 && hour < 13)) {
            roomF01();
            lcd.clear();
            weekAndHour();
            minuteFix();
            debatesInPsy();
            mrAbel();
            lcd.setCursor(0, 3);
            lcd.print("[11:30 - 13:00]");
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            breakTime();
          }
        }
        // WEDNESDAY
        if (dayOfWeek == 3) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            roomF01();
            lcd.clear();
            weekAndHour();
            minuteFix();
            individualDifferences();
            msAngeleena();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour >= 11 && hour < 13) {
            breakTime();
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            roomF01();
            lcd.clear();
            weekAndHour();
            minuteFix();
            individualDifferences();
            msAngeleena();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        }
        // THURSDAY
        if (dayOfWeek == 4) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            roomF01();
            lcd.clear();
            weekAndHour();
            minuteFix();
            OBM();
            drWaheed();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour == 11 && minute <= 29) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 30) || (hour == 12)) {
            roomF01();
            lcd.clear();
            weekAndHour();
            minuteFix();
            OBM();
            drWaheed();
            lcd.setCursor(0, 3);
            lcd.print("[11:30 - 13:00]");
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            breakTime();
          }
        }
      }
      // GROUP 2
      else if (group[selectedGroupIndex] == "Group 2") {
        // MONDAY
        if (dayOfWeek == 1) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            roomF02();
            lcd.clear();
            weekAndHour();
            minuteFix();
            OBM();
            drRabia();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour == 11 && minute >= 0 && minute <= 29) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 30) || (hour == 12)) {
            roomF02();
            lcd.clear();
            weekAndHour();
            minuteFix();
            OBM();
            drRabia();
            lcd.setCursor(0, 3);
            lcd.print("[11:30 - 13:00]");
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            breakTime();
          }
        }
        // TUESDAY
        else if (dayOfWeek == 2) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            roomF02();
            lcd.clear();
            weekAndHour();
            minuteFix();
            individualDifferences();
            msAngeleena();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour == 11 && minute >= 0 && minute <= 29) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 30) || (hour == 12)) {
            roomF02();
            lcd.clear();
            weekAndHour();
            minuteFix();
            individualDifferences();
            msAngeleena();
            lcd.setCursor(0, 3);
            lcd.print("[11:30 - 13:00]");
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            breakTime();
          }
        }
        // WEDNESDAY
        else if (dayOfWeek == 3) {
          if ((hour == 9 && minute >= 30) || (hour == 10) || (hour == 11 && minute <= 29)) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 30) || (hour == 12)) {
            roomF02();
            lcd.clear();
            weekAndHour();
            minuteFix();
            debatesInPsy();
            mrAbel();
            lcd.setCursor(0, 3);
            lcd.print("[11:30 - 13:00]");
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            roomF02();
            lcd.clear();
            weekAndHour();
            minuteFix();
            debatesInPsy();
            mrAbel();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        }
      }
    }
    // YEAR 2
    else if (year[selectedYearIndex] == "Year 2") {
      // GROUP 1
      if (group[selectedGroupIndex] == "Group 1") {
        // MONDAY
        if (dayOfWeek == 1) {
          if ((hour == 9 && minute >= 30) || (hour == 10) || (hour == 11 && minute <= 29)) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 30) || (hour == 12)) {
            lcd.clear();
            weekAndHour();
            minuteFix();
            roomG06_clinicalPsychology();
            msAngeleena();
            lcd.setCursor(0, 3);
            lcd.print("[11:30 - 13:00]");
          }
          else if ((hour == 13) || (hour == 14 <= 30)) {
            roomF02();
            lcd.clear();
            weekAndHour();
            minuteFix();
            clinicalPsychology();
            msAngeleena();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        }
        // WEDNESDAY
        else if (dayOfWeek == 3) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            roomF02();
            lcd.clear();
            weekAndHour();
            minuteFix();
            CABP();
            drRabia();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour == 11 && minute >= 0 && minute <= 29) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 30) || (hour == 12)) {
            roomF01();
            lcd.clear();
            weekAndHour();
            minuteFix();
            CABP();
            drRabia();
            lcd.setCursor(0, 3);
            lcd.print("[11:30 - 13:00]");
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            breakTime();
          }
        }
        // THURSDAY
        else if (dayOfWeek == 4) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            roomF02();
            lcd.clear();
            weekAndHour();
            minuteFix();
            bioSocialPsychology();
            mrAbel();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour == 11 && minute >= 0 && minute <= 29) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 30) || (hour == 12)) {
            roomF02();
            lcd.clear();
            weekAndHour();
            minuteFix();
            bioSocialPsychology();
            mrAbel();
            lcd.setCursor(0, 3);
            lcd.print("[11:30 - 13:00]");
          }
          else if ((hour == 13) || (hour == 14 <= 30)) {
            breakTime();
          }
        }
      }
      // GROUP 2
      else if (group[selectedGroupIndex] == "Group 2") {
        // MONDAY
        if (dayOfWeek == 1) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            lcd.clear();
            weekAndHour();
            minuteFix();
            roomG06_clinicalPsychology();
            mrsSaima();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          } 
          else if (hour >= 11 && hour < 13) {
            breakTime();
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            lcd.clear();
            weekAndHour();
            minuteFix();
            roomG06_clinicalPsychology();
            mrsSaima();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        }
        // TUESDAY
        else if (dayOfWeek == 2) {
          if ((hour == 9 && minute >= 30) || (hour == 10) || (hour == 11 && minute <= 29)) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 30) || (hour == 12)) {
            roomF01();
            lcd.clear();
            weekAndHour();
            minuteFix();
            bioSocialPsychology();
            mrAbel();
            lcd.setCursor(0, 3);
            lcd.print("[11:30 - 13:00]");
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            roomF03();
            lcd.clear();
            weekAndHour();
            minuteFix();
            bioSocialPsychology();
            mrAbel();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        }
        // THURSDAY
        else if (dayOfWeek == 4) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            roomF03();
            lcd.clear();
            weekAndHour();
            minuteFix();
            CABP();
            drRabia();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour == 11 && minute <= 29) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 30) || (hour == 12)) {
            roomF03();
            lcd.clear();
            weekAndHour();
            minuteFix();
            CABP();
            drRabia();
            lcd.setCursor(0, 3);
            lcd.print("[11:30 - 13:00]");
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            breakTime();
          }
        }
      }
    }
    // YEAR 3
    else if (year[selectedYearIndex] == "Year 3") {
      // GROUP 1
      if (group[selectedGroupIndex] == "Group 1") {
        // TUESDAY
        if (dayOfWeek == 2) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            roomF03();
            lcd.clear();
            weekAndHour();
            minuteFix();
            workInterventions();
            mrsSaima();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour >= 11 && hour < 13) {
            breakTime();
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            roomF01();
            lcd.clear();
            weekAndHour();
            minuteFix();
            workInterventions();
            mrsSaima();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        }
        // WEDNESDAY
        else if (dayOfWeek == 3) {
          if ((hour == 9 && minute >= 30) || (hour == 10) || (hour == 11 && minute <= 29)) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 30) || (hour == 12)) {
            roomF03();
            lcd.clear();
            weekAndHour();
            minuteFix();
            dissertationII();
            mrsSaima();
            lcd.setCursor(0, 3);
            lcd.print("[11:30 - 13:00]");
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            lcd.clear();
            weekAndHour();
            minuteFix();
            roomG06_dissertationII();
            drRabia();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        }
        // THURSDAY
        else if (dayOfWeek == 4) {
          if ((hour == 10) || (hour == 11 && minute <= 29)) {
            lcd.clear();
            weekAndHour();
            minuteFix();
            roomG06_advancedTopicsPsychology();
            msAngeleena();
            lcd.setCursor(0, 3);
            lcd.print("[10:00 - 11:30]");
          }
          else if (hour == 11 && minute >= 30) {
            breakTime();
          }
          else if ((hour == 12) || (hour == 13 && minute <= 29)) {
            lcd.clear();
            weekAndHour();
            minuteFix();
            roomG06_advancedTopicsPsychology();
            msAngeleena();
            lcd.setCursor(0, 3);
            lcd.print("[12:00 - 13:30]");
          }
          else if ((hour == 13 && minute >= 30) || (hour == 14 && minute <= 30)) {
            breakTime();
          }
        }
      }
    }
  }
  // CYBER SECURITY
  else if (course[selectedCourseIndex] == "Cyber Security") {
    // YEAR 1
    if (year[selectedYearIndex] == "Year 1") {
      // GROUP 1
      if (group[selectedGroupIndex] == "Group 1") {
        // TUESDAY
        if (dayOfWeek = 2) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            roomF06();
            lcd.clear();
            weekAndHour();
            minuteFix();
            digitalForensics();
            mrDanish();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour == 11 && minute <= 14) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 15) || (hour == 12 && minute <= 44)) {
            lcd.clear();
            weekAndHour();
            minuteFix();
            roomG07_databases();
            drLiju();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 12:45]");
          }
          else if ((hour == 12 && minute <= 45) || (hour == 13) || (hour == 14 && minute <= 30)) {
            breakTime();
          }
        }
        // WEDNESDAY
        else if (dayOfWeek = 3) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            lcd.clear();
            weekAndHour();
            minuteFix();
            roomG05_webDevI();
            mrDanish();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour == 11 && minute <= 14) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 15) || (hour == 12 && minute <= 44)) {
            lcd.clear();
            weekAndHour();
            minuteFix();
            roomG05_databases();
            drLiju();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 12:45]");
          }
          else if ((hour == 12 && minute >= 45) || (hour == 13) || (hour == 14 && minute <= 30)) {
            breakTime();
          }
        }
        // THURSDAY
        else if (dayOfWeek = 4) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            roomF06();
            lcd.clear();
            weekAndHour();
            minuteFix();
            digitalForensics();
            mrDanish();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour >= 11 && minute < 13) {
            breakTime();
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            lcd.clear();
            weekAndHour();
            minuteFix();
            roomG07_webDevI();
            mrDanish();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        }
      }
      // GROUP 2
      if (group[selectedGroupIndex] == "Group 2") {
        // TUESDAY
        if (dayOfWeek == 2) {
          if ((hour == 9 && minute <= 30) || (hour == 10) || (hour == 11 && minute <= 14)) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 15) || (hour == 12 && minute <= 44)) {
            lcd.clear();
            weekAndHour();
            minuteFix();
            roomG07_databases();
            drLiju();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 12:45]");
          }
          else if (hour == 12 && minute >= 45) {
            breakTime();
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            lcd.clear();
            weekAndHour();
            minuteFix();
            roomG05_digitalForensics();
            mrDanish();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        }
        // WEDNESDAY
        else if (dayOfWeek == 3) {
          if ((hour == 9 && minute >= 30) || (hour == 10)) {
            lcd.clear();
            weekAndHour();
            minuteFix();
            roomG06_databases();
            drLiju();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
          }
          else if (hour >= 11 && hour < 13) {
            breakTime();
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            roomF03();
            lcd.clear();
            weekAndHour();
            minuteFix();
            webDevI();
            mrDanish();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
          }
        }
        // THURSDAY
        else if (dayOfWeek == 4) {
          if ((hour == 9 && minute >= 30) || (hour == 10) || (hour == 11 && minute <= 14)) {
            breakTime();
          }
          else if ((hour == 11 && minute >= 15) || (hour == 12 && minute <= 44)) {
            lcd.clear();
            weekAndHour();
            minuteFix();
            roomG05_digitalForensics();
            mrDanish();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 12:45]");
          }
          else if ((hour == 12 && minute >= 45)) {
            breakTime();
          }
          else if ((hour == 13) || (hour == 14 && minute <= 30)) {
            lcd.clear();
            weekAndHour();
            minuteFix();
            roomG07_webDevI();
            mrDanish();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
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
      lcd.setCursor(0, 2);
      lcd.print("INVALID COURSE");
    }
}

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