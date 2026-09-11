#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *curr = head;
    ListNode *prev = nullptr;

    while (curr != nullptr) {
      // save the forward link before it gets overwritten
      ListNode *next = curr->next;
      // reverse curr's link to point back at the previous node
      curr->next = prev;
      // advance both pointers for the next iteration
      prev = curr;
      curr = next;
    }
    // prev now holds the last node processed, i.e. the new head
    return prev;
  }
};

ListNode *buildList(const int arr[], int n) {
  ListNode dummy;
  ListNode *tail = &dummy;
  for (int i = 0; i < n; i++) {
    tail->next = new ListNode(arr[i]);
    tail = tail->next;
  }
  return dummy.next;
}

void printList(ListNode *head) {
  while (head != nullptr) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "nullptr" << endl;
}

int main() {
  Solution sol;

  int arr[] = {1, 2, 3, 4, 5};
  ListNode *head = buildList(arr, 5);

  ListNode *reversed = sol.reverseList(head);
  printList(reversed);

  return 0;
}
