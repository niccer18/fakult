#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int new; // neue Zahl, die sich bei Multiplikation an dieser Stelle gemerkt werden muss
	int m; // Zahl an der jeweiligen Zehnerstelle
	struct node *next; // Pointer auf nächste Zehnerstelle
	struct node *before; // Pointer auf vorherige Zehnerstelle
} NCell;

int main() {
	long int n, input;
	printf("Bitte n eingeben: ");
	scanf("%ld", &n);
	input = n;
	NCell *q, *head, *man;

	/*Initialisierung des Einerelements*/
	head = (NCell *)malloc(sizeof(NCell));
	head->new = head->m = 1;
	head->before = head->next = NULL;
	man = head;

	/*CALCULATION*/
	int tmp, upadd = 0, again = 0;
	for(int i = 2; i <= input; i++) {
		man = head;
		do {
			again = 0;
			tmp = man->new;
			tmp = i * tmp + upadd;
			upadd = (tmp - (tmp % 10)) / 10;
			//upadd /= 10;
			tmp %= 10;
			man->new = tmp;
			
			if(man->next == NULL) {
				if(upadd > 0) {
					/*Erstellung eines zusätzlichen Elements bei Bedarf*/
					q = (NCell *)malloc(sizeof(NCell));
					q->m = 0;
					q->new = 0;
					q->next = NULL;
					q->before = man;
					man = man->next = q;
					again = 1;
				}
			}
			else { man = man->next; again++; }
		} while(again);
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