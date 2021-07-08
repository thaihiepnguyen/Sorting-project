#ifndef MY_FUNC
#define MY_FUNC

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <time.h>
#include <iomanip>
#include <cstring>
#include <vector>
using namespace std;


void swap(int& a, int& b);
void GenerateData(int a[], int n, int dataType);
//Selection sort
void SelectionSort_comp(int a[], int n, double& count_comp);
void SelectionSort_time(int a[], int n, double& time_taken);
//Quick sort
int partition_time(int a[], int left, int right);
int partition_comp(int a[], int left, int right, double& count_comp);
void quickSort_comp(int a[], int left, int right, double& count_comp);
void quickSort_time(int a[], int left, int right, double& time_taken);
//Counting sort
void countingSort_time(int a[], int n, double& time_taken);
void countingSort_comp(int a[], int n, double& count_comp);
//Insertion sort
void insertionSortCountCompare(int a[], int n, double& count_compare);
void insertionSortTimeTaken(int a[], int n, double& time_taken);
//Heap sort
void heaperCountCompare(int a[], int n, int i, double& count_compare);
void heapSortCountCompare(int a[], int n, double& count_compare);
void heaper(int a[], int n, int i);
void heapSortTimeTaken(int a[], int n, double& time_taken);
//Flash sort
void flashSortCountCompare(int a[], int n, double& count_compare);
void flashSortTimeTaken(int a[], int n, double& time_taken);
//Radix sort
void countSort(int a[], int n, int exp);
void radixSortTimeTaken(int a[], int n, double& time_taken);
void countSortCountCompare(int a[], int n, int exp, double& count_compare);
void radixSortCountCompare(int a[], int n, double& count_compare);
//Bubble Sort
void bubbleSortCountCompare(int a[], int n, double& count_compare);
void bubbleSortTimeTaken(int a[], int n, double& time_taken);
//Shell Sort
void shellSortCountCompare(int a[], int n, double& count_compare);
void shellSortTimeTaken(int a[], int n, double& time_taken);
//Merge Sort
void mergeCountCompare(int arr[], int l, int m, int r, double& count_compare);
void mergeTimeTaken(int arr[], int l, int m, int r);
void mergeSortCountCompare(int a[], int l, int r, double& count_compare);
void mergeSortTimeTaken(int a[], int l, int r, double& time_taken);
//Shaker sort
void shakerSortCountCompare(int a[], int n, double& count_compare);
void shakerSortTimeTaken(int a[], int n, double& time_taken);

void writeFile(int a[], int n, string file_name);
bool readFile(int*& a, int& n, string file_name);

void print_1(char* argv[], int n, double count_compare, double time_taken);
void print_2(char* argv[], double count_compare, double time_taken);
void print_3(char* argv[], double count_compare, double time_taken, int inputOrder);
void print_4(char* argv[], int n, double count_compare4, double time_taken4, double count_compare5, double time_taken5);
void print_5(char* argv[], double count_compare4, double time_taken4, double count_compare5, double time_taken5);
#endif