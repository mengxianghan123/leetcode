// 快慢指针法
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        fast = head;
        break;
      }
    }
    if (!fast || !fast->next) return nullptr;
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }
    return fast;
  }
};

int main() {
  // 先构造循环链表
  vector<int> input = {3, 2, 0, -4};
  int pos = 1;
  ListNode *cur = nullptr;
  ListNode *head = nullptr;
  ListNode *p = nullptr;
  head = new ListNode(input.front());
  p = head;
  int idx = 1;
  if (pos == 0) cur = head;
  while (idx != input.size()) {
    p->next = new ListNode(input[idx]);
    p = p->next;
    if (idx == pos) {
      cur = p;
    }
    ++idx;
  }
  p->next = cur;

  // 这里开始检验算法的正确性
  Solution sol;
  ListNode *m = sol.detectCycle(head);
  cout << m->val << endl;
}
