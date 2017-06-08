#include "ClassInvertedIndex.h"



struct nodeAVL
{
    int data;
    struct nodeAVL *left;
    struct nodeAVL *right;
    struct nodeAVL *gtn;//geitonas
}*root;


ClassInvertedIndex::ClassInvertedIndex()
{
    root = NULL;
}
//inster x,y int the tree
nodeAVL* ClassInvertedIndex::insert_x_y_intoTheTree(nodeAVL *root, int value,int linkValue)
{
    if (root == NULL || root->data==value)
    {
        root = new nodeAVL;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        root->gtn=insert_y(linkValue,root->gtn);
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value,int linkValue);
        root = balance (root);
    }
    else if (value >= root->data)
    {
        root->right = insert(root->right, value,int linkValue);
        root = balance (root);
    }
    return root;
}


//insert only y into the tree
nodeAVL* ClassInvertedIndex::insert_only_y(nodeAVL *root, int value)
{
    if (root == NULL)
    {
        root = new nodeAVL;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
        root = balance (root);
    }
    else if (value >= root->data)
    {
        root->right = insert(root->right, value);
        root = balance (root);
    }
    return root;
}


// Finding the Smallest
struct nodeAVL* ClassInvertedIndex::findmin(nodeAVL* &p)
{
    struct nodeAVL* current = node;
	if (p==NULL)
	{
		cout<<"The tree is empty\n"<<endl;
		return p;
	}
	else
	{
		while(p->left !=NULL)
		{
			p=p->left;
			//return p;
		}
		return p;
	}
}


// Finding the Largest node
struct nodeAVL* ClassInvertedIndex::findmax(nodeAVL* &p)
{

    struct nodeAVL* p = node;
	if (p==NULL)
	{
		cout<<"The tree is empty\n"<<endl;
		return p;
	}
	else
	{
		while(p->right !=NULL)
		{
			p=p->right;
			//return p;
		}
		return p;
	}
}

//delete actions

// Deleting y
void ClassInvertedIndex::delete_y_value(int x,nodeAVL* &p)
{
	nodeAVL* d;
	if (p==NULL)
	{
		cout<<"Sorry! element not found\n"<<endl;
	}
	else if ( x < p->element)
	{
		del(x,p->left);
	}
	else if (x > p->element)
	{
		del(x,p->right);
	}
	else if ((p->left == NULL) && (p->right == NULL))
	{
		d=p;
		free(d);
		p=NULL;
		cout<<"Element deleted successfully\n"<<endl;
	}
	else if (p->left == NULL)
	{
		d=p;
		free(d);
		p=p->right;
		cout<<"Element deleted successfully\n"<<endl;
	}
	else if (p->right == NULL)
	{
		d=p;
		p=p->left;
		free(d);
		cout<<"Element deleted successfully\n"<<endl;
	}
	else
	{
		p->element = deletemin(p->right);
	}
}

//delete the smallest
int ClassInvertedIndex::deletemin(nodeAVL* &p)
{
	int c;
	cout<<"inside deltemin\n"<<endl;
	if (p->left == NULL)
	{
		c=p->element;
		p=p->right;
		return c;
	}
	else
	{
		c=deletemin(p->left);
		return c;
	}
}


//deleting x value_type
void ClassInvertedIndex::delete_x_value(int value1, int value2, nodeAVL* &root)
{
    if(root->data==value1)
    {
        delete_y_value(value2,root->gtn);
    }
    else
    {
        if(root->data<value1)
        {
            delete_x_value(value1,value2,root->right);
        }
        else
        {
            delete_x_value(value1,value2, root->left);
        }
    }
    return;
}

//height of AVL tree
int ClassInvertedIndex::height(nodeAVL *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);

        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

//height difference
int ClassInvertedIndex::diff(nodeAVL *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}


/*
 * Right- Right Rotation
 */
nodeAVL *ClassInvertedIndex::rr_rotation(nodeAVL *parent)
{
    nodeAVL *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
/*
 * Left- Left Rotation
 */
nodeAVL *ClassInvertedIndex::ll_rotation(nodeAVL *parent)
{
    nodeAVL *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

/*
 * Left - Right Rotation
 */
nodeAVL *ClassInvertedIndex::lr_rotation(nodeAVL *parent)
{
    nodeAVL *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}

/*
 * Right- Left Rotation
 */
nodeAVL *ClassInvertedIndex::rl_rotation(nodeAVL *parent)
{
    nodeAVL *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}

//Balancing the tree
nodeAVL *ClassInvertedIndex::balance(nodeAVL *temp)
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
    return temp;
}


//OUTPUT
//inorder printing
void ClassInvertedIndex::inorderYout(nodeAVL root,ofstream & out)
{
	if (root!=NULL)
	{
		inorder(root->left,out);
		out<<root->element<<"\t";
		inorder(root->right,out);
	}
}

//inorder for x
void ClassInvertedIndex::inorderX(nodeAVL* root, ofstream & out)
{
    if (root!=NULL){
    inorderX(p->left,out);
    out<<root->element<<"\t";
    sum(root->gtn,out);
    inorderYout(root->gtn,out);
    out<<"\n";
    }
}

void ClassInvertedIndex::sum(nodeAVL *root,ofstream & out)
{
    int number=0;
    if(root!=NULL)
    {
        number=gtnFunction(root);
    }
    out<<"| "<<number<<" , ";
}
//end output


//function for neighbours(gtn for our's case)
int ClassInvertedIndex::gtnFunction(nodeAVL *root)
{
    if(root!==NULL)
    {
        return 1+gtnFunction(root->right)+gtnFunction(root->left);
    }
}


//write index with ofstream
void ClassInvertedIndex::writeIndex(nodeAVL *root)
{
    ofstream out;
    out.open("output.txt",ios::out);
    inorderX(root,out);
    return;
}
