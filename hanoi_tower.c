#include <stdio.h>

#define MAX 100

struct stack {
	int disk[MAX];
	int top;
} x, y, z;

int count = 0;

void pr_stack(struct stack *s)
{
	int i;

	for (i = 0; i < s->top; ++i)
		printf("%3d", s->disk[i]);
	putchar('\n');
}

void push(struct stack *s, int n)
{
	s->disk[s->top++] = n;
}

int pop(struct stack *s)
{
	return s->disk[--s->top];
}

void move(struct stack *from, struct stack *to)
{
	/* move the disk on the top of 'from' to 'to' */
	push(to, pop(from));
	++count;

	printf("-------------------------------\n");
	printf("rod1:");
	pr_stack(&x);
	printf("rod2:");
	pr_stack(&y);
	printf("rod3:");
	pr_stack(&z);
}

void init_hanoi(int n, struct stack *x)
{
	for ( ; n > 0; --n)
		push(x, n);
}

void hanoi(int n, struct stack *from, struct stack *mid, struct stack *to)
{
	/* move n disks form x to z, mid can be used as an auxiliary rod */
	if (n == 1) {
		move(from, to);
	} else {
		hanoi(n - 1, from, to, mid);
		move(from, to);
		hanoi(n - 1, mid, from, to);
	}
}

int main(void)
{
	int n;

	printf("Input n: ");
	scanf("%d", &n);
	init_hanoi(n, &x);
	hanoi(n, &x, &y, &z);
	printf("\nAll steps: %d\n", count);

	return 0;
}
