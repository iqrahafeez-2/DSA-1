#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

bool isValidExpression(const string& expression) {
    stack<char> st;

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    ifstream file("expressions.txt");
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    vector<string> expressions;
    string line;

    while (getline(file, line)) {
        expressions.push_back(line);
    }

    file.close();

    if (expressions.size() < 10) {
        cout << "The file must contain at least 10 expressions." << endl;
        return 1;
    }

    cout << "Expressions available in the file:\n " << endl;
    for (int i = 0; i < expressions.size(); ++i) {
        cout << i + 1 << ": " << expressions[i] << endl;
    }

    int choice;
    cout << "\nEnter the line number to check the expression: ";
    cin >> choice;

    if (choice < 1 || choice > expressions.size()) {
        cout << "Invalid line number." << endl;
        return 1;
    }

    string selectedExpression = expressions[choice - 1];

    if (isValidExpression(selectedExpression)) {
        cout << "The expression is valid." << endl;
    }
    else {
        cout << "The expression is not valid." << endl;
    }

    return 0;
}
