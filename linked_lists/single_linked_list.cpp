//single_linked_list
#include <bits/stdc++.h>

using namespace std;

template<typename T>

class Node {
public:
    T data;
    Node<T> *next;

    Node() {
        this->next = nullptr;
    }
};

template<typename T>
class SLL {
private:
    Node<T> *head;
public:
    SLL() { this->head = nullptr; }

    void insertAtHead(T element) {
        auto *newNode = new Node<T>();
        newNode->data = element;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(T element) {
        auto *newNode = new Node<T>();
        newNode->data = element;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        auto *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAt(T element, int index) {
        if (index > linkedListSize() || index < 0) {
            return;
        }
        if (index == 0) {
            insertAtHead(element);
            return;
        }
        if (index == linkedListSize()) {
            insertAtTail(element);
            return;
        }
        auto *newNode = new Node<T>();
        newNode->data = element;
        auto *temp = head;
        int count = 0;
        while (count < index) {
            if (count == index - 1) {
                if (temp->next != nullptr) {
                    newNode->next = temp->next;
                }
                temp->next = newNode;
                break;
            }
            temp = temp->next;
            count++;
        }
    }

    void removeAtHead() {
        if (head == nullptr)return;
        auto *temp = head;
        head = head->next;
        delete temp;
    }

    void removeAtTail() {
        if (head == nullptr)return;
        auto *temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        auto *lastNode = temp->next;
        temp->next = nullptr;
        delete lastNode;
    }

    void removeAt(int index) {
        if (head == nullptr)return;
        if (index > linkedListSize() || index < 0) {
            return;
        }
        if (index == 0) {
            removeAtHead();
            return;
        }
        auto *temp = head;
        int count = 0;
        while (count < index) {
            if (count == index - 1) {
                auto *node = temp->next;
                temp->next = temp->next->next;
                delete node;
                break;
            }
            count++;
            temp = temp->next;
        }
    }

    T retrieveAt(int index) {
        if (head == nullptr) {
            return -9999;
        }
        if (index >= linkedListSize() || index < 0) {
            return -9999;
        }
        if (index == 0) {
            return head->data;
        }
        auto *temp = head;
        int count = 0;
        while (temp != nullptr) {
            if (count == index) {
                return temp->data;
            }
            count++;
            temp = temp->next;
        }
    }

    void replaceAt(T newElement, int index) {
        if (index > linkedListSize() || index < 0) {
            return;
        }
        auto *newNode = new Node<T>();
        newNode->data = newElement;
        auto *temp = head;
        int count = 0;
        while (temp != nullptr) {
            if (count == index) {
                temp->data = newElement;
                break;
            }
            temp = temp->next;
            count++;
        }
    }

    bool isExist(T element) {
        auto *temp = head;
        while (temp != nullptr) {
            if (temp->data == element) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool isItemAtEqual(T element, int index) {
        if (head == nullptr)return false;
        if (index >= linkedListSize() || index < 0) {
            return false;
        }
        auto *temp = head;
        int count = 0;
        while (temp != nullptr) {
            if (count == index) {
                if (temp->data == element)return true;
            }
            temp = temp->next;
            count++;
        }
        return false;
    }

    void swap(int firstItemIdx, int secondItemIdx) {// swap two nodes without swapping data.
        if (firstItemIdx == secondItemIdx)return;
        Node<T> *node1 = nullptr, *node2 = nullptr, *prev1 = nullptr, *prev2 = nullptr;
        int count = 0;
        auto *curr = head;
        while (curr != nullptr) {
            if (count == firstItemIdx) {
                node1 = curr;
            } else if (count == secondItemIdx) {
                node2 = curr;
            }

            if (node1 == nullptr) {
                prev1 = curr;
            } else if (node2 == nullptr) {
                prev2 = curr;
            }

            if (node1 != nullptr && node2 != nullptr)break;

            curr = curr->next;
            count++;
        }

        if (node1 == nullptr || node2 == nullptr) {
            return;
        }

        if (prev1 == nullptr) {
            //el head elly hya el node al awla ha5aleha tshawer 3ala el node el tanya
            head = node2;
        } else {
            prev1->next = node2;
        }

        if (prev2 == nullptr) {
            head = node1;
        } else {
            prev2->next = node1;
        }

        Node<T> *temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;

    }

    bool isEmpty() {
        if (head == nullptr)return true;
        else return false;
    }

    int linkedListSize() {
        auto *temp = head;
        int len = 0;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    void clear() {
        auto *temp = head;
        while (temp != nullptr) {
            auto *node = temp;
            temp = temp->next;
            delete node;
        }
        head = nullptr;//to indicates that the list now empty
    }

    void print() {
        auto *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SLL<int> linkedList;
    linkedList.insertAtHead(3);
    linkedList.insertAtHead(2);
    linkedList.insertAtHead(1);
    linkedList.insertAtTail(4);
    linkedList.insertAt(0, 0);
    linkedList.insertAt(5, 1);
    linkedList.removeAtHead();
    linkedList.removeAtTail();
    linkedList.removeAt(2);
    linkedList.replaceAt(7, 1);
    linkedList.print();
    cout << (linkedList.isExist(7) ? "True" : "false") << endl;
    cout << (linkedList.isItemAtEqual(3, 2) ? "True" : "false") << endl;
    linkedList.swap(0, 2);
    cout << (linkedList.isEmpty() ?"True" : "false")<< endl;
    linkedList.print();
    linkedList.clear();
    linkedList.print();
//    cout << linkedList.retrieveAt(2);
    return 0;
}

