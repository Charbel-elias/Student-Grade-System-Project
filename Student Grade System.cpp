// Student Grade Management System:

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

class Student {
public:
    string name;
    float grade;

    Student(string n, float g) {
        name = n;
        grade = g;
    }
};

// Add Student
void addStudent(vector<Student>& students) {

    string name;
    float grade;

    cin.ignore();

    cout << "\nEnter student name: ";
    getline(cin, name);

    cout << "Enter student grade: ";
    cin >> grade;

    students.push_back(Student(name, grade));

    cout << "\nStudent added successfully!\n";
}

// Show All Students
void showStudents(const vector<Student>& students) {

    if (students.empty()) {
        cout << "\nNo students available.\n";
        return;
    }

    cout << "\n===== Students List =====\n";

    for (const auto& s : students) {

        string status;

        if (s.grade >= 50)
            status = "Pass";
        else
            status = "Fail";

        cout << "Name: " << s.name << " | Grade: " << s.grade << " | Status: " << status << endl;
    }
}

// Calculate Average
void calculateAverage(const vector<Student>& students) {

    if (students.empty()) {
        cout << "\nNo students available.\n";
        return;
    }

    float sum = 0;

    for (const auto& s : students) {
        sum += s.grade;
    }

    float average = sum / students.size();

    cout << fixed << setprecision(2);

    cout << "\nAverage Grade = " << average << endl;
}

// Highest Grade
void highestGrade(const vector<Student>& students) {

    if (students.empty()) {
        cout << "\nNo students available.\n";
        return;
    }

    Student highest = students[0];

    for (const auto& s : students) {

        if (s.grade > highest.grade) {
            highest = s;
        }
    }

    cout << "\nHighest Grade:\n";
    cout << highest.name << " - " << highest.grade << endl;
}

// Lowest Grade
void lowestGrade(const vector<Student>& students) {

    if (students.empty()) {
        cout << "\nNo students available.\n";
        return;
    }

    Student lowest = students[0];

    for (const auto& s : students) {

        if (s.grade < lowest.grade) {
            lowest = s;
        }
    }

    cout << "\nLowest Grade:\n";
    cout << lowest.name << " - " << lowest.grade << endl;
}

// Search Student
void searchStudent(const vector<Student>& students) {

    if (students.empty()) {
        cout << "\nNo students available.\n";
        return;
    }

    string searchName;

    cin.ignore();

    cout << "\nEnter student name to search: ";
    getline(cin, searchName);

    bool found = false;

    for (const auto& s : students) {

        if (s.name == searchName) {

            cout << "\nStudent Found!\n";
            cout << "Name: " << s.name << " | Grade: " << s.grade << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nStudent not found.\n";
    }
}

// Delete Student
void deleteStudent(vector<Student>& students) {

    if (students.empty()) {
        cout << "\nNo students available.\n";
        return;
    }

    string deleteName;

    cin.ignore();

    cout << "\nEnter student name to delete: ";
    getline(cin, deleteName);

    bool found = false;

    for (auto it = students.begin(); it != students.end(); it++) {

        if (it->name == deleteName) {

            students.erase(it);

            cout << "\nStudent deleted successfully!\n";

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nStudent not found.\n";
    }
}

// Sort Students by Grade
void sortStudents(vector<Student>& students) {

    sort(students.begin(), students.end(), [](Student a, Student b) {
        return a.grade > b.grade;
    });

    cout << "\nStudents sorted successfully!\n";
}

// Save Data to File
void saveToFile(const vector<Student>& students) {

    ofstream file("students.txt");

    if (!file) {
        cout << "\nError opening file.\n";
        return;
    }

    for (const auto& s : students) {

        file << s.name << " " << s.grade << endl;
    }

    file.close();

    cout << "\nData saved to students.txt successfully!\n";
}

int main() {

    vector<Student> students;

    int choice;

    do {

        cout << "\n========== Student Grade Management System ==========\n";

        cout << "1. Add Student\n";
        cout << "2. Show All Students\n";
        cout << "3. Calculate Average\n";
        cout << "4. Show Highest Grade\n";
        cout << "5. Show Lowest Grade\n";
        cout << "6. Search Student\n";
        cout << "7. Delete Student\n";
        cout << "8. Sort Students by Grade\n";
        cout << "9. Save Data to File\n";
        cout << "10. Exit\n";

        cout << "\nChoose an option: ";
        cin >> choice;

        switch (choice) {

        case 1:
            addStudent(students);
            break;

        case 2:
            showStudents(students);
            break;

        case 3:
            calculateAverage(students);
            break;

        case 4:
            highestGrade(students);
            break;

        case 5:
            lowestGrade(students);
            break;

        case 6:
            searchStudent(students);
            break;

        case 7:
            deleteStudent(students);
            break;

        case 8:
            sortStudents(students);
            break;

        case 9:
            saveToFile(students);
            break;

        case 10:
            cout << "\nProgram exited successfully.\n";
            break;

        default:
            cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 10);

    return 0;
}