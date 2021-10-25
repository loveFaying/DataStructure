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

class Solution_postOrder {

private:
    struct TagNode{
        TreeNode* node;
        bool isFirst;
        TagNode(TreeNode* node): node(node), isFirst(false){}
    };

public:
    // Non-Recursive
    // Using a tag to record whether the node has been visited
    //
    // Time Complexity: O(n), n is the node number in the tree
    // Space Complexity: O(h), h is the height of the tree
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> res;
        if(root == NULL)
            return res;

        stack<TagNode> stack;
        TreeNode* cur = root;
        while(cur != NULL || !stack.empty()){

            while(cur != NULL){
                stack.push(TagNode(cur));
                cur = cur->left;
            }

            TagNode tagNode = stack.top();
            stack.pop();
            cur = tagNode.node;
            if(tagNode.isFirst == false){
                tagNode.isFirst = true;
                stack.push(tagNode);
                cur = cur->right;
            }
            else{
                res.push_back(cur->val);
                cur = NULL;
            };
        }
        return res;
    }

    // Non-Recursive
    // Using two stacks
    //
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    vector<int> postorderTraversal2(TreeNode* root) {

        vector<int> res;
        if(root == NULL)
            return res;

        stack<TreeNode*> stack, output;

        stack.push(root);
        while(!stack.empty()){

            TreeNode* node = stack.top();
            stack.pop();
            output.push(node);

            if(node->left != NULL)
                stack.push(node->left);
            if(node->right != NULL)
                stack.push(node->right);
        }

        while(!output.empty()){
            res.push_back((output.top())->val);
            output.pop();
        }

        return res;
    }

    // Non-Recursive
    // Using two stacks, Reverse Preorder Traversal!
    //
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    vector<int> postorderTraversal3(TreeNode* root) {

        vector<int> res;
        if(root == NULL)
            return res;

        stack<TreeNode*> stack, output;

        TreeNode* p = root;
        while(p != NULL || !stack.empty()){
            if(p != NULL){
                stack.push(p);
                output.push(p);
                p = p->right;
            }
            else{
                p = stack.top();
                stack.pop();
                p = p->left;
            }
        }

        while(!output.empty()){
            res.push_back((output.top())->val);
            output.pop();
        }

        return res;
    }

    // Non-Recursive
    // Using a pre pointer to record the last visited node
    //
    // Time Complexity: O(n)
    // Space Complexity: O(h)
    vector<int> postorderTraversal4(TreeNode* root) {

        vector<int> res;
        if(root == NULL)
            return res;

        stack<TreeNode*> stack;
        TreeNode* pre = NULL;

        stack.push(root);
        while(!stack.empty()){

            TreeNode* node = stack.top();
            stack.pop();
            if((node->left == NULL && node->right == NULL) ||
               (pre != NULL && pre == node->left && node->right == NULL) ||
               (pre != NULL && pre == node->right)){
                res.push_back(node->val);
                pre = node;
            }
            else{
                stack.push(node);

                if(node->right != NULL)
                    stack.push(node->right);
                if(node->left != NULL)
                    stack.push(node->left);
            }
        }

        return res;
    }

    // Classic Non-Recursive
    // Using a pre pointer to record the last visted node
    //
    // Time Complexity: O(n)
    // Space Complexity: O(h)
    vector<int> postorderTraversal5(TreeNode* root) {

        vector<int> res;
        if(root == NULL)
            return res;

        stack<TreeNode*> stack;
        TreeNode* pre = NULL;
        TreeNode* cur = root;

        while(cur != NULL || !stack.empty()){

            while(cur != NULL){
                stack.push(cur);
                cur = cur->left;
            }

            cur = stack.top();
            stack.pop();

            if(cur->right == NULL || pre == cur->right){
                res.push_back(cur->val);
                pre = cur;
                cur = NULL;
            }
            else{
                stack.push(cur);
                cur = cur->right;
            }
        }

        return res;
    }

    // Classic Non-Recursive
    // Using a pre pointer to record the last visted node
    //
    // Time Complexity: O(n)
    // Space Complexity: O(h)
    vector<int> postorderTraversal6(TreeNode* root) {

        vector<int> res;
        if(root == NULL)
            return res;

        stack<TreeNode*> stack;
        TreeNode* pre = NULL;
        TreeNode* cur = root;

        while(cur != NULL || !stack.empty()){
            if(cur != NULL){
                stack.push(cur);
                cur = cur->left;
            }
            else{
                cur = stack.top();
                stack.pop();

                if(cur->right == NULL || pre == cur->right){
                    res.push_back(cur->val);
                    pre = cur;
                    cur = NULL;
                }
                else{
                    stack.push(cur);
                    cur = cur->right;
                }
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
    print_vec(Solution_postOrder().postorderTraversal(root));
    print_vec(Solution_postOrder().postorderTraversal2(root));
    print_vec(Solution_postOrder().postorderTraversal3(root));
    print_vec(Solution_postOrder().postorderTraversal4(root));
    print_vec(Solution_postOrder().postorderTraversal5(root));
    print_vec(Solution_postOrder().postorderTraversal6(root));
    return 0;
}

