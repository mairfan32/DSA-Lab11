
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

// Create a min heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

Node* mergeLists(Node* lists[], int k) {
    priority_queue<Node*, vector<Node*>, Compare> heap;

    // Insert first node of each list
    for (int i = 0; i < k; i++) {
        if (lists[i] != NULL)
            heap.push(lists[i]);
    }

    Node dummy(0);
    Node* tail = &dummy;

    while (!heap.empty()) {
        // Get smallest node
        Node* temp = heap.top();
        heap.pop();

        // Insert next node into heap
        if (temp->next != NULL)
            heap.push(temp->next);

        // Add smallest node to merged list
        tail->next = temp;
        tail = temp;
    }

    tail->next = NULL;

    return dummy.next;
}

// Print linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    // First sorted list
    Node* l1 = new Node(1);
    l1->next = new Node(4);
    l1->next->next = new Node(7);

    // Second sorted list
    Node* l2 = new Node(2);
    l2->next = new Node(5);
    l2->next->next = new Node(8);

    // Third sorted list
    Node* l3 = new Node(3);
    l3->next = new Node(6);
    l3->next->next = new Node(9);

    Node* lists[] = {l1, l2, l3};

    Node* result = mergeLists(lists, 3);

    cout << "Merged List: ";
    printList(result);

    return 0;
}
