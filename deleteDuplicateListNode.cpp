//
// Created by kezhiwei on 2020/7/6.
//

#include <stack>
#include <string>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

ListNode* deleteDuplication(ListNode* pHead)
{
    if(!pHead) return NULL;
    ListNode *pCur = pHead;
    ListNode *pPre = NULL;

    while(pCur)
    {
        if(pCur->next && pCur->val == pCur->next->val)
        {
            ListNode * pFirst = pCur;
            while(pCur->next && pCur->val == pCur->next->val )
            {
                ListNode *deleteNode = pCur;
                pCur = pCur->next;
                free(deleteNode);
            }

            if(pFirst == pHead) pHead = pCur->next;
            else{
                pPre->next = pCur->next;
            }
            ListNode *deleteNode = pCur;
            pCur = pCur->next;
            free(deleteNode);

        }
        else
        {
            pPre = pCur;
            pCur = pCur->next;
        }
    }
    return pHead;
}
int main()
{
    int a[] = {2,2,3,3,4,4,5};
    ListNode *pHead = new ListNode(a[0]);
    ListNode *pCur = pHead;
    for(int i = 1;i<sizeof(a)/sizeof(int);i++)
    {
        ListNode *pNode = new ListNode(a[i]);
        pCur->next = pNode;
        pCur = pNode;
    }
    pCur->next = NULL;

    pCur = pHead;
    while (pCur)
    {
        cout<<pCur->val<<endl;
        pCur = pCur->next;
    }
    pCur = deleteDuplication(pHead);
    cout<<"delete"<<endl;
    while (pCur)
    {
        cout<<pCur->val<<endl;
        pCur = pCur->next;
    }
}