#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTACK 40

typedef char ItemType;
typedef struct 
{
	ItemType item[MAXSTACK];
	int count;
}
Stack;

void initialize(Stack *s);
int full(Stack *s);
int empty(Stack *s);
void push(Stack *s, ItemType x);
ItemType pop(Stack *s);

int main()
{
	Stack operan, operator, kurung;
	initialize(&operan);
	initialize(&operator);
	initialize(&kurung);
	char kebenaran, operasi[MAXSTACK];
	push(&operator, '+');
	printf("Masukkan operasi: ");
	fflush(stdin);
	scanf("%s", &operasi);
	for (int i = 0; i < strlen(operasi); ++i)
	{
		if(operasi[i]=='(')
			push(&kurung, operasi[i]);
		else if(operasi[i]==')')
		{
			kebenaran = pop(&kurung);
			if(kebenaran=='X')
			{
				printf("Notasi infix salah, kurung tidak lengkap\n");
				return 0;
			}
		}
		else if(operasi[i]>='0' && operasi[i]<='9')
		{
			push(&operan, operasi[i]);
			pop(&operator);
		}
		else if(operasi[i]=='+' || operasi[i]=='-' || operasi[i]=='*' || operasi[i]=='/' || operasi[i]=='^')
		{
			push(&operator, operasi[i]);
			pop(&operan);
		}
	}

	pop(&operan);

	if(empty(&kurung)==1 && empty(&operan)==1 && empty(&operator)==1)
		printf("Notasi infix benar\n");
	else if(empty(&kurung)==0)
		printf("Notasi infix salah, kurung tidak lengkap\n");
	else if(empty(&operan)==0)
		printf("Notasi infix salah, operator tidak lengkap\n");
	else if(empty(&operator)==0)
		printf("Notasi infix salah, operan tidak lengkap\n");

	return 0;
}

void initialize(Stack *point)
{
	point->count=0;
}

int full(Stack *point)
{
	return (point->count==MAXSTACK);
}

int empty(Stack *point)
{
	return (point->count==0);
}

void push(Stack *point, ItemType x)
{
	if(full(point))
		printf("Stack penuh\n");
	else
	{
		point->item[point->count]=x;
		point->count++;
	}
}

ItemType pop(Stack *point)
{
	ItemType temp=' ';
	if(empty(point))
		return 'X';
	else
	{
		point->count--;
		temp=point->item[point->count];
	}
	return temp;
}