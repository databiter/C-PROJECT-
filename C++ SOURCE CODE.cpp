#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>  // For _getch()

using namespace std;

class login {
private:
    string username = "harsh"; // Predefined username
    string password = "123456"; // Predefined password

public:
    bool authenticate();
};

class student {
private:
    string name, roll_no, course, address, phone, fathers_name;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};

class academic {
private:
    string roll_no;
    int marks, total_marks;
    string grade;

public:
    void addAcademicRecord();
    void displayAcademicRecords();
};

bool login::authenticate() {
    string enteredUsername, enteredPassword;
    cout << "\n-----------------------------------\n";
    cout << "           LOGIN PAGE\n";
    cout << "-----------------------------------\n";
    cout << "Enter Username: ";
    cin >> enteredUsername;
    cout << "Enter Password: ";
    char ch;
    enteredPassword = "";
    ch = _getch();
    while (ch != 13) {  // 13 is the ASCII code for Enter
        enteredPassword.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    cout << endl;

    return (enteredUsername == username && enteredPassword == password);
}

void academic::addAcademicRecord() {
    system("cls");
    fstream file;
    vector<academic> academicRecords;
    string rollno;
    int found = 0;

    cout << "\n-----------------------------------" << endl;
    cout << "       ACADEMIC RECORD SECTION" << endl;
    cout << "-----------------------------------" << endl;

    file.open("academicRecord.txt", ios::app | ios::out);

    cout << "Enter Roll No. of Student: ";
    cin >> rollno;
    cout << "Enter Marks: ";
    cin >> marks;
    cout << "Enter Total Marks: ";
    cin >> total_marks;
    cout << "Enter Grade: ";
    cin >> grade;

    file << rollno << " " << marks << " " << total_marks << " " << grade << "\n";
    file.close();
}

void academic::displayAcademicRecords() {
    system("cls");
    fstream file;
    string rollno;
    vector<academic> academicRecords;

    cout << "\n-----------------------------------" << endl;
    cout << "     ACADEMIC RECORDS TABLE" << endl;
    cout << "-----------------------------------" << endl;

    file.open("academicRecord.txt", ios::in);
    if (!file) {
        cout << "\nNo Academic Data is Present..." << endl;
    } else {
        file >> rollno;
        while (!file.eof()) {
            academic record;
            record.roll_no = rollno;
            file >> record.marks >> record.total_marks >> record.grade;
            academicRecords.push_back(record);
            file >> rollno;
        }
        file.close();

        // Display academic records in a table format
        cout << "Roll No.\tMarks\tTotal Marks\tGrade" << endl;
        for (int i = 0; i < academicRecords.size(); i++) {
            cout << academicRecords[i].roll_no << "\t\t" << academicRecords[i].marks << "\t"
                 << academicRecords[i].total_marks << "\t\t" << academicRecords[i].grade << endl;
        }
    }
}

void student::menu() {
    while (true) {
        int choice;
        char x;
        system("cls");
        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t| STUDENT MANAGEMENT SYSTEM |" << endl;
        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t 1. Enter New Record" << endl;
        cout << "\t\t\t 2. Display Record" << endl;
        cout << "\t\t\t 3. Modify Record" << endl;
        cout << "\t\t\t 4. Search Record" << endl;
        cout << "\t\t\t 5. Delete Record" << endl;
        cout << "\t\t\t 6. Academic Section\n" << endl; // Added academic section
        cout << "\t\t\t 7. Exit\n" << endl;

        cout << "\t\t\t............................" << endl;
        cout << "\t\t\tChoose Options:[1/2/3/4/5/6/7]" << endl;
        cout << "\t\t\t............................" << endl;
        cout << " Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                do {
                    insert();
                    cout << "\n\n\t\t\t Add Another Student Record (Y, N) : ";
                    cin >> x;
                } while (x == 'y' || x == 'Y');
                break;
            case 2:
                display();
                break;
            case 3:
                modify();
                break;
            case 4:
                search();
                break;
            case 5:
                deleted();
                break;
            case 6:
                academic academicSection; // Create an academic section object
                int academicChoice;
                cout << "\n1. Add Academic Record\n";
                cout << "2. Display Academic Records\n";
                cout << "3. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> academicChoice;
                switch (academicChoice) {
                    case 1:
                        academicSection.addAcademicRecord();
                        break;
                    case 2:
                        academicSection.displayAcademicRecords();
                        break;
                    case 3:
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
                break;
            
        }
        getch();
    }
}


