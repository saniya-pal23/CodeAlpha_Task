#include <iostream>
#include <iomanip>  // for setting precision

using namespace std;

int main() {
    int numSubjects;
    float totalCredits = 0, totalGradePoints = 0;

    cout << "===============================" << endl;
    cout << "      CGPA CALCULATOR         " << endl;
    cout << "===============================" << endl;

    // Ask user for number of subjects
    cout << "Enter the number of subjects: ";
    cin >> numSubjects;

    // Input validation
    if (numSubjects <= 0) {
        cout << "Invalid number of subjects. Exiting..." << endl;
        return 1;
    }

    // Loop through each subject
    for (int i = 1; i <= numSubjects; ++i) {
        float credit, grade;

        cout << "\nSubject " << i << ":" << endl;

        // Take credit input
        cout << "Enter credit hours (e.g. 3 or 4): ";
        cin >> credit;

        if (credit <= 0) {
            cout << "Invalid credit entered. Skipping subject." << endl;
            continue;
        }

        // Take grade point input
        cout << "Enter grade point (out of 10): ";
        cin >> grade;

        if (grade < 0 || grade > 10) {
            cout << "Invalid grade entered. Skipping subject." << endl;
            continue;
        }

        // Add to totals
        totalCredits += credit;
        totalGradePoints += (credit * grade);
    }

    // Calculate and print CGPA
    if (totalCredits == 0) {
        cout << "\nNo valid subjects entered. CGPA cannot be calculated." << endl;
    } else {
        float cgpa = totalGradePoints / totalCredits;
        cout << fixed << setprecision(2);  // Show CGPA with 2 decimal places
        cout << "\nYour CGPA is: " << cgpa << " out of 10" << endl;
    }

    return 0;
}
