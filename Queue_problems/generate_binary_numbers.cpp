#include <bits/stdc++.h>

using namespace std;

template<class T>
class Queue {
private:
    list<T> lst;
    int sz;
public:
    Queue() {};


    void clear() {
        lst.clear();
        sz = 0;
    }

    int queueSize() {
        sz = 0;
        for (auto i: lst) {
            sz++;
        }
        return sz;
    }

    bool isEmpty() const {
        if (lst.empty()) return true;
        else return false;
    }

    T &first() {
        return lst.front();
    }

    T dequeue() {
        T element = lst.front();
        lst.pop_front();
        return element;
        sz--;
    }

    void enqueue(const T &element) {
        lst.push_back(element);
    }

    void print() {
        if (lst.empty()) {
            cout << "The Queue is empty";
        } else {
            for (auto i: lst) {
                cout << i << " ";
            }
            cout << endl;
        }

    }
};

void BinaryNumbers(int n) {
    Queue<string> q;
    q.enqueue("1");
    while (n--) {
        string str1 = q.first();
        q.dequeue();
        cout << str1 << endl;
        string str2 = str1;
        q.enqueue(str1.append("0"));
        q.enqueue(str2.append("1"));
    }
}

int main() {
    BinaryNumbers(5);
}


