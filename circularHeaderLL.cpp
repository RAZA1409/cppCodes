#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int v = 0) : data(v), next(nullptr) {}
};

class CircularList {
private:
    Node* header;
public:
    CircularList() {
        header = new Node();
        header->next = header; // empty circular
    }

    // insert at end
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        Node* temp = header;
        while (temp->next != header) temp = temp->next;
        temp->next = newNode;
        newNode->next = header;
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
        while (temp != header && temp->data != afterVal) temp = temp->next;
        if (temp == header) {
            cout << "insertAfter: node " << afterVal << " not found\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // delete first data node
    void deleteBegin() {
        if (header->next == header) {
            cout << "deleteBegin: list is empty\n";
            return;
        }
        Node* first = header->next;
        if (first->next == header) { // only one data node
            header->next = header;
            delete first;
            return;
        }
        header->next = first->next;
        delete first;
    }

    // delete last data node
    void deleteEnd() {
        if (header->next == header) {
            cout << "deleteEnd: list is empty\n";
            return;
        }
        Node* prev = header;
        Node* cur = header->next;
        while (cur->next != header) {
            prev = cur;
            cur = cur->next;
        }
        // cur is last data node
        prev->next = header;
        delete cur;
    }

    // delete node by value
    void deleteNode(int val) {
        if (header->next == header) {
            cout << "deleteNode: list is empty\n";
            return;
        }
        Node* prev = header;
        Node* cur = header->next;
        while (cur != header && cur->data != val) {
            prev = cur;
            cur = cur->next;
        }
        if (cur == header) {
            cout << "deleteNode: value " << val << " not found\n";
            return;
        }
        prev->next = cur->next;
        delete cur;
    }

    void display() {
        if (header->next == header) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = header->next;
        cout << "Circular Linked List: ";
        while (temp != header) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "(back to header)\n";
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
    CircularList clist;
    
    clist.insertEnd(10);
    clist.insertEnd(20);
    clist.insertEnd(30);
    cout << "Initial circular list:\n"; clist.display();

    clist.insertBegin(5);
    cout << "After insertBegin(5):\n"; clist.display();

    clist.insertAfter(10,15);
    cout << "After insertAfter(10,15):\n"; clist.display();

    clist.deleteBegin();
    cout << "After deleteBegin():\n"; clist.display(); 
    
    clist.deleteEnd();
    cout << "After deleteEnd():\n"; clist.display();

    clist.deleteNode(20);
    cout << "After deleteNode(20):\n"; clist.display();

    cout << "\nNow freeing memory manually...\n";
    clist.freeList();

    return 0;
}
