#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
	int data;
	struct node *next;
};

struct node *head = NULL;
struct node *last = NULL;

void addHead(int data)
{
	struct node *element;
	element = (struct node *)malloc(sizeof(struct node));
	element->data = data;
	element->next = head;
	head = element;
}

void addLast(int data)
{
	struct node *element;
	element = (struct node*)malloc(sizeof(struct node));
	element->data = data;
	element->next = NULL;

	if (head == NULL)
	{
		head = element;
	}
	else
	{
		last = head;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = element;
	}
}
void addToBetween(int n, int data)
{
	struct node *element;
	element = (struct node*)malloc(sizeof(struct node));
	element->data = data;
	last = head;
	while (last->next->data != n)
	{
		last = last->next;
	}
	struct node *last2;
	last2 = (struct node*)malloc(sizeof(struct node));
	last2 = last->next;
	last->next = element;
	element->next = last2;
}
void deleteFirst()
{
	if (head->next != NULL)
	{
		last = head->next;
		free(head);
		head = last;
	}
	else
	{
		free(head);
		head = NULL;
	}
}
void deleteLast()
{
	if (head->next != NULL)
	{
		last = head;
		while (last->next->next != NULL)
		{
			last = last->next;
		}
		free(last->next);
		last->next = NULL;
	}
	else
		deleteFirst();
}
void deleteInBetween(int data)
{
	last = head;
	if (last->data == data)
	{
		deleteFirst();
	}
	else
	{
		struct node * last2;
		last2 = (struct node * ) malloc (sizeof(struct node ));

		while (last->next->data!=data)
		{
			last = last->next;
		}

		if (last->next == NULL)
		{
			deleteLast();
		}
		last2 = last->next->next;
		free(last->next);
		last->next = last2;
	}
}
void reverse()
{
	struct node* prev = NULL;
	struct node* last2 = NULL;

	last = head;
	while (last != NULL)
	{

		last2 = last->next;
		last->next = prev;
		prev = last;
		last = last2;
	}
	head = prev;
}
int valueCount()
{
	int count = 0;
	if (head == NULL)
	{
		return count;
	}
	else
	{
		last = head;
		while (last->next != NULL)
		{
			count++;
			last = last->next;
		}
		count++;
		return count;
	}
}
int totalValues()
{
	int total = 0;
	if (head == NULL)
	{
		return total;
	}
	else
	{
		last = head;
		while (last->next != NULL)
		{
			total += last->data;
			last = last->next;
		}
		total += last->data;
		return total;
	}
}
void print()
{
	system("cls");
	if (head != NULL)
	{
		last = head;
		while (last->next != NULL)
		{
			printf(" %d -> ", last->data);
			last = last->next;
		}
		printf(" %d ", last->data);
	}
	else
	{
		printf("empty number !!!!!");
	}
}
int main() {
	int value;
	int count = 0;
	int choose;
	int n;
	while (6 == 6)
	{
		printf("\n\nAdd value into head :1\n");
		printf("Add value into last :2\n");
		printf("Add value into the between :3\n");
		printf("Deleting first value :4\n");
		printf("Deleting last value :5\n");
		printf("Deleting into the  between :6\n");
		printf("Reverse all value :7\n");
		printf("Count of values :8\n");
		printf("Sum of numbers :9\n");
		printf("\n   Your choose  :");
		scanf("%d",&choose);

		switch (choose)
		{
		case 1: printf("The value of the number add in head :");
			scanf("%d", &value);
			addHead(value);
			print();
			break;

		case 2: printf("The value of the number add in last :");
			scanf("%d", &value);
			addLast(value);
			print();
			break;
		case 3: printf("Before which number : ");
			scanf("%d", &n);
			printf("The value of the number add in between : ");
			scanf("%d", &value);
			addToBetween(n,value);
			print();
			break;
		case 4:
			deleteFirst();
			print();
			break;
		case 5:
			deleteLast();
			print();
			break;
		case 6:
			printf("The value of the number  deleting in between: ");
			scanf("%d", &value);
			deleteInBetween(value);
			print();
			break;
		case 7:
			printf("Numbers are reversed.. ");
			reverse();
			print();
			break;
		case 8:
			print();
			printf("\n\n Numbers Count :  %d",valueCount());
			break;
		case 9:
			print();
			printf("\n\n Sum of numbers :  %d", totalValues());
			break;
		case 0:
			return 0;
			break;
		}
}
		count++;
		return 0;
}
