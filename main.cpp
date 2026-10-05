#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Student {
public:
    int rollNumber;
    string name;
    float marks1, marks2, marks3;
    float gpa;

    void calculateGPA() {
        float avg = (marks1 + marks2 + marks3) / 3.0;
        gpa = avg / 10.0;
    }

    void display() const {
        cout << left << setw(10) << rollNumber 
             << setw(20) << name 
             << setw(10) << marks1 
             << setw(10) << marks2 
             << setw(10) << marks3 
             << setw(10) << fixed << setprecision(2) << gpa << "\n";
    }
};

class StudentManagementSystem {
private:
    vector<Student> students;
    const string filename = "students_data.txt";

public:
    StudentManagementSystem() {
        loadDataFromFile();
    }

    void addStudent(int roll, string name, float m1, float m2, float m3) {
        Student s;
        s.rollNumber = roll;
        s.name = name;
        s.marks1 = m1;
        s.marks2 = m2;
        s.marks3 = m3;
        s.calculateGPA();
        students.push_back(s);
        saveDataToFile();
        cout << ">> Student successfully added!\n";
    }

    void displayAll() {
        if (students.empty()) {
            cout << ">> Koi record nahi mila.\n";
            return;
        }
        cout << "\n-----------------------------------------------------------------\n";
        cout << left << setw(10) << "Roll No" << setw(20) << "Name" 
             << setw(10) << "Sub 1" << setw(10) << "Sub 2" 
             << setw(10) << "Sub 3" << setw(10) << "GPA" << "\n";
        cout << "-----------------------------------------------------------------\n";
        for (const auto& s : students) {
            s.display();
        }
        cout << "-----------------------------------------------------------------\n";
    }

    void searchStudent(int roll) {
        for (const auto& s : students) {
            if (s.rollNumber == roll) {
                cout << ">> Student Found:\n";
                s.display();
                return;
            }
        }
        cout << ">> Roll Number " << roll << " nahi mila.\n";
    }

    void saveDataToFile() {
        ofstream outFile(filename);
        for (const auto& s : students) {
            outFile << s.rollNumber << "," << s.name << "," 
                    << s.marks1 << "," << s.marks2 << "," 
                    << s.marks3 << "," << s.gpa << "\n";
        }
        outFile.close();
    }

    void loadDataFromFile() {
        ifstream inFile(filename);
        if (!inFile) return;

        students.clear();
        string line;
        while (getline(inFile, line)) {
            if (line.empty()) continue;
            Student s;
            size_t p1 = line.find(",");
            size_t p2 = line.find(",", p1 + 1);
            size_t p3 = line.find(",", p2 + 1);
            size_t p4 = line.find(",", p3 + 1);
            size_t p5 = line.find(",", p4 + 1);

            s.rollNumber = stoi(line.substr(0, p1));
            s.name = line.substr(p1 + 1, p2 - p1 - 1);
            s.marks1 = stof(line.substr(p2 + 1, p3 - p2 - 1));
            s.marks2 = stof(line.substr(p3 + 1, p4 - p3 - 1));
            s.marks3 = stof(line.substr(p4 + 1, p5 - p4 - 1));
            s.gpa = stof(line.substr(p5 + 1));
            students.push_back(s);
        }
        inFile.close();
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;

    do {
        cout << "\n=== STUDENT RECORD SYSTEM ===\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll No\n";
        cout << "4. Exit\n";
        cout << "Choice enter karein: ";
        cin >> choice;

        if (choice == 1) {
            int roll;
            string name;
            float m1, m2, m3;
            cout << "Enter Roll No: "; cin >> roll;
            cout << "Enter Name: "; cin.ignore(); getline(cin, name);
            cout << "Enter Marks for 3 Subjects (out of 100): ";
            cin >> m1 >> m2 >> m3;
            sms.addStudent(roll, name, m1, m2, m3);
        } else if (choice == 2) {
            sms.displayAll();
        } else if (choice == 3) {
            int roll;
            cout << "Enter Roll No to search: "; cin >> roll;
            sms.searchStudent(roll);
        }
    } while (choice != 4);

    cout << "Program exited.\n";
    return 0;
}