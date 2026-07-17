#include "grade_analyzer.hpp"
#include <iostream>
#include <limits>

using namespace std;

// Reads and validates one score to avoid repeating the same input logic.
double readValidScore(int scoreNumber) {
    double score = 0.0;

    cout << "Enter score " << scoreNumber << ": ";

    // Also checks for non-numeric input, such as letters.
    while (!(cin >> score) || !isValidScore(score)) {
        cout << "Invalid score. Enter a number from 0 to 100: ";

        cin.clear(); // Clears cin's error state.
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Removes invalid input.
    }

    return score;
}

int main() {
    cout << "Grade Analyzer" << endl;
    cout << endl;

    // Use the helper function to reduce repeated input and validation code.
    double score1 = readValidScore(1);
    double score2 = readValidScore(2);
    double score3 = readValidScore(3);

    double total = calculateTotal(score1, score2, score3);
    double average = calculateAverage(total, SCORE_COUNT);
    char letterGrade = determineLetterGrade(average);
    bool passing = isPassing(average);

    printGradeReport(total, average, letterGrade, passing);

    return 0;
}