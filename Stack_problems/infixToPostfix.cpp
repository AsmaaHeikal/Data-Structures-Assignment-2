#include <bits/stdc++.h>

using namespace std;

template<class T>
class Stack {
private:
    vector<T> stck;
    int sz = 0;

public:

    void push(T item) {
        stck.push_back(item);
    }

    T top() {
        return stck.back();
    }

    T pop() {
        T el;
        if (stck.size() > 0) {
            el = stck.back();
            stck.pop_back();
            sz--;
            return el;
        } else cout << "Cannot pop since the stack is empty" << endl;
        return -1;
    }

    int stackSize() {
        sz = 0;
        for (auto i: stck) {
            sz++;
        }
        return sz;
    }

    bool isEmpty() {
        if (stck.empty()) {
            return true;
        } else return false;
    }


    void print() {
        if (stck.empty()) {
            cout << "Stack is empty" << endl;
        } else {
            for (auto i: stck) {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    void clear() {

        if (!stck.empty()) {
            for (auto i: stck) {
                stck.pop_back();
            }
            sz = 0;
        } else cout << "The stack is already empty";

    }
};

int precedence(char c) {
    if (c == '^')return 3;
    else if (c == '/' || c == '*')return 2;
    else if (c == '+' || c == '-')return 1;
    else return -1;
}

void infixToPostfix(string &exp) {
    exp.erase(remove_if(exp.begin(), exp.end(), ::isspace), exp.end());
    Stack<char> s;
    string answer;
    for (char i: exp) {
        char c = i;
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            answer += c;
        } else if (c == '(')s.push('(');
        else if (c == ')') {
            while (s.top() != '(') {
                answer += s.top();
                s.pop();
            }
            s.pop();
        } else {
            while (!s.isEmpty() && precedence(i) <= precedence(s.top())) {
                answer += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        answer += s.top();
        s.pop();
    }
    cout << answer << endl;
}

int main() {
    string s = "(A + B) * (C + D)";
    infixToPostfix(s);
}
