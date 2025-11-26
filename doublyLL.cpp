#include <iostream>
using namespace std;

class Node {
public:
    Node* prev;
    int data;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) { 
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Insert after a given data
    void insertAfter(int prevData, int newData) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr && temp->data != prevData)
            temp = temp->next;
        if (temp == nullptr) {
            cout << "Node with data " << prevData << " not found." << endl;
            return;
        }
        Node* newNode = new Node(newData);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr)
            temp->next->prev = newNode;
        else
            tail = newNode; 
        temp->next = newNode;
    }

    // Delete from the beginning
    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr; 
        delete temp;
    }
    // Delete at the end
    void deleteAtEnd() {
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr)
            tail->next = nullptr;  
        else
            head = nullptr;         
        delete temp;
    }

    // Delete node with matching data value
    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        Node* curr = head;
        while (curr != nullptr && curr->data != value) {
            curr = curr->next;
        }
        if (curr == nullptr) { 
            cout << "Value " << value << " not found in list.\n";
            return;
        }
        // If node to delete is head
        if (curr == head) {
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
            else
                tail = nullptr;
            delete curr;
            cout << "Deleted value " << value << " from the list.\n";
            return;
        }
        // If node to delete is tail
        if (curr == tail) {
            tail = tail->prev;
            if (tail != nullptr)
                tail->next = nullptr;
            else
                head = nullptr;
            delete curr;
            cout << "Deleted value " << value << " from the list.\n";
            return;
        }
        // Node is in the middle
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        cout << "Deleted value " << value << " from the list.\n";
    }


    // Print in forward direction
    void printForward() {
        Node* temp = head;
        cout << "Forward: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Print in backward direction
    void printBackward() {
        Node* temp = tail;
        cout << "Backward: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

    // Manual function to free memory
    void freeList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr; 
        cout << "Memory freed successfully." << endl;
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    list.printForward();
    list.printBackward();

    list.insertAtBeginning(5);

    list.printForward();
    list.printBackward();

    list.insertAfter(30,50);

    list.printForward();
    list.printBackward();

    list.deleteAtBeginning();
    
    list.printForward();
    list.printBackward();

    list.deleteAtEnd();
    
    list.printForward();
    list.printBackward();

    list.deleteByValue(20);

    list.printForward();
    list.printBackward();

    list.freeList();

    return 0;
}
