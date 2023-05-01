#include <iostream>
#include <queue>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int a) : val(a), next(NULL) {}
};

struct CompareNodes{
    bool operator()(const ListNode* x, const ListNode* y) {
        return x->val > y->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, CompareNodes> pq;

    // Push the first node of each list onto the priority queue
    for (ListNode* list : lists) {
        if (list != NULL) {
            pq.push(list);
        }
    }

    ListNode dummy(0);
    ListNode* tail = &dummy;

    // Pop the smallest node from the priority queue and append it to the merged list
    while (!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();
        tail->next = node;
        tail = node;

        // Push the next node of the merged list onto the priority queue
        if (node->next != NULL) {
            pq.push(node->next);
        }
    }

    return dummy.next;
}
int main() {
    // Create three linked lists
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);

    // Store the head nodes of the linked lists in a vector
    vector<ListNode*> lists = {list1, list2, list3};

    // Merge the linked lists and print the result
    ListNode* merged = mergeKLists(lists);

    while (merged != NULL) {
        cout << merged->val << " ";
        merged = merged->next;
    }
    cout << endl;
    return 0;
}
