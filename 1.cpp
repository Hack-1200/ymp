// #include "stdafx.h" 
#include <iostream> 
#include <stdlib.h>
using namespace std; 

struct node 
{ 
int koef; 
int exp; 
node* next; 
}; 

bool empty_polinom(node* top)// проверяем, пуст ли полином 
{ 
return top == NULL; 
} 

void CreatePolinom(node* &top, node* &end, int n) 
{ 
int i;//счетчик 
top = NULL;//создаем пустой 
end = NULL;// полином 
for (i = 0; i<n; i++) 
{ 
node* p = new node; // выделяем память под узел записывая коеф и степень 
cout << " enter koef="; 
cin >>p->koef; 
cout << " enter exp="; 
cin >> p->exp; 
if (i == 0)// если полином пустой был 
{ 
p->next = top; 
top = p; 
end = p; 
} 
else // записывается в ост случаи 
{ 
end->next = p; 
p->next = NULL; 
end = p; 
} 
} 
} 

void PopPolinom(node* &top, int &koef, int &exp)//выкидываем из полином член 
{ 
node* p; //указатель с помощью него по полиному двигаться 
if (!empty_polinom(top)) //пока не пуст 
{ 
koef = top->koef; 
exp = top->exp; 
p = top->next; //передвигаем на следующий 
delete top; 
top = p; 
} 
} 

void PushPolinom(node* &top, node* &end, int koef, int exp) 
{ 

node* p = new node; 
p->koef = koef; 
p->exp = exp; 
p->next = NULL; 
if (empty_polinom(top)) 
{ 
top = p; 
end = p; 
} 
else 
{ 
end->next = p; 
end = p; 
} 
} 



void CreatePolinomPush(node* &top, node* &end, int n) 
{ 
int i; 
int koef, exp; 
top = NULL; 
end = NULL; 
for (i = 0; i<n; i++) 
{ 
cout << " enter koef="; 
cin >> koef; 
cout << " enter exp="; 
cin >> exp; 
PushPolinom(top, end, koef, exp); 
} 
} 

void ShowPolinom(node* top) 
{ 
node* p; 
p = top; 
while (p!=NULL) 
{ 
cout << p->koef << "*x^" << p->exp; 
if (p->next) 
cout << " + "; 
p = p->next; 
} 
cout << endl; 
} 

void OrderPolinom(node* top, node* end) 
{ 
int koef, exp; 
node* p, *q; 
p = top; 
while (p != end) 
{ 
q = p->next; 
while (q) 
{ 
if (p->exp<q->exp) //перемещаем таким образом чтобы они шли по убыванию 
{ 
exp = p->exp; 
p->exp = q->exp; 
q->exp = exp; 
koef = p->koef; 
p->koef = q->koef; 
q->koef = koef; 
} 
q = q->next; 
} 
p = p->next; 
} 
} 

node* previous(node* top, node* p) 
{ 
node* pr, *q; 
q = top; 
pr = NULL; 
while (q != p && q!=NULL)//пока не дошли до того с которого надо смотреть или полином не кончился 
{ 
pr = q;//pr-предущий 
q = q->next; 
} 

if (q == p) return pr; 
return NULL; 
} 

void CollectingTermsInPolinom(node* &top, node* end) 
{ 
int koef, exp; 
OrderPolinom(top, end);//сортируем полином по степеняем 
node* p, *q, *pr; 
p = top; 
q = p->next;//след за началом 
while (q) 
{ 
if (p->exp == q->exp)//если степени равны то склад коеф 
{ 
q->koef = q->koef + p->koef; 
if (p == top)//выкидываем член который уже сложили 
{ 
PopPolinom(top, koef, exp); 
p = top; 
} 

else 
{ 
pr = previous(top, p); 
pr->next = q; 
delete p; 
p = q; 
} 
q = q->next; 
} 
else 
{ 
p = q; 
q = q->next; 
} 
} 
} 

void CopyPolinom(node* top1, node* end1, node*& top2,node*& end2) 
{ 
top2 = NULL; 
end2 = NULL; 

while (top1) 
{ 
PushPolinom(top2, end2, top1->koef, top1->exp); 
top1 = top1->next; 
} 
} 

void AdditionOfPolinoms(node* top1, node* end1, 
node* top2, node* end2, node* &top3, node* &end3) 
{ 
node* top4, *end4; 
CopyPolinom(top1, end1, top3, end3); 
CopyPolinom(top2, end2, top4, end4); 
end3->next = top4; 
end3 = end4; 
CollectingTermsInPolinom(top3, end3); 
} 


main() 
{ 
int n; 

node* top_polinom, *end_polinom; 
node* top_polinom1, *end_polinom1; 
node* top_polinom2, *end_polinom2; 
node* top_polinom3, *end_polinom3; 

cout << "enter n= "; 
cin >> n; 
CreatePolinom(top_polinom, end_polinom, n); 

cout << " polinom = " << endl; 
ShowPolinom(top_polinom); 

cout << "enter n= "; 
cin >> n; 
CreatePolinomPush(top_polinom1, end_polinom1, n); 

cout << " polinom1 = " << endl;
ShowPolinom(top_polinom1); 

AdditionOfPolinoms(top_polinom, end_polinom, 
top_polinom1, end_polinom1, top_polinom2, end_polinom2); 
cout << "polinom2=polinom+polinom1 " << endl; 
ShowPolinom(top_polinom2); 

system("pause"); 

}