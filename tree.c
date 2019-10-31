#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node* left;
  struct node* right;
}node;

node* t=NULL,*tptr;
void insert(int n);
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
      printf("1.Insertion\n2.Travesal\n3.Deletion\n");
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

void insert(int n)
{
  node* cur=t,*prev=NULL;
    node* newnode=malloc(sizeof(node*));
    newnode->data=n;
    newnode->right=NULL;
    newnode->left=NULL;
    if(t==NULL) t=newnode;
    else{
    while(cur!=NULL){
        prev=cur;
        if(n==cur->data) break;
        else if(n>cur->data) cur=cur->right;
        else if(n<cur->data) cur=cur->left;
    }
    if(prev->data<n) prev->right=newnode;
    else prev->left=newnode;
    }
}
int traversal(int c,node* tptr)
{
  if (c==1)     //NLR
    {
      if(tptr==NULL) return 0;
      else{
	printf("%d ",tptr->data);
	traversal(1,tptr->left);
	traversal(1,tptr->right);
	return  0;
      }
    }
  if (c==2)     //LNR
    {
      if(tptr==NULL) return 0;
     else
	{
	traversal(2,tptr->left);
	    printf("%d ",tptr->data);
	    traversal(2,tptr->right);
	    return 0;  
      }
    }
  if (c==3)     //LRN
    {
      if(tptr==NULL) return 0;
      else
	{
	traversal(3,tptr->left);
	  traversal(3,tptr->right);
	      printf("%d ",tptr->data);
	      return 0;
      }
    }
  else
    printf("Wrong input\n");
  return 0;
}

void deletion(node *tptr)
{
  node *ptr,*parent=NULL,*s=NULL;
  int temp;
  if(t==NULL)
    printf("Empty Tree ");
  else
    {
      ptr=t;
      int flag=0;
      while((ptr!=NULL)&&(flag==0))
	{
	  if(tptr->data>ptr->data)
	    {
	      parent=ptr;
	      ptr=ptr->right;
	    }
	  else if(tptr->data<ptr->data)
	    {
	      parent=ptr;
	      ptr=ptr->left;
	    }
	  else
      {
	flag=1;
      }
	}
      if(flag==0)
	printf("Value Not found");
      else if((ptr->left==NULL)&&(ptr->right==NULL))
	{
	  if(parent->left==ptr)
	    parent->left=NULL;
	  else
	    parent->right=NULL;
	  free(ptr);
	}
      else if((ptr->left!=NULL)&&(ptr->right!=NULL))
    {
      s=ptr->right;
      while(s->left!=NULL)
	{ 
	  s=s->left;
	}
      temp=s->data; 
    
    deletion(s); 
    ptr->data=temp;
    //free(ptr);
    }
      else
	{
	  if(parent->left==ptr)
	    {
	      if(ptr->left==NULL)
		parent->left=ptr->right;
	      else
		parent->left=ptr->left;
	    } 
	  else if(parent->right==ptr)
	    {
	      if(ptr->left==NULL)
		parent->right=ptr->right;
	      else
		parent->right=ptr->left;
	    }  
	  free(ptr);   
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
