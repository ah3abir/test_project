#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* next;
};

Node* pushFront(Node* head, int key) {
    Node* newNode = new Node();
    newNode -> key = key;
    newNode -> next = head;
    head = newNode;

    return head;
}

Node* popFront(Node* head) {
    Node* temp = head;
    head = head -> next;
    delete temp;

    return head;
}

Node* pushBack(Node* head, int key) {
    Node* newNode = new Node();
    newNode -> key = key;
    newNode -> next = NULL;

    if(head == NULL) {
        head = newNode;
    }
    else {
        Node* cur = head;
        while(cur -> next != NULL) {
            cur = cur -> next;
        }
        cur -> next = newNode;
    }
    return head;
}

Node* popBack(Node* head) {
    Node* cur = head;

    while(cur -> next -> next != NULL) {
        cur = cur -> next;
    }
    Node* temp = cur -> next;
    cur -> next = NULL;
    delete temp;
    return head;
}

Node* findKey(Node* head, int search_key) {
    Node* cur = head;
    while(cur != NULL) {
        if(cur -> key == search_key){
            return cur;
        }
        cur = cur -> next;
    }
    return NULL;
}

Node* eraseKey(Node* head, int key) {
    Node* cur = head;
    Node* foundNode = findKey(head, key);
    if(foundNode != NULL) {
        if(head == foundNode) {
            head = head -> next;
        }
        else {
            while(cur -> next != foundNode) {
                cur = cur -> next;
            }
            Node* tempNode = cur;
            tempNode -> next = foundNode-> next;
        }
        delete foundNode;
    }
    else {
        cout << "Key not found" << endl;
    }
    return head;
}

void addAfter(Node* prevNode, int add_value) {

    Node* newNode = new Node();
    newNode -> key = add_value;

    if(prevNode != NULL) {
        newNode -> next = prevNode -> next;
        prevNode -> next = newNode;
    }
    else {
        cout << "key not found" << endl;
    }
}

Node* addBefore(Node* head, Node* nextNode, int add_value) {

    Node* newNode = new Node();
    newNode -> key = add_value;
    Node* cur = head;

    if(nextNode != NULL) {
        if(nextNode == head) {
            newNode -> next = head;
            head = newNode;
        }
        else {
            while(cur -> next != nextNode) {
                cur = cur -> next;
            }
            newNode -> next = nextNode;
            cur -> next = newNode;
        }
    }
    else {
        cout << "key not found" << endl;
    }
    return head;
}

void printList (Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        cout << cur -> key << " ";
        cur = cur -> next;
    }cout << endl;
}

void implementTestcase() {
    cout << "\n\tTestcase Starts" << endl;
    Node* head = NULL;
    cout << "Enter Direction: ";
    string s;
    while (cin >> s) {
        if(s == "0") {
            delete head;
            break;
        }
        else if (s == "psb" || s == "1") {
            cout << "Enter push back count: ";
            int n; cin >> n;
            cout << "Enter numbers: ";
            while (n--) {
                int temp; cin >> temp;
               head = pushBack(head, temp);
            }
            printList(head);
        }
        else if (s == "psf" || s == "2") {
            cout << "Enter push front count: ";
            int n; cin >> n;
            cout << "Enter numbers: ";
            while (n--) {
                int temp; cin >> temp;
               head = pushFront(head, temp);
            }
            printList(head);
        }
        else if (s == "ppb" || s == "3") {
            if (head == NULL) {
                cout << "NO element found" << endl;
            }
            else {
                head = popBack(head);
                printList(head);
            }
        }
        else if (s == "ppf" || s == "4") {
            if (head == NULL) {
                cout << "NO element found" << endl;
            }
            else {
                head = popFront(head);
                printList(head);
            }
        }
        else if (s == "find" || s == "5") {
            cout << "Enter a search key: ";
            int temp; cin >> temp;
            Node* isFound = findKey(head, temp);
            if (isFound != NULL) {
                cout << "Enter delete(dlt/6)/addBefore(addBft/7)/addAfter(addAftr/8): ";
                string ss; cin >> ss;
                if(ss == "dlt" || ss == "6") {
                    head = eraseKey(head, temp);
                    printList(head);
                }
                else if(ss == "addBft" || ss == "7") {
                    cout << "Enter number to Add Before: ";
                    int i; cin >> i;
                    head = addBefore(head, isFound, i);
                    printList(head);
                }
                else if(ss == "addAftr" || ss == "8") {
                    cout << "Enter number to Add After: ";
                    int i; cin >> i;
                    addAfter(isFound, i);
                    printList(head);
                }
                else {
                    cout << "Invalid Search Direction" << endl;
                }
            }
            else {
                cout << "NOT matched" << endl;
            }
        }
        else {
            cout << "Invalid Direction" << endl;
        }
    cout << "Enter Direction: ";
    }
}

int main() {
    cout << "Enter testcase: ";
    int T; cin >> T;
    while (T--) {
        implementTestcase();
    }
}
