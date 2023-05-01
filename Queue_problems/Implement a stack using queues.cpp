#include <iostream>
#include <list>
using namespace std;
template<class T>
class queue {
private:
    list<T> lst;
    int sz;
public:
    queue() {};
    void clear() {
        lst.clear();
        sz = 0;
    }
    int queueSize() {
        sz =0;
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
            cout<<endl;
        }

    }
 };

template<class T>
void push(queue<T>& q1, queue<T>& q2, const T& item) {
    // Move all elements from q1 to q2
    while (!q1.isEmpty()) {
        q2.enqueue(q1.first());
        q1.dequeue();
    }

    // Enqueue the new item to q1
    q1.enqueue(item);

    // Move all elements back to q1 from q2
    while (!q2.isEmpty()) {
        q1.enqueue(q2.first());
        q2.dequeue();
    }
}

template<class T>
T pop(queue<T>& q1) {
    if (q1.isEmpty()) {
        cout<<"Stack is empty";
    }

    T item = q1.first();
    q1.dequeue();
    return item;
}


int main() {
    queue<int> q1, q2;

    push(q1, q2, 1);
    push(q1, q2, 2);
    push(q1, q2, 3);

    cout << pop(q1) << endl; // Output: 3
    cout << pop(q1) << endl; // Output: 2
    cout << pop(q1) << endl; // Output: 1

    return 0;
}
