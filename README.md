# StormDefiner

## Overview

PerfectStorm is a simple C++ program designed to analyze storm data based on user input. It utilizes the StormAnalyzer class to determine storm categories for both the Pacific and Atlantic regions, taking into account the user's choice of measurement units (miles per hour or kilometers per hour).

## Program Structure

The program consists of a `main.cpp` file containing the `StormAnalyzer` class and the `main` function, which initiates storm analysis and prompts the user for input until they choose to exit.

## StormAnalyzer Class

### Private Members

- `conversionFactorM2K`: Conversion factor for miles per hour to kilometers per hour.
- `conversionFactorK2M`: Conversion factor for kilometers per hour to miles per hour.
- `windSpeed`: Input wind speed.
- `measurement`: User's choice of measurement units ('m' for miles per hour, 'k' for kilometers per hour).
- `speedKMH`: Wind speed in kilometers per hour.
- `speedMPH`: Wind speed in miles per hour.
- `pacificType`: Storm category for the Pacific region.
- `atlanticType`: Storm category for the Atlantic region.

### Private Methods

- `getTyphoonCategory(double windSpeedKmph)`: Determines the typhoon category based on wind speed in kilometers per hour.
- `getHurricaneCategory(double windSpeedMph)`: Determines the hurricane category based on wind speed in miles per hour.
- `printOutput()`: Prints storm analysis output.

### Public Methods

- `bool start()`: Initiates the storm analysis, prompting the user for input and displaying the analysis result.
- `bool goAgain()`: Asks the user if they want to analyze another storm.

## How to Use

1. Compile and run the program.
2. Enter 'm' for miles per hour or 'k' for kilometers per hour when prompted.
3. Enter the wind speed.
4. View the storm analysis output, including wind speed in both units and storm categories for the Pacific and Atlantic regions.
5. Choose whether to analyze another storm.

## Author

Zachary Patchen
