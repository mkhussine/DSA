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
    
    Node* Get_nth_from_back(int number);

};

Node* LinkedList::Get_nth_from_back(int number){
    int new_number = length - number;
    if(new_number < 0)
        return NULL;
    else {
        for (Node* current = head; number <= 0; ++number,current = current->next){
            if (number == 0)
            return current;
        }
        return NULL;
    }

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
}


void LinkedList::Print() {
    for (Node* itr = head; itr; itr = itr->next)
        cout << itr->data << " ";
    cout << endl;
}


int main() {
    // lets use/test our LinkedList
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.Print();
    



    return 0;
}
