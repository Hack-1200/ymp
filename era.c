#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int koef;
	int exp;
	struct node *next;
} node;

int max=0;
int i=0;

node *pop(node* root,int koef1,int exp1);
node *createList(int koef1,int exp1);
node *createPolinome(node* top,int num);
int MaxElement(node *root);
void pr(node *root);
void delFromEnd(node* root);
node* Delete_Item_node(node* Head, int Number);

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
	// printf("koef=%d exp=%d\n",end->koef,end->exp);
	// printf("prrrrrrrrrrrrrrr\n");
	pr(root);
	int max1=MaxElement(root);
	printf("\nmax=%d\n",max);
	printf("vvv=%d\n",i);
	// delFromEnd(root);
	Delete_Item_node(root,i-1);
	pr(root);
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
		printf("%d\n",num);
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
	// printf("pr is work");
	
		if(root->next==NULL) return;
		root=root->next;
		printf("%dx^%d +",root->koef, root->exp);

		pr(root);
}

int MaxElement(node *root){
	
	i++;
		if(max<root->exp){
			max=root->exp;
			// printf("%d\n",max);
		}
		if(root->next==NULL) return max;
		root=root->next;
		// max=(max<root->exp)?root->exp:max;
		
		max=MaxElement(root);
		return max;

}

// void delFromEnd(node* root){
// 	if(root->next==NULL)return;
// 	if((root->next->exp==max)){
// 		printf("exp=%d max=%d\n",root->next->exp,max);
// 		if(root->next->next!=NULL)root->next=root->next->next;

// 		printf("I work\n");
// 		// root->next=NULL;
// 		delete(root->next);
// 		// 
// 	}
// 	root=root->next;
// 	delFromEnd(root);
// }

node *plus(node *root){
	node *current=root;
	current=current->next;
	if(root->exp==current->exp){
		root->koef+current->koef;
		Delete_Item_node()

	}
}

node* Delete_Item_node(node* Head, int Number){
  node *ptr;//вспомогательный указатель
  node *Current = Head;
  for (int i = 1; i < Number && Current != NULL; i++)
    Current = Current->next;
  if (Current != NULL){//проверка на корректность
    if (Current == Head){//удаляем первый элемент
      Head = Head->next;
      delete(Current);
      Current = Head;
    }
    else {//удаляем непервый элемент
      ptr = Head;
      while (ptr->next != Current)
        ptr = ptr->next; 
      ptr->next = Current->next;
      delete(Current);
      Current=ptr;
    }
  }
  return Head;
}