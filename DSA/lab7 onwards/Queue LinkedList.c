#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * next;
};
struct Node * head=NULL;
int size,count=0;
void enqueue(int data){
    if(size==count){
        printf("\nQueue is full.");
    }
    else{
        struct Node * current=(struct Node *)malloc(sizeof(struct Node));
        current->data=data;
        if(head==NULL){
            head=current;
        }
        else{
            struct Node * temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=current;
        }
        count++;
    }
}
int dequeue(){
    if(head==NULL){
        printf("\nQueue is empty.");
    }
    else{
        int d=head->data;
        head=head->next;
        count--;
        return d;
    }
}
void display(){
    struct Node * current=head;
    printf("\n[");
    while(current!=NULL){
        printf("%d, ",current->data);
        current=current->next;
    }
    printf("]");
}
void main(){
    size=5;
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    dequeue();
    enqueue(6);
    display();
}
