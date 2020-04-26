#include "Node.h"
using namespace std;

void printList(Node* h) {
    Node* p = h->next;
    while(p != NULL) {
        std::cout << p->key << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

void follow(Node* p, Node* q) {
    q->next=p->next;
    p->next=q;
}

void remNode(Node* h, Node* toRem) {
    Node* p = h->next->next;
    Node* prev = h->next;
    while(p != NULL) {
        if(prev->key == toRem->key && prev->next == toRem->next) {
            prev->key = p->key;
            prev->next = p->next;
        } else if(p->next == NULL) {
                prev->next = NULL;
        }
        p = p->next;
        prev = prev->next;
    }
}

Node* minNode(Node* h) {
    Node* p = h->next;
    int min = p->key;
    Node* minimum = new Node();
    while (p != NULL) {
        cout << p->key << " ";
        if (min > p->key) {
            min = p->key;
            minimum = p;
        }
        p = p->next;
    }
    cout << endl;
    //cout << minimum->key << endl;
    return minimum;
}

void minSelSort(Node* h) {
    Node* p = h->next;
    int min = p->key;
    while(p != NULL) {
        Node* minimum = minNode(p);
        Node* ujelem = new Node(minimum->key);
        remNode(h,minimum);
        follow(h,ujelem);
        p = p->next;
    }
}

int main() {
    Node* h = new Node();
    Node* n1 = new Node(74);
    Node* n2 = new Node(632);
    Node* n3 = new Node(6);
    Node* n4 = new Node(32);
    Node* n5 = new Node(3);
    Node* n6 = new Node(34);
    h->next=n1;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    Node* n7 = new Node(15);
    //printList(h);
    //minSelSort(h);
    //remNode(h,minNode(h));
    //remNode(h,minNode(h));
    //Node* head = new Node();
    //follow(head,new Node(minNode(h)->key));
    //follow(head,new Node(minNode(h)->key));
    //follow(head,harom);
    //printList(h);
    //minSelSort(h);
    //printList(h);
    Node* ujlista = new Node();
    //follow(ujlista, new Node(minNode(h)->key));
    remNode(h,minNode(h));
    //follow(ujlista, new Node(minNode(h)->key));
    remNode(h,minNode(h));
    //follow(ujlista, new Node(minNode(h)->key));
    remNode(h,minNode(h));
    //follow(ujlista, new Node(minNode(h)->key));
    remNode(h,minNode(h));
    remNode(h,minNode(h));
    remNode(h,minNode(h));
    remNode(h,minNode(h));

    //printList(h);
    //printList(ujlista);
    //printList(h);
    //cout << minNode(h) << endl;
}