void student::insert() {
    system("cls");
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Add Student Details ---------------------------------------------" << endl;
    cout << "\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\tEnter Roll No.: ";
    cin >> roll_no;
    cout << "\t\t\tEnter Course: ";
    cin >> course;
    cout << "\t\t\tEnter Address: ";
    cin >> address;
    cout << "\t\t\tEnter Phone: ";
    cin >> phone;
    cout << "\t\t\tEnter Father's Name: ";
    cin >> fathers_name;
    file.open("studentRecord.txt", ios::app | ios::out);
    file << " " << name << " " << roll_no << " " << course << " " << address << " " << phone << " " << fathers_name << "\n";
    file.close();
}

void student::display() {
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    } else {
        file >> name >> roll_no >> course >> address >> phone >> fathers_name;
        while (!file.eof()) {
            cout << "\n\n\t\t\tStudent No.: " << total++ << endl;
            cout << "\t\t\tName: " << name << "\n";
            cout << "\t\t\tRoll No.: " << roll_no << "\n";
            cout << "\t\t\tCourse: " << course << "\n";
            cout << "\t\t\tAddress: " << address << "\n";
            cout << "\t\t\tPhone: " << phone << "\n";
            cout << "\t\t\tFather's Name: " << fathers_name << "\n";
            file >> name >> roll_no >> course >> address >> phone >> fathers_name;
        }
        if (total == 1) {
            cout << "\n\t\t\tNo Data is Present..." << endl;
        }
    }
    file.close();
}

void student::modify() {
    system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    } else {
        cout << "\nEnter Roll No. of Student which you want to Modify: ";
        cin >> rollno;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> address;
        while (!file.eof()) {
            if (rollno != roll_no)
                file1 << " " << name << " " << roll_no << " " << course << " " << address << "\n";
            else {
                cout << "\n\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\tEnter Roll No.: ";
                cin >> roll_no;
                cout << "\t\t\tEnter Course: ";
                cin >> course;
                cout << "\t\t\tEnter Address: ";
                cin >> address;
                file1 << " " << name << " " << roll_no << " " << course << " " << address << "\n";
                found++;
            }
            file >> name >> roll_no >> course >> address;
        }
        if (found == 0) {
            cout << "\n\n\t\t\t Student Roll No. Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}

void student::search() {
    system("cls");
    fstream file;
    int found = 0;
    file.open("studentRecord.txt", ios::in);
    if (!file) {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data --------------------------------------------" << endl;
        cout << "\n\t\t\tNo Data is Present... " << endl;
    } else {
        string rollno;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Table --------------------------------------------" << endl;
        cout << "\nEnter Roll No. of Student which you want to search: ";
        cin >> rollno;
        file >> name >> roll_no >> course >> address;
        while (!file.eof()) {
            if (rollno == roll_no) {
                cout << "\n\n\t\t\tName: " << name << "\n";
                cout << "\t\t\tRoll No.: " << roll_no << "\n";
                cout << "\t\t\tCourse: " << course << "\n";
                cout << "\t\t\tAddress: " << address << "\n";
                found++;
            }
            file >> name >> roll_no >> course >> address;
        }
        if (found == 0) {
            cout << "\n\t\t\t Student Roll NO. Not Found....";
        }
        file.close();
    }
}

void student::deleted() {
    system("cls");
    fstream file, file1;
    int found = 0;
    string roll;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    } else {
        cout << "\nEnter Roll No. of Student which you want Delete Data: ";
        cin >> roll;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> address;
        while (!file.eof()) {
            if (roll != roll_no) {
                file1 << " " << name << " " << roll_no << " " << course << " " << address << "\n";
            } else {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> roll_no >> course >> address;
        }
        if (found == 0) {
            cout << "\n\t\t\t Student Roll NO. Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}

int main() {
    login loginPage;
    student project;

    if (!loginPage.authenticate()) {
        cout << "Authentication failed. Exiting program." << endl;
        return 1;
    }

    project.menu();
    return 0;
}
