// Contestant ID

#include <iostream>
using namespace std;

// This array will store the number of students in each class taken from user input
// for the ten classes in a department.
int classes[10];
// This integer stores the department number that the user inputs.
int department;

/**
 * Method prints the menu to the console and prompts user to select a department
 * stores the inputted value in department
 * Method also prompts the user to specify the number of students for each class (ten total)
 * If the user does not enter a valid department(0 - 9) or class size(0 - 40) they are prompted again
 */
void menu_collect();
/**
 * Prints the data collected from the user in a horizontal orientation
 */
void horizontal_graph();
/**
 * Prints the data collected form the use in a vertical orientation
 */
void vertical_graph();

int main() {
    // boolean flag: when true, end program
    bool done = false;
    // program continues executing until the user enter n to terminate
    while (!done) {
        // collect the data and store it in department variable and classes array
        menu_collect();
        cout << "\n\n\n\n\n\n\n";
        // display horizontal graph
        horizontal_graph();
        cout << "\n\n";
        // prompt the user to press enter
        cout << "Press ENTER to see vertical graph." << endl << "\n\n\n\n";
        // then display the vertical graph
        vertical_graph();
        cout << "\n\n";

        // prompt the user to enter "n" if the wish to end the program or "Y" if they want to continue
        while (true) {
            cout << "Run the program again (Y/n)?";
            string str;
            cin >> str;
            if (str == "n") { // if n, break out of loop and set the flag to true to terminate
                cout << "\n\n\n\n\n\n\n";
                done = true;
                break;
            } else if (str != "Y") { // if Y, only break to rerun program
                break;
            }
            // if neither n or Y is entered, prompt user again
            cout << "Please enter only Y or n." << endl;
        }
        cout << "\n\n\n\n\n\n";
    }

    return 0;
}

void menu_collect() {
    // print the menu to console
    cout << "\tUp Town University" << endl;
    cout << "0. English Department" << endl;
    cout << "1. Mathematics Department" << endl;
    cout << "2. Computer Science Department" << endl;
    cout << "3. Business Department" << endl;
    cout << "4. Kinesiology Department" << endl;
    cout << "5. Architecture Department" << endl;
    cout << "6. Biology Department" << endl;
    cout << "7. Education Department" << endl;
    cout << "8. Chemistry Department" << endl;
    cout << "9. Engineering Department" << endl;
    cout << endl;
    // prompt the user to enter a department number
    while (true) {
        cout << "Please pick the department: ";
        // store value
        cin >> department;
        // if a valid department is selected, break out of the loop
        if (department >= 0 && department <= 9) {
            break;
        }
        // if not, display error message
        cout << "Please enter ONLY a number from 0 - 9" << endl;
    }
    cout << "\n\n\n\n\n\n\n";
    // prompt the user to enter number of students for each of the ten classes
    for (int i = 0; i <= 9; i++) {
        while (true) {
            cout << "Class sizes are from 0 - 40 students." << endl;
            // print out the class number
            cout << department * 100 + i << " ";
            cin >> classes[i];
            // if the class size is in the range 0 - 40, break to prompt the user for the next class
            if (classes[i] >= 0 && classes[i] <= 40) {
                break;
            }
            // else display an error message
            cout << "Please enter numbers ONLY 0 - 40." << endl << endl;
        }
    }
    cout << "\n\n\n\n\n\n";
}

void horizontal_graph() {
    // print header for horizontal graph
    cout << "Department                                Students" << endl;
    for (int i = 0; i <= 9; i++) {
        cout << department * 100 + i << " "; // print class number
        for (int s = 0; s < classes[i]; s++) { // print an asterik for each student in class
            cout << "*";
        }
        for (int s = 0; s < 40 - classes[i]; s++) { // fill empty space
            cout << " ";
        }
        cout << " " << classes[i] << endl; // print total number of students in class
    }
}

void vertical_graph() {
    // print header of vertical graph
    cout << "Students\t\t";
    // print each class number vertically
    // print the tens place or space if < 10
    for (int i = 0; i <= 9; i++) {
        int n = classes[i] / 10;
        if (n == 0) {
            cout << " ";
        } else {
            cout << n;
        }
        cout << " ";
    }
    // print the ones place
    cout << endl;
    cout << "\t\t\t\t";
    for (int i = 0; i <= 9; i++) {
        cout << classes[i] % 10 << " ";
    }
    cout << endl;
    cout << "\t\t\t\t";
    // print asterisks for each student in each class
    for (int i = 40; i >= 1; i--) {
        for (int c = 0; c <= 9; c++) {
            if (classes[c] >= i) {
                cout << "*";
            } else {
                cout << " ";
            }
            cout << " ";
        }
        cout << endl;
        cout << "\t\t\t\t";
    }
    // Display the class numbers
    cout << endl;
    cout << "Department\t\t";
    for (int i = 0; i <= 9; i++) {
        cout << department << " ";
    }
    cout << endl;
    cout << "\t\t\t\t";
    for (int i = 0; i <= 9; i++) {
        cout << 0 << " ";
    }
    cout << endl;
    cout << "\t\t\t\t";
    for (int i = 0; i <= 9; i++) {
        cout << i << " ";
    }
}