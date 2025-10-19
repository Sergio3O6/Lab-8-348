// Author: Sergio Medrano
// Date: 10/19/2025
// Purpose: Converts tempature units

#include <stdio.h>

// Convert temperature from one scale to another
double convertTemperature(double value, char from, char to) {
    double celsius;

    // Step 1: Convert the input value to Celsius
    if (from == 'C' || from == 'c') {
        celsius = value;
    } else if (from == 'F' || from == 'f') {
        celsius = (value - 32) * 5.0 / 9.0;
    } else if (from == 'K' || from == 'k') {
        celsius = value - 273.15;
    } else {
        return 0; // Invalid scale (shouldn't reach here due to validation)
    }

    // Step 2: Convert Celsius to target scale
    if (to == 'C' || to == 'c') {
        return celsius;
    } else if (to == 'F' || to == 'f') {
        return celsius * 9.0 / 5.0 + 32;
    } else if (to == 'K' || to == 'k') {
        return celsius + 273.15;
    }

    return 0;
}

// Categorize temperature and display advisory message
void categorizeTemperature(double celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Wear a heavy jacket.\n");
    } else if (celsius < 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius < 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: Nice weather outside.\n");
    } else if (celsius < 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors and stay hydrated.\n");
    }
}

int main() {
    double value;       // User temperature input
    char fromScale;     // Original scale (C, F, or K)
    char toScale;       // Target scale to convert to (C, F, or K)

    // Prompt user for temperature value
    printf("Enter the temperature value: ");
    if (scanf("%lf", &value) != 1) { // Check if input is a valid number
        printf("Invalid input: temperature must be a number.\n");
        return 1;
    }

    // Prompt for original scale
    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &fromScale);

    // Validate input scale
    if (fromScale != 'C' && fromScale != 'c' &&
        fromScale != 'F' && fromScale != 'f' &&
        fromScale != 'K' && fromScale != 'k') {
        printf("Invalid input: scale must be C, F, or K.\n");
        return 1;
    }

    // Prompt for target scale
    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &toScale);

    // Validate target scale
    if (toScale != 'C' && toScale != 'c' &&
        toScale != 'F' && toScale != 'f' &&
        toScale != 'K' && toScale != 'k') {
        printf("Invalid input: scale must be C, F, or K.\n");
        return 1;
    }

    // Perform the conversion
    double converted = convertTemperature(value, fromScale, toScale);

    // Display converted value
    printf("Converted temperature: %.2f %c\n", converted, toScale);

    // Categorize temperature based on Celsius
    double celsiusValue = convertTemperature(value, fromScale, 'C');
    categorizeTemperature(celsiusValue);

    return 0;
}
