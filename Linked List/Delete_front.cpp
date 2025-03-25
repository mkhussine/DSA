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
    int improved_search(int number);
    ~LinkedList() {
        for(Node* current = head; current; current = current -> next){
            Node*temp = current;
            current = current-> next;
            delete temp;
            --length;
        }
    };

    void insert_front(int number);
    void delete_front();

};
    void LinkedList::delete_front(){
        if(!head)
            return;        
        else {
            Node* temp = head;
            head = head->next;
            delete temp;
            --length;
        }

    };

    void LinkedList::insert_front(int number){
        Node* temp = new Node(number);
        if(!head) {
            head = tail = temp;
            ++length;
        }    
        
        else {
            temp -> next = head;
            head = temp;
            ++length;
        }

    };


void LinkedList::Print() {
    for (Node* itr = head; itr; itr = itr->next)
        cout << itr->data << " ";
    cout << endl;
}


int main() {
    // lets use/test our LinkedList
    LinkedList list;
    list.insert_front(9);
    list.insert_front(8);
    list.insert_front(7);
    list.insert_front(6);
    list.Print();

    list.delete_front();
    list.Print();

    list.delete_front();
    list.delete_front();
    list.Print();

    return 0;
}
