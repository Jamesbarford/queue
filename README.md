# FIFO Queue

A simple FIFO queue implemented as a form of circular linked list, aiming for a fast enqueue and dequeue speed.

## Usage

To create a `queue_t` instance call `create_queue`.

The queue can accept any pointer to store.

- `enqueue` Successful insertion returns `0`. Failure returns `-1`.
- `dequeue` will return the first inserted item or `NULL` if the queue is empty.

```c
#include "queue.h"

int main(void) {
	queue_t *queue = create_queue();

	int *array = (int *)malloc(sizeof(int) * 100);
	
	if (enqueue(queue, array) == -1) {
		// handle error case.
	}

	int *ptr = (int *)dequeue(queue);

	if (ptr != NULL) {
		// do something;
	}
}

```

## Tests

To run the tests:

```
mkdir build

make

./tests.out
```
