#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*first=NULL,*second=NULL,*third=NULL;

void display(struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
int lengthh(struct node *p){
    int l=0;
    while(p!=NULL){
        l++;
        p=p->next;
    }
    return l;
}
void insert(struct node *p, int index, int x){
    struct node *t;
    int i;
    if(index<0|| index>lengthh(p)){
        return ;
    }
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;

    if(index == 0){
        t->next=first;
        first=t;
    }
    else{
        for(i=0;i<index-1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }

}
struct node *ILsearch(struct node *p,int key ){
    struct node *q;
    while(p!=NULL){
        if(key==p->data){
            q->next=p->next;
            p->next=first;
            first=p;
            return p;

        }
        q=p;
        p=p->next;
    }
}
void sortedinsert(struct node *p, int x){
    struct node *t,*q=NULL;

    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;

    if(first==NULL){
        first=t;
    }
    else{
        while(p!=NULL && p->data<x){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
    }
}
void delete(struct node *p, int index){
    struct node *t,*q;
    if(index==0){
        p=first;
        int x=p->data;
        first=first->next;
        free(p);
        printf("deleted element is %d\n",x);
    }
    else{
        for(int i=0;i<index;i++){
            q=p;
            p=p->next;
        }
        int x=p->data;
        q->next=p->next;
        free(p);
        printf("deleted element is %d\n",x);
    }
}
int checkifsort(struct node *p){
    int x=0;
    struct node *q;
    while(p!=NULL){
        if(p->data<x){
            return 0;
        }
        else{
            x=p->data;
            p=p->next;

        }
    }
    return 1;
}
void duplicate(struct node *p){
    struct node *q=p->next;
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
             p->next=q->next;
            free(q);
            q=p->next;

        }
       
    }
}
void reverse(struct node *p){
    struct node *q=NULL,*r=NULL;
    p=first;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
        
    }
    first=q;
}
void insertsecond(struct node *p, int index, int x){
    struct node *t;
    int i;
    if(index<0|| index>lengthh(p)){
        return ;
    }
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;

    if(index == 0){
        t->next=second;
        second=t;
    }
    else{
        for(i=0;i<index-1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}
void concat(struct node *p,struct node *q){
    third=p;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
    //q=NULL;
    //return p;
}
int main(){
    int ch;
    int index,x,key;
    struct node *temp;
    
    while(1){
        printf("\n");
        printf("\n1.insert\n");
        printf("\n2.search\n");
        printf("\n3.inserted sorted\n");
        printf("\n4.delete\n");
        printf("\n5.checkifsort\n");
        printf("\n6.remove duplicate\n");
        printf("\n7.reverse\n");
        printf("\n8.display\n");
       


        printf("\nenter your choice\n");
        scanf("%d",&ch);

        switch(ch){
            case 1: printf("enter the value \n");
                scanf("%d",&x);
                printf("enter the index\n");
                scanf("%d",&index);
                insert(first,index,x);
                display(first);
                break;


            case 2: printf("enter key\n");
                scanf("%d",&key);
                temp=ILsearch(first,key);
                if(temp){
                    printf("found element %d at address %d",temp->data,temp->next);
                }
                else{
                    printf("element not found");
                }
                break;

            case 3: printf("enter element\n");
                scanf("%d",&key);
                sortedinsert(first,key);
                display(first);
                break;
            case 4: printf("enter index\n");
                scanf("%d",&index);
                delete(first,index);
                display(first);
                break;

            case 5: printf("the vaulue returned %d",checkifsort(first));
                break;    

            case 6: printf("removed");
                    duplicate(first);
                    //display(first);
                    break;


            case 7: printf("reversed\n");
                    reverse(first);
                    display(first);
                    break;


            case 8: display(first);
                break;
        }
                    
    }
    return 0;
}