/*
Given a Sorted Doubly Linked List and a Binary Search Tree , Check if they are identical or not .
The DLL will have nodes of type node_dll
Note :
A DLL can be represented as a BST in many forms ,And if a dll and any one of the forms is given as input you
need to return 1 otherwise 0. 

->Dont Create an Extra Array ,or else your solution would receive 20% Cut in the Marks you got .

Examples :

Example 0:
DLL:1->5->8
BST(All 3 return 1):
    5         8      1
   / \       /        \
  1   8     5          5
           /            \
          1              8
Returns 1
    8
   / \
  5   1
Returns 0
Example 1:
DLL : 1->5
BST : 
5
 \
 10
Returns 0

Example 2:
DLL:1->3->5-9->11
BST:
    5
   / \
  1   11
   \  /      
    3 9

Returns 1

Example 3:
DLL: 1->5->7->10->12->15->20
BST:
        10
        /\
       5  15
      /\  / \
     1  7 12 20
Returns 1

Note 2 :
Unequal Length BST and DLL should return 0;
Return -1 for NULL inputs

Difficulty : Medium +
*/
#include <stdlib.h>
#include <stdio.h>
#include<stdbool.h>

struct node_dll{
	int data;
	struct node_dll *next;
	struct node_dll *prev;
};
struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node_dll* temp = NULL;
bool not_match = false;
int bst_len = 0;


void inorder1(struct node *root)
{
	if (root->left != NULL)		inorder1(root->left);

	if (not_match == false){

		if (root->data == temp->data)
		{
			temp = temp->next;
		}

		else
		{
			not_match = true;
			return;
		}

	}

	if (not_match == false)
	if (root->right != NULL)	inorder1(root->right);



}



void  bst_length(struct node *root)
{
	if (root != NULL)
	{
		bst_len++;
	}
	if (root->left != NULL)		bst_length(root->left);

	if (root->right != NULL)	bst_length(root->right);



}



int is_identical(struct node_dll *head, struct node *root){

	if (head == NULL || root == NULL)  return -1;

	int dll_length = 0;
	not_match = false;
	bst_len = 0;
	temp = head;

	while (temp)
	{
		dll_length++;
		temp = temp->next;
	}

	bst_length(root);

	if (bst_len != dll_length)
	{
		return 0;
	}


	temp = head;
	inorder1(root);

	if (not_match == false)
		return 1;

	else return 0;



}