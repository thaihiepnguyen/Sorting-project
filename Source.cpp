#include "Header.h"
#include <cstring>
using namespace std;

int main(int argc, char* argv[]) {
	int n = -1;
	int* a=NULL;
	int input_order = -1;
	double count_compare = 0;
	double time_taken = 0;
	//    cmp and time for cmd 4 vs 5:
	double count_compare4 = 0;
	double time_taken4 = 0;
	double count_compare5 = 0;
	double time_taken5 = 0;
	if (strcmp(argv[1], "-a") == 0 && argc == 6) //Command 2
	{
		n = atoi(argv[3]);	//Data size
		a = new int[n];
		if (strcmp(argv[4], "-rand") == 0) input_order = 0;		//Randomized data
		if (strcmp(argv[4], "-sorted") == 0) input_order = 1;	//Sorted data
		if (strcmp(argv[4], "-rev") == 0) input_order = 2;		//Reverse data
		if (strcmp(argv[4], "-nsorted") == 0) input_order = 3;	//Nearly Sorted data
		GenerateData(a, n, input_order);	
		writeFile(a, n, "input.txt");	//Write generated input
	}
	int check = atoi(argv[3]);	//Check the diferent between command 1 and command 3
	if (strcmp(argv[1], "-a") == 0 && argc == 5 && check == 0) // check==0 is command 1
	{
		if (readFile(a, n, argv[3]) == false) {	//Read generated input
			cout << "File not exist!";
			return -1;
		}
	}
	if (strcmp(argv[1], "-a") == 0 && argc == 5 && check != 0)// check!=0 is command 3 then check is data size
	{
		n = check;	
		a = new int[n];
	}
	if (strcmp(argv[1], "-a") == 0)	//Different bettween command 1, 2, 3 and command 4, 5
	{
		if (argc == 6) //Command 2
		{
			if (strcmp(argv[2], "selection-sort") == 0)
			{
				if (strcmp(argv[5], "-time") == 0)
					SelectionSort_time(a, n, time_taken);
				if (strcmp(argv[5], "-comp") == 0)
					SelectionSort_comp(a, n, count_compare);
				if (strcmp(argv[5], "-both") == 0) {
					int* b = new int[n];
					memcpy(b, a, n * sizeof(int));
					SelectionSort_time(a, n, time_taken);
					SelectionSort_comp(b, n, count_compare);
					delete[]b;
				}
			}
			if (strcmp(argv[2], "quick-sort") == 0)
			{
				count_compare = 0;
				time_taken = 0;
				if (strcmp(argv[5], "-time") == 0)
					quickSort_time(a, 0, n - 1, time_taken);
				if (strcmp(argv[5], "-comp") == 0)
				{
					count_compare = 0;
					quickSort_comp(a, 0, n - 1, count_compare);
				}
				if (strcmp(argv[5], "-both") == 0) {
					count_compare = 0;
					int* b = new int[n];
					memcpy(b, a, n * sizeof(int));
					quickSort_time(a, 0, n - 1, time_taken);
					quickSort_comp(b, 0, n - 1, count_compare);
					delete[]b;
				}
			}
			if (strcmp(argv[2], "counting-sort") == 0) {
				if (strcmp(argv[5], "-time") == 0)
					countingSort_time(a, n, time_taken);
				if (strcmp(argv[5], "-comp") == 0)
					countingSort_comp(a, n, count_compare);
				if (strcmp(argv[5], "-both") == 0) {
					int* b = new int[n];
					memcpy(b, a, n * sizeof(int));
					countingSort_time(a, n, time_taken);
					countingSort_comp(b, n, count_compare);
					delete[]b;
				}
			}
			if (strcmp(argv[2], "insertion-sort") == 0) {
				if (strcmp(argv[5], "-time") == 0)
					insertionSortTimeTaken(a, n, time_taken);
				if (strcmp(argv[5], "-comp") == 0)
					insertionSortCountCompare(a, n, count_compare);
				if (strcmp(argv[5], "-both") == 0) {
					int* b = new int[n];
					memcpy(b, a, n * sizeof(int));
					insertionSortTimeTaken(a, n, time_taken);
					insertionSortCountCompare(b, n, count_compare);
					delete[]b;
				}
			}
			if (strcmp(argv[2], "heap-sort") == 0) {
				if (strcmp(argv[5], "-time") == 0)
					heapSortTimeTaken(a, n, time_taken);
				if (strcmp(argv[5], "-comp") == 0)
					heapSortCountCompare(a, n, count_compare);
				if (strcmp(argv[5], "-both") == 0) {
					int* b = new int[n];
					memcpy(b, a, n * sizeof(int));
					heapSortTimeTaken(a, n, time_taken);
					heapSortCountCompare(b, n, count_compare);
					delete[]b;
				}
			}
			if (strcmp(argv[2], "flash-sort") == 0) {
				if (strcmp(argv[5], "-time") == 0)
					flashSortTimeTaken(a, n, time_taken);
				if (strcmp(argv[5], "-comp") == 0)
					flashSortCountCompare(a, n, count_compare);
				if (strcmp(argv[5], "-both") == 0) {
					int* b = new int[n];
					memcpy(b, a, n * sizeof(int));
					flashSortTimeTaken(a, n, time_taken);
					flashSortCountCompare(b, n, count_compare);
					delete[]b;
				}
			}
			if (strcmp(argv[2], "radix-sort") == 0) {
				if (strcmp(argv[5], "-time") == 0)
					radixSortTimeTaken(a, n, time_taken);
				if (strcmp(argv[5], "-comp") == 0)
					radixSortCountCompare(a, n, count_compare);
				if (strcmp(argv[5], "-both") == 0) {
					int* b = new int[n];
					memcpy(b, a, n * sizeof(int));
					radixSortTimeTaken(a, n, time_taken);
					radixSortCountCompare(b, n, count_compare);
					delete[]b;
				}
			}
			if (strcmp(argv[2], "bubble-sort") == 0) {
				if (strcmp(argv[5], "-time") == 0)
					bubbleSortTimeTaken(a, n, time_taken);
				if (strcmp(argv[5], "-comp") == 0)
					bubbleSortCountCompare(a, n, count_compare);
				if (strcmp(argv[5], "-both") == 0) {
					int* b = new int[n];
					memcpy(b, a, n * sizeof(int));
					bubbleSortTimeTaken(a, n, time_taken);
					bubbleSortCountCompare(b, n, count_compare);
					delete[]b;
				}
			}
			if (strcmp(argv[2], "shell-sort") == 0) {
				if (strcmp(argv[5], "-time") == 0)
					shellSortTimeTaken(a, n, time_taken);
				if (strcmp(argv[5], "-comp") == 0)
					shellSortCountCompare(a, n, count_compare);
				if (strcmp(argv[5], "-both") == 0) {
					int* b = new int[n];
					memcpy(b, a, n * sizeof(int));
					shellSortTimeTaken(a, n, time_taken);
					shellSortCountCompare(b, n, count_compare);
					delete[]b;
				}
			}
			if (strcmp(argv[2], "merge-sort") == 0) {
				if (strcmp(argv[5], "-time") == 0)
					mergeSortTimeTaken(a, 0, n - 1, time_taken);
				if (strcmp(argv[5], "-comp") == 0)
					mergeSortCountCompare(a, 0, n - 1, count_compare);
				if (strcmp(argv[5], "-both") == 0) {
					int* b = new int[n];
					memcpy(b, a, n * sizeof(int));
					mergeSortTimeTaken(a, 0, n - 1, time_taken);
					mergeSortCountCompare(b, 0, n - 1, count_compare);
					delete[]b;
				}
			}
			if (strcmp(argv[2], "shaker-sort") == 0) {
				if (strcmp(argv[5], "-time") == 0)
					shakerSortTimeTaken(a, n, time_taken);
				if (strcmp(argv[5], "-comp") == 0)
					shakerSortCountCompare(a, n, count_compare);
				if (strcmp(argv[5], "-both") == 0) {
					int* b = new int[n];
					memcpy(b, a, n * sizeof(int));
					shakerSortTimeTaken(a, n, time_taken);
					shakerSortCountCompare(b, n, count_compare);
					delete[]b;
				}
			}
		}
		if (argc == 5 && check == 0) //Command 1
		{
			if (strcmp(argv[2], "selection-sort") == 0)
			{
				if (strcmp(argv[4], "-time") == 0)
					SelectionSort_time(a, n, time_taken);
				if (strcmp(argv[4], "-comp") == 0)
					SelectionSort_comp(a, n, count_compare);
				if (strcmp(argv[4], "-both") == 0) {
					int* b = new int[n];
					memcpy(b, a, n * sizeof(int));
					SelectionSort_time(a, n, time_taken);
					SelectionSort_comp(b, n, count_compare);
					delete[]b;
				}
			}
			if (strcmp(argv[2], "quick-sort") == 0)
			{
				count_compare = 0;
				time_taken = 0;
				if (strcmp(argv[4], "-time") == 0)
					quickSort_time(a, 0, n - 1, time_taken);
				if (strcmp(argv[4], "-comp") == 0)
					quickSort_comp(a, 0, n - 1, count_compare);
				if (strcmp(argv[4], "-both") == 0) {
					int* b = new int[n];
					memcpy(b, a, n * sizeof(int));
					quickSort_time(a, 0, n - 1, time_taken);
					quickSort_comp(b, 0, n - 1, count_compare);
					delete[]b;
				}
			}
			if (strcmp(argv[2], "counting-sort") == 0) {
				if (strcmp(argv[4], "-time") == 0)
					countingSort_time(a, n, time_taken);
				if (strcmp(argv[4], "-comp") == 0)
					countingSort_comp(a, n, count_compare);
				if (strcmp(argv[4], "-both") == 0) {
					int* b = new int[n];
					memcpy(b, a, n * sizeof(int));
					countingSort_time(a, n, time_taken);
					countingSort_comp(b, n, count_compare);
					delete[]b;
				}
			}
			if (strcmp(argv[2], "insertion-sort") == 0) {
				if (strcmp(argv[4], "-time") == 0)
					insertionSortTimeTaken(a, n, time_taken);
				if (strcmp(argv[4], "-comp") == 0)
					insertionSortCountCompare(a, n, count_compare);
				if (strcmp(argv[4], "-both") == 0) {
					int* b = new int[n];
					memcpy(b, a, n * sizeof(int));
					insertionSortTimeTaken(a, n, time_taken);
					insertionSortCountCompare(b, n, count_compare);
					delete[]b;
				}
			}
			if (strcmp(argv[2], "heap-sort") == 0) {
				if (strcmp(argv[4], "-time") == 0)
					heapSortTimeTaken(a, n, time_taken);
				if (strcmp(argv[4], "-comp") == 0)
					heapSortCountCompare(a, n, count_compare);
				if (strcmp(argv[4], "-both") == 0) {
					int* b = new int[n];
					memcpy(b, a, n * sizeof(int));
					heapSortTimeTaken(a, n, time_taken);
					heapSortCountCompare(b, n, count_compare);
					delete[]b;
				}
			}
			if (strcmp(argv[2], "flash-sort") == 0) {
				if (strcmp(argv[4], "-time") == 0)
					flashSortTimeTaken(a, n, time_taken);
				if (strcmp(argv[4], "-comp") == 0)
					flashSortCountCompare(a, n, count_compare);
				if (strcmp(argv[4], "-both") == 0) {
					int* b = new int[n];
					memcpy(b, a, n * sizeof(int));
					flashSortTimeTaken(a, n, time_taken);
					flashSortCountCompare(b, n, count_compare);
					delete[]b;
				}
			}
			if (strcmp(argv[2], "radix-sort") == 0) {
				if (strcmp(argv[4], "-time") == 0)
					radixSortTimeTaken(a, n, time_taken);
				if (strcmp(argv[4], "-comp") == 0)
					radixSortCountCompare(a, n, count_compare);
				if (strcmp(argv[4], "-both") == 0) {
					int* b = new int[n];
					memcpy(b, a, n * sizeof(int));
					radixSortTimeTaken(a, n, time_taken);
					radixSortCountCompare(b, n, count_compare);
					delete[]b;
				}
			}
			if (strcmp(argv[2], "bubble-sort") == 0) {
				if (strcmp(argv[4], "-time") == 0)
					bubbleSortTimeTaken(a, n, time_taken);
				if (strcmp(argv[4], "-comp") == 0)
					bubbleSortCountCompare(a, n, count_compare);
				if (strcmp(argv[4], "-both") == 0) {
					int* b = new int[n];
					memcpy(b, a, n * sizeof(int));
					bubbleSortTimeTaken(a, n, time_taken);
					bubbleSortCountCompare(b, n, count_compare);
					delete[]b;
				}
			}
			if (strcmp(argv[2], "shell-sort") == 0) {
				if (strcmp(argv[4], "-time") == 0)
					shellSortTimeTaken(a, n, time_taken);
				if (strcmp(argv[4], "-comp") == 0)
					shellSortCountCompare(a, n, count_compare);
				if (strcmp(argv[4], "-both") == 0) {
					int* b = new int[n];
					memcpy(b, a, n * sizeof(int));
					shellSortTimeTaken(a, n, time_taken);
					shellSortCountCompare(b, n, count_compare);
					delete[]b;
				}
			}
			if (strcmp(argv[2], "merge-sort") == 0) {
				if (strcmp(argv[4], "-time") == 0)
					mergeSortTimeTaken(a, 0, n - 1, time_taken);
				if (strcmp(argv[4], "-comp") == 0)
					mergeSortCountCompare(a, 0, n - 1, count_compare);
				if (strcmp(argv[4], "-both") == 0) {
					int* b = new int[n];
					memcpy(b, a, n * sizeof(int));
					mergeSortTimeTaken(a, 0, n - 1, time_taken);
					mergeSortCountCompare(b, 0, n - 1, count_compare);
					delete[]b;
				}
			}
			if (strcmp(argv[2], "shaker-sort") == 0) {
				if (strcmp(argv[4], "-time") == 0)
					shakerSortTimeTaken(a, n, time_taken);
				if (strcmp(argv[4], "-comp") == 0)
					shakerSortCountCompare(a, n, count_compare);
				if (strcmp(argv[4], "-both") == 0) {
					int* b = new int[n];
					memcpy(b, a, n * sizeof(int));
					shakerSortTimeTaken(a, n, time_taken);
					shakerSortCountCompare(b, n, count_compare);
					delete[]b;
				}
			}
		}
		if (argc == 5 && check != 0) //Command 3
		{
			cout << "ALGORITHM MODE" << endl;
			cout << "Algorithm: " << argv[2] << endl;
			cout << "Input size: " << argv[3] << endl;
			for (int i = 0; i <= 3; i++) 
			{
				GenerateData(a, n, i);
				switch (i) { //Write generated file
				case 0: writeFile(a, n, "input_1.txt"); break;
				case 1: writeFile(a, n, "input_3.txt"); break;
				case 2: writeFile(a, n, "input_4.txt"); break;
				case 3: writeFile(a, n, "input_2.txt"); break;
				}
				count_compare = 0;
				time_taken = 0;
				if (strcmp(argv[2], "selection-sort") == 0)
				{
					if (strcmp(argv[4], "-time") == 0)
						SelectionSort_time(a, n, time_taken);
					if (strcmp(argv[4], "-comp") == 0)
						SelectionSort_comp(a, n, count_compare);
					if (strcmp(argv[4], "-both") == 0) {
						int* b = new int[n];
						memcpy(b, a, n * sizeof(int));
						SelectionSort_time(a, n, time_taken);
						SelectionSort_comp(b, n, count_compare);
						delete[]b;
					}
				}
				if (strcmp(argv[2], "quick-sort") == 0)
				{
					count_compare = 0;
					time_taken = 0;
					if (strcmp(argv[4], "-time") == 0)
						quickSort_time(a, 0, n - 1, time_taken);
					if (strcmp(argv[4], "-comp") == 0)
						quickSort_comp(a, 0, n - 1, count_compare);
					if (strcmp(argv[4], "-both") == 0) {
						int* b = new int[n];
						memcpy(b, a, n * sizeof(int));
						quickSort_time(a, 0, n - 1, time_taken);
						quickSort_comp(b, 0, n - 1, count_compare);
						delete[]b;
					}
				}
				if (strcmp(argv[2], "counting-sort") == 0) {
					if (strcmp(argv[4], "-time") == 0)
						countingSort_time(a, n, time_taken);
					if (strcmp(argv[4], "-comp") == 0)
						countingSort_comp(a, n, count_compare);
					if (strcmp(argv[4], "-both") == 0) {
						int* b = new int[n];
						memcpy(b, a, n * sizeof(int));
						countingSort_time(a, n, time_taken);
						countingSort_comp(b, n, count_compare);
						delete[]b;
					}
				}
				if (strcmp(argv[2], "insertion-sort") == 0) {
					if (strcmp(argv[4], "-time") == 0)
						insertionSortTimeTaken(a, n, time_taken);
					if (strcmp(argv[4], "-comp") == 0)
						insertionSortCountCompare(a, n, count_compare);
					if (strcmp(argv[4], "-both") == 0) {
						int* b = new int[n];
						memcpy(b, a, n * sizeof(int));
						insertionSortTimeTaken(a, n, time_taken);
						insertionSortCountCompare(b, n, count_compare);
						delete[]b;
					}
				}
				if (strcmp(argv[2], "heap-sort") == 0) {
					if (strcmp(argv[4], "-time") == 0)
						heapSortTimeTaken(a, n, time_taken);
					if (strcmp(argv[4], "-comp") == 0)
						heapSortCountCompare(a, n, count_compare);
					if (strcmp(argv[4], "-both") == 0) {
						int* b = new int[n];
						memcpy(b, a, n * sizeof(int));
						heapSortTimeTaken(a, n, time_taken);
						heapSortCountCompare(b, n, count_compare);
						delete[]b;
					}
				}
				if (strcmp(argv[2], "flash-sort") == 0) {
					if (strcmp(argv[4], "-time") == 0)
						flashSortTimeTaken(a, n, time_taken);
					if (strcmp(argv[4], "-comp") == 0)
						flashSortCountCompare(a, n, count_compare);
					if (strcmp(argv[4], "-both") == 0) {
						int* b = new int[n];
						memcpy(b, a, n * sizeof(int));
						flashSortTimeTaken(a, n, time_taken);
						flashSortCountCompare(b, n, count_compare);
						delete[]b;
					}
				}
				if (strcmp(argv[2], "radix-sort") == 0) {
					if (strcmp(argv[4], "-time") == 0)
						radixSortTimeTaken(a, n, time_taken);
					if (strcmp(argv[4], "-comp") == 0)
						radixSortCountCompare(a, n, count_compare);
					if (strcmp(argv[4], "-both") == 0) {
						int* b = new int[n];
						memcpy(b, a, n * sizeof(int));
						radixSortTimeTaken(a, n, time_taken);
						radixSortCountCompare(b, n, count_compare);
						delete[]b;
					}
				}
				if (strcmp(argv[2], "bubble-sort") == 0) {
					if (strcmp(argv[4], "-time") == 0)
						bubbleSortTimeTaken(a, n, time_taken);
					if (strcmp(argv[4], "-comp") == 0)
						bubbleSortCountCompare(a, n, count_compare);
					if (strcmp(argv[4], "-both") == 0) {
						int* b = new int[n];
						memcpy(b, a, n * sizeof(int));
						bubbleSortTimeTaken(a, n, time_taken);
						bubbleSortCountCompare(b, n, count_compare);
						delete[]b;
					}
				}
				if (strcmp(argv[2], "shell-sort") == 0) {
					if (strcmp(argv[4], "-time") == 0)
						shellSortTimeTaken(a, n, time_taken);
					if (strcmp(argv[4], "-comp") == 0)
						shellSortCountCompare(a, n, count_compare);
					if (strcmp(argv[4], "-both") == 0) {
						int* b = new int[n];
						memcpy(b, a, n * sizeof(int));
						shellSortTimeTaken(a, n, time_taken);
						shellSortCountCompare(b, n, count_compare);
						delete[]b;
					}
				}
				if (strcmp(argv[2], "merge-sort") == 0) {
					if (strcmp(argv[4], "-time") == 0)
						mergeSortTimeTaken(a, 0, n - 1, time_taken);
					if (strcmp(argv[4], "-comp") == 0)
						mergeSortCountCompare(a, 0, n - 1, count_compare);
					if (strcmp(argv[4], "-both") == 0) {
						int* b = new int[n];
						memcpy(b, a, n * sizeof(int));
						mergeSortTimeTaken(a, 0, n - 1, time_taken);
						mergeSortCountCompare(b, 0, n - 1, count_compare);
						delete[]b;
					}
				}
				if (strcmp(argv[2], "shaker-sort") == 0) {
					if (strcmp(argv[4], "-time") == 0)
						shakerSortTimeTaken(a, n, time_taken);
					if (strcmp(argv[4], "-comp") == 0)
						shakerSortCountCompare(a, n, count_compare);
					if (strcmp(argv[4], "-both") == 0) {
						int* b = new int[n];
						memcpy(b, a, n * sizeof(int));
						shakerSortTimeTaken(a, n, time_taken);
						shakerSortCountCompare(b, n, count_compare);
						delete[]b;
					}
				}
				print_3(argv, count_compare, time_taken, i);//Print result command 3
			}
		}
	}
	//    hiep added: 7/7/2021
//    bonus command 4 vs 5
//    start
//    init cmd 5!
	if (strcmp(argv[1], "-c") == 0 && argc == 6)
	{
		n = atoi(argv[4]);
		a = new int[n];
		if (strcmp(argv[5], "-rand") == 0) input_order = 0;
		if (strcmp(argv[5], "-sorted") == 0) input_order = 1;
		if (strcmp(argv[5], "-rev") == 0) input_order = 2;
		if (strcmp(argv[5], "-nsorted") == 0) input_order = 3;
		GenerateData(a, n, input_order);
		writeFile(a, n, "input.txt");
	}

	int check2 = atoi(argv[4]);

	//    cmd 4 and file error!
	if (strcmp(argv[1], "-c") == 0 && argc == 5 && check2 == 0)
	{
		if (readFile(a, n, "input.txt") == false) {
			cout << "File not exist!";
			return -1;
		}
	}
	
	if (strcmp(argv[1], "-c") == 0)
	{
		//        solve cmd 5 || cmd 4:
		if (argc == 6 || argc == 5)
		{
			if (strcmp(argv[2], "selection-sort") == 0)
			{
				int* b = new int[n];
				memcpy(b, a, n * sizeof(int));
				SelectionSort_time(a, n, time_taken4);
				SelectionSort_comp(b, n, count_compare4);
				delete[]b;
			}
			if (strcmp(argv[3], "selection-sort") == 0)
			{
				int* b = new int[n];
				memcpy(b, a, n * sizeof(int));
				SelectionSort_time(a, n, time_taken5);
				SelectionSort_comp(b, n, count_compare5);
				delete[]b;
			}
			if (strcmp(argv[2], "quick-sort") == 0)
			{
				int* b = new int[n];
				memcpy(b, a, n * sizeof(int));
				quickSort_time(a, 0, n - 1, time_taken4);
				quickSort_comp(b, 0, n - 1, count_compare4);
				delete[]b;
			}
			if (strcmp(argv[3], "quick-sort") == 0)
			{
				int* b = new int[n];
				memcpy(b, a, n * sizeof(int));
				quickSort_time(a, 0, n - 1, time_taken5);
				quickSort_comp(b, 0, n - 1, count_compare5);
				delete[]b;
			}
			if (strcmp(argv[2], "counting-sort") == 0)
			{
				int* b = new int[n];
				memcpy(b, a, n * sizeof(int));
				countingSort_time(a, n, time_taken4);
				countingSort_comp(b, n, count_compare4);
				delete[]b;
			}
			if (strcmp(argv[3], "counting-sort") == 0)
			{
				int* b = new int[n];
				memcpy(b, a, n * sizeof(int));
				countingSort_time(a, n, time_taken5);
				countingSort_comp(b, n, count_compare5);
				delete[]b;
			}
			if (strcmp(argv[2], "insertion-sort") == 0)
			{
				int* b = new int[n];
				memcpy(b, a, n * sizeof(int));
				insertionSortTimeTaken(a, n, time_taken4);
				insertionSortCountCompare(b, n, count_compare4);
				delete[]b;
			}
			if (strcmp(argv[3], "insertion-sort") == 0)
			{
				int* b = new int[n];
				memcpy(b, a, n * sizeof(int));
				insertionSortTimeTaken(a, n, time_taken5);
				insertionSortCountCompare(b, n, count_compare5);
				delete[]b;
			}
			if (strcmp(argv[2], "heap-sort") == 0)
			{
				int* b = new int[n];
				memcpy(b, a, n * sizeof(int));
				heapSortTimeTaken(a, n, time_taken4);
				heapSortCountCompare(b, n, count_compare4);
				delete[]b;
			}
			if (strcmp(argv[3], "heap-sort") == 0)
			{
				int* b = new int[n];
				memcpy(b, a, n * sizeof(int));
				heapSortTimeTaken(a, n, time_taken5);
				heapSortCountCompare(b, n, count_compare5);
				delete[]b;
			}
			if (strcmp(argv[2], "flash-sort") == 0)
			{
				int* b = new int[n];
				memcpy(b, a, n * sizeof(int));
				flashSortTimeTaken(a, n, time_taken);
				flashSortCountCompare(b, n, count_compare);
				delete[]b;
			}
			if (strcmp(argv[3], "flash-sort") == 0)
			{
				int* b = new int[n];
				memcpy(b, a, n * sizeof(int));
				flashSortTimeTaken(a, n, time_taken);
				flashSortCountCompare(b, n, count_compare);
				delete[]b;
			}
			if (strcmp(argv[2], "radix-sort") == 0)
			{
				int* b = new int[n];
				memcpy(b, a, n * sizeof(int));
				radixSortTimeTaken(a, n, time_taken4);
				radixSortCountCompare(b, n, count_compare4);
				delete[]b;
			}
			if (strcmp(argv[3], "radix-sort") == 0)
			{
				int* b = new int[n];
				memcpy(b, a, n * sizeof(int));
				radixSortTimeTaken(a, n, time_taken5);
				radixSortCountCompare(b, n, count_compare5);
				delete[]b;
			}
			if (strcmp(argv[2], "bubble-sort") == 0)
			{
				int* b = new int[n];
				memcpy(b, a, n * sizeof(int));
				bubbleSortTimeTaken(a, n, time_taken4);
				bubbleSortCountCompare(b, n, count_compare4);
				delete[]b;
			}
			if (strcmp(argv[3], "bubble-sort") == 0)
			{
				int* b = new int[n];
				memcpy(b, a, n * sizeof(int));
				bubbleSortTimeTaken(a, n, time_taken5);
				bubbleSortCountCompare(b, n, count_compare5);
				delete[]b;
			}
			if (strcmp(argv[2], "shell-sort") == 0)
			{
				int* b = new int[n];
				memcpy(b, a, n * sizeof(int));
				shellSortTimeTaken(a, n, time_taken4);
				shellSortCountCompare(b, n, count_compare4);
				delete[]b;
			}
			if (strcmp(argv[3], "shell-sort") == 0)
			{
				int* b = new int[n];
				memcpy(b, a, n * sizeof(int));
				shellSortTimeTaken(a, n, time_taken5);
				shellSortCountCompare(b, n, count_compare5);
				delete[]b;
			}
			if (strcmp(argv[2], "merge-sort") == 0)
			{
				int* b = new int[n];
				memcpy(b, a, n * sizeof(int));
				mergeSortTimeTaken(a, 0, n - 1, time_taken4);
				mergeSortCountCompare(b, 0, n - 1, count_compare4);
				delete[]b;
			}
			if (strcmp(argv[3], "merge-sort") == 0)
			{
				int* b = new int[n];
				memcpy(b, a, n * sizeof(int));
				mergeSortTimeTaken(a, 0, n - 1, time_taken5);
				mergeSortCountCompare(b, 0, n - 1, count_compare5);
				delete[]b;
			}
			if (strcmp(argv[2], "shaker-sort") == 0)
			{
				int* b = new int[n];
				memcpy(b, a, n * sizeof(int));
				shakerSortTimeTaken(a, n, time_taken4);
				shakerSortCountCompare(b, n, count_compare4);
				delete[]b;
			}
			if (strcmp(argv[3], "shaker-sort") == 0)
			{
				int* b = new int[n];
				memcpy(b, a, n * sizeof(int));
				shakerSortTimeTaken(a, n, time_taken5);
				shakerSortCountCompare(b, n, count_compare5);
				delete[]b;
			}
		}
	}
	//   end
	if (strcmp(argv[1], "-a") == 0 && argc == 6) //Print result and write file command 2
	{
		writeFile(a, n, "output.txt");
		print_2(argv, count_compare, time_taken);
	}
	if (strcmp(argv[1], "-a") == 0 && argc == 5 && check == 0)	//Print result and write file command 1
	{
		writeFile(a, n, "output.txt");
		print_1(argv, n, count_compare, time_taken);
	}
	//Print resultcommand 4 vs 5
	if (strcmp(argv[1], "-c") == 0 && argc == 5)
	{
		print_4(argv, n, count_compare4, time_taken4, count_compare5, time_taken5);
	}
	if (strcmp(argv[1], "-c") == 0 && argc == 6)
	{
		print_5(argv, count_compare4, time_taken4, count_compare5, time_taken5);
	}

	delete[]a;
	return 0;
}
