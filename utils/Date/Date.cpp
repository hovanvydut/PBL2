#include "Date.h"

Date::Date()
{

}

Date::Date(int year, int month, int day) {
    if (year < 0) {
        throw "Year must be greater than 0";
    }
    if (month <= 0 || month > 12) {
        throw "Month must be between 1 and 12";
    }
    if (day <= 0 || day > 31) {
        throw "Day must be between 1 and 31";
    }

    this->year = year;
    this->month = month;
    this->day = day;
}

Date::Date(std::string dateString) {
    std::string *arr = this->split(dateString, '-');
    this->year = stringToInt(arr[0]);
    this->month = stringToInt(arr[1]);
    this->day = stringToInt(arr[2]);
}

Date::Date(QString dateString) {
    QString *arr = this->split(dateString, '-');
    this->year = arr[0].toInt();
    this->month = arr[1].toInt();
    this->day = arr[2].toInt();
}

Date::~Date()
{

}

std::string* Date::split(std::string dateString, char seperated) {
    std::string *arr = new std::string[3];
    int count = 0;
    std::string acc;
    for (char s : dateString) {
        if (s == seperated) {
            arr[count] = acc;
            acc = "";
            count++;
        } else {
            acc += s;
        }
    }
    arr[count] = acc;
    if (count != 2) {
      throw "Date::split --> Date string is invalid";
    }
    return arr;
}

QString* Date::split(QString dateString, QChar seperated) {
    QString *arr = new QString[3];
    int count = 0;
    QString acc;
    for (QChar s : dateString) {
        if (s == seperated) {
            arr[count] = acc;
            acc = "";
            count++;
        } else {
            acc += s;
        }
    }
    arr[count] = acc;
    if (count != 2) {
      throw "Date::split --> Date string is invalid";
    }
    return arr;
}

int Date::stringToInt(std::string str) {
  int num = 0;
  int factor = 1;
  for (int i = str.length() - 1; i >= 0; i--) {
    if (str[i] < '0' || str[i] > '9') {
      throw "Date::stringToInt --> String is invalid";
    }
    int x = str[i] - 48;
    num = num + x * factor;
    factor = factor * 10;
  }
  return num;
}

int Date::stringToInt(QString str) {
  return str.toInt();
}

std::ostream& operator << (std::ostream& o, Date& date) {
  o << date.day << "/" << date.month << "/" << date.year << std::endl;
  return o;
}

