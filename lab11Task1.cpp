
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Node {
    char data;
    int freq;
    Node* left;
    Node* right;

    Node(char d, int f) {
        data = d;
        freq = f;
        left = NULL;
        right = NULL;
    }
};

// Create a min heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Print Huffman codes using preorder
void printCodes(Node* root, string code) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        cout << root->data << ": " << code << endl;

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void huffman(string s, int freq[]) {
    priority_queue<Node*, vector<Node*>, Compare> heap;

    // Insert all characters into heap
    for (int i = 0; i < s.length(); i++) {
        heap.push(new Node(s[i], freq[i]));
    }

    // Build Huffman tree
    while (heap.size() > 1) {
        Node* left = heap.top();
        heap.pop();

        Node* right = heap.top();
        heap.pop();

        Node* parent = new Node('*', left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        heap.push(parent);
    }

    // Print codes from root
    printCodes(heap.top(), "");
}

int main() {
    string s = "abcdef";
    int freq[] = {5, 9, 12, 13, 16, 45};

    huffman(s, freq);

    return 0;
}
