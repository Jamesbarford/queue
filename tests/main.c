#include <stdio.h>
#include <stdlib.h>

#include "../queue.h"

#define PASS 1
#define FAIL 0

void debug(void *i, char *msg) {
	printf("%s: %d\n", msg, (*(int *)i));
}

void walk_q(queue_t *q) {
	qnode_t *start = q->prev;
	qnode_t *n = q->next;

	if (start == NULL || n == NULL)
		return;

	while (n != start) {
		debug(n->q_obj, "n");
		n = n->next;
	}
}

int run_test(char *name, int(*test_func)(void)) {
	int passed = test_func();
	if (passed) {
		printf("PASSED:   %s\n", name);
	} else {
		printf("!FAILED:   %s\n", name);
	}

	return passed;
}

int should_enqueue() {
	queue_t *queue = create_queue();
	int *p = malloc(sizeof(int));
	*p = 6;
	
	if (enqueue(queue, p) == -1) {
		(void)free(p);
		return FAIL;
	}

	(void)free(p);
	return PASS;
}

int should_return_correct_item() {
	queue_t *queue = create_queue();

	int retval = PASS;
	int *p_1 = (int *)malloc(sizeof(int));
	*p_1 = 1;

	int *p_2 = (int *)malloc(sizeof(int));
	*p_2 = 2;

	int *p_3 = (int *)malloc(sizeof(int));
	*p_3 = 3;

	int *p_4 = (int *)malloc(sizeof(int));
	*p_4 = 4;

	enqueue(queue, (void *)p_1);
	enqueue(queue, (void *)p_2);
	enqueue(queue, (void *)p_3);
	enqueue(queue, (void *)p_4);

	int *r_1 = ((int *)dequeue(queue));
	if (r_1 != p_1)
		retval = FAIL;

	int *r_2 = ((int *)dequeue(queue));
	if (r_2 != p_2)
		retval = FAIL;
	
	int *r_3 = ((int *)dequeue(queue));
	if (r_3 != p_3)
		retval = FAIL;
	
	int *r_4 = ((int *)dequeue(queue));
	if (r_4 != p_4)
		retval = FAIL;

	dequeue(queue);
	dequeue(queue);
	dequeue(queue);
	dequeue(queue);

	(void)free(r_1);
	(void)free(r_2);
	(void)free(r_3);
	(void)free(r_4);
	return retval;
}

int main(void) {
	int passed = 0;

	passed += run_test("Should enqueue", should_enqueue);
	passed += run_test("Should return correct item", should_return_correct_item);

	printf("Passed: %d/%d\n", passed, 2);
}
