#include<iostream>
#include<math.h>
#include<iomanip>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

bool isLeap(int year) {
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

int daysIn(int month, int year) {
    switch(month) {
        case(1): return 31;
        case(2): 
            if (isLeap(year)) {
                return 29;
            } else return 28;
        case(3): return	31;
        case(4): return 30;
        case(5): return 31;
        case(6): return 30;
        case(7): return 31;
        case (8): return 31;
        case (9): return 30;
        case (10): return 31;
        case (11): return 30;
        case (12): return 31;
    }
    return 0;
}

int getC(int month, int year) {
    switch (month) {
        case (1):
            if (isLeap(year)) {
                return 6;
            } else {
                return 0;
            }
        case (2):
            if (isLeap(year)) {
                return 2;
            } else {
                return 3;
            }
        case (3): return 3;
        case (4): return 6;
        case (5): return 1;
        case (6): return 4;
        case (7): return 6;
        case (8): return 2;
        case (9): return 5;
        case (10): return 0;
        case (11): return 3;
        case (12): return 5;
    }
    return 0;
}

int getDayOfWeek(int month, int year, int day) {
    int s = year / 100;
    int a = year % 100;
    int ds = ((5*a/4) + getC(month, year) + day - 2*(s%4) + 7) % 7;
    return ds;
}

string monthsStr(int month) {  //aesthetic purposes
    switch (month) {
        case (1): return "January";
        case (2): return "February";
        case (3): return "March";
        case (4): return "April";
        case (5): return "May";
        case (6): return "June";
        case (7): return "July";
        case (8): return "August";
        case (9): return "September";
        case (10): return "October";
        case (11): return "November";
        case (12): return "December";
    }
    return 0;
}

void getYear(vector<vector<int>> &v, int year) {  //fills vector
    for (int month = 1; month <=12; month++) {
        vector<int> Month;
        for (int day = 1; day <= daysIn(month, year); day++) {
            Month.push_back(day);
        }
        v.push_back(Month);
    }

}

void displayDay(vector<vector<int>> &v, int year, int month, int day) {
    int x = getDayOfWeek(month + 1, year, day+1);
            
        if (day+1 == daysIn(month+1, year)) {  //spacing between months
            if (x == 2) {
                cout << "\x1B[38;2;246;74;164m" << v[month][day] << "\n" << "\x1B[0m" << endl;
            } else if ((x == 3) || (x == 4) || (x == 5) || (x == 6)) {
                cout << "\x1B[38;2;246;74;164m" << setw(5) << v[month][day] << "\n" << "\x1B[0m" << endl;
            } else {
                cout << "\x1B[38;2;246;74;164m" << setw(5) << v[month][day] << "\x1B[0m" << "\n" << endl;
            }

        } else if (day == 0) {
            switch (x) {  //aligning first row
                case (2):
                    cout << "\x1B[38;2;246;74;164m" << " " << v[month][day] << "\x1B[0m";
                    break; 
                case (3):
                    cout << "\x1B[38;2;246;74;164m" << setw(7)  << v[month][day] << "\x1B[0m";
                    break;
                case (4): 
                    cout << "\x1B[38;2;246;74;164m" << setw(12) << v[month][day] << "\x1B[0m";
                    break;
                case (5):
                    cout << "\x1B[38;2;246;74;164m" << setw(17) << v[month][day] << "\x1B[0m";
                    break;
                case (6):
                    cout << "\x1B[38;2;246;74;164m" << setw(22) << v[month][day] << "\x1B[0m";
                    break;
                case (0): 
                    cout << "\x1B[38;2;246;74;164m" << setw(27) << v[month][day] << "\x1B[0m";
                    break;
                case (1): 
                    cout << "\x1B[38;2;246;74;164m" << setw(32) << v[month][day] << "\x1B[0m" << endl;
                    break;
            }

        } else if (day < 9) { //aligning 1 digit numbers
                switch (x) {
                    case (2):
                        cout << "\x1B[38;2;246;74;164m" << " " << v[month][day] << "\x1B[0m";
                        break;
                    case (3): 
                        cout << "\x1B[38;2;246;74;164m" << setw(5) << v[month][day] << "\x1B[0m";
                        break;
                    case (4):
                        cout << "\x1B[38;2;246;74;164m" << setw(5) << v[month][day] << "\x1B[0m";
                        break;
                    case (5):
                        cout << "\x1B[38;2;246;74;164m" << setw(5) << v[month][day] << "\x1B[0m";
                        break;
                    case (6): 
                        cout << "\x1B[38;2;246;74;164m" << setw(5) << v[month][day] << "\x1B[0m";
                        break;
                    case (0): 
                        cout << "\x1B[38;2;246;74;164m" << setw(5) << v[month][day] << "\x1B[0m";
                        break;
                    case (1):
                        cout << "\x1B[38;2;246;74;164m" << setw(5) << v[month][day] << "\x1B[0m" << endl;
                        break;
                    } 

            } else {
                switch (x) {
                    case (2):
                        cout << "\x1B[38;2;246;74;164m" << v[month][day] << "\x1B[0m";
                        break;
                    case (3): 
                        cout << "\x1B[38;2;246;74;164m" << setw(5) << v[month][day] << "\x1B[0m";
                        break;
                    case (4):
                        cout << "\x1B[38;2;246;74;164m" << setw(5) << v[month][day] << "\x1B[0m";
                        break;
                    case (5):
                        cout << "\x1B[38;2;246;74;164m" << setw(5) << v[month][day] << "\x1B[0m";
                        break;
                    case (6): 
                        cout << "\x1B[38;2;246;74;164m" << setw(5) << v[month][day] << "\x1B[0m";
                        break;
                    case (0): 
                        cout << "\x1B[38;2;246;74;164m" << setw(5) << v[month][day] << "\x1B[0m";
                        break;
                    case (1):
                        cout << "\x1B[38;2;246;74;164m" << setw(5) << v[month][day] << "\x1B[0m" << endl;
                        break;
                    }

                }  //printing calendar default
}

void displaymonth(vector<vector<int>> v, int year, int month, int d) {
    int day = 0;
    while (day < v[month].size()) {
            int x = getDayOfWeek(month+1, year, day+1);

            if (d == v[month][day]) {

            if (day+1 == daysIn(month+1, year)) {  //spacing between months
                if (x == 2) {
                    cout << v[month][day] << "\n" << endl;
                } else if ((x == 3) || (x == 4) || (x == 5) || (x == 6)) {
                    cout << setw(5) << v[month][day] << "\n" << endl;
                } else {
                    cout << "\x1B[38;2;147;250;216m" << setw(5) << v[month][day] << "\x1B[0m" << "\n" << endl;
                }

            } else if (day == 0) {
                switch (x) {  //aligning first row
                    case (2):
                        cout << " " << v[month][day];
                        break; 
                    case (3):
                        cout << setw(7)  << v[month][day];
                        break;
                    case (4): 
                        cout << setw(12) << v[month][day];
                        break;
                    case (5):
                        cout << setw(17) << v[month][day];
                        break;
                    case (6):
                        cout << setw(22) << v[month][day];
                        break;
                    case (0): 
                        cout << "\x1B[38;2;147;250;216m" << setw(27) << v[month][day] << "\x1B[0m";
                        break;
                    case (1): 
                        cout << "\x1B[38;2;147;250;216m" << setw(32) << v[month][day] << "\x1B[0m" << endl;
                        break;
                }

            } else if (day < 9) { //aligning 1 digit numbers
                    switch (x) {
                        case (2):
                            cout << " " << v[month][day];
                            break;
                        case (3): 
                            cout << setw(5) << v[month][day];
                            break;
                        case (4):
                            cout << setw(5) << v[month][day];
                            break;
                        case (5):
                            cout << setw(5) << v[month][day];
                            break;
                        case (6): 
                            cout << setw(5) << v[month][day];
                            break;
                        case (0): 
                            cout << "\x1B[38;2;147;250;216m" << setw(5) << v[month][day] << "\x1B[0m";
                            break;
                        case (1):
                            cout << "\x1B[38;2;147;250;216m" << setw(5) << v[month][day] << "\x1B[0m" << endl;
                            break;
                    } 

            } else {
                switch (x) {
                    case (2):
                        cout << v[month][day];
                        break;
                    case (3): 
                        cout << setw(5) << v[month][day];
                        break;
                    case (4):
                        cout << setw(5) << v[month][day];
                        break;
                    case (5):
                        cout << setw(5) << v[month][day];
                        break;
                    case (6): 
                        cout << setw(5) << v[month][day];
                        break;
                    case (0): 
                        cout << "\x1B[38;2;147;250;216m" << setw(5) << v[month][day] << "\x1B[0m";
                        break;
                    case (1):
                        cout << "\x1B[38;2;147;250;216m" << setw(5) << v[month][day] << "\x1B[0m" << endl;
                        break;
                    }
                
            }
            day++;
        }  //printing calendar default
    }
}

void displayCalendar(vector<vector<int>> v, int year, int m, int d) {  //displays calendar
    for (int month = 0; month < 12; month++) {
        cout << "\x1B[38;2;167;251;252m" << month + 1 << "/" << year << " - " << monthsStr(month + 1) << "\x1B[0m" << endl; //displays month/year - <month name>


        cout << "Mon" << setw(5) << "Tue" << setw(5) << "Wed" << setw(5) << "Thu" << setw(5) << "Fri"  
        << "\x1B[38;2;105;245;199m" << "\x1B[1m" << setw(5) << "Sat" << setw(5) << "Sun" << "\x1B[0m" << endl;  //header

            for (int day = 0; day < v[month].size(); day++) {
                int x = getDayOfWeek(month + 1, year, day+1);
                 
                if ((d == v[month][day]) && (month == m)) {
                    displayDay(v, year, month, d-1);
                } else if (day+1 == daysIn(month+1, year)) {  //spacing between months
                    if (x == 2) {
                        cout << v[month][day] << "\n" << endl;
                    } else if ((x == 3) || (x == 4) || (x == 5) || (x == 6)) {
                        cout << setw(5) << v[month][day] << "\n" << endl;
                    } else {
                        cout << "\x1B[38;2;147;250;216m" << setw(5) << v[month][day] << "\x1B[0m" << "\n" << endl;
                    }

                } else if (day == 0) {
                    switch (x) {  //aligning first row
                        case (2):
                            cout << " " << v[month][day];
                            break; 
                        case (3):
                            cout << setw(7)  << v[month][day];
                            break;
                        case (4): 
                            cout << setw(12) << v[month][day];
                            break;
                        case (5):
                            cout << setw(17) << v[month][day];
                            break;
                        case (6):
                            cout << setw(22) << v[month][day];
                            break;
                        case (0): 
                            cout << "\x1B[38;2;147;250;216m" << setw(27) << v[month][day] << "\x1B[0m";
                            break;
                        case (1): 
                            cout << "\x1B[38;2;147;250;216m" << setw(32) << v[month][day] << "\x1B[0m" << endl;
                            break;
                    }

                } else if (day < 9) { //aligning 1 digit numbers
                        switch (x) {
                            case (2):
                                cout << " " << v[month][day];
                                break;
                            case (3): 
                                cout << setw(5) << v[month][day];
                                break;
                            case (4):
                                cout << setw(5) << v[month][day];
                                break;
                            case (5):
                                cout << setw(5) << v[month][day];
                                break;
                            case (6): 
                                cout << setw(5) << v[month][day];
                                break;
                            case (0): 
                                cout << "\x1B[38;2;147;250;216m" << setw(5) << v[month][day] << "\x1B[0m";
                                break;
                            case (1):
                                cout << "\x1B[38;2;147;250;216m" << setw(5) << v[month][day] << "\x1B[0m" << endl;
                                break;
                            } 

                    } else {
                        switch (x) {
                            case (2):
                                cout << v[month][day];
                                break;
                            case (3): 
                                cout << setw(5) << v[month][day];
                                break;
                            case (4):
                                cout << setw(5) << v[month][day];
                                break;
                            case (5):
                                cout << setw(5) << v[month][day];
                                break;
                            case (6): 
                                cout << setw(5) << v[month][day];
                                break;
                            case (0): 
                                cout << "\x1B[38;2;147;250;216m" << setw(5) << v[month][day] << "\x1B[0m";
                                break;
                            case (1):
                                cout << "\x1B[38;2;147;250;216m" << setw(5) << v[month][day] << "\x1B[0m" << endl;
                                break;
                        }

                    }  //printing calendar default
            }
            cout << endl;
        
    }
}

void newDates(vector<vector<int>> &v, int year) { 
    string option, message;
    int day, month;

    cout << "Do you want to highlight a memory? (y/n)  ";  //should work by pressing enter
    cin >> option;

    if (option == "y") {
        cout << "Input date: ";
        cin >> day >> month;
        getline(cin, message);

        if (day > daysIn(month, year) || (month > 12)) {
            cout <<  "Not a valid date" << endl;

        } else {
            cout << "\x1B[2J" << "\x1B[3J" << flush;
            displayCalendar(v, year, month-1, day);

            cout << "\x1B[38;2;166;247;243m" << day << ((day == 1) ? "st " : (day == 2) ? "nd " : (day == 3) ? "rd " : "th ") 
                    << monthsStr(month) << message << "\x1B[0m" << endl;            
        }   
        
    } else if (option == "n") {
        cout << "See you soon!" << endl;

    } else if ((option != "y") || (option != "n")) {
        cout << "Not a valid option.";
        newDates(v, year);
    }

    bool valid = true;
    while (valid) {
        cout << "Do you want to another highlight a memory? (y/n)  ";  //should work by pressing enter
        cin >> option;

        if (option == "y") {
            cout << "Input date: ";
            cin >> day >> month;
            getline(cin, message);

            if (day > daysIn(month, year) || (month > 12)) {
                cout <<  "Not a valid date" << endl;

            } else {
                cout << "\x1B[2J" << "\x1B[3J" << flush;
                displayCalendar(v, year, month-1, day);

                cout << "\x1B[38;2;166;247;243m" << day << ((day == 1) ? "st " : (day == 2) ? "nd " : (day == 3) ? "rd " : "th ") 
                     << monthsStr(month) << message << "\x1B[0m" << endl;
            }

        } else if (option == "n") {
            cout << "See you soon!" << endl;
            valid = false;

        } else if ((option != "y") || (option != "n")) {
            cout << "Not a valid option.";
            newDates(v, year);
        }

    }
}   

int main() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;
    
    vector<vector<int>> calendar;

    getYear(calendar, year);
    displayCalendar(calendar, year, month-1, day-1);
    newDates(calendar, year);

    return 0; 
}