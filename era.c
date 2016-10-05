#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int koef;
	int exp;
	struct node *next;
} node;

int max=0;
int i=0;
char c=' ';

node *pop(node* root,int koef1,int exp1);
node *createList(int koef1,int exp1);
node *createPolinome(node* top,int num);
int MaxElement(node *root);
void pr(node *root);
void delFromEnd(node* root);
void Delete_Item_node(node* head,node* nextEl);
void each(node* root,node* la,node* cur);
void plus(node *root1);

int main(int argc, char const *argv[])
{
	// node *root=createList();
	int pol;
	node *top,*end;
	node *root=createList(0,0);
	top=root;
	end=root;
	printf("Number of polynomial member: ");
	scanf("%d",&pol);
	end=createPolinome(top,pol);
	printf("\n");
	pr(root);	
	plus(root);
	printf("= ");
	pr(root);
	printf("\n");
	return 0;
}

node *createList(int koef1,int exp1){
	node *root;
	root=(node*)malloc(sizeof(node));
	root->koef=koef1;
	root->exp=exp1;
	root->next=NULL;
	return root;
}

node *pop(node* root,int koef1,int exp1){
	// if(root==NULL){
	// 	root=createList(0,0);
	// }
	node *conductor;
	conductor=root;
	conductor->next=createList(koef1,exp1);
	conductor=conductor->next;
	return conductor;
}

node *createPolinome(node* current,int num){
	
	if(num==0){
		// printf("%d\n",num);
		return current;
	}

	
	int k,e;
	// current=top;
	printf("Enter coefficient: ");
	scanf("%d",&k);
	printf("Enter exponent: ");
	scanf("%d",&e);
	
	current=pop(current,k,e);
	num--;
    current=createPolinome(current,num);
    return current;
}						

void pr(node *root){
	
		root=root->next;

		if(root==NULL) return;
		
		// c='+';
		printf("%dx^%d",root->koef, root->exp);	
		if(root->next==NULL)
		printf(" ");
		else printf(" + ");

		pr(root);
}



void plus(node* root1){
	node *root=root1;
	if(root->next==NULL){
		// printf("Plus work good\n");
		return;
	}
	// printf("work1\n");
	each(root,root,root->next);
	// printf("work2\n");
	plus(root->next);
	return;
}

void each(node* root,node* la,node* cur){
	node *current=cur;
	
	if(root->exp==current->exp){
		root->koef=root->koef+current->koef;
		max=current->exp;
		// printf("each work\n");
		Delete_Item_node(la,current);
	}
	if(current->next==NULL)return;
	each(root,current,current->next);
	return;
}

void Delete_Item_node(node* head,node *nextEl){
  node *ptr;

  if(nextEl==NULL)
  	return;
  ptr=head;
  // i++;
  // printf("%d\n",i);
  if(nextEl->exp==max){
  	ptr->next=nextEl->next;
  	free(nextEl);
  	return ;
  }

  Delete_Item_node(nextEl,nextEl->next);
	 
}