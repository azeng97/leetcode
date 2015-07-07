typedef struct {
	int max;
    int size;
    int min;
    int contents[max];
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
    struct MinStack* stack = malloc(sizeof(MinStack));
    assert (stack!=NULL);
    stack->size = 0;
    stack->max = maxSize;
}

void minStackPush(MinStack *stack, int element) {
    assert ((stack!=NULL) && (stack->size<=stack->max));
    stack->contents[stack->size] = element;
    stack->size++;
}

void minStackPop(MinStack *stack) {
    assert ((stack!=NULL) && (stack->size>0));
    stack->size--;
}

int minStackTop(MinStack *stack) {
    assert ((stack!=NULL) && (stack->size>0));
    return stack->contents[stack->size-1];
}

int minStackGetMin(MinStack *stack) {
	int x = 0;
	int min = stack->contents[0];
	while (x<stack->size){
		if (stack->contents[x]<min){
			min = stack->contents[x];
		}
		x++;
	}
    return min;
}

void minStackDestroy(MinStack *stack) {
    assert (stack!=NULL);
    free(stack);
}