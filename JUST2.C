#include<stdio.h>
#include<conio.h>
static int count1=0, count2=0, count3=0;
struct node {
	int priority;
	int data;
	struct node *next;
}*f1=NULL,*f2=NULL,*f3=NULL,*r1=NULL,*r2=NULL,*r3=NULL;
void enqueue() {
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter data: ");
	scanf("%d",&new_node->data);
	printf("\nEnter priority(1, 2 or 3): ");
	scanf("%d",&new_node->priority);
	if(new_node->priority==1 && count1>=3) {
		new_node->priority = 2;
	}

	if(new_node->priority==2 && count2>=2) {
		new_node->priority = 3;
	}

	if(new_node->priority==3 && count3>=1) {
		printf("\nQueue Overflow");
		return;
	}

	if(new_node->priority==1) {
		if(f1==NULL) {
			f1 = new_node;
			r1 = new_node;
		} else {
			r1->next=new_node;
			r1=new_node;
		}

		if(f2!=NULL) {
			r1->next=f2;
		} else if(f3!=NULL) {
			r1->next=f3;
		} else {
			r1->next=NULL;
		}
		count1++;
	} else if(new_node->priority==2) {
	       if(f2==NULL) {
			f2 = new_node;
			r2 = new_node;
	       } else {
			r2->next=new_node;
			r2=new_node;
	       }

	       if(r1!=NULL) {
			r1->next=f2;
	       }
	       if(f3!=NULL) {
			r2->next=f3;
	       } else {
			r2->next=NULL;
	       }
	       count2++;
	} else {
		if(f3==NULL) {
			f3 = new_node;
			r3 = new_node;
		} else {
			r3->next=new_node;
			r3=new_node;
		}
		if(r2!=NULL) {
			r2->next=f3;
		} else if(r1!=NULL) {
			r1->next=f3;
		}
		r3->next=NULL;
		count3++;
	}
}
void dequeue() {
	if(count1!=0) {
		if(count1>1) {
			f1 = f1->next;
			count1--;
		} else if(count1==1) {
			f1=NULL;
			r1=NULL;
			count1--;
		}
	} else if(count2!=0) {
		if(count2>1) {
			f2 = f2->next;
			count2--;
		} else if(count2==1) {
			f2=NULL;
			r2=NULL;
			count2--;
		}
	} else if(count3!=0) {
		f3=NULL;
		r3=NULL;
		count3--;
	} else {
		printf("\nQueue Underflow");
	}
}
void display() {
	struct node *p;
	if(f1!=NULL) {
		p=f1;
	} else if(f2!=NULL) {
		p=f2;
	} else if(f3!=NULL) {
		p=f3;
	} else {
		printf("\nQueue Underflow");
		return;
	}
	for(;p!=NULL;p=p->next) {
		printf("\n%d",p->data);
	}
}
void main() {
	int x = 0;
	while(x!=4) {
		printf("\nMENU\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
		printf("\nEnter your choice: ");
		scanf("%d",&x);
		switch(x) {
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				break;
			default:
				printf("\nWRONG CHOICE");
				break;
		}
	}
	getch();
}