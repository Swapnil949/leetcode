#include <iostream>
#include <chrono>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void append(int x);
    void display();
};

void ListNode::append(int x)
{
    ListNode *newNode = new ListNode(x);

    // if this is the first node in list
    if (this == NULL)
    {
        // this = newNode;
        newNode = this;
        return;
    }

    // find the last node
    ListNode *last = this;
    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
}

void ListNode::display()
{
    if (this == NULL)
    {
        std::cout << "Empty Node " << std::endl;
    }
    std::cout << std::endl << "\t";
    ListNode *temp = this;
    while (temp != NULL)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    { 
        // edge cases of null lists
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        
        // Get the header for answer
        ListNode *ptr = list1;
        if (list1->val > list2->val)
        {
            ptr = list2;
            list2 = list2->next;
        }
        else 
        {
            list1 = list1->next;
        }

        ListNode *curr = ptr;

        while (list1 != NULL & list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                curr->next = list1;
                list1 = list1->next;
            }
            else 
            {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        if(list1 != NULL)
            curr->next = list1;
        else
            curr->next = list2;

        return ptr;
    }
};

int main()
{
    ListNode list1(1);
    list1.append(2);
    list1.append(4);

    ListNode list2(1);
    list2.append(3);
    list2.append(4);

    // Start measuring time
    auto begin = std::chrono::high_resolution_clock::now();
    Solution solve;
    ListNode *ans = solve.mergeTwoLists(&list1, &list2);

    // Stop measuring time and calculate the elapsed time
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    std::cout << std::endl;
    ans->display();

    std::cout << "Time measured " << (elapsed.count() * 1e-6) << " milliseconds.\n";
    return 0;
}