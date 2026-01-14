#include<bits/stdc++.h>
using namespace std;

class Node {
    public:

    int val ;
    Node * next ;

    Node (int x){
        val = x;
        next = NULL;
    }
};


Node *  reverse(Node * head ){
    if(head == nullptr) return nullptr ;

    Node* prevptr = NULL;
    Node* currptr = head;
    
    while (currptr){
        Node * nextptr = currptr -> next;
        currptr -> next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;
}





int main(){


    return 0;
}