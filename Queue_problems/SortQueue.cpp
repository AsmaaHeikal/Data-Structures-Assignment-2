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


int minIndex(Queue<int> &q, int sortedIndex) {
    int min_index = -1;
    int min = INT_MAX;
    int n = q.queueSize();
    for (int i = 0; i < n; i++) {
        int curr = q.first();
        q.dequeue();
        if (curr <= min && i <= sortedIndex) {
            min_index = i;
            min = curr;
        }
        q.enqueue(curr);
    }
    return min_index;
}

void insertMinToEnd(Queue<int> &q, int min_index) {
    int min;
    int n = q.queueSize();
    for (int i = 0; i < n; i++) {
        int curr = q.first();
        q.dequeue();
        if (i != min_index)
            q.enqueue(curr);
        else min = curr;
    }
    q.enqueue(min);
}

void sortQueue(Queue<int> &q) {
    for (int i = 1; i <= q.queueSize(); i++) {
        int min_index = minIndex(q, q.queueSize() - i);
        insertMinToEnd(q, min_index);
    }
    q.print();
}


int main() {
    Queue<int> q;
    q.enqueue(4);
    q.enqueue(10);
    q.enqueue(0);
    q.enqueue(1);
    q.enqueue(500);
    q.enqueue(-1);
    q.enqueue(2);
    sortQueue(q);
}
