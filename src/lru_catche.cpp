#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache{
    public:
    
    LRUCache(int capacity){
        assert(capacity>0 && capacity<=1000);
        cp = capacity;
        tail = NULL;
        head = NULL;
    }

    void set(int key, int value){
        assert(key>0 && key<=20);
        assert(value>0 && value<=2000);

        if(head == NULL && head == tail){
            Node *node = new Node(key, value);
            mp.insert(pair<int, Node*>(key,node));
            head = node;
            tail = node;
            return;
        }

        //if key not present
        auto it = mp.find(key);
        if(it == mp.end()){
            if(mp.size() == cp){
                //catche full
                Node *temp = tail;
                tail->prev->next = NULL;
                tail = temp->prev;
                mp.erase(temp->key);
                delete temp;
            }
            Node *node = new Node(NULL,head,key,value);
            mp.insert(pair<int, Node*>(key,node));
            head->prev = node;
            head = node;
        } else{

            Node *temp = it->second;
            temp->value = value;
            Node *prev = temp->prev;
            Node *next = temp->next;
            if(prev == NULL){
                //already head node. do not need to shift
                return;
            } else if(next == NULL){
                //if it is the tail node
                prev->next = NULL;
            } else {
                //it is in the middle. remove this from linked list
                prev->next = next;
                next->prev = prev;
            }
            //set this as head
            temp->prev = NULL;
            temp->next = head;
            head->prev = temp;
            head = temp;
        }

    }
    int get(int key){
        auto it = mp.find(key);
        if(it == mp.end()){
            return -1;
        } else{
            return it->second->value;
        }
    }

    void displayAll(){
        cout<<"Map iteration==========>"<<endl;
        
        for(auto it = mp.begin(); it!=mp.end(); it++)
            cout<<it->first<<"=>"<<it->second->value<<endl;

        cout<<"List iteration==========>"<<endl;
        Node *temp = head;
        while(temp!=NULL){
            cout<<temp->key<<"=>"<<temp->value<<endl;
            temp = temp->next;
        }
    }
};

void test(){
    int n, capacity,i;
    LRUCache *lp;
    ifstream infile("input01.txt");
    string line;
    bool firstLine = true;
    while (getline(infile, line))
    {
        std::istringstream iss(line);
        //int a, b;
        //if (!(iss >> a >> b)) { break; } // error

        if(firstLine){
            if (!(iss >> n >> capacity)) { break; }
            lp = new LRUCache(capacity);
            firstLine = false;
            continue;
        }

        string command;
        int key, value;

        iss >> command >> key >>value;

        cout<<command<<"====="<<key<<"======="<<value<<endl;
        if(command == "get") {
            cout << lp->get(key) << endl;
        } 
        else if(command == "set") {
            lp->set(key,value);
        }
        

        //cout<<line;

        // process pair (a,b)
    }

    lp->displayAll();
}

void run(){
    int n, capacity,i;
    cin >> n >> capacity;
    assert(n>0 && n<=500000);
    LRUCache l(capacity);
    for(i=0;i<n;i++) {
        string command;
        cin >> command;
        if(command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        } 
        else if(command == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key,value);
        }
        else if(command == "dis") {
            l.displayAll();
        }
    }

    l.displayAll();
}

int main() {
   test();
   //run();
   return 0;
}