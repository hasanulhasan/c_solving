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

int checkNumberInNode(Node* &head, int x){
    int countIndx = 0;
    Node* temp = head;
    while (temp != NULL)
    {
        if(temp->val == x){
            return countIndx;
        }
        countIndx++;
        temp = temp->next;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
            int searchVal;
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
            cin >> searchVal;
            int indx = checkNumberInNode(head, searchVal);
            cout << indx << endl;
    }
    
    return 0;
}