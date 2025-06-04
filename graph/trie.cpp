#include<bits/stdc++.h>
using namespace std;


class Node{
    public: 
    char data;
    bool terminal;
    unordered_map<char,Node*> children;

    Node(char data){
        this->data = data;
        terminal = false;
    }
    void makeTerminal(){
        this->terminal = false;
    } 
    bool isTerminal(){
        return this->terminal==true;
    }
};

class Trie {
    public: 

    Node* root;
    Trie(){
        root = new Node('\0');
    }

    void insert(string word){
        Node* curr = root;
        for(int i =0 ; i< word.size();i++){
            char ch = word[i];
            if(curr->children.count(ch)){
                curr = curr->children[ch];
            } else {
                Node* child = new Node(ch);
                curr->children[ch] = child;
                curr = child;
            }
        }
        curr->makeTerminal();
    }

};