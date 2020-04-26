#include "Node.h"
using namespace std;

void printList(Node h) {
    Node* p = h.next;
    while(p != NULL) {
        std::cout << p->key << " ";
        p = p->next;
    }
    std::cout << std::endl;
}
void insNodeAfterHead(Node &h, int toIns) {
    Node newNode;
    newNode.key = toIns;
    newNode.next = h.next;
    h.next = &newNode;
    printList(h);
}
void remNode(Node &h, Node* toRem) {
    Node* p = h.next;
    while(p != NULL) {
        if(p->key == toRem->key && p->next == toRem->next) {
            p->key = p->next->key;
            p->next = p->next->next;
        }
        p = p->next;
    }
}
void minSelSort(Node h) {
    Node* p = h.next;
    int min = p->key;
    while(p != NULL) {
        if(min > p->key) {
            min = p->key;
            remNode(h, p);
            insNodeAfterHead(h, min);
            printList(h);
        }
        printList(h);
        p = p->next;
    }
}
int main() {
    Node h(42069);
    Node n1(74);
    Node n2(632);
    Node n3(6);
    Node n4(32);
    Node n5(3);
    Node n6(34);

    h.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    minSelSort(h);
    printList(h);
}
