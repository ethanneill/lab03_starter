// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE
// Omar Sanchez
// Ethan Neil
// February 1 2022
 
#include "intlist.h"
 
#include <iostream>
using std::cout;
 
 
// copy constructor
IntList::IntList(const IntList& source) {
   
 
}
 
// destructor deletes all nodes
IntList::~IntList() {
    Node* p = first;
    while(p != nullptr) {
        Node* n = p->next;
        delete p;
        p = n;
    }
}
 
 
// return sum of values in list
int IntList::sum() const {
    int add = 0;
    Node* p = first;

    while(p){
        add += p->info;
        p = p->next;
    }
    return add;
}
 
// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node *p = new Node;
    p = first;
 
    while (p)
    {
        if (p->info == value) {return true;}
        p = p->next;
    }
   
   
    return false; // REPLACE THIS NON-SOLUTION
}
 
//how to test for empty lists??
 
// returns maximum value in list, or 0 if empty list
int IntList::max() const {
 
    if (first == 0) { // empty list
        return 0;
    }
    else {
        Node *p = new Node;
        p = first;
        p->info = first->info;
 
        Node *max = new Node;
        max->info = first->info;
 
        while(p != nullptr) {
            if (max->info<p->info) {
                max->info = p->info;
            }
            p = p->next;
        }
 
        return max->info;
    }
}
 
// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    double s = sum();
    double c = count();
    double avg = s/c;
    return avg;
}
 
// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
   
    if (first == 0) { // empty list
        Node* p = new Node;
        p->info = value;
 
        first = p;
    }
    else {
        Node* p = new Node;
        p->info = value;
 
        if (first == nullptr) {
            first = p;
        }
 
        p->next = first;
        first = p;
    }
}
 
//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
    return *this;
}
 
 
 
// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)
 
// constructor sets up empty list
IntList::IntList() : first(0) { }
 
 
// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}
 
// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}
 
// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
 

