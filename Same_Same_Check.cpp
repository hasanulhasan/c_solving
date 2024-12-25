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

int size_of_list(Node* &head){
    int x = 0;
    Node* temp = head;
    while (temp != NULL)
    {
        x++;
        temp = temp->next;
    }
    return x;
}

bool checkSimilarVal(Node* &head_1, Node* &head_2){
    Node* temp_1 = head_1;
    Node* temp_2 = head_2;
    while (temp_1 != NULL)
    {   
        if(temp_1->val == temp_2->val){
            temp_1 = temp_1->next;
            temp_2 = temp_2->next;
        }else{
            return false;
        }
    }
    return true;
}

int main()
{
    Node* head_1 = NULL;
    Node* tail_1 = NULL;
    Node* head_2 = NULL;
    Node* tail_2 = NULL;

    int val_1;
    while(true)
    {
        cin >> val_1;
        if(val_1 == -1)
        {
            break;
        }
        insert_at_tail(head_1,tail_1,val_1);
    }
    int val_2;
    while(true)
    {
        cin >> val_2;
        if(val_2 == -1)
        {
            break;
        }
        insert_at_tail(head_2,tail_2,val_2);
    }

    int sz_1 = size_of_list(head_1);
    int sz_2 = size_of_list(head_2);

    if(sz_1 != sz_2){
        cout << "NO" << endl;
    }else{
        if(checkSimilarVal(head_1, head_2)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}