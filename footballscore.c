// Author: Sergio Medrano
// Date: 10/19/2025
// Purpose: Gives possible scores for a game

#include <stdio.h>

int main() {
    int score;

    // Repeat until user enters 1 to stop
    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        scanf("%d", &score);

        // If user enters 1, exit the program
        if (score == 1) {
            break;
        }

        // Check for invalid (negative) scores
        if (score < 0) {
            printf("Invalid input: score cannot be negative.\n");
            continue;
        }

        // Display the current score being evaluated
        printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);

        // Variables for each scoring play count
        int td2;    // TD + 2 point conversion (8 points)
        int td1;    // TD + 1 point FG (7 points)
        int td;     // Regular TD (6 points)
        int fg;     // Field goal (3 points)
        int safety; // Safety (2 points)

        int found = 0; // Flag to check if at least one combination exists

        // Try all possible combinations of each scoring play
        for (td2 = 0; td2 <= score / 8; td2++) {
            for (td1 = 0; td1 <= score / 7; td1++) {
                for (td = 0; td <= score / 6; td++) {
                    for (fg = 0; fg <= score / 3; fg++) {
                        for (safety = 0; safety <= score / 2; safety++) {

                            // Calculate total points for the current combination
                            int total = td2 * 8 + td1 * 7 + td * 6 + fg * 3 + safety * 2;

                            // If total matches the score, print the combination
                            if (total == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                       td2, td1, td, fg, safety);
                                found = 1; // mark that at least one combination was found
                            }
                        }
                    }
                }
            }
        }

        // If no valid combination was found, print a message
        if (!found) {
            printf("No combinations found for %d.\n", score);
        }
    }

    return 0;
}
