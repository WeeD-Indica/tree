#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node* left;
  struct node* root;
  struct node* right;
}node;

node* t;
void insert(int x);
int traversal(int c,node*tptr);
void deletion(node* tptr);
node* search(int x);

void main()
{
  int x,ch,choice,c;
  node* tptr;
  
  do
    {
      tptr=t;
      printf("1.Insertion\n2.Travesal\n3.Deletion\n4.Searching\n");
      scanf("%d",&choice);
      switch(choice)
	{
	case 1:printf("Enter element to insert:");
	  scanf("%d",&c);
	  insert(c);
	  break;
	case 2: printf("\n1.Preorder\n2.Inorder\n3.Postorder");
	  scanf("%d",&c);
	  traversal(c,tptr);
      break;    
	case 3: printf("\nEnter element to delete\n");
	  scanf("%d",&x);
	  if(search(x)==NULL) printf("\nElement does not exist\n");
	  else 
	  deletion(search(x));
	  break;
	default:printf("\nWrong Input\n");
	}
      printf("\nDo you want to continue(1|0):");
      scanf("%d",&ch);
    }while(ch);
}

void insert(int x)
{
  node*curr=t;
  node*prev=NULL;
  node* newnode=malloc(sizeof(node*));
  newnode->data=x;
  newnode->left=NULL;
  newnode->right=NULL;
  if(t==NULL)
    {
      t=newnode;
    }
  while(curr!=NULL)
    {
      prev=curr;
      if(x==curr->data) break;
      else if(x>curr->data) curr=curr->right;
      else if(x<curr->data) curr=curr->left;
    }
  if(prev->data<x) prev->right=newnode;
  else prev->left=newnode;
}
int traversal(int c,node* tptr)
{
  if (c==1)     //NLR
    {
      if(tptr==NULL) return 0;
      else{
	printf("%d",tptr->data);
	traversal(1,tptr->left);
	traversal(1,tptr->right);
      }
    }
  if (c==2)     //LNR
    {
     if(tptr==NULL) return 0;
      else{
	traversal(2,tptr->left);
	printf("%d",tptr->data);
	traversal(2,tptr->right);
      }
    }
  if (c==3)     //LRN
    {
      if(tptr==NULL) return 0;
      else{
	traversal(3,tptr->left);
	traversal(3,tptr->right);
	printf("%d",tptr->data);
      }
    }
  else
    printf("Wrong input\n");
  return 0;
}

void deletion(node* tptr)
{
    node* cur=t,*prev=NULL;
    while(cur!=tptr)
    {
        prev=cur;
        if(tptr==cur) break;
        else if(tptr->data>cur->data) cur=cur->right;
        else if(tptr->data<cur->data) cur=cur->left;
    }

    if(tptr->right==NULL && tptr->left==NULL)
    {
        if(prev->right==tptr){
            free(tptr);
            prev->right=NULL;
        }
        else prev->left=NULL;
    }
    else if(tptr->right!=NULL && tptr->left!=NULL)
    {
        node* cur=tptr->right,*prev;
        while(cur->left!=NULL)
        {
            prev=cur;
            cur=cur->left;
        }
        tptr->data=cur->data;
        free(cur);
    }
    else
    {
        if(tptr==prev->right)
        {
            if(tptr->right!=NULL) 
            {
                prev->right=tptr->right;
                free(tptr);
            }
            else
            {
                prev->right=tptr->left;
                free(tptr);
            }
        }
        else{
            if(tptr->right!=NULL){
                prev->left=tptr->right;
                free(tptr);
            }
            else{
                prev->left=tptr->left;
                free(tptr);
            }
        }
    }


}

node* search(int x)
{
    node* curr=t;
    while(curr!=NULL)
    {
        if(x==curr->data) return curr;
        else if(x>curr->data) curr=curr->right;
        else if(x<curr->data) curr=curr->left;
    }
    return NULL;
}
