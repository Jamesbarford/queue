#ifndef QUEUE_H
#define QUEUE_H

typedef struct qnode_t {
	void *q_obj;
	struct qnode_t *next;
} qnode_t;

typedef struct queue_t {
	int count;
	struct qnode_t *next;
	struct qnode_t *prev;
} queue_t;

queue_t *create_queue();

/**
 * Returns 0 if the `void *q_obj` was placed on the queue -1 on failure
 */
int enqueue(queue_t *queue, void *q_obj);

/**
 * Returns generic pointer to stored data or NULL if the queue is empty
 */
void *dequeue(queue_t *queue);

#endif
