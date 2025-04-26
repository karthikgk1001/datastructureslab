#include <iostream>
#include <stack>
using namespace std;

string processString(const string& input) {
    stack<char> s; // Stack to process characters

    for (char ch : input) {
        if (ch == '+') {
            if (!s.empty()) {
                s.pop(); // Remove the last non-'+' character
            }
        } else {
            s.push(ch); // Push only non-'+' characters
        }
    }

    // Construct the final string from stack
    string result;
    while (!s.empty()) {
        result = s.top() + result; 
        s.pop();
    }

    return result;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string output = processString(input);
    cout << "Processed String: " << output << endl;

    return 0;
}
