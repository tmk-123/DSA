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

    Node* temp = head; // Node tạm thời để không thay đổi head
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
} 

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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

    printList(head);
}