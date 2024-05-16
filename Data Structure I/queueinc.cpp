// Implementation of QUEUE data structure
#include<bits/stdc++.h>
using namespace std;
#define MX_size 5

int items[MX_size], front = -1, rear = -1;
void enQueue(int value) {
  if (rear == MX_size - 1)
    printf("\nQueue is Full!!");
  else {
    if (front == -1)
      front = 0;
    // rear++;
    items[++rear] = value;
    printf("Inserted -> %d\n", value);
  }
}

void deQueue() {
  if (front == -1)
    printf("\nQueue is Empty!!");
  else {
    printf("\nDeleted : %d", items[front]);
    front++;
    if (front > rear)
      front = rear = -1;
  }
}

void print() {
  if (rear == -1)
    printf("\nQueue is Empty!!!");
  else {
    int i;
    printf("\nQueue elements are:\n");
    for (i = front; i <= rear; i++)
      printf("%d  ", items[i]);
  }
  printf("\n");
}

int main() {

  	int arr[5] = {4, 7, 9, 2, 6};
	for (int i = 0; i < 5; ++i)
	{
		enQueue(arr[i]);
	}
	enQueue(10);
  print();
  //remove an element from the queue
  deQueue();
  //print the queue
  print();

  return 0;
}