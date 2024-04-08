// Rayyan Mohsin 22i-2052 Semester-End Project

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h> // This header might be specific to certain systems (Windows), and is not used in the code.

using namespace std;

// Define a class for notifications
class Notification
{
private:
    string notification;
    string date;

public:
    // Constructors
    Notification()
    {
        notification = "";
        date = "";
    }

    Notification(string notification, string date)
    {
        this->notification = notification;
        this->date = date;
    }

    // Setters and getters for notification and date
    void setNotification(string notification)
    {
        this->notification = notification;
    }

    string getNotification()
    {
        return notification;
    }

    void setDate(string date)
    {
        this->date = date;
    }

    string getDate()
    {
        return date;
    }

    // Print notification details
    void print()
    {
        cout << "Notification: " << notification << endl;
        cout << "Date: " << date << endl;
    }

    // Destructor
    ~Notification() {}
};

// Define a base class for users
class User
{
private:
    string name;
    string email;
    string rollNum;
    string password;
    string number;

public:
    // Constructors
    User()
    {
        name = "";
        email = "";
        rollNum = "";
        password = "";
        number = "";
    }

    User(string name, string email, string rollNum, string password, string number)
    {
        this->name = name;
        this->email = email;
        this->rollNum = rollNum;
        this->password = password;
        this->number = number;
    }

    // Setters and getters for user attributes
    string getName()
    {
        return name;
    }

    string getEmail()
    {
        return email;
    }

    string getRollNum()
    {
        return rollNum;
    }

    string getPassword()
    {
        return password;
    }

    string getNumber()
    {
        return number;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setEmail(string email)
    {
        this->email = email;
    }

    void setRollNum(string rollNum)
    {
        this->rollNum = rollNum;
    }

    void setPassword(string password)
    {
        this->password = password;
    }

    void setNumber(string number)
    {
        this->number = number;
    }

    // Print user details
    void print()
    {
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Roll Number: " << rollNum << endl;
        cout << "Password: " << password << endl;
        cout << "Number: " << number << endl;
    }

    // Virtual function for viewing classes, to be overridden by derived classes
    virtual void ViewClass(string *Maths1, string *Physics1, string *Chemistry1, int p)
    {
    }

    // Virtual destructor
    virtual ~User()
    {
    }
};

// Define a class for assignments
class Assignments
{
private:
    string assignmentName;
    string dueDate;
    double marks;

public:
    // Constructors
    Assignments()
    {
        assignmentName = "";
        dueDate = "";
        marks = 0;
    }

    Assignments(string assignmentName, string dueDate, double marks)
    {
        this->assignmentName = assignmentName;
        this->dueDate = dueDate;
        this->marks = marks;
    }

    // Setters and getters for assignment attributes
    void setAssignmentName(string assignmentName)
    {
        this->assignmentName = assignmentName;
    }

    string getAssignmentName()
    {
        return assignmentName;
    }

    void setDueDate(string dueDate)
    {
        this->dueDate = dueDate;
    }

    string getDueDate()
    {
        return dueDate;
    }

    void setMarks(double marks)
    {
        this->marks = marks;
    }

    double getMarks()
    {
        return marks;
    }

    // Print assignment details
    void printAssignment()
    {
        cout << "Assignment Name: " << assignmentName << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "Marks: " << marks << endl;
    }

    // Destructor
    ~Assignments()
    {
    }
};

// Define a class for students, derived from User
class Student : public User
{
private:
    static int studentCount; // A static member to count the number of students
    Assignments homework;    // An instance of Assignments class for homework

public:
    // Constructors
    Student()
    {
        User();
        studentCount++;
    }

    Student(string name, string email, string rollNum, string password, string number)
    {
        setName(name);
        setEmail(email);
        setRollNum(rollNum);
        setPassword(password);
        setNumber(number);
    }

    // Function to register for a class
    void RegisterClass()
    {
    }

    // Function to get student count
    int getStudentCount()
    {
        return studentCount;
    }

    // Function to get student name
    string getStudentName()
    {
        return getName();
    }

    // Function to attempt an assignment
    bool AttemptAssignment()
    {
        return true;
    }

    // Print student details
    void print()
    {
        User::print();
    }

    // Override the ViewClass function to display registered classes for a student
    void ViewClass(string *Maths1, string *Physics1, string *Chemistry1, int p)
    {
        // Check if the student is registered for each subject and print accordingly
        if (Maths1[p] == "1")
        {
            cout << "\n- Maths" << endl;
        }
        if (Physics1[p] == "1")
        {
            cout << "\n- Physics" << endl;
        }
        if (Chemistry1[p] == "1")
        {
            cout << "\n- Chemistry" << endl;
        }
        else if (Maths1[p] == "0" && Physics1[p] == "0" && Chemistry1[p] == "0")
        {
            cout << "You are not registered for any class" << endl;
        }
    }
};

// Initialize the static member variable studentCount
int Student::studentCount = 0;

// Define a class for teachers, derived from User
class Teacher : public User
{
private:
public:
    // Constructors
    Teacher()
    {
        User();
    }

