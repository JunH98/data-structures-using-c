//#include <stdio.h>
//
//int ISearch(int ar[], int first, int last, int target) {
//	int mid;
//
//	if (first > last)
//		return -1;
//
//	mid = ((double)(target - ar[first]) / 
//			(ar[last] - ar[first]) * (last - first)) + first;
//
//	if(ar[first]>target || ar[last] < target){
//		return -1;
//	}
//
//	else if (target < ar[mid])
//		return ISearch(ar, first, mid - 1, target);
//	else
//		return ISearch(ar, mid + 1, last, target);
//}
//
//int InterpolMain() {
//	int arr[] = { 1,3,5,7,9 };
//	int idx;
//
//	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 2);
//
//	if (idx == -1) {
//		printf("failed search");
//	}
//	else
//		printf("target saved index : %d\n", idx);
//
//}