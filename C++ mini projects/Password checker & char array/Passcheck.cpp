// Ramis Hasanli & William Wilson | Lab 10 | COMP053
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//////////////////////////// Global Variables \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

char title[] = "Data Structures In C++";
char title2[] = "Data   Structures In        C++";
char password[4][30]{ {"monkey"},
  {"MonnkeeY"},
  {"M8nnkeeY"},
  {"M8nnkeeY!"} };



//////////////////////////// APP FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

// STRING FUNCTIONS
// Split sentence to words & print them out.
void splittedPrint(char arr[]) {
    int count = 0;
    for (int i = 0; i < strlen(arr); ++i) {
        if (isblank(arr[i])) {
            count++;
            if (count == 1)
                cout << endl;
        }
        else {
            cout << arr[i];
            count = 0;
        }
    }
}


// Flip the case of first verb all words in array starting with & print them out
void stringFlipCase(char arr[]) {
    char tempLetter;
    for (int i = 0; i < strlen(arr); ++i) {
        if (isupper(arr[i])) {
            tempLetter = tolower(arr[i]);
            cout << tempLetter;
        }
        else if (islower(arr[i])) {
            tempLetter = toupper(arr[i]);
            cout << tempLetter;
        }
        else
            cout << arr[i];
    }
}



// Remove alpha characters in array & print string
void stringTrimNonAlphanumeric(char arr[]) {
    for (int i = 0; i < strlen(arr); ++i) {
        if (isalnum(arr[i])) {
            cout << arr[i];
        }
        else {
            continue;
        }
    }
    }


// PASSWORD FUNCTIONS
// Bool for Upper ch.
bool hasUpper(char arr[]) {
    for (int i = 0; arr[i] != '\0'; ++i) {
        if (isupper(arr[i])) {
            return true;
        }
        else if (i == strlen(arr) - 1) {
            return false;
        }
        else {
            continue;
        }
    }
}


// Bool for Low ch.
bool hasLower(char arr[]) {
    for (int i = 0; arr[i] != '\0'; ++i) {
        if (islower(arr[i])) {
            return true;
        }
        else if (i == strlen(arr) - 1) {
            return false;
        }
        else {
            continue;
        }
    }
}


// Bool for special ch.
bool hasSpecial(char arr[]){
for (int i = 0; arr[i] != '\0'; ++i) {
    if (ispunct(arr[i])) {
        return true;
    }
    else if (i == strlen(arr) - 1) {
        return false;
    }
    else {
        continue;
    }
}
}


// Bool for alpha ch.
bool hasAlpha(char arr[]){
if (strlen(arr) < 8) {
    return false;
}
else {
    return true;
}
}


// Bool for digits.
bool hasDigit(char arr[]) {
    for (int i = 0; arr[i] != '\0'; ++i) {
        if (isdigit(arr[i])) {
            return true;
        }
        else if (i == strlen(arr) - 1) {
            return false;
        }
        else {
            continue;
        }
    }
}

// Valid password check
bool isValidPassword(char arr[]) {
    bool isValid = true;
    if (!hasLower(arr)) {
        cout << arr << " Not Accepted! Passwords must include at least one lowercase alphabetic character. " << endl;
        isValid = false;
    }
    if (!hasUpper(arr)) {
        cout << arr << " Not Accepted! Passwords must include at least one uppercase alphabetic character." << endl;
        isValid = false;
    }
    if (!hasDigit(arr)) {
        cout << arr << " Not Accepted! Passwords must include at least one digit." << endl;
        isValid = false;
    }
    if (!hasAlpha(arr)) {
        cout << arr << " Not Accepted! Passwords must be at least 8 characters long." << endl;
        isValid = false;
    }
    if (!hasSpecial(arr)) {
        cout << arr << " Not Accepted! Passwords must include at least one special character" << endl;
        cout << "$%&’()*+,-./:;<=>?@[\]^_‘{|}~" << endl;
        isValid = false;
    }
    return isValid;
}




//////////////////////////// MAIN FUNCTION \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

int main() {

    cout << "Splitting title: " << endl;
    splittedPrint(title);
    cout << endl;

    cout << "\nSplitting title2: " << endl;
    splittedPrint(title2);

    cout << "\n\nFlipping the case in title1: ";
    stringFlipCase(title);

    cout << "\nTrimming non-alphanumeric characters in title1: ";
    stringTrimNonAlphanumeric(title);

    cout << "\nTrimming non-alphanumeric characters in title2: ";
    stringTrimNonAlphanumeric(title2);
    cout << endl << endl;

    for (int i = 0; i < 4; i++) {
        if (isValidPassword(password[i]))
            cout << password[i] << " Accepted." << endl;
        cout << endl;
    }

    cout << "^_^ This lab completed by William Wilson & Ramis Hasanli. Thanks & Have a Good Day! ^_^" << endl;
    return 0;

}
