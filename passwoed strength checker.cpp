#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string password;
    bool uppercase = false;
    bool lowercase = false;
    bool digit = false;
    bool special = false;

    cout << "===== Password Strength Checker =====" << endl;
    cout << "Enter your password: ";
    cin >> password;

    for (int i = 0; i < password.length(); i++)
    {
        if (isupper(password[i]))
            uppercase = true;
        else if (islower(password[i]))
            lowercase = true;
        else if (isdigit(password[i]))
            digit = true;
        else
            special = true;
    }

    int score = 0;

    if (password.length() >= 8)
        score++;

    if (uppercase)
        score++;

    if (lowercase)
        score++;

    if (digit)
        score++;

    if (special)
        score++;

    cout << "\nPassword Analysis:" << endl;

    cout << "Length >= 8: "
         << (password.length() >= 8 ? "Yes" : "No") << endl;

    cout << "Uppercase letter: "
         << (uppercase ? "Yes" : "No") << endl;

    cout << "Lowercase letter: "
         << (lowercase ? "Yes" : "No") << endl;

    cout << "Number: "
         << (digit ? "Yes" : "No") << endl;

    cout << "Special character: "
         << (special ? "Yes" : "No") << endl;

    cout << "\nPassword Strength: ";

    if (score <= 2)
        cout << "Weak";
    else if (score <= 4)
        cout << "Medium";
    else
        cout << "Strong";

    cout << endl;

    return 0;
}
