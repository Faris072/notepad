#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXSTACK 100

typedef char ItemType;
typedef struct
{
	char item[MAXSTACK];
	int count;
}
Stack;

typedef int tipe_item;
typedef struct
{
	tipe_item item[MAXSTACK];
	int count;
}
Tumpukan;

Stack tumpukan, operator;
Tumpukan operan;

void initialize(Stack *s);
void inisialisasi(Tumpukan *t);
int full(Stack *s);
int penuh(Tumpukan *t);
int empty(Stack *s);
int kosong(Tumpukan *t);
void push(Stack *s, ItemType x);
void taruh(Tumpukan *t, tipe_item x);
ItemType pop(Stack *s);
tipe_item ambil(Tumpukan *t);
int derajat(char x);
void konversi_cetak(char temp[]);

int main()
{
	char kontainer[MAXSTACK], jawab='y';
	printf("MENGUBAH NOTASI INFIX MENJADI POSTFIX\n");
	printf("DAN MENGHITUNG HASIL OPERASINYA\n");
	printf("DENGAN MEMANFAATKAN STRUKTUR STACK\n");

	while ((jawab=='Y') || (jawab=='y'))
	{
		initialize(&tumpukan);
		fflush(stdin);
		puts("");
		printf("Masukan operasi dalam notasi infix: ");
		fgets(kontainer, sizeof(kontainer), stdin);
		printf("Ungkapan postfixnya: ");
		konversi_cetak(kontainer);
		puts("");
		fflush(stdin);
		printf("\nMau mencoba lagi (y/t) ? ");
		scanf("%c", &jawab);
	} 

	return 0;
}

void initialize(Stack *s)
{
	s->count=0;
}

void inisialisasi(Tumpukan *t)
{
	t->count=0;
}

int full(Stack *s)
{
	return (s->count==MAXSTACK);
}

int penuh(Tumpukan *t)
{
	return (t->count==MAXSTACK);
}

int empty(Stack *s)
{
	return (s->count==0);
}

int kosong(Tumpukan *t)
{
	return (t->count==0);
}

void push(Stack *s, ItemType x)
{
	if(full(s))
		printf("Stack penuh! Data tidak dapat masuk\n");
	else
	{
		s->count++;
		s->item[s->count]=x;
	}
}

void taruh(Tumpukan *t, tipe_item x)
{
	if(penuh(t))
		printf("Stack penuh! Data tidak dapat masuk\n");
	else
	{
		t->count++;
		t->item[t->count]=x;
	}
}

ItemType pop(Stack *s)
{
	ItemType x;
	if(empty(s))
	{
		printf("Stack kosong!\n");
		return 0;
	}
	else
	{
		x=s->item[s->count];
		s->count--;
	}
	return x;
}

tipe_item ambil(Tumpukan *t)
{
	tipe_item x;
	if(kosong(t))
	{
		printf("Stack kosong!\n");
		return 0;
	}
	else
	{
		x=t->item[t->count];
		t->count--;
	}
	return x;
}

int derajat(char x)
{
	if(x=='(')
		return 0;
	else if((x=='+') || (x=='-'))
		return 1;
	else if((x=='*') || (x=='/'))
		return 2;
	else if(x=='^')
		return 3;
	else
		return -1;
}

