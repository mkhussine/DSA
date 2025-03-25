// we will implemnt LinkedList without tail node and length variable
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data){}
};
 

class Linkedlist {
private:
    Node *head;
public:
    void print();
    void add_number();
    Node* get_tail();
};
