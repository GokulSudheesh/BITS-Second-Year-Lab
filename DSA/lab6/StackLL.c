#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};
struct Node *head = NULL;
int size, count = 0;
void push (int data)
{
  if (size == count)
    {
      printf ("Stack is full");
    }
  else
    {
      struct Node *current = (struct Node *) malloc (sizeof (struct Node));
      current->data = data;
      if (head == NULL)
	{
	  head = current;
	}
      else
	{
	  current->next = head;
	  head = current;
	}
      count++;
    }
}

int pop ()
{
  if (head == NULL)
    {
      printf ("\nStack is empty");
    }
  else
    {
      int d = head->data;
      head = head->next;
      count--;
      return d;
    }
}

void display ()
{
  struct Node *current = head;
  printf ("\n[");
  while (current != NULL)
    {
      printf ("%d, ", current->data);
      current = current->next;
    }
  printf ("]");
}

void main ()
{
  size = 5;
  push (1);
  push (2);
  push (3);
  push (4);
  push (5);
  pop ();
  push (6);
  display ();
}
