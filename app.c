#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

typedef struct PCB
{
	int procId;
	int cpuBurst;
	int waitingTime;
	struct PCB *next,*prev;
}pcb;

int main()
{
	pcb *head = (pcb *) malloc(sizeof(pcb));
	head->prev = head->next = NULL;
	int n,i=1,wait=0;
	float sum=0.0f;
	pcb *pre = (pcb *) malloc(sizeof(pcb));
	printf("Enter number of processes :");
	scanf("%d",&n);
	printf("Enter procId :");
	scanf("%d",&(head->procId));
	printf("Enter cpuBurst :");
	scanf("%d",&(head->cpuBurst));
	pre = head;
	for(;i<n;i++)
	{
		pcb *temp = (pcb *) malloc(sizeof(pcb));
		temp->prev = temp->next = NULL;
		printf("Enter procId :");
		scanf("%d",&(temp->procId));
		printf("Enter cpuBurst :");
		scanf("%d",&(temp->cpuBurst));
		pre->next = temp;
		temp->prev = pre;
		pre = temp;
	}
	pre = head;
	for(i=0;i<n;i++)
	{
		pre->waitingTime = wait;
		sum += wait;
		wait += pre->cpuBurst;
		pre = pre->next;
	}
	pre = head;
	for(i=0;i<n;i++)
	{
		printf("Waiting time of process %d is %d\n",pre->procId,pre->waitingTime);
		pre = pre->next;
	}
	printf("The average waiting time is %f\n",sum/n);
}
