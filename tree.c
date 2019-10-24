#include<stdio.h>
#include<stdio.h>

typdef struct node
{
  int data;
  int flag=0;
  struct node* left;
  struct node* root;
  struct node* right;
}node;

node* t;
int insert(int c);
int traversal(int c);
int deletion(int x);
int search(int x);

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
	case 2: printf("\nPreorder\n2.Inorder\n2.Postorder");
	  scanf("%d",&c);
	  traversal(c,tptr);

	case 3: printf("\nEnter element to delete\n")
	  scanf("%d",&x);
	  deletion(x);

	case 4: printf("\nEnter element to be searched\n")
	  scanf("%d",&x);
	  int k=search(x);
	  if(k) printf("\nElement is found");
	  else printf("\nElement not found");
	default:printf("\nWrong Input\n");
	}
      printf("\nDo you want to continue(1|0):");
      scanf("%d",&ch);
    }while(ch);
}

int insert(int n)
{
  node*curr=t,prev==NULL;
  node* newnode=malloc(sizeof(node*));
  newnode->data=n;
  newnode->left=NULL;
  newnode->right=NULL;
  if(t==NULL)
    {
      t=newnode;
      return;
    }
  while(curr!=NULL)
    {
      prev=curr;
      if(n==curr->data) break;
      else if(n>curr->data) curr=curr->right;
      else if(n<curr->data) curr=curr->left;
    }
  return;
}
int traversal(int c,node* tptr)
{
  if (c==1)     //NLR
    {
      if(tptr==NULL) return;
      else{
	printf("%d",tptr->data);
	traversal(1,tptr->left);
	traversal(1,tptr->right);
      }
    }
  if (c==2)     //LNR
    {
     if(tptr==NULL) return;
      else{
	traversal(2,tptr->left);
	printf("%d",tptr->data);
	traversal(2,tptr->right);
      }
    }
  if (c==3)     //LRN
    {
      if(tptr==NULL) return;
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

int deletion(int x,node* tptr)
{
  node* temp;
  if(tptr==NULL) return;
  else{
    if(x==tptr->data)
      {
	if (tptr->left==NULL && tptr->right==NULL)
	  {
	    temp=tptr;
	    tptr=tptr->root;
	    if (tptr->left==temp)
	      tptr->left=NULL;
	    else
	      tptr->right=NULL;
	    free(temp);
	    return;
	  }
	else
	  {
	    
	  }
    deletion(x,tptr->left);
    deletion(x,tptr->right);
  }
  
}

    int search(int x,node* tptr)
{
  if(tptr==NULL) return;
  else{
    if(x==tptr->data) return 1;
    search(x,tptr->left);
    search(x,tptr->right);
  }
  return 0;
}

	   
  

	  
