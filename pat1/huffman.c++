
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code) {
    if (root == nullptr)
        return;

    if (root->left == nullptr && root->right == nullptr) {
        cout << root->ch << " : " << code << '\n';
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cin >> n;

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < n; i++) {
        char ch;
        int freq;
        cin >> ch >> freq;
        pq.push(new Node(ch, freq));
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$',
                                left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    printCodes(pq.top(), "");
    return 0;
}



// 2.Algorithm
// 1. Read the number of characters and their frequencies.
// 2. Insert each character into a min-priority queue based on frequency.
// 3. Remove the two nodes with the smallest frequencies.
// 4. Create a parent node with their combined frequency.
// 5. Make the two removed nodes its left and right children.
// 6. Insert the parent back into the priority queue.
// 7. Repeat until only one node remains; this is the Huffman tree's root.
// 8. Traverse the tree recursively:
//    - Left edge: append 0.
//    - Right edge: append 1.
//    - Leaf node: print the character and its code.


// 5. Pseudocode
// HUFFMAN(C):
//     Insert all characters into a min-priority queue Q

//     WHILE size(Q) > 1:
//         left = EXTRACT-MIN(Q)
//         right = EXTRACT-MIN(Q)

//         parent.frequency = left.frequency + right.frequency
//         parent.left = left
//         parent.right = right

//         INSERT(Q, parent)

//     PRINT-CODES(Q.root, "")

// PRINT-CODES(node, code):
//     IF node is a leaf:
//         PRINT node.character, code
//     ELSE:
//         PRINT-CODES(node.left, code + "0")
//         PRINT-CODES(node.right, code + "1")


// 6. Time and space complexity
// Let \(n\) be the number of distinct characters.
// - Time complexity: \(O(n\log n)\) — building the tree using the priority queue.
// - Space complexity: \(O(n)\) — storing the tree and priority queue.