/*
----------------------------------------------
Project Name : Login & Registration System

Internship : CodeAlpha C++ Programming Internship

Developed By : Namra Saleem Ahmed

Language : C++

----------------------------------------------
*/


#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

//==============================
// Function Prototypes
//==============================
void displayMenu();
void registerUser();
void loginUser();
bool usernameExists(string username);

//==============================
// Main Function
//==============================
int main()
{
    int choice;

    do
    {
        displayMenu();

        cout << "\nEnter Your Choice : ";
        cin >> choice;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid Input! Enter Again : ";
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
            registerUser();
            break;

        case 2:
            loginUser();
            break;

        case 3:
            cout << "\nThank You For Using CodeAlpha Login System.\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

        if (choice != 3)
        {
            cout << "\nPress Enter To Continue...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 3);

    return 0;
}
//==============================
// Display Menu
//==============================
void displayMenu()
{
    system("cls");

    cout << "=====================================================\n";
    cout << "        CODEALPHA LOGIN & REGISTRATION SYSTEM\n";
    cout << "=====================================================\n";
    cout << "1. Register New User\n";
    cout << "2. Login\n";
    cout << "3. Exit\n";
    cout << "=====================================================\n";
}

//==============================
// Check Existing Username
//==============================
bool usernameExists(string username)
{
    ifstream file("users.txt");

    string storedUsername;
    string storedPassword;

    while (file >> storedUsername >> storedPassword)
    {
        if (storedUsername == username)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

//==============================
// Register User
//==============================
void registerUser()
{
    string username;
    string password;
    string confirmPassword;

    cout << "\n========== USER REGISTRATION ==========\n";

    cout << "Enter Username : ";
    cin >> username;

    if (usernameExists(username))
    {
        cout << "\nUsername Already Exists!\n";
        return;
    }

    cout << "Enter Password : ";
    cin >> password;

    if (password.length() < 6)
    {
        cout << "\nPassword Must Contain At Least 6 Characters.\n";
        return;
    }

    cout << "Confirm Password : ";
    cin >> confirmPassword;

    if (password != confirmPassword)
    {
        cout << "\nPasswords Do Not Match!\n";
        return;
    }

    ofstream file("users.txt", ios::app);

    file << username << " " << password << endl;

    file.close();

    cout << "\n=======================================\n";
    cout << "Registration Successful!\n";
    cout << "Welcome, " << username << "!\n";
    cout << "=======================================\n";
}
//==============================
// Login User
//==============================
void loginUser()
{
    string username;
    string password;

    cout << "\n========== USER LOGIN ==========\n";

    cout << "Enter Username : ";
    cin >> username;

    cout << "Enter Password : ";
    cin >> password;

    ifstream file("users.txt");

    if (!file)
    {
        cout << "\nNo registered users found!\n";
        return;
    }

    string storedUsername;
    string storedPassword;
    bool loginSuccess = false;

    while (file >> storedUsername >> storedPassword)
    {
        if (username == storedUsername && password == storedPassword)
        {
            loginSuccess = true;
            break;
        }
    }

    file.close();

    if (loginSuccess)
    {
        cout << "\n=====================================\n";
        cout << "        LOGIN SUCCESSFUL!\n";
        cout << "=====================================\n";
        cout << "Welcome Back, " << username << "!\n";
        cout << "You have successfully logged in.\n";
    }
    else
    {
        cout << "\n=====================================\n";
        cout << "Login Failed!\n";
        cout << "Invalid Username or Password.\n";
        cout << "=====================================\n";
    }
}
