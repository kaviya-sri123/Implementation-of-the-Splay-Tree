#include "splay_header.h"
int main()
{
    SplayTree *s = new SplayTree();
    TreeNode *root=NULL;
    int d,ch;
    do
    {
        cout<<"\t=============MENU=============\n";
    	cout<<"\t1.Insert\n";
    	cout<<"\t2.Search\n";
    	cout<<"\t3.Find Minimum\n";
    	cout<<"\t4.Find Maximum\n";
    	cout<<"\t5.Inorder Traversal\n";
    	cout<<"\t6.Preorder Traversal\n";
    	cout<<"\t7.Postorder Traversal\n";
    	cout<<"\t8.Delete\n";
        cout<<"\t9.Exit\n";
    	cout<<"\t==============================\n";
    	cout<<"\nEnter your choice : ";
    	cin>>ch;
        switch(ch)
        {
            case 1:
            	cout<<"\nEnter a Number : ";
            	cin>>d;
            	root = s->insert(root,d);
                cout<<"\nNumber inserted.\n\n";
            	break;
            case 2:
                if(root==NULL)
                {
                    cout<<"\nTree is empty.\n\n";
                    break;
                }
                int key;
                TreeNode *t;
                cout<<"\nEnter the Element to search : ";
                cin>>key;
                t = s->search(root,key);
                if(t == NULL)
                    cout<<"\nElement not found.\n\n";
                else
                    cout<<"\nElement found.\n\n";
                break;
            case 3:
                if(root==NULL)
                {
                    cout<<"\nTree is empty.\n\n";
                    break;
                }
                TreeNode *minimum;
                minimum = s->findMin(root);
                if(minimum==NULL)
                    cout<<"\nTree is empty.\n\n";
                else
                    cout<<"\nMinimum Element : "<<minimum->data<<"\n\n";
                break;
            case 4:
                if(root==NULL)
                {
                    cout<<"\nTree is empty.\n\n";
                    break;
                }
                TreeNode *maximum;
                maximum = s->findMax(root);
                if(maximum==NULL)
                    cout<<"\nTree is empty.\n\n";
                else
                    cout<<"\nMaximum Element : "<<maximum->data<<"\n\n";
                break;
            case 5:
                if(root==NULL)
                {
                    cout<<"\nTree is empty.\n\n";
                    break;
                }
                cout<<"\nInorder Traversal : ";
                s->inorder(root);
                cout<<"\n\n";
                break;
            case 6:
                if(root==NULL)
                {
                    cout<<"\nTree is empty.\n\n";
                    break;
                }
                cout<<"\nPreorder Traversal : ";
                s->preorder(root);
                cout<<"\n\n";
                break;
            case 7:
                if(root==NULL)
                {
                    cout<<"\nTree is empty.\n\n";
                    break;
                }
                cout<<"\nPostorder Traversal : ";
                s->postorder(root);
                cout<<"\n\n";
                break;
            case 8:
                if(root==NULL)
                {
                    cout<<"\nTree is empty.\n\n";
                    break;
                }
                int num;
                cout<<"\nEnter Number to be deleted : ";
                cin>>num;
                t = s->search(root,num);
                if(t == NULL)
                    cout<<"\nNumber not found.\n\n";
                else
                {
                    root = s->deleteNode(root,num);
                    cout<<"\nNumber deleted.\n\n";
                }
                break;
            case 9:
                break;
            default:
                cout<<"\n\nEnter a valid choice.\n";
                break;
        }
    }while(ch!=9);
}