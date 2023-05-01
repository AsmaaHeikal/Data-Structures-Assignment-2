//
// Created by Salma on 30/03/2023.
//
#include <iostream>
#include <list>
using namespace std;

template<class T>
class Queue {
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

