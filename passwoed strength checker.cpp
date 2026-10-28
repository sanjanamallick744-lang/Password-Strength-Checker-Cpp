
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

bool isCommonPassword(string password)
{
    string commonPasswords[] = {
        "password", "password123", "12345678",
        "qwerty123", "admin123", "welcome123",
        "iloveyou", "123456789", "abc123"
    };

    transform(password.begin(), password.end(),
              password.begin(),
              [](unsigned char ch) {
                  return static_cast<char>(tolower(ch));
              });

    for (int i = 0; i < 9; i++)
    {
        if (password == commonPasswords[i])
            return true;
    }

    return false;
}

int main()
{
    string password;
    char choice;

    do
    {
        bool uppercase = false;
        bool lowercase = false;
        bool digit = false;
        bool special = false;
        bool space = false;
        bool allSame = true;

        int score = 0;

        cout << "\n====================================";
        cout << "\n     PASSWORD STRENGTH CHECKER";
        cout << "\n====================================";
        cout << "\nEnter your password: ";

        getline(cin, password);

        if (password.empty())
        {
            cout << "\nPassword cannot be empty!\n";
            continue;
        }

        for (int i = 0; i < (int)password.length(); i++)
        {
            unsigned char ch =
                static_cast<unsigned char>(password[i]);

            if (isupper(ch))
                uppercase = true;
            else if (islower(ch))
                lowercase = true;
            else if (isdigit(ch))
                digit = true;
            else if (isspace(ch))
                space = true;
            else
                special = true;

            if (password[i] != password[0])
                allSame = false;
        }

        bool common = isCommonPassword(password);

        // Length score
        if (password.length() >= 8)
            score += 20;

        if (password.length() >= 12)
            score += 15;

        if (password.length() >= 16)
            score += 10;

        // Character variety score
        if (uppercase)
            score += 10;

        if (lowercase)
            score += 10;

        if (digit)
            score += 10;

        if (special)
            score += 15;

        // Additional security checks
        if (!space)
            score += 5;

        if (!common)
            score += 5;

        // Apply penalties
        if (common)
            score -= 30;

        if (allSame)
            score -= 30;

        if (score < 0)
            score = 0;

        cout << "\n---------- SECURITY REPORT ----------\n";

        cout << "Password length: "
             << password.length() << " characters\n";

        cout << "At least 8 characters: "
             << (password.length() >= 8 ? "Yes" : "No") << endl;

        cout << "At least 12 characters: "
             << (password.length() >= 12 ? "Yes" : "No") << endl;

        cout << "Uppercase letter: "
             << (uppercase ? "Yes" : "No") << endl;

        cout << "Lowercase letter: "
             << (lowercase ? "Yes" : "No") << endl;

        cout << "Number: "
             << (digit ? "Yes" : "No") << endl;

        cout << "Special character: "
             << (special ? "Yes" : "No") << endl;

        cout << "Contains spaces: "
             << (space ? "Yes" : "No") << endl;

        cout << "Common password detected: "
             << (common ? "Yes" : "No") << endl;

        cout << "All characters identical: "
             << (allSame ? "Yes" : "No") << endl;

        cout << "\nPassword Score: " << score << "/100\n";

        cout << "Password Strength: ";

        if (common || allSame ||
            password.length() < 8 || score < 40)
        {
            cout << "WEAK";
        }
        else if (score < 70)
        {
            cout << "MEDIUM";
        }
        else if (score < 90)
        {
            cout << "STRONG";
        }
        else
        {
            cout << "VERY STRONG";
        }

        cout << "\n\n---------- SUGGESTIONS ----------\n";

        bool suggestion = false;

        if (password.length() < 12)
        {
            cout << "- Use at least 12 characters.\n";
            suggestion = true;
        }

        if (!uppercase)
        {
            cout << "- Add an uppercase letter (A-Z).\n";
            suggestion = true;
        }

        if (!lowercase)
        {
            cout << "- Add a lowercase letter (a-z).\n";
            suggestion = true;
        }

        if (!digit)
        {
            cout << "- Include a number (0-9).\n";
            suggestion = true;
        }

        if (!special)
        {
            cout << "- Include a special character (!, @, #, etc.).\n";
            suggestion = true;
        }

        if (space)
        {
            cout << "- Remove spaces for better compatibility.\n";
            suggestion = true;
        }

        if (common)
        {
            cout << "- Avoid common or predictable passwords.\n";
            suggestion = true;
        }

        if (allSame)
        {
            cout << "- Avoid repeating the same character.\n";
            suggestion = true;
        }

        if (!suggestion)
        {
            cout << "Good! No basic improvements detected.\n";
        }

        cout << "\nCheck another password? (y/n): ";
        cin >> choice;
        cin.ignore(10000, '\n');

    } while (choice == 'y' || choice == 'Y');

    cout << "\nThank you for using Password Strength Checker!\n";

    return 0;
}
