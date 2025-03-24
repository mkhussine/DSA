#include <iostream>
#include <assert.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data){}
};

class LinkedList {
private:
    Node* head{};
    Node* tail{};
    int length = 0;

public:
    void Printing_LinkedList(Node* head);
    void printing(Node* head);
    void insert(int number);
    void Print();
    int get_n_th_item(int order);
    int search_by_index(int number);
};


//printing in an iterative approch
void LinkedList::Printing_LinkedList(Node* head) {
    Node* Temp_Head = head;
    while (Temp_Head) {
        cout << Temp_Head->data << " ";
        Temp_Head = Temp_Head->next;
    }
    cout << endl;
}

//printing in a Recursive approch
void LinkedList::printing(Node* head) {
    Node* Temp_Head = head;
    if (!Temp_Head) {
        cout << endl;
        return;
    }
    cout << Temp_Head->data << " ";
    printing(Temp_Head->next);
}

//another way of printing

void LinkedList::Print() {
    for (Node* itr = head; itr; itr = itr->next)
        cout << itr->data << " ";
    cout << endl;
}

void LinkedList::insert(int number) {
    Node* node = new Node(number);
    if (!head) {
        head = tail = node;
        ++length;
    }
    else {
         tail->next = node;
         tail = node;
         ++length;
    }
};

int LinkedList::get_n_th_item(int order) {
    int counter = 0;
    for (Node* temp = head; temp; temp = temp->next)
        if (++counter == order)
            return counter;
    return NULL;
}

int LinkedList::search_by_index(int number) {
    int index = 0;
    for (Node* temp = head; temp; temp = temp->next) {
        if (temp->data == number)
            return index;
        ++index;
    }
    return -1;
}

int main() {
    // lets use/test our LinkedList
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);
    Node* node4 = new Node(550);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = nullptr;

    cout << node1->data << "\n";
    cout << node1->next->data << "\n";
    cout << node1->next->next->data << "\n";
    cout << node1->next->next->next->data << "\n";
    
    cout << node2->next->next->data << "\n";
    cout << node3->data << "\n";


    cout << "\n\n\n";

    LinkedList list;
    list.insert(9);
    list.insert(4);
    list.insert(1);
    list.Print();
    return 0;
}
