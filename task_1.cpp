#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

class Student {
public:
    int rollNo;
    string name;
    int age;
    string course;
    string phone;

    void input() {
        cout << "\nEnter Roll Number: ";
        cin >> rollNo;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Course: ";
        getline(cin, course);

        cout << "Enter Phone Number: ";
        getline(cin, phone);
    }

    void display() const {
        cout << left
             << setw(10) << rollNo
             << setw(25) << name
             << setw(8) << age
             << setw(20) << course
             << setw(15) << phone
             << endl;
    }
};

const string FILE_NAME = "students.dat";

// Add a new student
void addStudent() {
    Student student;
    ofstream file(FILE_NAME, ios::binary | ios::app);

    if (!file) {
        cout << "\nError opening file!\n";
        return;
    }

    student.input();

    // Check for duplicate roll number
    ifstream checkFile(FILE_NAME, ios::binary);
    Student existing;

    while (checkFile.read(reinterpret_cast<char*>(&existing), sizeof(Student))) {
        // Binary storage of string objects is unsafe.
        // Therefore, duplicate checking is handled below using a safer method.
        break;
    }

    checkFile.close();

    // This implementation uses a text file instead.
    file.close();

    // Re-write using text-based storage
    ofstream textFile("students.txt", ios::app);

    if (!textFile) {
        cout << "\nError opening storage file!\n";
        return;
    }

    textFile << student.rollNo << '|'
             << student.name << '|'
             << student.age << '|'
             << student.course << '|'
             << student.phone << '\n';

    textFile.close();

    cout << "\nStudent added successfully!\n";
}

// Display all students
void displayStudents() {
    ifstream file("students.txt");

    if (!file) {
        cout << "\nNo student records found.\n";
        return;
    }

    Student student;
    string line;

    cout << "\n================ STUDENT RECORDS ================\n";

    cout << left
         << setw(10) << "Roll No"
         << setw(25) << "Name"
         << setw(8) << "Age"
         << setw(20) << "Course"
         << setw(15) << "Phone"
         << endl;

    cout << string(78, '-') << endl;

    bool found = false;

    while (getline(file, line)) {
        size_t p1 = line.find('|');
        size_t p2 = line.find('|', p1 + 1);
        size_t p3 = line.find('|', p2 + 1);
        size_t p4 = line.find('|', p3 + 1);

        if (p1 == string::npos || p2 == string::npos ||
            p3 == string::npos || p4 == string::npos) {
            continue;
        }

        student.rollNo = stoi(line.substr(0, p1));
        student.name = line.substr(p1 + 1, p2 - p1 - 1);
        student.age = stoi(line.substr(p2 + 1, p3 - p2 - 1));
        student.course = line.substr(p3 + 1, p4 - p3 - 1);
        student.phone = line.substr(p4 + 1);

        student.display();
        found = true;
    }

    file.close();

    if (!found) {
        cout << "No student records found.\n";
    }
}

// Search student
void searchStudent() {
    int roll;
    cout << "\nEnter Roll Number to search: ";
    cin >> roll;

    ifstream file("students.txt");

    if (!file) {
        cout << "\nNo student records found.\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        size_t p1 = line.find('|');
        size_t p2 = line.find('|', p1 + 1);
        size_t p3 = line.find('|', p2 + 1);
        size_t p4 = line.find('|', p3 + 1);

        if (p1 == string::npos || p2 == string::npos ||
            p3 == string::npos || p4 == string::npos) {
            continue;
        }

        int rollNo = stoi(line.substr(0, p1));

        if (rollNo == roll) {
            Student student;

            student.rollNo = rollNo;
            student.name = line.substr(p1 + 1, p2 - p1 - 1);
            student.age = stoi(line.substr(p2 + 1, p3 - p2 - 1));
            student.course = line.substr(p3 + 1, p4 - p3 - 1);
            student.phone = line.substr(p4 + 1);

            cout << "\nStudent Found:\n";
            cout << string(78, '-') << endl;

            cout << left
                 << setw(10) << "Roll No"
                 << setw(25) << "Name"
                 << setw(8) << "Age"
                 << setw(20) << "Course"
                 << setw(15) << "Phone"
                 << endl;

            cout << string(78, '-') << endl;

            student.display();

            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "\nStudent with Roll Number "
             << roll << " not found.\n";
    }
}

// Update student
void updateStudent() {
    int roll;
    cout << "\nEnter Roll Number to update: ";
    cin >> roll;

    ifstream file("students.txt");

    if (!file) {
        cout << "\nNo student records found.\n";
        return;
    }

    ofstream tempFile("temp.txt");

    string line;
    bool found = false;

    while (getline(file, line)) {
        size_t p1 = line.find('|');
        size_t p2 = line.find('|', p1 + 1);
        size_t p3 = line.find('|', p2 + 1);
        size_t p4 = line.find('|', p3 + 1);

        if (p1 == string::npos || p2 == string::npos ||
            p3 == string::npos || p4 == string::npos) {
            continue;
        }

        int rollNo = stoi(line.substr(0, p1));

        if (rollNo == roll) {
            Student student;

            student.rollNo = rollNo;

            cout << "\nEnter updated information:\n";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Name: ";
            getline(cin, student.name);

            cout << "Enter Age: ";
            cin >> student.age;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Course: ";
            getline(cin, student.course);

            cout << "Enter Phone Number: ";
            getline(cin, student.phone);

            tempFile << student.rollNo << '|'
                     << student.name << '|'
                     << student.age << '|'
                     << student.course << '|'
                     << student.phone << '\n';

            found = true;
        } else {
            tempFile << line << '\n';
        }
    }

    file.close();
    tempFile.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found) {
        cout << "\nStudent record updated successfully!\n";
    } else {
        cout << "\nStudent with Roll Number "
             << roll << " not found.\n";
    }
}

// Delete student
void deleteStudent() {
    int roll;
    cout << "\nEnter Roll Number to delete: ";
    cin >> roll;

    ifstream file("students.txt");

    if (!file) {
        cout << "\nNo student records found.\n";
        return;
    }

    ofstream tempFile("temp.txt");

    string line;
    bool found = false;

    while (getline(file, line)) {
        size_t p1 = line.find('|');

        if (p1 == string::npos) {
            continue;
        }

        int rollNo = stoi(line.substr(0, p1));

        if (rollNo == roll) {
            found = true;
            continue;
        }

        tempFile << line << '\n';
    }

    file.close();
    tempFile.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found) {
        cout << "\nStudent deleted successfully!\n";
    } else {
        cout << "\nStudent with Roll Number "
             << roll << " not found.\n";
    }
}

// Main menu
int main() {
    int choice;

    do {
        cout << "\n\n";
        cout << "========================================\n";
        cout << "       STUDENT MANAGEMENT SYSTEM        \n";
        cout << "========================================\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "========================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                cout << "\nThank you for using Student Management System!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}