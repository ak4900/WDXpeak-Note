#include <iostream>
#include <math.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la = getLength(headA), lb = getLength(headB);
        int cnt = abs(la - lb);
        for (int i = 0; i < cnt; i++){
            if (la > lb)
                headA = headA->next;
            else
                headB = headB->next;
        }

        while(headA != NULL && headB != NULL){
            if (headA == headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }

    int getLength(ListNode *head){
        int length = 0;
        while (head != NULL){
            length++;
            head = head->next;
        }
        return length;
    }
};

int main()
{
    return 0;
}