#include <iostream>
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
    
    // implementing a destructur
    ~LinkedList() {
        for(Node* current = head; current; current = current -> next){
            Node*temp = current;
            current = current-> next;
            delete temp;
            --length;
        }
    };
};


int main() {
    


    return 0;
}
