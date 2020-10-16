#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
#include <QString>

class Date
{
private:
    int year;
    int month;
    int day;
public:
    Date();
    Date(int year, int month, int day);
    Date(std::string dateString);
    Date(QString dateString);

    std::string* split(std::string dateString, char seperated);
    QString* split(QString dateString, QChar seperated);

    int stringToInt(std::string);
    int stringToInt(QString str);

    friend std::ostream& operator << (std::ostream& o, Date& date);
    ~Date();
};


#endif // DATE_H
