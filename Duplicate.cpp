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

void print_linked_list(Node* &head, vector<int>* v)
{   int coutIndx = 0;
    Node* tmp = head;
    while(tmp != NULL)
    {
        cout << tmp->val << " "; 
        if(tmp->val == tmp->next->val){
            cout << " found index " << coutIndx << endl;
            v->push_back(coutIndx);
        }
        tmp = tmp->next;
        coutIndx++;
    }
}

void sort_linked_list(Node* head)
{
    for(Node* i = head;i->next != NULL;i = i->next)
    {
        for(Node* j = i->next;j != NULL;j = j->next)
        {
            if(i->val > j->val)
            {
                swap(i->val,j->val);
            }
        }
    }
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    vector<int> v;

    int val;
    while(true)
    {
        cin >> val;
        if(val == -1)
        {
            break;
        }
        insert_at_tail(head,tail,val);
    }

    sort_linked_list(head);
    print_linked_list(head, &v);

    for (int x : v) {
        cout << x << " ";
    }
    

    return 0;
}