#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node* next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail,int val)
{
    Node *newnode = new Node(val);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}
void insert_at_head(Node* &head, int val)
{
    Node* newnode = new Node(val);
    newnode->next = head;
    head = newnode;
}
void print_linked_list(Node* head)
{
    Node* tmp = head;
    while(tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}
void insert_at_tail(Node* &head, int val)
{
    Node *newnode = new Node(val);
    if(head == NULL)
    {
        head = newnode;
        return;
    }

    Node* tmp = head;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newnode;
}
void delete_at_head(Node* &head)
{
    Node* deleteNode = head;
    head = head->next;
    delete deleteNode;
}
void delete_at_any_pos(Node* head, int idx)
{
    Node* tmp = head;
    for(int i=1;i<idx;i++)
    {
        tmp = tmp->next;
    }
    Node* deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    delete deleteNode;
}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int flag, val;
        cin >> flag;
        cin >> val;
        if(flag == 0){
            insert_at_head(head, val);
            print_linked_list(head);
        }
        if(flag == 1){
            insert_at_tail(head, val);
            print_linked_list(head);
        }
        if(flag == 2){
            if(val == 0){
                delete_at_head(head);
                print_linked_list(head);
            }else{
                delete_at_any_pos(head, val);
                print_linked_list(head);
            }
        }
        cout << endl;
    }
    return 0;
}

// 0 -> Head
// 1 -> Tail
// 2 -> Delete ------> 0-> Head
//                     1,2,3 ..... -> Any postion
//                     eqal of size -> Tail