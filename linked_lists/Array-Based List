#include <iostream>
#include <array>

using namespace std;

template<class T>
class list {
private:
    T *arr;
    int sz{};
    int maxSize{};
    



public:
    list() {}
    
    list(int size) : sz(0) {
        maxSize = size;
    }

    ~list() { delete[] arr; }

    void insert(T ele) {
        if (sz == maxSize) cout << "The list is full\nNo more elements can be added" << endl;
        else {
            if (sz < maxSize) {

                arr[sz] = ele;
                sz++;
            } else cout << "list is full\nConnot add element";
        }
    }

    void insertAt(T ele, int index) {
        if (sz == maxSize) cout << "The list is full\nNo more elements can be added" << endl;
        else {
            for (int i = sz; i > index; i--) {
                arr[i] = arr[i - 1];
            }
            arr[index] = ele;
            sz++;
        }
    }

    T retriveAt(int index) {
        if(sz==0)cout<<"List is empty"<<endl;
        else {
            return arr[index];
        }
    }

    void removeAt(int index) {
        if(sz==0)cout<<"List is empty"<<endl;
        else {
            if (index == sz - 1) {
                arr[index] = 0;
                sz--;
            } else {
                for (int i = index; i < sz; i++) {
                    arr[i] = arr[i + 1];
                }
                sz--;
            }
        }
    }

    void replaceAt(T newElement, int index) {

        if (sz == 0)cout << "List is empty" << endl;
        else {
            arr[index] = newElement;
        }
    }

    bool isItemAtEqual(T element, int index) {
        if (arr[index] == element) return true;
        else return false;
    }

    bool isEmpty() {
        if (sz == 0) return true;
        else return false;
    }

    bool isFull() {
        if (sz == maxSize) return true;
        else return false;
    }

    int listSize() {
        return sz;
    }

    int maxListSize() {
        return maxSize;
    }

    void clear() {
        sz = 0;
        for (int i = 0; i < sz; i++) {
            arr[i] = 0;
            sz--;
        }
    }

    void print() {
        if (sz == 0) cout << "List is empty" << endl;
        else {
            for (int i = 0; i < sz; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }


    
};

int main() {

  


}
