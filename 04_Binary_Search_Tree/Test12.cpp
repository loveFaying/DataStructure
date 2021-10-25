#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_inOrder {

public:
    // Classic Non-Recursive algorithm for inorder traversal
    // Time Complexity: O(n), n is the node number in the tree
    // Space Complexity: O(h), h is the height of the tree
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> res;
        if( root == NULL )
            return res;

        stack<TreeNode*> stack;
        TreeNode* cur = root;
        while(cur != NULL || !stack.empty()){

            while(cur != NULL){
                stack.push(cur);
                cur = cur->left;
            }

            cur = stack.top();
            stack.pop();
            res.push_back(cur->val);
            cur = cur->right;

        }
        return res;
    }

    // Another Classic Non-Recursive algorithm for inorder traversal
    // Time Complexity: O(n), n is the node number in the tree
    // Space Complexity: O(h), h is the height of the tree
    vector<int> inorderTraversal2(TreeNode* root) {

        vector<int> res;
        if( root == NULL )
            return res;

        stack<TreeNode*> stack;
        TreeNode* cur = root;
        while(cur != NULL || !stack.empty()){

            if(cur != NULL){
                stack.push(cur);
                cur = cur->left;
            }
            else {
                cur = stack.top();
                stack.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
 
};

void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    print_vec(Solution_inOrder().inorderTraversal(root));
    print_vec(Solution_inOrder().inorderTraversal2(root));
    return 0;
}


