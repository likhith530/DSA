#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * Delete (struct Node * root , int key)
{
    if(root == NULL) return NULL;
    else
    {
        if(key < root->data)    
            root->left = Delete(root->left , key);
        else if(key > root->data)
            root->right = Delete(root->right,key);
        else //Three cases now 
        {
            // No child
            if(root->left == NULL && root->right == NULL)
            {
                free(root);
                root = NULL;
            }
            // 1 child -> (right child is present)
            else if (root->left == NULL)
            {
                struct Node* temp = root;
                root = root->right;
                free(temp);
            }
            // 1 child -> (left child is present)     
            else if (root->right == NULL)
            {   
                struct Node* temp = root;
                root = root->left;
                free(temp);
            }
            // 2 Child
            else
            {
                
            }
        }
    }
}
