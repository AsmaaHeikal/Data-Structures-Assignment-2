#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node<T> *next;
    Node<T> *prev;

    explicit Node(T data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

template<typename T>
class DLL {
private:
    Node<T> *head;
    int size;
public:
    DLL() {
        head = nullptr;
        size = 0;
    }

    void insertAtHead(T element) {
        auto *newNode = new Node<T>(element);
        if (head == nullptr) {
            head = newNode;
            size++;
            return;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        size++;
    }

    void insertAtTail(T element) {
        auto *newNode = new Node<T>(element);
        if (head == nullptr) {
            head = newNode;
            size++;
            return;
        }
        auto temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        size++;
    }

    void insertAt(T element, int index) {
        auto *newNode = new Node<T>(element);
        if (index > size || index < 0)return;
        if (index == 0) {
            insertAtHead(element);
            return;
        } else if (index == size) {
            insertAtTail(element);
            return;
        }
        auto *temp = head;
        int count = 0;
        while (temp != nullptr) {
            if (count == index - 1) {
                break;
            }
            count++;
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        if (newNode->next != nullptr) {
            newNode->next->prev = newNode;
        }
        size++;
    }

    void insertAfter(Node<T> *prev_node, T data) {
        auto *newNode = new Node<T>(data);
        auto *temp = head;
        while (temp != prev_node) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (newNode->next != nullptr) {
            newNode->next->prev = newNode;
        }
        temp->next = newNode;
        size++;
    }

    void removeAtHead() {
        if (head != nullptr) {
            auto *temp = head;
            head = head->next;
            delete temp;
            head->prev = nullptr;
            size--;
        }
    }

    void removeAtTail() {
        if (head->next == nullptr) {
            head = nullptr;
        } else {
            auto *temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            Node<T> *last = temp->next;
            temp->next = nullptr;
            delete last;
        }
        size--;
    }

    void removeAt(int index) {
        if (index > size || index < 0)return;
        if (index == 0) {
            removeAtHead();
            return;
        } else if (index == size - 1) {
            removeAtTail();
            return;
        }
        if (head == nullptr)return;
        auto *temp = head;
        int count = 0;
        while (temp != nullptr && count < index) {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr)return;
        temp->prev->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        delete temp;
        size--;
    }

    T retrieveAt(int index) {
        if (head == nullptr) {
            return -9999;
        }
        if (index >= size || index < 0) {
            return -9999;
        }
        if (index == 0) {
            return head->data;
        }
        auto *temp = head;
        int count = 0;
        while (temp->next != nullptr) {
            if (count == index) {
                return temp->data;
            }
            count++;
            temp = temp->next;
        }
    }

    void replaceAt(T newElement, int index) {
        if (index > size || index < 0) {
            return;
        }
        auto *newNode = new Node<T>(newElement);
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
        if (index >= size || index < 0) {
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
        if (firstItemIdx >= size || firstItemIdx < 0) {
            return;
        }
        if (secondItemIdx >= size || secondItemIdx < 0) {
            return;
        }
        if (firstItemIdx == secondItemIdx) {
            return;
        }
        if (firstItemIdx > secondItemIdx) {
            swap(firstItemIdx, secondItemIdx);
        }
        Node<T> *node1 = head;
        for (int i = 0; i < firstItemIdx && node1 != nullptr; i++) {
            node1 = node1->next;
        }
        Node<T> *node2 = node1;
        for (int i = firstItemIdx; i < secondItemIdx && node2 != nullptr; i++) {
            node2 = node2->next;
        }
        if (node1->next == node2) {//law el etnen wara ba3d
            node1->next = node2->next;
            if (node2->next != nullptr) {
                node2->next->prev = node1;
            }
            node2->next = node1;
            node1->prev = node2;
            node2->prev = node1->prev;
            if (node1 == head) {//by5aly el head yshawer 3ala el node elly tel3et odam
                head = node2;
            }
        } else {
            Node<T> *temp = node1->next;
            node1->next = node2->next;
            node2->next = temp;
            if (node1->next != nullptr) {//da ba3d ma na2altohom ya3ny ka2n node1 ba2t node2 wl 3aks
                node1->next->prev = node1;
            }
            if (node2->next != nullptr) {
                node2->next->prev = node2;
            }
            temp = node1->prev;
            node1->prev = node2->prev;
            node2->prev = temp;
            if (node1->prev != nullptr) {
                node1->prev->next = node1;
            }
            if (node2->prev != nullptr) {
                node2->prev->next = node2;
            }
            if (node1 == head) {
                head = node2;
            }
        }
    }

    void reverse() { //reverse the data in the double linked list
        if (size <= 1)return;
        Node<T> *temp = nullptr;
        auto *curr = head;
        while (curr != nullptr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            curr = curr->prev; //da elly kan zaman curr=curr->next bas e7na 8ayrnah
        }
        head = temp->prev;
    }

    bool isEmpty() {
        if (size == 0)return true;
        else return false;
    }

    int doubleLinkedListSize() {
        return size;
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

    void forwardTraversal() {//Print from head to tail
        auto *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void backwardTraversal() { //Print from tail to head
        if (head == nullptr)return;
        auto *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        while (temp != nullptr) {
            cout << temp->data << ' ';
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DLL<int> list;
    list.insertAtHead(5);
    list.insertAtHead(4);
    list.insertAtHead(3);
    list.insertAtHead(2);
    list.insertAtHead(1);
    list.insertAtTail(6);
//    list.swap(1, 3);
    list.insertAt(10, 4);
//    list.reverse();
//    list.removeAtHead();
//    list.removeAt(2);
//    list.replaceAt(1000, 0);
//    list.replaceAt(900, 5);
//    list.replaceAt(1000, 2);
//    cout << list.retrieveAt(2);
//    list.forwardTraversal();
//    cout << list.isItemAtEqual(3, 2) << endl;
//    cout << list.isExist(3);
//    cout << list.isEmpty();
//    cout << list.doubleLinkedListSize();
//    list.clear();
    list.forwardTraversal();
    return 0;
}
