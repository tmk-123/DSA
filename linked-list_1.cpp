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

int getElementAt(Node* head, int k) {
    Node* temp = head;
    int index = 0;
    while (temp != nullptr) {
        if (index == k) {
            return temp->data;
        }
        temp = temp->next;
        index++;
    }
    return -1;
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

    int k;
    cin >> k;
    cout << getElementAt(head, k);

    return 0;
}