#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool authenticateUser(const string& username, const string& password)
{
    const string validUsername = "admin";
    const string validPassword = "password";
    
    return (username == validUsername && password == validPassword);
}

void login()
{
    string username;
    string password;

    cout << "\n\n        ::::::::::::::::::::::::::  LOGIN FORM  ::::::::::::::::::::::::::  ";
    cout << " \n                              ENTER USER ID:-";
    cin >> username;
    cout << "                              ENTER PASSWORD:-";
    cin >> password;
    
    if (authenticateUser(username, password))
    {
        cout << "Login successful!" << "\n";
       
    }
    else
    {
        cout << "Login failed. Invalid username or password." << "\n";
        
    }
}

int main()
{
    login();
 
}