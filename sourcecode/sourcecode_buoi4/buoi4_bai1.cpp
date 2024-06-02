#include <iostream>
using namespace std;
struct Node {
int data;
Node* next;
Node(int data) {
this->data = data;
next = NULL;
}
};
// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
 if(head == NULL) return null;
 Node node {data, head};
 return node;
}
// print the list content on a line
void print(Node* head) {
    Node *tmp = head;
if(head == NULL) return;
while(tmp!=NULL){
    cout<<tmp->data<<" ";
    tmp = tmp->next;
}
}

// return the new head of the reversed list
Node* reverse(Node* head) {
 if(head == NULL) return h;
 Node *p1 = NULL, *p2 = head, *p3 = head->next;
 while(p2!=NULL){
    p2->next = p1;
    p1 = p2;
    p2 = p3;
    if(p3!=NULL) p3 = p3->next;
    return p1;
 }
}
int main() {
int n, u;
cin >> n;
Node* head = NULL;
for (int i = 0; i < n; ++i){
cin >> u;
head = prepend(head, u);
}
cout << "Original list: ";
print(head);
head = reverse(head);
cout << "Reversed list: ";
print(head);
return 0;
}

