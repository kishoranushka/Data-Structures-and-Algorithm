#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node* next;
};

struct node* head = NULL;

void append(int val);
void printList();
void insertbyPosition(int val, int pos);
void insertafterval(int val, int newNodeVal);
void insertbeforeval(int val, int newNodeVal);
void reverselist();
void Delete(int pos);

int main() {
    int choice;
    while (1) {
        printf("\nEnter your choice:\n 1) Append a value\n 2) Traverse\n 3)Insert by position\n 4)Insert after value\n 5)Insert before value\n 6)Reverse linked list\n 7)Delete linked list by position\n 8)Exit\n ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            int val;
            printf("Enter the value to append: ");
            scanf("%d", &val);
            append(val);
            break;
        }

        case 2: printList();
        break;

        case 3: {
          int val, pos;
          printf("Enter the value to be inserted: ");
          scanf("%d",&val);
          printf("Enter the position: ");
          scanf("%d",&pos);
          insertbyPosition(val, pos);
        break;
        }

        case 4:{
          int val,newNodeVal;
          printf("Enter the value after which the node is to be inserted: ");
          scanf("%d",&val);
          printf("Enter the node value: ");
          scanf("%d",&newNodeVal);
          insertafterval(val, newNodeVal);
          // printf("This is insert by value code.");
          break;
        }
        case 5:{
          int val,newNodeVal;
          printf("Enter the value before which the node is to be inserted: ");
          scanf("%d",&val);
          printf("Enter the node value: ");
          scanf("%d",&newNodeVal);
          insertbeforeval(val, newNodeVal);
          // printf("This is insert by value code.");
          break;
        }

        case 6: 
          reverselist();
          break;

        case 7:{
          int pos;
          printf("Enter the position to be deleted: ");
          scanf("%d",&pos);
          Delete( pos);
          break;
        }

        case 8:
            exit(0);

        default:
            printf("Enter a valid choice.\n");
        }
    }

    return 0;
}

void append(int val) {
    struct node* q = (struct node*)malloc(sizeof(struct node));
    q->val = val;
    q->next = NULL;

    if (!head) {
        head = q;
    }
    else {
        struct node* p = head;
        while (p->next) {
            p = p->next;
        }
        p->next = q;
    }
}

void printList() {
    printf("List: ");
    struct node* p = head;
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    if(!head){
      printf("Linked list doesn't exist.");
    }
    printf("\n\n");
}

void insertbyPosition(int val, int pos) {
    struct node* p = head;
    struct node* q = (struct node*)malloc(sizeof(struct node));
    q->val = val;

    int count = 1;

    if (!head) {
        q->next = NULL;
        head = q;
        return;
    }

    if (pos == 1) {
        q->next = head;
        head = q;
        return;
    }

    while (p && count < pos - 1) {
        p = p->next;
        count++;
    }

    if (p == NULL) {
        printf("Position out of bounds.\n");
        free(q);
        return;
    }

    q->next = p->next;
    p->next = q;
}

void insertafterval(int val, int newNodeVal){
  struct node* p = head;
    struct node* q = (struct node*)malloc(sizeof(struct node));
    q->val = newNodeVal;

    if(!head){
      q->next=NULL;
      head=q;
      return;
    }

    while(p!=NULL && (p->val)!=val){
      p=p->next;
    
    }
    if(p==NULL){
      printf("Node not found.");
      return;
    }
    
      q->next=p->next;
      p->next=q;
    


}

void insertbeforeval(int val, int newNodeVal){
  struct node* p = head;
    struct node* q = (struct node*)malloc(sizeof(struct node));
    q->val = newNodeVal;

    if(!head){
      q->next=NULL;
      head=q;
      return;
    }

    while((p->next)!=NULL && (p->next->val)!= val ){
      p=p->next;

    }

    if(p->next==NULL){
      printf("Node not found.");
      return;
    }

    q->next=p->next;
    p->next=q;

}

void reverselist(){
  struct node *prev=NULL, *curr=head, *next=NULL;
  if(!head){
    printf("Linked list doesn't exist.\n");
    return;
  }

  if((curr->next)==NULL){
    printf("Only one node exist\n List: %d\n",curr->val);
    return;
  }


  while(curr!=NULL){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
  }

  head =prev;
  printf("Traverse the list to see the output: \n");
}

void Delete(int pos){
  struct node *p=head;

  if(!head){
    printf("\nLinked list doesn't exist.\n");
    return;
  }
  if(pos==1&&(p->next)==NULL){
    head=NULL;
    return;
  }

  if(pos==1&&(p->next)!=NULL){
    head=p->next;
    return;
  }
int count=2;
while(count<pos && (p->next)!=NULL){
  p=p->next;
  count++;
}


if(p->next->next==NULL && count<pos){
  p->next=NULL;
  return;
}
p->next=p->next->next;


}