    Teacher(string name, string email, string rollNum, string password, string number)
    {
        setName(name);
        setEmail(email);
        setRollNum(rollNum);
        setPassword(password);
        setNumber(number);
    }

    // Function to make an assignment for a subject
    void MakeAssignment(string maths[], string phys[], string chem[], int index, Assignments &a)
    {
        // Prompt the user to set due date and marks for the assignment based on the subject
        if (maths[index] == "1")
        {
            cout << "Set due date: ";
            string input;
            cin >> input;
            cout << "Set marks: ";
            double marks;
            cin >> marks;
            a.setAssignmentName("Maths");
            a.setDueDate(input);
            a.setMarks(marks);
            cout << endl;
            a.printAssignment();
            cout << "\nAssignment made for Maths" << endl;
        }
        if (phys[index] == "1")
        {
            cout << "Set due date: ";
            string input;
            cin >> input;
            cout << "Set marks: ";
            double marks;
            cin >> marks;
            a.setAssignmentName("Physics");
            a.setDueDate(input);
            a.setMarks(marks);
            cout << endl;
            a.printAssignment();
            cout << "\nAssignment made for Physics" << endl;
        }
        if (chem[index] == "1")
        {
            cout << "Set due date: ";
            string input;
            cin >> input;
            cout << "Set marks: ";
            double marks;
            cin >> marks;
            a.setAssignmentName("Chemistry");
            a.setDueDate(input);
            a.setMarks(marks);
            cout << endl;
            a.printAssignment();
            cout << "\nAssignment made for Chemistry" << endl;
        }
    }

    // Function to create a new class
    string MakeClass()
    {
        cout << "Enter subject name: ";
        string subject;
        cin >> subject;
        return subject;
    }

    // Override the ViewClass function to display the subjects taught by the teacher
    void ViewClass(string *Maths1, string *Physics1, string *Chemistry1, int p)
    {
        cout << "\nSubjects you teach:" << endl;

        if (Maths1[p] == "1")
        {
            cout << "\n- Mathematics" << endl;
        }
        if (Physics1[p] == "1")
        {
            cout << "- Physics" << endl;
        }
        if (Chemistry1[p] == "1")
        {
            cout << "- Chemistry" << endl;
        }
    }

    // Print teacher details
    void print()
    {
        User::print();
    }

    // Destructor
    ~Teacher()
    {
    }
};

// Define a class for classrooms
class Classroom : public Teacher
{
private:
    string subject;
    string studentsArr[100];
    Teacher teacher;
    Assignments homework;

public:
    // Constructors
    Classroom()
    {
        subject = "";
        for (int i = 0; i < 100; i++)
        {
            studentsArr[i] = "";
        }
        teacher = Teacher();
        homework = Assignments();
    }

    Classroom(string subject, Student *students[100], Teacher teacher, Assignments a)
    {
        this->subject = subject;
        this->teacher = teacher;
        this->homework = a;
    }

    // Function to add a student to the classroom
    void addStudent(Student newStudent)
    {
        for (int i = 0; i < 100; i++)
        {
            if (studentsArr[i] == "")
            {
                studentsArr[i] = newStudent.getName();
                return; // Found an empty slot and added the student, so return from the function.
            }
        }
    }

    // Function to print the list of students in the classroom
    void getStudents()
    {
        for (int i = 0; i < 100; i++)
        {
            if (studentsArr[i] != "")
            {
                cout << studentsArr[i] << endl;
            }
        }
    }

    // Setters and getters for subject and teacher
    void setSubject(string subject)
    {
        this->subject = subject;
    }

    string getSubject()
    {
        return subject;
    }

    void setTeacher(Teacher teacher)
    {
        this->teacher = teacher;
    }

    Teacher getTeacher()
    {
        return teacher;
    }

    // Function to print the teacher's name
    void printTeacher()
    {
        cout << teacher.getName() << endl;
    }

    // Function to print the list of students in the classroom
    void printStudents()
    {
        for (int i = 0; i < 100; i++)
        {
            if (studentsArr[i] != "")
            {
                cout << studentsArr[i] << endl;
            }
        }
    }

    // Function to remove the classroom
    void RemoveClass()
    {
        subject = "";
        cout << "Class removed" << endl;
    }

    // Function to print classroom details
    void printClassroom()
    {
        cout << "Subject: " << subject << endl;
        cout << "Teacher: " << endl;
        printTeacher();
        cout << "Students: " << endl;
        printStudents();
    }

    // Function to add a teacher to the classroom
    void AddTeacher(Teacher teacher)
    {
        this->teacher = teacher;
    }

    // Destructor
    ~Classroom()
    {
    }
};