/*
Question: Write a C program to add two given polynomials using linked list.
Instructions: Addition of two given polynomials using Single Linked List
              Polynomial -1     4X3+2X+1
              Polynomial-2      3X3+3X2+2
              ------------------------------
              Sum              7X3+3X2+2X+3
              input
              3     ------No.of Terms in the First Polynomial
              4 3   ---- Term-1 for 4X3  4 is coefficient, 3 is exponent
              2 1   ---- Term-2  for 2X  2 is coefficient,1 is exponent
              1 0   ---- Term-3  for 1   1 is coefficient, 0 is exponent 
              3 ------ No.of Terms in the second polynomial
              3 3 -- Term-1  3X3   3 is coefficient, 3 is exponent
              3 2  -- Term-2  3X2  3 is coefficient, 2 is exponent
              2 0 -- Term-3   2   2 is coefficient, 0 is exponent
              
              output
              7X^3+3X^2+2X+3
*/

//My Approach/Solution:
#include <stdio.h> 
#include <stdlib.h>

struct node
{
    int coef,expo;
    struct node* next;
};

struct node* insertpoly(struct node* thead,int c,int e)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coef=c;
    newnode->expo=e;
    if(thead==NULL)
    {           
        newnode->next=NULL;
        return newnode;
    }
    struct node* prev,* curr;
    prev=curr=thead;
    while(curr!=NULL && curr->expo>e){
        prev=curr;
        curr=curr->next;
    }
    if(curr==thead)
    {            
        newnode->next=curr;
        return newnode;
    }
    else if(curr==NULL)
    {  
        prev->next=newnode;
        newnode->next=NULL;
    }
    else{
        newnode->next=curr;
        prev->next=newnode;
    }
    return thead;
}

struct node* append(struct node* thead,int c,int e)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coef=c;
    newnode->expo=e;
    if(thead==NULL)
    {
        newnode->next=NULL;
        return newnode;
    }
    struct node* trav=thead;
    while(trav->next!=NULL)
        trav=trav->next;
    trav->next=newnode;
    newnode->next=NULL;
    return thead;
}

struct node* polyaddition(struct node* p1thead,struct node* p2thead)
{
    struct node* ans=NULL;
    struct node* t1,* t2;
    t1=p1thead;
    t2=p2thead;
    while(t1!=NULL && t2!=NULL){
        if(t1->expo > t2->expo){
            ans=append(ans,t1->coef,t1->expo);
            t1=t1->next;
        }
        else if(t1->expo < t2->expo){
            ans=append(ans,t2->coef,t2->expo);
            t2=t2->next;
        }
        else{
            ans=append(ans,(t1->coef)+(t2->coef),t1->expo);
            t1=t1->next;
            t2=t2->next;
        }
    }

    while(t1!=NULL)
    {   
        ans=append(ans,t1->coef,t1->expo);
        t1=t1->next;
    }

    while(t2!=NULL)
    { 
        ans=append(ans,t2->coef,t2->expo);
        t2=t2->next;
    }
    return ans;
}

void display(struct node* thead)
{
    //printf ("\nThe final added polynomial is: ");
    struct node* temp=thead;
    if(temp==NULL){
        printf("\nEmpty..");
    }
    else{
        while(temp->next!=NULL){
            if(temp->coef == 0);
            else if(temp->coef == 1 && temp->expo == 1)
                printf("X+");
            else if(temp->coef == 1 && temp->expo != 0 && temp->expo != 1)
                printf("X^%d+",temp->expo);
            else if( temp->expo == 1)
                printf("%dX+",temp->coef);
            else
            printf("%dX^%d+",temp->coef,temp->expo);
            temp=temp->next;
        }
        if(temp->coef == 0);
        else if(temp->coef == 1 && temp->expo == 1)
            printf("X");
        else if(temp->coef == 1 && temp->expo != 0 && temp->expo != 1)
            printf("X^%d",temp->expo);
        else if( temp->expo == 0)
            printf("%d",temp->coef);
        else if( temp->expo == 1)
            printf("%dX",temp->coef);
        else
        printf("%dX^%d",temp->coef,temp->expo);
    }
}

int main() {
    int a,b,n,i;
    struct node* p1head,* p2head,* p3head;
    p1head=p2head=NULL;

    //printf ("Enter Number of Terms in First Polynomial: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        //printf ("Coefficient ");
        scanf("%d",&a);
        //printf ("Exponent ");
        scanf("%d",&b);
        p1head=insertpoly(p1head,a,b);
    }

    //printf ("Enter Number of Terms in Second Polynomial: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        //printf ("Coefficient ");
        scanf("%d",&a);
        //printf ("Exponent ");
        scanf("%d",&b);
        p2head=insertpoly(p2head,a,b);
    }
    
    p3head=polyaddition(p1head,p2head);

    display(p3head);
    
    return 0;
}
