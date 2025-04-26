#include <iostream>
#include <cmath>

using namespace std;

// Function to check if a number is a Palindrome
int isPalindrome(int *num) {
    int *original = new int(*num);
    int *reversed = new int(0);
    int *temp = new int(*num);
    
    while (*temp > 0) {
        int *remainder = new int(*temp % 10);
        *reversed = *reversed * 10 + *remainder;
        *temp /= 10;
        delete remainder;
    }

    int *result = new int((*original == *reversed) ? 1 : 0);
    delete original;
    delete reversed;
    delete temp;
    return *result;
}

// Function to check if a number is an Armstrong number
int isArmstrong(int *num) {
    int *original = new int(*num);
    int *sum = new int(0);
    int *temp = new int(*num);
    int *digits = new int(0);
    
    while (*temp > 0) {
        *temp /= 10;
        (*digits)++;
    }
    
    *temp = *num; 
    while (*temp > 0) {
        int *remainder = new int(*temp % 10);
        *sum += pow(*remainder, *digits);
        *temp /= 10;
        delete remainder;
    }

    int *result = new int((*original == *sum) ? 1 : 0);
    delete original;
    delete sum;
    delete temp;
    delete digits;
    return *result;
}

// Function to check if a number is a Perfect number
int isPerfect(int *num) {
    int *sum = new int(0);
    
    for (int *i = new int(1); *i <= (*num) / 2; (*i)++) {
        if (*num % *i == 0)
            *sum += *i;
        delete i;
    }

    int *result = new int((*sum == *num) ? 1 : 0);
    delete sum;
    return *result;
}

int main() {
    int *choice = new int(0);
    
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Check Palindrome\n";
        cout << "2. Check Armstrong Number\n";
        cout << "3. Check Perfect Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> *choice;

        if (*choice >= 1 && *choice <= 3) {
            int *num = new int;
            cout << "Enter a positive integer: ";
            cin >> *num;

            if (*num < 0) {
                cout << "Negative numbers are not allowed!\n";
            } else {
                switch (*choice) {
                    case 1:
                        cout << (isPalindrome(num) ? "Palindrome Number" : "Not a Palindrome") << endl;
                        break;
                    case 2:
                        cout << (isArmstrong(num) ? "Armstrong Number" : "Not an Armstrong Number") << endl;
                        break;
                    case 3:
                        cout << (isPerfect(num) ? "Perfect Number" : "Not a Perfect Number") << endl;
                        break;
                }
            }

            delete num; 
        } 
        else if (*choice != 4) {
            cout << "Invalid choice! Please try again.\n";
        }

    } while (*choice != 4);

    delete choice;
    cout << "Program exited successfully.\n";
    return 0;
}