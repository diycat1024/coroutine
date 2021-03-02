#include "coroutine.h"
#include <stdio.h>

#include <sys/types.h>

struct args {
	int n;
};
void product(struct schedule *S)
{
	int i = 999999;
	while (i>0)
	{
		coroutine_yield(S, &i);
		i++;
	}
}

void consumer(struct schedule *S, int co)
{
	while (coroutine_status(S,co)) {
		int i = *(int *)coroutine_resume(S,co);
		printf("get int %d\n", i);
	} 
	printf("stop consumer\n");
}


// int64_t dg(size_t n)
// {
// 	int64_t avg = 1;
// 	for (size_t i = 0; i < n; i++)
// 	{
// 		avg *= 2;
// 	}
// 	return avg;
// }

int 
main() {
	// int64_t n = dg(32);
	// printf("%lld\n",n);
	struct schedule * S = coroutine_open();
	struct args arg1 = { 0 };
	int co = coroutine_new(S, product, &arg1);
	printf("co: %d\n", co);
	consumer(S, co);
	coroutine_close(S);
	
	return 0;
}