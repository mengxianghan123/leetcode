// 哈希表法
#include <iostream>
#include <unordered_set>
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
    unordered_set<ListNode *> visited;
    while (head) {
      if (!visited.count(head)) {
        visited.insert(head);
        head = head->next;
      }
			else break;
    }
		return head;
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
