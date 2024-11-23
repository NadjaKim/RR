#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
	int id;
	int time_for_job;
	Process* next;
}process;

process* read_all_process(int n) {
	int a = 0, b = 0;
	scanf("%d %d ", &a, &b);
	process* first = (process*)malloc(sizeof(process));
	process* prev = NULL, * curr = NULL;
	first->id = a;
	first->time_for_job = b;
	first->next = NULL;
	prev = first;
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		curr = (process*)malloc(sizeof(process));
		curr->id = a;
		curr->time_for_job = b;
		curr->next = NULL;
		prev->next = curr;
		prev = curr;
	}
	prev->next = first;
	return first;
}

void execute(int quant, process** first) {
	process* curr = NULL, *prev = NULL;
	curr = (*first), prev = (*first);
	while (prev->next != (*first)) prev = prev->next;
	while (curr->next != curr) {
		bool flag = false; //bilo li udaleniye
		for (int i = 0; i < quant; i++) {
			(curr->time_for_job)--;
			if (!curr->time_for_job) {
				printf("%d\n", curr->id);
				process* temp = curr;
				curr = curr->next;
				temp->next = NULL;
				prev->next = curr;
				free(temp);
				flag = true;
			}
		}
		if (!flag) {
			prev = prev->next;
			curr = curr->next;
		}
	}
	printf("%d\n", curr->id);
	curr->next = NULL;
	free(curr);
}

int main() {
	int n = 0, quant = 0;
	scanf("%d %d ", &n, &quant);
	process* first, * prev = NULL, * curr = NULL;
	first = read_all_process(n);
	curr = first;
	execute(quant, &first);
	return 0;
}