#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
 public:
  void dfs(TreeNode *root, vector<string> &rst, string path) {
    if (!root) return;
    path += to_string(root->val);
    if ((!root->left) && (!root->right)) {
      rst.push_back(path);
      return;
    }
    path += "->";
    dfs(root->left, rst, path);
    dfs(root->right, rst, path);
  }
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> rst;
    string path;
    dfs(root, rst, path);
    return rst;
  }
};
void create_tree(TreeNode *root) {
  // root->val = 1;
  // TreeNode m(2);
  // TreeNode n(5);
  // TreeNode p(3);
  // root->left = &m;
  // TreeNode *a = root->left;
  // a->right = &n;
  // root->right = &p;
  // cout << root->val << (root->left)->val << (root->left)->right->val
  //      << (root->right)->val;
}
int main() {
  Solution sol;
  TreeNode root;
  root.val = 1;
  TreeNode m(2);
  TreeNode n(5);
  TreeNode p(3);
  root.left = &m;
  TreeNode *a = root.left;
  a->right = &n;
  root.right = &p;
  // create_tree(&root);
  // cout << root.val << (root.left)->val;
  vector<string> rst;
  rst = sol.binaryTreePaths(&root);
  for (string m : rst) {
    cout << m << endl;
  }
}