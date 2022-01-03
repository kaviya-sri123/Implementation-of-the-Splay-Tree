#include "splay_header.h"
TreeNode* SplayTree::insert(TreeNode *root,int d)
{
    TreeNode *temp = new TreeNode();
    temp->data=d;
    temp->left = NULL;
    temp->right = NULL;
    if(root==NULL)
    {
        root=temp;
        return root;
    }
    root = splay(root,d);
    if(d < root->data)
    {
        temp->left= root->left;
        temp->right = root;
        root->left = NULL;
        root = temp;
    }
    else if(d > root->data)
    {
        temp->right = root->right;
        temp->left = root;
        root->right = NULL;
        root = temp;
    }
    else
        return root;
}
TreeNode* SplayTree::splay(TreeNode *root,int d)
{
    if (!root)
        return NULL;
    TreeNode *head;
    head->left = head->right = NULL;
    TreeNode* L = head;
    TreeNode* R = head;
    while(true)
    {
        if(d < root->data)
        {
            if(root->left==NULL)
                break;
            if(d < root->left->data)
            {
                root = rightRotate(root);
                if(root->left==NULL)
                    break;
            }
            R->left= root;
            R = R->left;
            root = root->left;
            R->left = NULL;
        }
        else if(d> root->data)
        {
            if(root->right==NULL)
                break;
            if(d > root->right->data)
            {
                root = leftRotate(root);
                if (root->right==NULL)
                    break;
            }
            L->right= root;
            L = L->right;
            root = root->right;
            L->right = NULL;
         }
        else
            break;
      }
      L->right = root->left;
      R->left = root->right;
      root->left = head->right;
      root->right = head->left;
      return root;
}
TreeNode* SplayTree::search(TreeNode *root,int d)
{
    TreeNode *temp = root;
    if(temp==NULL || temp->data == d)
        return temp;
    else if(temp->data < d)
        search(temp->right,d);
    else if(temp->data > d)
        search(temp->left,d);
}
TreeNode* SplayTree::deleteNode(TreeNode *root,int d)
{
    TreeNode* temp;
    if(root==NULL)
        return NULL;
    root = splay(root,d);
    if(d != root->data)
        return root;
    else
    {
        if(root->left==NULL)
        {
            temp = root;
            root = root->right;
        }
        else
        {
            temp = root;
            root = splay(root->left,d);
            root->right = temp->right;
        }
        free(temp);
        return root;
    }
}
TreeNode* SplayTree::findMin(TreeNode *root)
{
    TreeNode *temp = root;
    if(temp == NULL)
        return NULL;
    if(temp->left != NULL)
        findMin(temp->left);
    else
        return temp;
}
TreeNode* SplayTree::findMax(TreeNode *root)
{
    TreeNode *temp = root;
    if(temp == NULL)
        return NULL;
    if(temp->right != NULL)
        findMax(temp->right);
    else
        return temp;
}
void SplayTree::inorder(TreeNode *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void SplayTree::preorder(TreeNode *root)
{
    if(root != NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void SplayTree::postorder(TreeNode *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
TreeNode* SplayTree::leftRotate(TreeNode *k2)
{
    TreeNode* k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    return k1;
}
TreeNode* SplayTree::rightRotate(TreeNode *k2)
{
    TreeNode* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    return k1;
}