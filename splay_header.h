#include<iostream>
using namespace std;
class TreeNode
{
    public: 
        int data;  
        TreeNode* left;
        TreeNode* right;
};
class SplayTree
{
    public:
        TreeNode* insert(TreeNode *root,int d);
        TreeNode* search(TreeNode *root,int d);
        TreeNode* deleteNode(TreeNode *root,int d);
        TreeNode* findMax(TreeNode *root); 
        TreeNode* findMin(TreeNode *root); 
        void inorder(TreeNode *root); 
        void preorder(TreeNode *root); 
        void postorder(TreeNode *root); 
        TreeNode* splay(TreeNode *root,int d);
        TreeNode* leftRotate(TreeNode *k2);
        TreeNode* rightRotate(TreeNode *k2);
};