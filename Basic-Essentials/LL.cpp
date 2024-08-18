#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(): val(0) , next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution{
public:
    ListNode* reverseList(ListNode* head){
        ListNode* p = head, *q = nullptr, *r = nullptr;
        while(p){
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        return q;
    }
public:
    void printList(ListNode* node) {
        while (node != nullptr) {
            cout << " " << node->val;
            node = node->next;
        }
    }
};


// Driver code
int main() {

    // Create a hard-coded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution ob;

      // Print the original linked list
    cout << "Given Linked list:";
    ob.printList(head);


      // Function call to return the reversed list
    head = ob.reverseList(head);

    
      // Print the reversed linked list
    cout << "\nReversed Linked List:";
    ob.printList(head);

    return 0;
}