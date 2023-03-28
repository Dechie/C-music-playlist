#ifndef LINK_H
#define LINK_H
#include <iostream>

using namespace std;


struct node {
  
  char song[30];
  char artist[30];

  struct node * next;
};

class LinkedList {

  public:
    node *head;
    char listName[30];
    int len;
    bool taken;

    LinkedList()
    {
      len = 0;
      head = nullptr;
      taken = false;
    }
    
    void add_beg(char song[30], char artist[30]);
    void add_end(char song[30], char artist[30]);
    void add_at(char song[30], char artist[30], int pos);
    void del_beg();
    void del_end();
    void del_at(int pos);
    void display();
};

struct stackNode {
  node* item;

  stackNode* next;
};


class Stack{
  public:
  stackNode* topPtr = new stackNode;
  bool isEmpty();
  void push(node *item);
  void top();
  node* pop();
  node* stackTop;
};

#endif
