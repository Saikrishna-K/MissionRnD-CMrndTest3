/*

Given two Binary Search Trees ,Merge Both of them into a Single Binary Search Tree .
The Resultant Binary Search Tree will be BST1 .ie Merge all elements of BST2 into BST1.

Example 1:
Input : 
   20        25
  /  \      /  \
 5    30   10   35
Output :
Bst 1 :
     20
   /   \
  5     30
   \   /  \
   10 25   35

BST 2 can be merged in BST1 sometimes in many number of ways ,Any 1 of those correct ways would be fine .
Finally All elements of Both Trees should be in BST 1 .Dont process NULL Inputs 
(Both r1 and r2 shouldnt be NULL at the time of Input)

Note : Dont Create Nodes using malloc,or Swap the data values or else your solution would receive 100%
cut in the marks you got for this question .
You need to solve this question only by changing links.

You will also receive Bonus marks for any better optimizations you make .
Difficulty : Medium -Hard 
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

int attach = -1;// to represent the given node is attached or not



void attachBst(struct node *root, struct node *bst1, struct node *prev)
{



	if (bst1 != NULL && attach == -1){


		if (root->data > bst1->data)
		{
			attachBst(root, bst1->right, bst1);

		}
		else if (root->data < bst1->data)
		{
			attachBst(root, bst1->left, bst1);
		}

	}



}







void postOrder(struct node *root, struct node *bst1, struct node *prev, int side)
{
	if (root->left != NULL)		postOrder(root->left, bst1, root, 1);

	if (root->right != NULL)	postOrder(root->right, bst1, root, 2);

	attach = -1;

	if (side == 1)
	{
		prev->left = NULL;
	}
	else if (side == 2)
	{
		prev->right = NULL;
	}



	attachBst(root, bst1, bst1);

}




void merge_two_bst(struct node *root1, struct node *root2){

	if (root1 == NULL || root2 == NULL) return;


	postOrder(root2, root1, root2, 0);

	

}