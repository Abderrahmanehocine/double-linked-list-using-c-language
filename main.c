#include <stdio.h>
#include <stdlib.h>
#define sd struct node

/*--------------------
  | * |          | * |
  |pre|   DATA   |nex|
  | v |          | t |
  --------------------
         NODE        */
  /* 
    the definition of the node in the 
 */
struct node{
  char name[40];       
  int age;
  sd *next,*prev;
};

int main() {
 sd *head; // head=the first node adress of the linked list
 sd *temp; // temp pointer to work with in the linked list
 sd *rev;  // rev=the last node adress of the linked list
 head=(sd*)malloc(sizeof(sd)); //allocate the first node in the memory
 head->prev=NULL; // prev of the first node=NULL
 temp=head; //give temp the first node adress
 int num; // number of students
 printf("Enter number of student: ");
 scanf("%d",&num);
 printf("\n");
 for(int i=0 ; i<num ; i++){
   printf("Student number %d\n",i+1);
   printf("Name: ");
   scanf("\n");
   scanf("%[^\n]",temp->name);
   printf("Age: ");
   scanf("%d",&temp->age);
   if(i!=num-1){
     temp->next=(sd*)malloc(sizeof(sd)); //allocate another node in the memory
     temp->next->prev=temp; //prev of the next node=the adress of the previous node 
     temp=temp->next;//temp take the adress of the next node
    }
   if(i==num-1){
     temp->next=NULL; //next of last node=NULL
   }
   printf("\n");
 } //end for
 temp=head; //temp take the first node adress
 printf("-------------\n");
 // print data from the first node to the last 
 while(temp!=NULL){
   printf("Name: %s\n",temp->name);
   printf("Age: %d\n",temp->age);
   printf("-------------\n");
   if(temp->next==NULL){
     rev=temp; // rev take the adress of the last node 
    }
   temp=temp->next;//temp take the adress of the next node
 }
 printf("\n\n");
 //print data from the last node to the first node
 while(rev!=NULL){
   printf("Name: %s\n",rev->name);
   printf("Age: %d\n",rev->age);
   printf("-------------\n");
   rev=rev->prev;//rev take the adress of the previous node
 }
}
