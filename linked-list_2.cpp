#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void insertAtTail(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void replace(Node*& head, int a, int b) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == a) {
            temp->data = b;
        }
        temp = temp->next;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main() {
    Node* head = nullptr;
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertAtTail(head, value);
    }

    int a, b;
    cin >> a >> b;
    replace(head, a, b);
    printList(head);
    return 0;
}