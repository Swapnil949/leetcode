
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
void append(ListNode **node, int n)
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

class Solution
{
public:
	ListNode *swapPairs(ListNode *head)
	{
		if (head == NULL || head->next == NULL)
			return head;

		ListNode *newHead = head->next;

		head->next = swapPairs(newHead->next);
		newHead->next = head;

		return newHead;

	}
};

int main()
{

    ListNode *head =  new ListNode(1);
	append(&head, 2);
	append(&head, 3);
	append(&head, 4);


	// Start measuring time
	auto begin = std::chrono::high_resolution_clock::now();
	Solution solve;

	solve.swapPairs(head);

	// Stop measuring time and calculate the elapsed time
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	std::cout << "Time measured " << (elapsed.count() * 1e-6) << " milliseconds.\n";
    return 0;
}