#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node{
	int new; // neue Zahl, die sich bei Multiplikation an dieser Stelle gemerkt werden muss
	int m; // Zahl an der jeweiligen Zehnerstelle
	struct node *next; //Pointer auf nächste Zehnerstelle
	struct node *before; //Pointer auf vorherige Zehnerstelle
} NCell;

int main() {
	long int n, input;
	printf("Bitte n eingeben: ");
	scanf("%ld", &n);
	input = n;
	NCell *q, *head, *man;

	/*INPUT*/
/*	do {
		q = (NCell *)malloc(sizeof(NCell));
		q->new = q->m = n % 10;
		n -= q->m;
		n /= 10;
		q->next = NULL;
		q->before = man;

		if(head == NULL) { head = q; man = q; }
		else { man->next = q; man = q;}
		//printf("%d\n", q->m);
	} while(n);
*/

//	printf("\n");

	head = (NCell *)malloc(sizeof(NCell));
	head->new = head->m = 1;
	head->before = head->next = NULL;

	man = head;

	/*CALCULATION*/
	int tmp, upadd=0, again=0;
	for(int i = 2; i <= input; i++) {
		man = head;
		do {
			again = 0;
			tmp = man->new;
			printf("tmp = %d\n", tmp);
			tmp = i * tmp + upadd;
			printf("tmp = %d\n", tmp);
			upadd = tmp - (tmp % 10);
			upadd /= 10;
			printf("upadd = %d\n", upadd);
			tmp %= 10;
			man->new = tmp;
			printf("new = %d\n", man->new);
			
			if(man->next == NULL) {
				printf("\nman->next = NULL\n");
				if(upadd > 0) {
					printf("upadd > 0\n");
					q = (NCell *)malloc(sizeof(NCell));
					q->m = 0;
					q->new = /*upadd % 1*/0;
					printf("q->new = %d\n", q->new);
					printf("upadd = %d\n", upadd);
					q->next = NULL;
					q->before = man;
					man = man->next = q; 
					printf("man->new = %d\n", man->new);
					printf("\n");
					again = 1;
				}
			}
			else if(man->next != NULL) { printf("not NULL\n"); man = man->next; }
			printf("\n");
		} while(man->next/* != NULL/* && man->next->new > -1*/ || again);
		printf("\nexit\n");		
	}
	switch(input) {
		case 1: man->new = 1; break;
		case 2: man->new = 2; break;
		default: break;
	}

	man = head;

	/*OUTPUT*/
	while(man->next != NULL) man = man->next;
	while(man != NULL) {
		printf("%d", man->new);
		man = man->before;
	}
	printf("\n");
}