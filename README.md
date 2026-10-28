# 🔐 Password Strength Checker

## 📌 Overview
The **Password Strength Checker** is a beginner-friendly cybersecurity mini-project developed using C++. It analyzes a password based on its length, character variety, and basic security risks to estimate its strength and suggest improvements.

## ✨ Features
- **Password Scoring:** Calculates a score out of 100.
- **Length Validation:** Checks whether the password meets minimum length requirements.
- **Character Analysis:** Detects uppercase letters, lowercase letters, numbers, and special characters.
- **Common Password Detection:** Identifies selected common passwords.
- **Repeated Character Detection:** Flags passwords containing only the same character.
- **Security Report:** Displays a detailed analysis of the password.
- **Improvement Suggestions:** Recommends ways to strengthen weak passwords.
- **Multiple Checks:** Allows users to analyze multiple passwords in one session.
- **Input Handling:** Supports passwords containing spaces.

## 🛠️ Technologies Used
- **Programming Language:** C++
- **Libraries:** `iostream`, `string`, `cctype`, `algorithm`

## ⚙️ How It Works
1. The user enters a password.
2. The program checks its length and character types.
3. It detects selected common passwords and repeated characters.
4. A score is calculated using predefined rules and penalties.
5. The password is classified as Weak, Medium, Strong, or Very Strong.
6. Suggestions are displayed to improve password security.

## 📊 Password Strength Levels

| Score / Condition | Strength |
|---|---|
| Score below 40 | Weak |
| Score 40–69 | Medium |
| Score 70–89 | Strong |
| Score 90–100 | Very Strong |

**Note:** Common passwords, passwords shorter than 8 characters, and passwords containing only identical characters are classified as Weak regardless of score.

## ▶️ How to Run

1. Install a C++ compiler, such as GCC.
2. Clone or download this repository.
3. Save the source code as `password_checker.cpp`.
4. Open a terminal in the project directory.
5. Compile the program:

   ```bash
   g++ password_checker.cpp -o password_checker
   ```

6. Run the program:

   **Windows:**
   ```bash
   .\password_checker.exe
   ```

   **Linux:**
   ```bash
   ./password_checker
   ```

## 💻 Sample Output

```text
====================================
     PASSWORD STRENGTH CHECKER
====================================
Enter your password: example

---------- SECURITY REPORT ----------
Password length: 7 characters
At least 8 characters: No
At least 12 characters: No
Uppercase letter: No
Lowercase letter: Yes
Number: No
Special character: No
Contains spaces: No
Common password detected: No
All characters identical: No

Password Score: 20/100
Password Strength: WEAK

---------- SUGGESTIONS ----------
- Use at least 12 characters.
- Add an uppercase letter (A-Z).
- Include a number (0-9).
- Include a special character (!, @, #, etc.).
```

## 🎯 Project Objectives
- Understand basic password security concepts.
- Practice C++ loops, conditional statements, strings, and functions.
- Learn character validation and basic security checks.
- Develop problem-solving skills through a practical cybersecurity application.

## 🔮 Future Enhancements
- Random password generation.
- Password masking during input.
- Detection of predictable patterns and keyboard sequences.
- Exporting analysis reports to a text file without storing passwords.
- Graphical user interface (GUI).

## ⚠️ Limitations
This project uses a simple, rule-based scoring system and a limited list of common passwords. Its score is an estimate, not a guarantee of password security. It should not be used as a replacement for professional password-auditing tools.

**Privacy:** Do not enter real or sensitive passwords into demonstration programs. This program does not need to save passwords to perform its analysis.

## 👩‍💻 Author
**Sanjana Mallick**

B.Tech CSIT (Cybersecurity) Student

## 📄 License
This project is available for educational and personal learning purposes.
