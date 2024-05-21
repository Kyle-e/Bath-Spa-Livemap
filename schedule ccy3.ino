if (group[selectedGroupIndex] == "Group 1")
{
    // MONDAY
    if (dayOfWeek == 1)
    {
        if ((hour == 9 && minute >= 30) || (hour > 9 && hour < 11))
        {
            roomF03();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            physicalComputing();
            msAnmol();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
        }
        else if (hour == 11 && minute >= 0 && minute < 15)
        {
            breakTime();
        }
        else if ((hour == 11 && minute >= 15) || (hour > 11 && hour < 13) || (hour == 13 && minute <= 14))
        {
            roomF06();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            creativeIncubator();
            msArshiya();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 13:00]");
        }
        else if ((hour == 13 && minute >= 15) || (hour > 13 && hour < 14) || (hour == 14 && minute <= 30))
        {
            breakTime();
        }
    }
    // TUESDAY
    else if (dayOfWeek == 2)
    {
        if ((hour == 9 && minute >= 30) || (hour > 9 && hour < 11))
        {
            roomF05();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            physicalComputing();
            msAnmol();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
        }
        else if ((hour == 11 && minute >= 0) || (hour > 11 && hour < 13))
        {
            breakTime();
        }
        else if ((hour == 13 && minute >= 0) || (hour == 14 && minute <= 30))
        {
            roomF07();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            tomorrowsWeb();
            mrUsman();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
        }
    }
    // WEDNESDAY
    else if (dayOfWeek == 4)
    {
        if ((hour == 9 && minute >= 30) || (hour == 10) || (hour == 11 && minute <= 14))
        {
            breakTime();
        }
        else if ((hour >= 11 && minute >= 15) || (hour < 13))
        {
            roomG06();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            tomorrowsWeb();
            mrUsman();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 13:00]");
        }
        else if ((hour == 13 && minute >= 0) || (hour == 14 && minute <= 30))
        {
            roomF06();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            creativeIncubator();
            msArshiya();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
        }
    }
}

// GROUP 2 BEST GROUP UWU
if (group[selectedGroupIndex] == "Group 2")
{
    // MONDAY
    if (dayOfWeek == 1)
    {
        if ((hour == 9 && minute >= 30) || (hour > 9 && hour < 11) || (hour == 11 && minute <= 14))
        {
            breakTime();
        }
        else if ((hour == 11 && minute >= 0) || (hour > 11 && hour < 12) || (hour == 12 && minute <= 44))
        {
            roomF03();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            physicalComputing();
            msAnmol();
            lcd.setCursor(0, 3);
            lcd.print("[11:15 - 12:45]");
        }
        else if ((hour == 12 && minute >= 45) || (hour < 13))
        {
            breakTime();
        }
        else if ((hour == 13) || (hour == 14 && minute <= 30))
        {
            roomF03();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            tomorrowsWeb();
            mrUsman();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
        }
    }
    // TUESDAY
    else if (dayOfWeek == 2)
    {
        if ((hour == 9 && minute >= 30) || (hour > 9 && hour < 11))
        {
            roomF07();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            creativeIncubator();
            msArshiya();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
        }
        else if (hour == 11 && minute <= 14)
        {
            breakTime();
        }
        else if ((hour == 11 && minute >= 15) || (hour == 12 && minute <= 44))
        {
            roomF07();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            tomorrowsWeb();
            mrUsman();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
        }
        else if ((hour == 12 && minute >= 15) || (hour > 12 && hour < 14) || (hour == 14 && minute >= 30))
        {
            breakTime();
        }
    }
    // WEDNESDAY
    else if (dayOfWeek == 4)
    {
        if ((hour == 9 && minute >= 30) || (hour > 9 && hour < 11))
        {
            roomF03();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            creativeIncubator();
            msArshiya();
            lcd.setCursor(0, 3);
            lcd.print("[9:30 - 11:00]");
        }
        else if ((hour >= 11 && minute >= 15) || (hour < 13))
        {
            breakTime();
        }
        else if ((hour == 13 && minute >= 0) || (hour == 14 && minute <= 30))
        {
            roomF07();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(dayOfWeekToString(dayOfWeek));
            lcd.print(", ");
            lcd.print(hour);
            lcd.print(":");
            minuteFix();
            tomorrowsWeb();
            mrUsman();
            lcd.setCursor(0, 3);
            lcd.print("[13:00 - 14:30]");
        }
    }
}