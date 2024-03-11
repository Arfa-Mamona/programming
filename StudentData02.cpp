#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct Student {
    string firstName;
    string lastName;
    string rollNo;
    string dob;
    int Class;
    int totalMarks;
    int obtainedMarks;
    float percentage;
    char grade;
};

const int MAX_STUDENTS = 10;
Student students[MAX_STUDENTS];
int numStudents = 0;

bool validateMarks(int marks) {
    return (marks >= 0 && marks <= 100);
}
 //Add Records.
void addRecord() {
    if (numStudents < MAX_STUDENTS) {
        Student newStudent;
        cout << "Enter First Name: ";
        cin >> newStudent.firstName;
        cout << "Enter Last Name: ";
        cin >> newStudent.lastName;
        cout << "Enter Roll No: ";
        cin >> newStudent.rollNo;
        cout << "Enter Date of Birth: ";
        cin >> newStudent.dob;
        cout << "Enter Class: ";
        cin >> newStudent.Class;

        do {
            cout << "Enter total Marks (0-100): ";
            cin >> newStudent.totalMarks;
            if (!validateMarks(newStudent.totalMarks)) {
                cout << "Invalid input! Total Marks must be between 0 and 100." << endl;
            }
        } while (!validateMarks(newStudent.totalMarks));

        do {
            cout << "Enter Obtained Marks (0-" << newStudent.totalMarks << "): ";
            cin >> newStudent.obtainedMarks;
            if (!validateMarks(newStudent.obtainedMarks) || newStudent.obtainedMarks > newStudent.totalMarks) {
                cout << "Invalid input! Obtained Marks must be between 0 and " << newStudent.totalMarks << "." << endl;
            }
        } while (!validateMarks(newStudent.obtainedMarks) || newStudent.obtainedMarks > newStudent.totalMarks);

        newStudent.percentage = (float)newStudent.obtainedMarks / newStudent.totalMarks * 100;
        if (newStudent.percentage >= 90)
            newStudent.grade = 'A';
        else if (newStudent.percentage >= 80)
            newStudent.grade = 'B';
        else if (newStudent.percentage >= 70)
            newStudent.grade = 'C';
        else if (newStudent.percentage >= 60)
            newStudent.grade = 'D';
        else if (newStudent.percentage >= 50)
            newStudent.grade = 'E';
        else
            newStudent.grade = 'F';

        students[numStudents++] = newStudent;
        cout << "Record added successfully!" << endl;
    }
    else {
        cout << "Maximum number of students reached." << endl;
    }
}
 //Find Records.
void findRecord(const string& rollNo) {
    bool found = false;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].rollNo == rollNo) {
            cout << "Record found:" << endl;
            cout << "First Name: " << students[i].firstName << endl;
            cout << "Last Name: " << students[i].lastName << endl;
            cout << "Roll No: " << students[i].rollNo << endl;
            cout << "Date of Birth: " << students[i].dob << endl;
            cout << "Class: " << students[i].Class << endl;
            cout << "Total Marks: " << students[i].totalMarks << endl;
            cout << "Obtained Marks: " << students[i].obtainedMarks << endl;
            cout << "Percentage: " << students[i].percentage << endl;
            cout << "Grade: " << students[i].grade << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Record not found." << endl;
}
 //Display Records.
void displayRecords() {
    if (numStudents == 0) {
        cout << "No records found" << endl;
        return;
    }
    cout << "List of records:" << endl;
    for (int i = 0; i < numStudents; ++i) {
        cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].firstName << " " << students[i].lastName << endl;
    }
}
 //Save Records.
void saveRecords() {
    ofstream file("records.txt");
    if (file.is_open()) {
        for (int i = 0; i < numStudents; ++i) {
            file << students[i].firstName << " " << students[i].lastName << " " << students[i].rollNo << " " << students[i].dob << " "
                << students[i].Class << " " << students[i].totalMarks << " " << students[i].obtainedMarks << " " << students[i].percentage << " "
                << students[i].grade << endl;
        }
        file.close();
        cout << "Records saved to file." << endl;
    }
    else {
        cout << "Unable to open file." << endl;
    }
}
 //Update Records.
