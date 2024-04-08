// Rayyan Mohsin 22i-2052 Semester-End Project

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include <iomanip>
#include "Project.h"

using namespace std;


int main()
{
    ifstream inputFile;
    inputFile.open("file.csv");
    string name, roll, email, password, temp, maths1, phys1, chem1;
    string line, myString, Name[220], Roll[220], Email[220], Password[220], Maths1[220], Physics1[220], Chemistry1[220];
    int i = 0;

    while (getline(inputFile, line))
    {
        stringstream ss(line);
        getline(ss, temp, ',');
        getline(ss, roll, ',');
        getline(ss, name, ',');
        getline(ss, password, ',');
        getline(ss, email, ',');
        getline(ss, maths1, ',');
        getline(ss, phys1, ',');
        getline(ss, chem1, ',');
        Maths1[i] = maths1;
        Physics1[i] = phys1;
        Chemistry1[i] = chem1;
        Name[i] = name;
        Roll[i] = roll;
        Email[i] = email;
        Password[i] = password;
        i++;
    }

    inputFile.close();

    ifstream inputFile2;
    inputFile2.open("Teachers.csv");
    int p;
    string name2, roll2, email2, password2, temp2;
    string mathematics, phys, chem;
    string line2, myString2, Name2[13], Roll2[13], Email2[13], Password2[13];
    string Maths[13], Physics[13], Chemistry[13];
    int j = 0;

    while (getline(inputFile2, line2))
    {
        stringstream ss(line2);
        getline(ss, name2, ',');
        getline(ss, roll2, ',');
        getline(ss, password2, ',');
        getline(ss, email2, ',');
        getline(ss, mathematics, ',');
        getline(ss, phys, ',');
        getline(ss, chem, ',');
        Name2[j] = name2;
        Roll2[j] = roll2;
        Email2[j] = email2;
        Password2[j] = password2;
        Maths[j] = mathematics;
        Physics[j] = phys;
        Chemistry[j] = chem;
        j++;
    }

    inputFile2.close();
    User *user;
    User *user2;

    int choice;
    cout << "Welcome to the Classroom management system " << endl;
    cout << "Select your role: " << endl;
    cout << "1. Student" << endl;
    cout << "2. Teacher" << endl;
    cin >> choice;

    while (choice != 1 && choice != 2)
    {
        cout << "Invalid choice, please try again" << endl;
        cin >> choice;
    }

    Classroom maths, physics, chemistry;
    maths.setSubject("Maths");
    physics.setSubject("Physics");
    chemistry.setSubject("Chemistry");

    Student s;
    user = &s;

    Teacher t;
    user2 = &t;

    switch (choice)
    {
    case 1:
    {
        bool login = false;
        int Student_LoginCount = 0;
        do
        {
            if (Student_LoginCount >= 1)
            {
                cout << "\nInvalid credentials, please try again";
            }

            Student_LoginCount++;
            cout << "\nEnter your roll number: ";
            cin >> roll;
            cout << "\nEnter your email: ";
            cin >> email;
            cout << "\nEnter your password: ";
            char ch;
            string password;
            while ((ch = _getch()) != '\r')
            { // Enter key
                if (ch == '\b')
                { // Backspace
                    if (!password.empty())
                    {
                        std::cout << "\b \b";
                        password.pop_back();
                    }
                }
                else
                {
                    std::cout << '*';
                    password.push_back(ch);
                }
            }

            for (int i = 0; i < 220; i++)
            {
                if (roll == Roll[i] && email == Email[i] && password == Password[i])
                {
                    cout << "Login Successful" << endl;
                    user->setName(Name[i]);
                    user->setRollNum(Roll[i]);
                    user->setEmail(Email[i]);
                    user->setPassword(Password[i]);
                    login = true;
                    p = i;
                }
            }
        } while (login == false);
        int x;
        Notification student_notification;
        if (login == true)
        {
            student_notification.setNotification("Alert: You have a new assignment");
            cout << "\n\nWelcome"
                 << " " << user->getName() << setw(50) << student_notification.getNotification() << endl;
        }
        do
        {
            if (login == true)
            {
                cout << "\nSelect your choice" << endl;
                cout << "1. Register for a class" << endl;
                cout << "2. View your classes" << endl;
                cout << "3. Attempt Assignment" << endl;
                cout << "4. View your attendance" << endl;
                cout << "\nPress 0 to exit" << endl;

                cin >> x;
                while (x != 1 && x != 2 && x != 3 && x != 4 && x != 0)
                {
                    cout << "\nInvalid choice, please try again" << endl;
                    cin >> x;
                }

                if (x == 1)
                {
                    student_notification.setNotification("Alert: You can choose uptil 3 classes only");
                    cout << "Select the class you want to register for" << setw(50) << student_notification.getNotification() << endl;
                    cout << "1. Maths" << endl;
                    cout << "2. Physics" << endl;
                    cout << "3. Chemistry" << endl;
                    int y;
                    cin >> y;
                    while (y != 1 && y != 2 && y != 3)
                    {
                        cout << "Invalid choice, please try again" << endl;
                        cin >> y;
                    }
                    if (y == 1)
                    {
                        maths.addStudent(s);
                        Maths1[p] = "1";
                        cout << "\nYou have been added to the Mathematics Classroom." << endl;
                    }
                    if (y == 2)
                    {
                        physics.addStudent(s);
                        Physics1[p] = "1";
                        cout << "\nYou have been added to the Physics Classroom." << endl;
                    }
                    if (y == 3)
                    {
                        chemistry.addStudent(s);
                        Chemistry1[p] = "1";
                        cout << "\nYou have been added to the Chemistry Classroom." << endl;
                    }
                }
                else if (x == 2)
                {
                    user->ViewClass(Maths1, Physics1, Chemistry1, p); // Use of PolyMorphism
                }

                else if (x == 3)
                {
                    if (Maths1[p] == "1")
                    {
                        char ch;
                        cout << "Assignment available for Maths" << endl;
                        do
                        {

                            cout << "Attempt Assignment? (Y/N)" << endl;
                            cin >> ch;
                            while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n')
                            {
                                cout << "Invalid choice, please try again" << endl;
                                cin >> ch;
                            }

                            if (ch == 'Y' || ch == 'y')
                            {
                                s.AttemptAssignment();
                                cout << "Assignment attempted successfully" << endl;
                            }

                            else if (ch == 'N' || ch == 'n')
                            {
                                cout << "YOU'RE SUPPOSED TO ATTEMPT YOUR ASSIGNMENT!" << endl;
                            }
                        } while (ch != 'y' && ch != 'Y');
                    }

                    if (Physics1[p] == "1")
                    {
                        char ch;
                        cout << "Assignment available for Physics" << endl;
                        do
                        {

                            cout << "Attempt Assignment? (Y/N)" << endl;
                            cin >> ch;
                            while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n')
                            {
                                cout << "Invalid choice, please try again" << endl;
                                cin >> ch;
                            }

                            if (ch == 'Y' || ch == 'y')
                            {
                                s.AttemptAssignment();
                                cout << "Assignment attempted successfully" << endl;
                            }

                            else if (ch == 'N' || ch == 'n')
                            {
                                cout << "YOU'RE SUPPOSED TO ATTEMPT YOUR ASSIGNMENT!" << endl;
                            }
                        } while (ch != 'y' && ch != 'Y');
                    }

                    if (Chemistry1[p] == "1")
                    {
                        char ch;
                        cout << "Assignment available for Chemistry" << endl;
                        do
                        {

                            cout << "Attempt Assignment? (Y/N)" << endl;
                            cin >> ch;
                            while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n')
                            {
                                cout << "Invalid choice, please try again" << endl;
                                cin >> ch;
                            }

                            if (ch == 'Y' || ch == 'y')
                            {
                                s.AttemptAssignment();
                                cout << "Assignment attempted successfully" << endl;
                            }

                            else if (ch == 'N' || ch == 'n')
                            {
                                cout << "YOU'RE SUPPOSED TO ATTEMPT YOUR ASSIGNMENT!" << endl;
                            }
                        } while (ch != 'y' && ch != 'Y');
                    }
                }

                else if (x == 4){
                    cout << "Marked Present upon login" << endl;
                }
            }
            else if (login == false)
            {
                cout << "Invalid credentials" << endl;
            }
        } while (x != 0);
        break;
    }
    case 2:
    {
        bool login = false;
        int LoginCount = 0;
        do
        {
            if (LoginCount >= 1)
            {
                cout << "\nInvalid credentials, please try again" << endl;
            }
            LoginCount++;
            cout << "\nEnter your roll number: " << endl;
            cin >> roll2;
            cout << "\nEnter your email: " << endl;
            cin >> email2;
            cout << "\nEnter your password: " << endl;
            cin >> password2;
            int p;
            for (int i = 0; i < 13; i++)
            {
                if (roll2 == Roll2[i] && email2 == Email2[i] && password2 == Password2[i])
                {
                    cout << "\nLogin Successful" << endl;
                    user2->setName(Name2[i]);
                    p = i;
                    user2->setRollNum(Roll2[i]);
                    user2->setEmail(Email2[i]);
                    user2->setPassword(Password2[i]);
                    login = true;
                }
            }
        } while (login == false);
        int b;
        Notification teacher_notification;
        teacher_notification.setNotification("Alert: Students are waiting for your assignment");
        if (login == true)
        {
            cout << "\nWelcome, " << t.getName() << "!" << setw(50) << teacher_notification.getNotification() << endl;
        }
        do
        {

            if (login == true)
            {
                cout << "\nSelect your choice" << endl;
                cout << "1. Register for a class" << endl;
                cout << "2. View your classes" << endl;
                cout << "3. View your students" << endl;
                cout << "4. Make assignment" << endl;
                cout << "5. Add a student to a class" << endl;
                cout << "6. Remove a class" << endl;
                cout << "7. Make a class" << endl;
                cout << "\nPress 0 to exit" << endl;
                cin >> b;

                while (b != 1 && b != 2 && b != 3 && b != 4 && b != 0 && b != 5 && b != 6 && b != 7)
                {
                    cout << "\nInvalid choice, please try again" << endl;
                    cin >> b;
                }

                switch (b)
                {
                case 1:
                {
                    teacher_notification.setNotification("Alert: You can only teach 3 classes at a time");
                    cout << "\nWhich class do you want to register for?" << setw(100) << teacher_notification.getNotification() << endl;
                    cout << "1. Maths" << endl
                         << "2. Physics" << endl
                         << "3. Chemistry" << endl;
                    int c;
                    cin >> c;
                    while (c != 1 && c != 2 && c != 3)
                    {
                        cout << "Invalid choice, please try again" << endl;
                        cin >> c;
                    }

                    if (c == 1)
                    {

                        Maths[p] = "1";
                        cout << "\nYou have been registered as a Teacher for Maths class." << endl;
                        maths.AddTeacher(t);
                    }
                    else if (c == 2)
                    {

                        Physics[p] = "1";
                        cout << "\nYou have been registered as a Teacher for Physics class." << endl;
                        physics.AddTeacher(t);
                    }
                    else if (c == 3)
                    {

                        Chemistry[p] = "1";
                        cout << "\nYou have been registered as a Teacher for Chemistry class." << endl;
                        chemistry.AddTeacher(t);
                    }
                    break;
                }
                case 2:
                {

                    user2->ViewClass(Maths, Physics, Chemistry, p);

                    break;
                }
                case 3:
                {
                    if (Maths[p] == "1")
                    {
                        cout << "\nStudents in your Maths class:" << endl;
                        for (int i = 0; i < 218; i++)
                        {
                            if (Maths1[i] == "1")
                            {
                                cout << "- " << Name[i] << endl;
                            }
                        }
                    }
                    if (Physics[p] == "1")
                    {
                        cout << "\nStudents in your Physics class:" << endl;
                        for (int i = 0; i < 218; i++)
                        {
                            if (Physics1[i] == "1")
                            {
                                cout << "- " << Name[i] << endl;
                            }
                        }
                    }
                    if (Chemistry[p] == "1")
                    {
                        cout << "\nStudents in your Chemistry class:" << endl;
                        for (int i = 0; i < 218; i++)
                        {
                            if (Chemistry1[i] == "1")
                            {
                                cout << "- " << Name[i] << endl;
                            }
                        }
                    }
                    if (Maths[p] == "0" && Physics[p] == "0" && Chemistry[p] == "0")
                    {
                        cout << "\nYou are not registered as a teacher for any class." << endl;
                    }
                    break;
                }
                case 4:
                {

                    Assignments a;
                    t.MakeAssignment(Maths, Physics, Chemistry, p, a);

                    break;
                }

                case 5:
                {
                    string roll;
                    bool validRoll = false;

                    do
                    {
                        cout << "Enter the roll number of the student you want to add: " << endl;
                        cin >> roll;

                        for (int i = 0; i < 218; i++)
                        {
                            if (roll == Roll[i])
                            {
                                validRoll = true;
                                cout << "Student is: " << Name[i] << endl;
                                cout << "\nEnter the class you want to add the student to: " << endl;
                                cout << "1. Maths" << endl
                                     << "2. Physics" << endl
                                     << "3. Chemistry" << endl;
                                int c;
                                cin >> c;

                                while (c != 1 && c != 2 && c != 3)
                                {
                                    cout << "Invalid choice, please try again" << endl;
                                    cin >> c;
                                }

                                if (c == 1)
                                {
                                    if (maths.getSubject() == "")
                                    {
                                        cout << "Maths class doesn't exist" << endl;
                                    }
                                    if (Maths1[i] == "1")
                                    {
                                        cout << "Student is already in Maths class" << endl;
                                        break;
                                    }
                                    Maths1[i] = "1";
                                    cout << "Student added to Maths class" << endl;
                                }
                                else if (c == 2)
                                {
                                    if (physics.getSubject() == "")
                                    {
                                        cout << "Physics class doesn't exist" << endl;
                                    }
                                    if (Physics1[i] == "1")
                                    {
                                        cout << "Student is already in Physics class" << endl;
                                        break;
                                    }
                                    Physics1[i] = "1";
                                    cout << "Student added to Physics class" << endl;
                                }
                                else if (c == 3)
                                {
                                    if (chemistry.getSubject() == "")
                                    {
                                        cout << "Chemistry class doesn't exist" << endl;
                                    }
                                    if (Chemistry1[i] == "1")
                                    {
                                        cout << "Student is already in Chemistry class" << endl;
                                        break;
                                    }
                                    Chemistry1[i] = "1";
                                    cout << "Student added to Chemistry class" << endl;
                                }
                            }
                        }

                        if (!validRoll)
                        {
                            cout << "Invalid roll number. Please try again." << endl;
                        }
                    } while (!validRoll);

                    break;
                }

                case 6:
                {
                    cout << "Which class do you want to remove?" << endl;
                    cout << "1. Maths" << endl
                         << "2. Physics" << endl
                         << "3. Chemistry" << endl;
                    int c;
                    cin >> c;

                    while (c != 1 && c != 2 && c != 3)
                    {
                        cout << "Invalid choice, please try again" << endl;
                        cin >> c;
                    }

                    if (c == 1)
                    {
                        maths.setSubject("");
                    }
                    else if (c == 2)
                    {
                        physics.setSubject("");
                    }
                    else if (c == 3)
                    {
                        chemistry.setSubject("");
                    }

                    break;
                }

                case 7:
                {
                    cout << "Enter the subject of your new class: ";
                    string s;
                    cin >> s;
                    Classroom c;
                    c.setSubject(s);
                    cout << s << " Class created successfully" << endl;
                }

                default:
                    break;
                }
            }
        } while (b != 0);
        break;
    }
    }
}