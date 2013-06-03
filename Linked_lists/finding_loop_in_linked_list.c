#if 0
Link:
======
http://leetcode.com/2010/09/detecting-loop-in-singly-linked-list.html 

This elegant algorithm is known as Floyd’s cycle finding algorithm, 
also called the Tortoise and hare algorithm.

#endif

int hasLoop(Node *head) {
  Node *slow = head, *fast = head;
  while (slow && fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      return 1; // Loop is present
  }
  return 0; // Loop is not present
}