void updateRecords(const string& rollNo) {
    bool recordFound = false;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].rollNo == rollNo) {
            cout << "Enter new data: " << endl;
            cout << "Enter First Name: ";
            cin >> students[i].firstName;
            cout << "Enter Last Name: ";
            cin >> students[i].lastName;
            cout << "Enter Date of Birth: ";
            cin >> students[i].dob;
            cout << "Enter Class: ";
            cin >> students[i].Class;

            do {
                cout << "Enter total Marks (0-100): ";
                cin >> students[i].totalMarks;
                if (!validateMarks(students[i].totalMarks)) {
                    cout << "Invalid input! Total Marks must be between 0 and 100." << endl;
                }
            } while (!validateMarks(students[i].totalMarks));

            do {
                cout << "Enter Obtained Marks (0-" << students[i].totalMarks << "): ";
                cin >> students[i].obtainedMarks;
                if (!validateMarks(students[i].obtainedMarks) || students[i].obtainedMarks > students[i].totalMarks) {
                    cout << "Invalid input! Obtained Marks must be between 0 and " << students[i].totalMarks << "." << endl;
                }
            } while (!validateMarks(students[i].obtainedMarks) || students[i].obtainedMarks > students[i].totalMarks);

            students[i].percentage = (float)students[i].obtainedMarks / students[i].totalMarks * 100;
            if (students[i].percentage >= 90)
                students[i].grade = 'A';
            else if (students[i].percentage >= 80)
                students[i].grade = 'B';
            else if (students[i].percentage >= 70)
                students[i].grade = 'C';
            else if (students[i].percentage >= 60)
                students[i].grade = 'D';
            else if (students[i].percentage >= 50)
                students[i].grade = 'E';
            else
                students[i].grade = 'F';

            cout << "Record updated successfully!" << endl;
            recordFound = true;
            break;
        }
    }
    if (!recordFound) {
        cout << "Record not found." << endl;
    }
}
 //Delete Records.
void deleteRecords(const string& rollNo) {
    bool found = false;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].rollNo == rollNo) {
            found = true;
          
            for (int j = i; j < numStudents - 1; ++j) {
                students[j] = students[j + 1];
            }
           
            numStudents--;
            cout << "Record deleted successfully" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Record not found" << endl;
    }
}

 //Load Records.
void loadRecords() {
    ifstream file("records.txt");
    if (file.is_open()) {
        while (numStudents < MAX_STUDENTS &&
            file >> students[numStudents].firstName >> 
            students[numStudents].lastName >>
            students[numStudents].rollNo >>
            students[numStudents].dob >> 
            students[numStudents].Class >>
            students[numStudents].totalMarks >>
            students[numStudents].obtainedMarks >>
            students[numStudents].percentage >>
            students[numStudents].grade)
        {
            numStudents++;
        }
        file.close();
        cout << "Records loaded from file." << endl;
    }
    else {
        cout << "No records found." << endl;
    }
}

int main() {
    loadRecords();

    char choice;
    string rollNo;
    do {
        cout << "\nChoose an option:" << endl;
        cout << "1. Add record" << endl;
        cout << "2. Find record by Roll No" << endl;
        cout << "3. Display all records" << endl;
        cout << "4. Save records to file" << endl;
        cout << "5. Update records" << endl;
        cout << "6. Delete record by roll no" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            addRecord();
            break;
        case '2':
            cout << "Enter Roll No to find record: ";
            cin >> rollNo;
            findRecord(rollNo);
            break;
        case '3':
            displayRecords();
            break;
        case '4':
            saveRecords();
            break;
        case '5':
            cout << "Enter Roll no to update record:";
            cin >> rollNo;
            updateRecords(rollNo);
            break;
        case '6':
            cout << "Enter Roll no to delete record: ";
            cin >> rollNo;
            deleteRecords(rollNo);
            break;
        case '7':
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '7');

    return 0;
}


