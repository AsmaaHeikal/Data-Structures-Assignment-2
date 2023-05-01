#include <iostream>
#include <vector>

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
        
    }

    int stackSize() {
        sz =0;
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

