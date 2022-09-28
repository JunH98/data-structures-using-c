//#include <stdio.h>
//#include "ListBaseStack.h"
//
//int ArrayBaseStackMain() {
//	//stack생성 및 초기화
//	Stack stack;
//	StackInit(&stack);
//
//	//push data
//	SPush(&stack, 1);
//	SPush(&stack, 2);
//	SPush(&stack, 3);
//	SPush(&stack, 4);
//	SPush(&stack, 5);
//
//	printf("%d\n", SPeek(&stack));
//
//	//pop data
//	while (!SIsEmpty(&stack))
//		printf("%d ", SPop(&stack));
//
//	return 0;
//}