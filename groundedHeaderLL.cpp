#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val = 0) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* header;
public:
    LinkedList() {
         header = new Node(); 
    } // header node

    // insert at end
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        Node* temp = header;
        while (temp->next != nullptr) {
            temp = temp->next;
        }    
        temp->next = newNode;
    }

    // insert at beginning (after header)
    void insertBegin(int val) {
        Node* newNode = new Node(val);
        newNode->next = header->next;
        header->next = newNode;
    }

    // insert after a node with data == afterVal
    void insertAfter(int afterVal, int val) {
        Node* temp = header->next;
        while (temp != nullptr && temp->data != afterVal) {
            temp = temp->next;
        }    
        if (temp == nullptr) {
            cout << "insertAfter: node " << afterVal << " not found\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // delete first data node
    void deleteBegin() {
        Node* first = header->next;
        if (first == nullptr) {
            cout << "deleteBegin: list is empty\n";
            return;
        }
        header->next = first->next;
        delete first;
    }

    // delete last data node
    void deleteEnd() {
        Node* prev = header;
        Node* cur = header->next;
        if (cur == nullptr) {
            cout << "deleteEnd: list is empty\n";
            return;
        }
        // only one data node
        if (cur->next == nullptr) {
            header->next = nullptr;
            delete cur;
            return;
        }
        while (cur->next != nullptr) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = nullptr;
        delete cur;
    }

    // delete node by value
    void deleteNode(int val) {
        Node* temp = header;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }    
        if (temp->next == nullptr) {
            cout << "deleteNode: value " << val << " not found\n";
            return;
        }
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void display() {
        Node* temp = header->next;
        if (!temp) {
            cout << "List is empty\n";
            return;
        }
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Free all nodes manually
    void freeList() {
        Node* temp = header;
        while (temp != NULL) {
            Node* nextNode = temp->next;  // store next node
            delete temp;                  // free current node
            temp = nextNode;              // move to next
        }
        header = NULL;  // mark list as cleared
        cout << "All nodes deleted successfully.\n";
    }
};

int main() {
    LinkedList list;
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    cout << "Initial grounded list:\n"; list.display();           

    list.insertBegin(5);
    cout << "After insertBegin(5):\n"; list.display();           

    list.insertAfter(10, 15); 
    cout << "After insertAfter(10,15):\n"; list.display();         

    list.deleteBegin();
    cout << "After deleteBegin():\n"; list.display();             

    list.deleteEnd();
    cout << "After deleteEnd():\n"; list.display();             

    list.deleteNode(20);
    cout << "After deleteNode(20):\n"; list.display();         

    cout << "\nNow freeing memory manually...\n";
    list.freeList();

    return 0;
}
