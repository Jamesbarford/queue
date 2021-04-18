/**
 * Very simple FIFO queue implemented as a circular linked list able to store any value
 */

#include <stdlib.h>
#include <stdio.h>

#include "queue.h"

queue_t *create_queue() {
	queue_t *queue;

	if ((queue = (queue_t *)malloc(sizeof(queue_t))) == NULL)
		return NULL;

	queue->next = NULL;
	queue->prev = NULL;
	queue->count = 0;

	return queue;
}

int enqueue(queue_t *queue, void *q_obj) {
	qnode_t *qnode;

	if ((qnode = (qnode_t *)malloc(sizeof(qnode_t))) == NULL)
		return -1; // failed to allocate;

	qnode->q_obj = q_obj;

	if (queue->next == NULL) {
		queue->next = qnode;
		queue->prev = qnode;
		qnode->next = queue->prev;
	} else {
		queue->prev->next = qnode;
		qnode->next = queue->prev;
		// put on the back of the queue
		queue->prev = qnode;
	}

	queue->count++;

	return 0;
}

void *dequeue(queue_t *queue) {
	if (queue->next == NULL) return NULL;

	void *retval = queue->next->q_obj;
	qnode_t *tmp = queue->next;

	queue->next = queue->next->next;

	if (tmp)
		(void)free(tmp);

	queue->count--;
	
	if (queue->count == 0) {
		queue->next = NULL;
		queue->prev = NULL;
	}

	return retval;
}

