#include<bits/stdc++.h>
using namespace std;



class Stack{
    
    int * arr;
    int top ;
    int capacity;

    Stack(int c){
        this-> capacity = c;
        arr = new int[c];
        this->top = -1;
    }

    void push(int data){
        if(this->top == this->capacity-1){
            cout<<"overflow";
            return;
        }

        this->top++;
        this->arr[this->top] = data;
        return;
    }

    int size(){
        return this->top +1;
    }

    int pop(){
        if(this->top ==-1){
            cout<<"underflow"<<endl;
            return INT_MIN;
        }
        this->top--;
    }

    int top(){
        if(this->top ==-1){
            cout<<"underflow"<<endl;
            return INT_MIN;
        }

        return this->arr[this->top];
    }

    bool isEmpty(){
        return this->top==-1 ? true : false;
    }

    bool isFull(){
        return this->top == this->capacity-1 ?  true: false;
    }




};




int main(){

    

    return 0;
}