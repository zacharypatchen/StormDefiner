//
// main.cpp
// PerfectStorm
//
// Created by Zachary Patchen on 11/18/23.
//

#include <iostream>
#include <string>
#include <limits> // for numeric_limits
#include <iomanip> // for setprecision
using namespace std;

// Class definition for StormAnalyzer
class StormAnalyzer {
private:
    const double conversionFactorM2K = 1.60934;
    const double conversionFactorK2M = 0.621371;
    double windSpeed;
    char measurement;
    double speedKMH;
    double speedMPH;
    string pacificType;
    string atlanticType;

    // Function to determine the typhoon category based on wind speed in kilometers per hour
    string getTyphoonCategory(double windSpeedKmph) {
        if (windSpeedKmph < 63) {
            return "Tropical Depression";
        } else if (windSpeedKmph < 88) {
            return "Tropical Storm";
        } else if (windSpeedKmph < 118) {
            return "Severe Tropical Storm";
        } else if (windSpeedKmph < 150) {
            return "Typhoon";
        } else if (windSpeedKmph < 185) {
            return "Severe Typhoon";
        } else {
            return "Super Typhoon";
        }
    }

    // Function to determine the hurricane category based on wind speed in miles per hour
    string getHurricaneCategory(double windSpeedMph) {
        if (windSpeedMph < 39) {
            return "Tropical Depression";
        } else if (windSpeedMph < 74) {
            return "Tropical Storm";
        } else if (windSpeedMph < 96) {
            return "Category 1";
        } else if (windSpeedMph < 111) {
            return "Category 2";
        } else if (windSpeedMph < 130) {
            return "Category 3";
        } else if (windSpeedMph < 157) {
            return "Category 4";
        } else {
            return "Category 5";
        }
    }

    // Function to print storm analysis output
    void printOutput() {
        cout << fixed << setprecision(2);
        cout << "Wind speed: " << speedMPH << " mph\n" << speedKMH << " kmph";
        cout << "\nPacific Storm Type: " << pacificType;
        cout << "\nAtlantic Storm Type: " << atlanticType << "\n";
    }

public:
    // Function to initiate the storm analysis
    bool start() {
        cout << "Enter m for miles per hour," << "\n" << "k for kilometers per hour\n";
        cin >> measurement;

        while (cin.fail() || (measurement != 'm' && measurement != 'k')) {
            cout << "Invalid input. Please enter 'm' or 'k': ";
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore last input
            cin >> measurement;
        }

        cout << "Enter wind speed: ";
        cin >> windSpeed;

        while (cin.fail() || windSpeed < 0) {
            cout << "Invalid input. Please enter a non-negative number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> windSpeed;
        }

        if (measurement == 'm') {
            speedKMH = windSpeed * conversionFactorM2K;
            speedMPH = windSpeed;
            pacificType = getTyphoonCategory(speedKMH);
            atlanticType = getHurricaneCategory(speedMPH);
            printOutput();
        } else if (measurement == 'k') {
            speedKMH = windSpeed;
            speedMPH = windSpeed * conversionFactorK2M;
            pacificType = getTyphoonCategory(speedKMH);
            atlanticType = getHurricaneCategory(speedMPH);
            printOutput();
        }

        return goAgain();
    }

    // Function to check if the user wants to analyze another storm
    bool goAgain() {
        char input;
        cout << "\n\nAsk another?\ny or n\n\n";
        cin >> input;

        while (cin.fail() || (input != 'y' && input != 'n')) {
            cout << "Invalid input. Please enter 'y' or 'n': ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> input;
        }

        return (input == 'y');
    }
};

// Entry point of the program
int main() {
    StormAnalyzer analyzer;
    
    // Loop for continuous storm analysis until the user chooses to exit
    do {
        if (!analyzer.start()) {
            break;
        }
    } while (true);

    return 0;
}
