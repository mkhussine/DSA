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

    bool is_same(LinkedList first, LinkedList second);

    bool Is_Same(LinkedList first, LinkedList second);


};
    // here we will use length variable
    bool LinkedList::is_same(LinkedList first, LinkedList second) {
        if(first.length != second.length)
            return 0;
        else {
            Node* current2 = second.head;
            for(Node* current = first.head; current; current = current ->next,current2 ->next) 
                if (current->data != current2->data)
                return 0;
            return true;
        }
    }


    // here we will not use length variable
    bool LinkedList::Is_Same(LinkedList first, LinkedList second) {
        if(!first.head && !second.head)
            return true;       

        else if(!first.head && second.head  || first.head && !second.head)
            return 0;

        else {
            Node* current2 = second.head;
            for(Node* current = first.head; current; current = current ->next,current2 ->next){ 
                if(!current && current2  || current && !current2 || current->data != current2->data)
                    return 0;
                }
            return true;
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
    
    cout<<list.Is_Same(list,list)<<endl;


    return 0;
}
