// C++ program to find predecessor and successor in a BST
#include <iostream>
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

int key=0;
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key);

 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new Node(n2);
                    break;
          case 'R': root->right=new Node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    Node *pre=NULL;
    Node *suc=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
   // Inorder(root);
    //Node * target =ptr;
    //printkdistanceNode(root, target, k);
    //cout<<endl;
    cin>>key;
    findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	cout << pre->key;
	else
	cout << "-1";

	if (suc != NULL)
	cout <<" "<<suc->key<<endl;
	else
	cout << " "<<"-1"<<endl;
    }
	return 0;
}// } Driver Code Ends


/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
/*void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root==NULL ) return;
    while(root!=NULL){
    if(root->key==key)
    {
        if(root->right)
        {
            suc=root->right;
            while(root->left)
            suc=suc->left;
        }
        if(root->right)
        {
            pre=root->left;
            while(root->right)
            pre=pre->right;
        }
        }
       else if(root->key<key)
       {
          pre=root;
          root=root->left;
        }
        else if(root->key>key)
        {
        suc=root;
        root=root->right;
        }
    }
}*/
 void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) 
{ 
    if (root == NULL) 
        return; 
  
    // Search for given key in BST. 
    while (root != NULL) { 
  
        // If root is given key. 
        if (root->key == key) { 
  
            // the minimum value in right subtree 
            // is predecessor. 
            if (root->right) { 
                suc = root->right; 
                while (suc->left) 
                    suc = suc->left; 
            } 
  
            // the maximum value in left subtree 
            // is successor. 
            if (root->left) { 
                pre = root->left; 
                while (pre->right) 
                    pre = pre->right; 
            } 
  
            return; 
        } 
  
        // If key is greater than root, then 
        // key lies in right subtree. Root 
        // could be predecessor if left 
        // subtree of key is null. 
        else if (root->key < key) { 
            pre = root; 
            root = root->right; 
        } 
  
        // If key is smaller than root, then 
        // key lies in left subtree. Root 
        // could be successor if right 
        // subtree of key is null. 
        else { 
            suc = root; 
            root = root->left; 
        } 
    } 
} 
  
