//mentoring 2. 10/30
//연결리스트의 삽입과 삭제

#include <iostream>
#include<stdlib.h>
#include <string>
using namespace std;

typedef struct node {
    string data;
    node* next;
    node* prev;
}node;

void printNode(node* n) {
    node* cur = n;
    cur = cur->next;
    while (cur) {
        cout << cur->data;
        cur = cur->next;
    }
    cout << "\n\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    node* head = new node;
    head->data = "start";
    head->prev = head->next = NULL;
    node* cur = head;

    string t;
    cin >> t;
    for(int i=0; i<t.length(); i++){
        node* newnode = new node;
        newnode->data = t[i];
        newnode->prev = cur;
        newnode->next = NULL;
        cur->next = newnode;
        cur = newnode;
    }

    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        switch (c) {
        case 'L': {
            if (cur->prev) cur = cur->prev;
            break;
        }
        case 'D': {
            if (cur->next)
                cur = cur->next;
            break;
        }
        case 'B': {
            if (cur->prev == NULL)
                continue;
            node* del = new node;
            del = cur;
            cur = del->prev;
            if (del->next) {
                cur->next = del->next;
                del->next->prev = cur;
                del->prev = NULL;
            }
            else { cur->next = NULL; }
            delete(del);
            break;
        }
        case 'P': {
            string add;
            cin>>add;
            node* newnode = new node;
            newnode->data = add;
            newnode->prev = cur;
            if (cur->next) {
                newnode->next = cur->next;
                cur->next->prev = newnode;
            }
            else {
                newnode->next = NULL;
            }
            cur->next = newnode;
            cur = cur->next;
            break;
        }
        }
    }
    printNode(head);
}
