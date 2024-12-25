#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtTail(Node*& head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAt(Node*& head, int k, int x) {
    Node* newNode = createNode(x);

    if (k == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }
    
    Node* temp = head;
    for (int i = 0; i < k - 1; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        temp->next = newNode;
    }
    else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
int main() {
    int n;
    cin >> n;

    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertAtTail(head, value);
    }

    int k, x;
    cin >> k >> x;  
    insertAt(head, k, x);
    printList(head);

    return 0;
}