void konversi_cetak(char temp[])
{
	int num1, num2, num3, length, valid=1;
	char kar, smtr;

	length=strlen(temp)-1;
	for (int i = 0; i < length; ++i)
	{
		kar = temp[i];
		if(kar=='(')
		{
			push(&tumpukan, kar);
			push(&operator, kar);
		}
		else if(kar>='0' && kar<='9')
		{
			printf("%c", kar);
			if(kar=='0')
				taruh(&operan, 0);
			else if(kar=='1')
				taruh(&operan, 1);
			else if(kar=='2')
				taruh(&operan, 2);
			else if(kar=='3')
				taruh(&operan, 3);
			else if(kar=='4')
				taruh(&operan, 4);
			else if(kar=='5')
				taruh(&operan, 5);
			else if(kar=='6')
				taruh(&operan, 6);
			else if(kar=='7')
				taruh(&operan, 7);
			else if(kar=='8')
				taruh(&operan, 8);
			else if(kar=='9')
				taruh(&operan, 9);
		}
		else if(kar=='+' || kar=='-' || kar=='*' || kar=='/' || kar=='^')
		{
			if((empty(&tumpukan)) || ((derajat(kar)>derajat(tumpukan.item[tumpukan.count]))))
			{
				push(&tumpukan, kar);
				push(&operator, kar);
			}
			else
			{
				while(derajat(kar)<=derajat(tumpukan.item[tumpukan.count]))
				{
					smtr=pop(&tumpukan);
					
					if(smtr=='^')
					{
						num2=ambil(&operan);
						num1=ambil(&operan);
						num3=pow(num1, num2);
						taruh(&operan, num3);
					}
					else if(smtr=='*')
					{
						num2=ambil(&operan);
						num1=ambil(&operan);
						num3=num1*num2;
						taruh(&operan, num3);
					}
					else if(smtr=='/')
					{
						num2=ambil(&operan);
						num1=ambil(&operan);
						num3=num1/num2;
						taruh(&operan, num3);
					}
					else if(smtr=='+')
					{
						num2=ambil(&operan);
						num1=ambil(&operan);
						num3=num1+num2;
						taruh(&operan, num3);
					}
					else if(smtr=='-')
					{
						num2=ambil(&operan);
						num1=ambil(&operan);
						num3=num1-num2;
						taruh(&operan, num3);
					}
					
					printf("%c", smtr);
				}
				push(&tumpukan, kar);
			}
		}
		else if(kar==')')
		{
			while(tumpukan.item[tumpukan.count] != '(')
			{
				smtr=pop(&tumpukan);
				if(smtr=='^')
				{
					num2=ambil(&operan);
					num1=ambil(&operan);
					num3=pow(num1, num2);
					taruh(&operan, num3);
				}
				else if(smtr=='*')
				{
					num2=ambil(&operan);
					num1=ambil(&operan);
					num3=num1*num2;
					taruh(&operan, num3);
				}
				else if(smtr=='/')
				{
					num2=ambil(&operan);
					num1=ambil(&operan);
					num3=num1/num2;
					taruh(&operan, num3);
				}
				else if(smtr=='+')
				{
					num2=ambil(&operan);
					num1=ambil(&operan);
					num3=num1+num2;
					taruh(&operan, num3);
				}
				else if(smtr=='-')
				{
					num2=ambil(&operan);
					num1=ambil(&operan);
					num3=num1-num2;
					taruh(&operan, num3);
				}
				printf("%c", smtr);
			}
			pop(&tumpukan);
		}
		else
		{
			valid = 0;
			puts("Invalid Statement!");
		}
	}

	while((valid!=0) && (!empty(&tumpukan)))
	{
		smtr = pop(&tumpukan);
		if(smtr=='^')
		{
			num2=ambil(&operan);
			num1=ambil(&operan);
			num3=pow(num1, num2);
			taruh(&operan, num3);
		}
		else if(smtr=='*')
		{
			num2=ambil(&operan);
			num1=ambil(&operan);
			num3=num1*num2;
			taruh(&operan, num3);
		}
		else if(smtr=='/')
		{
			num2=ambil(&operan);
			num1=ambil(&operan);
			num3=num1/num2;
			taruh(&operan, num3);
		}
		else if(smtr=='+')
		{
			num2=ambil(&operan);
			num1=ambil(&operan);
			num3=num1+num2;
			taruh(&operan, num3);
		}
		else if(smtr=='-')
		{
			num2=ambil(&operan);
			num1=ambil(&operan);
			num3=num1-num2;
			taruh(&operan, num3);
		}
		printf("%c", smtr);
	}
	printf("\nHasil: %d", ambil(&operan));
}