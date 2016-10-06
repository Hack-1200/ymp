#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int KOEF;
	int EXP;
	struct node *next;
} node;

int max=0;

node *pop(node* head,int KOEF1,int EXP1);
node *Create_List(int KOEF1,int EXP1);
node *createPolinome(node* top,int num);
int MaxElement(node *head);
void pr(node *head);
void delFromEnd(node* head);
void Delete_Element(node* head,node* next_node);
void Sum(node* head,node* la,node* cur);
void Addition_Of_Polinoms(node *head1);

int main(int argc, char const *argv[])
{
	int pol;
	node *top,*end;
	node *head=Create_List(0,0);
	top=head;
	end=head;
	printf("Number of polynomial member: ");
	scanf("%d",&pol);
	end=createPolinome(top,pol);
	printf("\n");
	pr(head);	
	Addition_Of_Polinoms(head);
	printf("= ");
	pr(head);
	printf("\n");
	return 0;
}

node *Create_List(int KOEF1,int EXP1){
	node *head;
	head=(node*)malloc(sizeof(node));
	head->KOEF=KOEF1;
	head->EXP=EXP1;
	head->next=NULL;
	return head;
}

node *pop(node* head,int KOEF1,int EXP1){
	node *conductor;
	conductor=head;
	conductor->next=Create_List(KOEF1,EXP1);
	conductor=conductor->next;
	return conductor;
}

node *createPolinome(node* current,int num){
	
	if(num==0){
		return current;
	}

	
	int k,e;
	printf("Enter coefficient: ");
	scanf("%d",&k);
	printf("Enter EXPonent: ");
	scanf("%d",&e);
	
	current=pop(current,k,e);
	num--;
    current=createPolinome(current,num);
    return current;
}						

void pr(node *head){
	
		head=head->next;

		if(head==NULL) return;
		
		// c='+';
		printf("%dx^%d",head->KOEF, head->EXP);	
		if(head->next==NULL)
		printf(" ");
		else printf(" + ");

		pr(head);
}



void Addition_Of_Polinoms(node* head1){
	node *head=head1;
	if(head->next==NULL){
		return;
	}
	Sum(head,head,head->next);
	Addition_Of_Polinoms(head->next);
	return;
}

void Sum(node* head,node* la,node* cur){
	node *current=cur;
	
	if(head->EXP==current->EXP){
		head->KOEF=head->KOEF+current->KOEF;
		max=current->EXP;
		Delete_Element(la,current);
	}
	if(current->next==NULL)return;
	Sum(head,current,current->next);
	return;
}

void Delete_Element(node* head,node *next_node){
  node *node;

  if(next_node==NULL)
  	return;
  node=head;
  if(next_node->EXP==max){
  	node->next=next_node->next;
  	free(next_node);
  	return ;
  }

  Delete_Element(next_node,next_node->next);
	 
}