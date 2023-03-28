#include "link.h"
#include "audio.h"
#include <cstring>
#include <iostream>
#include <unistd.h>

using namespace std;

string doubletab = "\t\t";

void LinkedList::add_beg(char song[30], char artist[30]) {
    
    node *temp = new node;

    strcpy(temp->song, song);
    strcpy(temp->artist, artist);

    temp->next = head;
    head = temp;

    len++;

}

void LinkedList::add_end(char song[30], char artist[30]) {
    node *temp = new node;
    node *hold = new node;
     
    strcpy(hold->song, song);
    strcpy(hold->artist, artist);

    if (head == nullptr) {
        head = hold;
        hold->next = head;
    }

    else {
        temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = hold;
        hold->next = head;
    }

    len++;
}

void LinkedList::add_at(char song[30], char artist[30], int pos) {
    node *temp = new node;
    node *follow = new node;
    node *hold = new node;

    strcpy(hold->song, song);
    strcpy(hold->artist, artist);

    temp = head;

    for (int i = 0; i < pos - 1; ++i) {
        follow = temp;
        temp = temp->next;
    }

    follow->next = hold;
    hold->next = temp;

    len++;
}

void LinkedList::del_beg() {

    node *temp = new node;                                                               
                                                                                          
    temp = head;                                                                        
                                                                                          
    head = temp->next;                                                                  
                                                                                          
    delete temp;

    len--;                                                                        
}                                                                                        
                                                                                          
void LinkedList::del_at(int pos) {
    node *temp = new node;
    node *follow = new node;

    temp = head;

    for (int i = 0; i < pos -1 ; ++i) {                                                  
        follow = temp;                                                                   
        temp = temp->next;   
    }                                                                                    
                                                                                          
     follow->next = temp->next;                                                           
                                                                                          
     delete temp;

     len--;                                                                         
}                                                                                        

void LinkedList::del_end() {                                                             
     
    node * temp = new node;
    node * follow = new node;

    temp = head;

    if (temp->next == temp)
    {
        delete temp;
    }

    while(temp->next != head)
    {
        follow = temp;
        temp = temp->next;
    }

    follow->next = temp->next;
    head = follow->next;

    delete temp;

    len--;                                                                         
} 

void LinkedList::display() {

    node *temp = head;
    
    cout<< "\t\t\t" << listName << endl;
    if (head == nullptr)
        cout << endl
             << doubletab << "\t\tno elements to show." << endl;

    else {
   
       for (int i = 0; i < len ; ++i) {

            cout << "\t\t" << temp->song << " -- " << temp->artist << endl;
            temp = temp->next;
        }

        cout << endl;
    }
}            


bool Stack::isEmpty() {
    return topPtr == NULL;
}

void Stack::push(node* item) {

    stackNode *newPtr = new stackNode;

    newPtr->item = item;

    newPtr->next = topPtr;
    topPtr = newPtr;
}

node* Stack::pop() {

    node *stackTop = new node;
    if (!isEmpty()) 
    {
      stackTop = topPtr->item;
      stackNode *temp = topPtr;
      topPtr = topPtr->next;

      temp->next = nullptr;
      delete temp;
    }

    return stackTop;
      
}
