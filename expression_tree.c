#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>



typedef struct tree
{
	char data;
	struct tree *lchild,*rchild;
}Tree_NODE;

typedef struct stack
{
	Tree_NODE *ptr;
	struct stack *next;
}Stack_Node;

Stack_Node *push(Stack_Node *top,Tree_NODE *t)
{
	Stack_Node *new_node=(Stack_Node*)malloc(sizeof(Stack_Node));
	new_node->ptr=t;
	new_node->next=NULL;
	if(top==NULL)
	{
		top=new_node;
	}
	else
	{
		new_node->next=top;
		top=new_node;
	}
	return top;
}

Stack_Node *pop(Stack_Node *top)
{
	Stack_Node *temp=top;
	top=top->next;
	free(temp);
	return top;
}

Tree_NODE *read_top(Stack_Node *top)
{
	return top->ptr;
}

int is_empty(Stack_Node *top)
{
	if(top==NULL)
		return 1;
	return 0;
}

void pre_order_traversal(Tree_NODE *root) {
   if(root != NULL) {
      printf("%c ",root->data);
      pre_order_traversal(root->lchild);
      pre_order_traversal(root->rchild);
   }
}
void inorder_traversal(Tree_NODE *root) {
   if(root != NULL) {
      inorder_traversal(root->lchild);
      printf("%c ",root->data);          
      inorder_traversal(root->rchild);
   }
}

void post_order_traversal(Tree_NODE *root) {
   if(root != NULL) {
      post_order_traversal(root->lchild);
      post_order_traversal(root->rchild);
      printf("%c ", root->data);
   }
}

void inOrder_non_recursive(Tree_NODE *root)
{
  /* set current to root of binary tree */
  Tree_NODE *current = root;
  Stack_Node *top=NULL;
  int done = 0;
 
  while (!done)
  {
    /* Reach the left most tNode of the current tNode */
    if(current !=  NULL)
    {
      /* place pointer to a tree node on the stack before traversing
        the node's left subtree */
      top=push(top,current);                                              
      current = current->lchild; 
    }
        
    /* backtrack from the empty subtree and visit the tNode
       at the top of the stack; however, if the stack is empty,
      you are done */
    else                                                             
    {
      if (!is_empty(top))
      {
        current = read_top(top);
		top=pop(top);
        printf("%c ", current->data);
 
        /* we have visited the node and its left subtree.
          Now, it's right subtree's turn */
        current = current->rchild;
      }
      else
        done = 1;
    }
  } /* end of while */ 
}    

Tree_NODE* postfix_expression(Tree_NODE *root)
{
	Stack_Node *top=NULL;
	char str[20];
	int i;
	printf("Enter postfix expression :");
	scanf("%s",str);
	
	for(i=0;str[i]!='\0';i++)
	{
		Tree_NODE *t=(Tree_NODE*)malloc(sizeof(Tree_NODE));
		t->data=str[i];
		t->rchild=t->lchild=NULL;
		if(isalpha(str[i]))
		{
			top=push(top,t);
		}
		else
		{
			t->rchild=read_top(top);
			top=pop(top);
			t->lchild=read_top(top);
			top=pop(top);
			
			top=push(top,t);
		}
	}
	
	root=read_top(top);
	top=pop(top);
	return root;
}


Tree_NODE* prefix_expression(Tree_NODE *root)
{
	Stack_Node *top=NULL;
	char str[20];
	int i;
	printf("Enter prefix expression :");
	scanf("%s",str);
	int length=strlen(str);
	for(i=length-1;i>=0;i--)
	{
		Tree_NODE *t=(Tree_NODE*)malloc(sizeof(Tree_NODE));
		t->data=str[i];
		t->rchild=t->lchild=NULL;
		if(isalpha(str[i]))
		{
			top=push(top,t);
		}
		else
		{
			t->lchild=read_top(top);
			top=pop(top);
			t->rchild=read_top(top);
			top=pop(top);
			
			top=push(top,t);
		}
	}
	
	root=read_top(top);
	top=pop(top);
	return root;
}











int main()
{

	Tree_NODE *root=NULL;
	int choice;
	
	do{
		printf("\n1. Create Expression Tree using postfix expression \n2. Create Expression Tree using prefix expression\n3. In-order Traversal\n4. Pre-order Traversal\n5. Postorder Traversal \n6. Non Recursive traversal- In-order\n7. Non Recursive traversal- Pre-order\n8. Non Recursive traversal- Post-order\n0. Exit");
		printf("\nEnter your Choice :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				root=postfix_expression(root);
				break;
			case 2:
				root=prefix_expression(root);
				break;
			case 3: 
				printf("\nRecursive-Inorder traversal is :");
				inorder_traversal(root);
				break;
			case 4:
				printf("\nRecursive-Pre-order traversal is :");
				pre_order_traversal(root);
				break;
			case 5:
				printf("\nRecursive-Post-order traversal is :");
				post_order_traversal(root);
				break;			
			
		}
	}while(choice!=0);

}