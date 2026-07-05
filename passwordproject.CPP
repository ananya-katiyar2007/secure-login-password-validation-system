#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

bool checkPassword(string password)
{
    bool upper = false, lower = false, digit = false, special = false;

    if(password.length() < 8)
        return false;

    for(char ch : password)
    {
        if(isupper(ch))
            upper = true;
        else if(islower(ch))
            lower = true;
        else if(isdigit(ch))
            digit = true;
        else
            special = true;
    }

    return upper && lower && digit && special;
}

void registerUser()
{
    string username, password;

    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    if(!checkPassword(password))
    {
        cout << "\nWeak Password!\n";
        cout << "Password should have:\n";
        cout << "- At least 8 characters\n";
        cout << "- One uppercase letter\n";
        cout << "- One lowercase letter\n";
        cout << "- One digit\n";
        cout << "- One special character\n";
        return;
    }

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "\nRegistration Successful!\n";
}

void login()
{
    string username, password;
    string u, p;
    bool found = false;

    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream file("users.txt");

    while(file >> u >> p)
    {
        if(username == u && password == p)
        {
            found = true;
            break;
        }
    }

    file.close();

    if(found)
        cout << "\nLogin Successful!\n";
    else
        cout << "\nInvalid Username or Password!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== PASSWORD CHECKER =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                login();
                break;

            case 3:
                cout << "Thank You!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 3);

    return 0;
}