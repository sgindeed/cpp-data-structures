/* C++ Program for creating the mirror image of a given Binary tree */
#include<iostream>
using namespace std;
struct node
{
    int info;
    struct node *left, *right;
};
class Tree
{
    public:
        struct node *root;
        struct node *createnode(int key);
        void mirrorimage(struct node *root);
        int heightoftree(struct node *root);
        void currentlevel(struct node *root, int level);
        Tree()
        {
            root = NULL;
        }
};
/*
 * Function to create new nodes.
 */
struct node *Tree :: createnode(int key)
{
    struct node *newnode = new node;
    newnode->info = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return(newnode);
}
/*
 * Function to swap left and right child of  a node for creating mirror image.
 */
void Tree :: mirrorimage(struct node *root)
{
  if (root != NULL)
    {
        struct node *temp;
        /* first traversing the left subtree */
        mirrorimage(root->left);
        /* Traversing the right subtree. */      
        mirrorimage(root->right);     
        temp = root->left;         
         /* 
          * swap the left and the right child 
          * of all the nodes to create
          * a mirror image of a tree 
          */
        root->left  = root->right;  
        root->right = temp;
    }
}
/*
 * Function to find the height of a tree.
 */
int Tree :: heightoftree(struct node *root)
{
    int maximum;
    if (root!=NULL)
    {
        /* Finding the height of left subtree. */
        int leftsubtree = heightoftree(root->left); 
        /* Finding the height of right subtree. */
        int rightsubtree = heightoftree(root->right);  
        if (leftsubtree > rightsubtree)
        {
            maximum = leftsubtree + 1;
            return maximum;
        }
        else
        {
            maximum = rightsubtree + 1;
            return maximum;
        }
    }
}
/*
 * Function to print all the nodes left to right of the current level
 */
void Tree :: currentlevel(struct node *root, int level)
{
    if (root != NULL)
    {
        if (level == 1)
        {
            cout<<root->info<<"\t";
        }
        else if (level > 1)
        {
            currentlevel(root->left, level-1);
            currentlevel(root->right, level-1);
        }
    }
}
int main()
{
   /* Creating first Tree. */
    Tree t;
    struct node *newnode = t.createnode(25);
    newnode->left = t.createnode(27);
    newnode->right = t.createnode(19);
    newnode->left->left = t.createnode(17);
    newnode->left->right = t.createnode(91);
    newnode->right->left = t.createnode(13);
    newnode->right->right = t.createnode(55);
    /* Sample Tree 1- Balanced Tree.
     *               25                   |                      25
     *             /    \                 |                    /     \
     *            27     19               |                  19      27
     *           / \     / \              |                 /  \    /  \
     *         17  91   13 55             |                55  13  91   17
     *           Input Tree              Mirror               Output Tree
     */
    cout<<"Level Order Traversal of Tree 1 before creating its mirror image is";
    cout<<endl;
    int i;
    int height = t.heightoftree(newnode);
     /* Printing nodes level by level */
    for(i = 1; i <= height; i++)     
    {
        t.currentlevel(newnode,i);
    }
    cout<<"\n\nLevel Order Traversal of Tree 1 after creating its mirror image is";
    cout<<endl;
    height = t.heightoftree(newnode);
    t.mirrorimage(newnode);
    /* Printing nodes level by level */
    for(i = 1; i <= height; i++)      
    {
        t.currentlevel(newnode,i);
    }
 
    /* Creating second Tree. */
    struct node *node = t.createnode(1);
    node->right = t.createnode(2);
    node->right->right = t.createnode(3);
    node->right->right->right = t.createnode(4);
    node->right->right->right->right = t.createnode(5);
    /* Sample Tree 2-   Right Skewed Tree (Unbalanced).
     *     1                                   |                        1
     *      \                                  |                       /
     *       2                                 |                      2
     *        \                                |                     /
     *         3                               |                    3
     *          \                              |                   /
     *           4                             |                  4
     *            \                            |                 /
     *             5                           |               5
     *          Input Tree                   Mirror           Output Tree
     */
    cout<<endl;
    cout<<"\nLevel Order Traversal of Tree 2 before creating its mirror image is";
    cout<<endl;
    height = t.heightoftree(node);
    /* Printing nodes level by level */
    for(i = 1; i <= height; i++) 
    {
        t.currentlevel(node,i);
    }
    cout<<endl;
    cout<<"\nLevel Order Traversal of Tree 2 after creating its mirror image is";
    cout<<endl;
    height = t.heightoftree(node);
    t.mirrorimage(node);
    /* Printing nodes level by level */
    for(i = 1; i <= height; i++) 
    {
        t.currentlevel(node,i);
    }
 
    /* Creating  third tree having just one root node */
    struct node *root = t.createnode(15);
    /* Sample Tree 3 - Tree having just one root node.
     *              15           |              15
     *        Input Tree                      Output Tree
     *                         Mirror
     */
    cout<<endl;
    cout<<"\nLevel Order Traversal of Tree 3 before creating its mirror image is";
    cout<<endl;
    height = t.heightoftree(root);
    /* Printing nodes level by level */
    for(i = 1; i <= height; i++) 
    {
        t.currentlevel(root,i);
    }
    cout<<endl;
    cout<<"\nLevel Order Traversal of Tree 3 after creating its mirror image is";
    cout<<endl;
    height = t.heightoftree(root);
    t.mirrorimage(root);
    /* Printing nodes level by level */
    for(i = 1; i <= height; i++) 
    {
        t.currentlevel(root,i);
    }
    return 0;
}