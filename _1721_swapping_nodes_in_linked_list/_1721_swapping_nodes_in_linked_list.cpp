#include <iostream>
#include <chrono>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Inserts n value at the end of the linked list
void appendNode(ListNode **node, int n)
{
    ListNode *newNode = new ListNode(n);
    // newNode = (ListNode *)malloc(sizeof(ListNode));
    // newNode->val = n;
    // newNode->next = NULL;

    if (*node == NULL)
    {
        *node = newNode;
        return;
    }

    ListNode *last = *node;
    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
}

void displayList(ListNode *head)
{
    std::cout<< "\n\r\t";
    ListNode *temp = head;
    while(temp != NULL)
    {
        std::cout<< temp->val << " ";
        temp = temp->next;
    }
    std::cout <<"\n\r";
}

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        int size = countNodes(head);

        // check if k is outside size
        if (k > size)
            return head;

        // if kth node is same from both end
        if (2 * k - 1 == size)
            return head;

        
        // kth node from start 
        ListNode *fromStartPrev, *fromStart;
        fromStart = head;
        for(int i = 1; i < k; i++)
        {
            fromStartPrev = fromStart;
            fromStart = fromStart->next;
        }
    }

private:
    int countNodes(ListNode *head)
    {
        int i = 0;

        ListNode *temp = head;
        while (temp != NULL)
        {
            i++;
            temp = temp->next;
        }
        return i;
    }
};

int main()
{

    ListNode *head = new ListNode(1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    displayList(head);

    //Need to swap kth element from front and back. 
    // indexed using 1;
    int k = 2;

    // Start measuring time
    auto begin = std::chrono::high_resolution_clock::now();
    Solution solve;

    ListNode *ans = solve.swapNodes(head, k);

    // Stop measuring time and calculate the elapsed time
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    std::cout << "Time measured " << (elapsed.count() * 1e-6) << " milliseconds.\n";

    std::cout << "Answer :";
    displayList(ans);

    return 0;
}