#include <iostream>
#include <vector>
#include <string>
#include <ctime> 

using namespace std;

// 二分搜索树   key-value的模板类型 Key-Value
template <typename Key, typename Value>
class BST{

private:
    // 树中的节点为私有的结构体, 外界不需要了解二分搜索树节点的具体实现
    struct Node{
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }
    };

    Node *root; // 根节点
    int count;  // 树中的节点个数

public:
    // 构造函数, 默认构造一棵空二分搜索树
    BST(){
        root = NULL;
        count = 0;
    }
    ~BST(){
        // TODO: ~BST()
    }

    // 返回二分搜索树的节点个数
    int size(){
        return count;
    }

    // 返回二分搜索树是否为空
    bool isEmpty(){
        return count == 0;
    }

    // 向二分搜索树中插入一个新的(key, value)数据对
    void insert(Key key, Value value){
        root = insert(root, key, value);
    }

    // 查看二分搜索树中是否存在键key
    bool contain(Key key){
        return contain(root, key);
    }

    // 在二分搜索树中搜索键key所对应的值。如果这个值不存在, 则返回NULL
    Value* search(Key key){
        return search( root , key );
    }

private:
    // 向以node为根的二分搜索树中, 插入节点(key, value), 使用递归算法
    // 返回插入新节点后的二分搜索树的根
    Node* insert(Node *node, Key key, Value value){

        if( node == NULL ){
            count ++;
            return new Node(key, value);
        }

        if( key == node->key )
            node->value = value;
        else if( key < node->key )
            node->left = insert( node->left , key, value);
        else    // key > node->key
            node->right = insert( node->right, key, value);

        return node;
    }

    // 查看以node为根的二分搜索树中是否包含键值为key的节点, 使用递归算法
    bool contain(Node* node, Key key){

        if( node == NULL )
            return false;

        if( key == node->key )
            return true;
        else if( key < node->key )
            return contain( node->left , key );
        else // key > node->key
            return contain( node->right , key );
    }

    // 在以node为根的二分搜索树中查找key所对应的value, 递归算法
    // 若value不存在, 则返回NULL
    Value* search(Node* node, Key key){

        if( node == NULL )
            return NULL;

        if( key == node->key )
            return &(node->value);
        else if( key < node->key )
            return search( node->left , key );
        else // key > node->key
            return search( node->right, key );
    }
};

int main(){

    string wordArray[]={"hello","world","hello","hello","world","hello","xyz","csl","edg","rng"};
    int length = sizeof(wordArray)/sizeof(string); // 10
    vector<string> words(wordArray, wordArray+length);

    BST<string, int> bst = BST<string, int>();
    for( vector<string>::iterator iter = words.begin() ; iter != words.end() ; iter++ ){
        int* res = bst.search(*iter);
        if(res == NULL)
            bst.insert(*iter, 1);
        else
            (*res)++;
    }

    string searchString = "rng";
    if( bst.contain(searchString) )
        cout << searchString << " : " << *bst.search(searchString) << endl;
    else
        cout << "No " << searchString << endl;
    return 0;
}
