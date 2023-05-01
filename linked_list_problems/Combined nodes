SLL<int> combineNodes(SLL<int> llst){
    SLL<int> result;
    auto p = llst.getHead();
    int sum = 0;

    while (p != NULL) {
        if (p->data == 0) {
            if (sum > 0) {
                result.insertAtTail(sum);
                sum = 0;
            }
        } else {
            sum += p->data;
        }
        p = p->next;
    }

    if (sum > 0) {
        result.insertAtTail(sum);
    }

    return result;
}
