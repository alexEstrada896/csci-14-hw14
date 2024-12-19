/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/


#include <iomanip>
#include <iostream>
using namespace std;
//total months 
const int TOTALMONTHS = 6;
//structure to hold the data for each month 
struct WeatherData {
    double totalRainfall;
    double highTemp;
    double lowTemp;
    double avgTemp;
};
//function to gain user input for each month 
void InputData(WeatherData& d, string monthname);
//function to output and calculate user data 
void OutputData(const WeatherData d[], const string monthmame[]);
//enum to store the months 
enum Month { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE };

int main() {
    //array structure for the 6 months 
    WeatherData months[TOTALMONTHS];
   //array structure for the names of the 6 months 
    string monthnames[TOTALMONTHS] = { "January", "February", "March", "April", "May", "June" };

    //inputs data for each month 
    for (int i = 0; i <= JUNE; i++) {
        InputData(months[i], monthnames[i]);
    }
//outputs data for each month 
    OutputData(months, monthnames);

    return 0;
}
//function to input user data for each month 
void InputData(WeatherData& d, string monthName) {
    cout << "What is the total rainfall (inch) in " << monthName << ": ";
    cin >> d.totalRainfall;

    cout << "What is the high temperature (degrees Fahrenheit) in " << monthName << ": ";
    cin >> d.highTemp;
//validates input   
    while (d.highTemp < -100 || d.highTemp > 140) {
        cout << "Invalid input. Please enter a value between -100 and 140: ";
        cin >> d.highTemp;
    }

    cout << "What is the low temperature (degrees Fahrenheit) in " << monthName << ": ";
    cin >> d.lowTemp;
//validates input  
    while (d.lowTemp < -100 || d.lowTemp > 140) {
        cout << "Invalid input. Please enter a value between -100 and 140: ";
        cin >> d.lowTemp;
    }

    d.avgTemp = (d.highTemp + d.lowTemp) / 2.0;
}
//function to output data for each month 
void OutputData(const WeatherData d[], const string monthnames[]) {
    double totalRainfall = 0;
    double totalAvgTemp = 0;
    double highestTemp = -1000.0;
    double lowestTemp = 1000.0;
    string highestMonth, lowestMonth;

    for (int i = 0; i <= JUNE; i++) {
        totalRainfall += d[i].totalRainfall;
        totalAvgTemp += d[i].avgTemp;

        if (d[i].highTemp > highestTemp) {
            highestTemp = d[i].highTemp;
            highestMonth = monthnames[i];
        }

        if (d[i].lowTemp < lowestTemp) {
            lowestTemp = d[i].lowTemp;
            lowestMonth = monthnames[i];
        }
    }

    double avgTotalRainfall = totalRainfall / TOTALMONTHS;
    double avgTotalTemp = totalAvgTemp / TOTALMONTHS;

    cout << fixed << setprecision(2);
    cout << "The total rainfall for the half year (inch): " << totalRainfall << endl;
    cout << "The average monthly rainfall (inch): " << avgTotalRainfall << endl;
    cout << "The highest temperature was " << highestTemp << ", which occurred in " << highestMonth << "." << endl;
    cout << "The lowest temperature was " << lowestTemp << ", which occurred in " << lowestMonth << "." << endl;
    cout << "The average of all the monthly temperatures (degrees Fahrenheit): " << avgTotalTemp << endl;
}