/*
Problem Statement 

Given the head of a singly linked lsit, retun true if it is a plaindrome or false otherwise.

Input: head = [1, 2, 2, 1]
Output: true

*/



#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedListPalindrome {
public:
    Node* head = NULL;
    Node* tail = NULL;

    // Add node to linked list
    void addNode(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Reverse a linked list
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Check if list is palindrome
    bool isPalindrome(Node* head) {
        if (!head || !head->next) return true;

        // Step 1: Find middle
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        Node* secondHalf = reverse(slow);
        Node* firstHalf = head;

        // Step 3: Compare halves
        while (secondHalf) {
            if (firstHalf->data != secondHalf->data) {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }
};

int main() {
    LinkedListPalindrome list;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        list.addNode(x);
    }

    if (list.isPalindrome(list.head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
