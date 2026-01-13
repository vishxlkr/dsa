#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int val ; 
    Node* next;

    Node(int x){
        val = x;
        next = nullptr;
    }
};



bool findcycle ( Node * head ){
    Node * slow = head;
    Node * fast = head;

    while(fast and fast -> next){

       
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) return true;   // we are not writing this at top , because at the starting both will be same
    }

    return false;
}


int main(){

    

    return 0;
}