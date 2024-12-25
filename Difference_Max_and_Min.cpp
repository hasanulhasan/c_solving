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

int find_max_val(Node* head){   
    int x = 0;
    Node* tmp = head;
    while(tmp != NULL)
    {
        if(tmp->val > x){
            x = tmp->val;
        }
        tmp = tmp->next;
    }
    return x;
}

int find_min_val(Node* head){   
    int x = 100000000;
    Node* tmp = head;
    while(tmp != NULL)
    {
        if(tmp->val < x){
            x = tmp->val;
        }
        tmp = tmp->next;
    }
    return x;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

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

    int max = find_max_val(head);
    int min = find_min_val(head);
    int result = max - min;
    cout << result << endl;
    return 0;
}