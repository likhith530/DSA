#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int val;
    struct Node* next;
};
int hash(int key)
{
    return key%10;
}

void SortedInsert(struct Node**H, int key)
{
    struct Node* new = (struct Node *)malloc(sizeof(struct Node));
    new->val = key;
    new->next = NULL;
    struct Node*p = *H; //Starting at head of this node
    struct Node*q = NULL; //Tailing pointer to p
    if(*H==NULL)
        *H = new;
    else
    {
    while(p!=NULL && p->val < key)
    {
        q=p;
        p=p->next;
    }
    //It ends when x > q->val and x < p->val -->Need to insert b/w p and q 
    //Or It ends when p becomes NULL -> when only one index is present (i.e Only H)
    if(p==*H) //Fist node to H
    {
        new ->next = *H;
        *H = new;
    }
    else{
        new->next = p;
        q->next = new;
    }
    }
}

struct Node* Search(struct Node *p, int key)
{
    while(p!=NULL)
    {
        if(p->val == key)
            return p;
        p = p->next;
    }
    return NULL;
}
void Insert(struct Node *H[], int key)
{
    int index = hash(key);
    SortedInsert(&H[index],key); //We have to insert at this node , so passing this by reference
}
int main()
{
    struct Node *HT[10];
    struct Node *search_node;
    for(int i=0;i<10;i++)
        HT[i]=NULL;
    Insert(HT,12);
    Insert(HT,22);
    Insert(HT,32);
    Insert(HT,11);
    //search_node = Search(HT[hash(key)] , key);
    search_node = Search(HT[hash(11)] , 11);
    printf("The Node value is %d " , search_node->val);
    return 0;
}