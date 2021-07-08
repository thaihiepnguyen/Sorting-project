#include "Header.h"
#include <cstring>
using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void SelectionSort_comp(int a[], int n, double& count_comp)
{
	count_comp = 0;
	int minIdx;
	for (int i = 0; ++count_comp && i < n-1; i++)
	{
		minIdx = i;
		for (int j = i + 1; ++count_comp && j < n; j++) // find minIdx in subArray
		{
			if (++count_comp && a[j] < a[minIdx])
			{
				minIdx = j;
			}
		}
		swap(a[i], a[minIdx]);	//exchange minVal and current Value
	}
}
void SelectionSort_time(int a[], int n, double& time_taken)
{
	time_taken = 0;
	clock_t start, end;
	start = clock();
	int minIdx;
	for (int i = 0; i < n - 1; i++)
	{
		minIdx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[minIdx])
			{
				minIdx = j;
			}
		}
		swap(a[i], a[minIdx]);
	}
	end = clock();
	time_taken = double(end) - double(start);
}	
int partition_time(int a[], int left, int right)
{
	int pivot = a[(left + right) / 2];	//Pivot is value of the middle index
	int i = left;
	int j = right;
	while (i <= j)
	{
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	return i;
}
int partition_comp(int a[], int left, int right, double& count_comp)
{
	int pivot = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (++count_comp && i <= j)
	{
		while (++count_comp && a[i] < pivot)
			i++;
		while (++count_comp && a[j] > pivot)
			j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	return i;
}
void quickSort_comp(int a[], int left, int right, double& count_comp)
{
TailRecurse:
	if (++count_comp && left < right)
	{
		int mid = partition_comp(a, left, right, count_comp);
		if (++count_comp && mid < (left + right) / 2)
		{
			quickSort_comp(a, left, mid - 1, count_comp); 
			left = mid + 1; 
			goto TailRecurse; 
		}
		else
		{
			quickSort_comp(a, mid + 1, right, count_comp);
			right = mid - 1; 
			goto TailRecurse;
		}
	}
}
void quickSort_time(int a[], int left, int right, double& time_taken)
{
	clock_t start, end;
	start = clock();
TailRecurse:	//To advoid Stack overflow when large data
	if (left < right)
	{
		int mid = partition_time(a, left, right);
		if (mid < (left + right) / 2)
		{
			quickSort_time(a, left, mid - 1, time_taken);
			left = mid + 1; goto TailRecurse;
		}
		else
		{
			quickSort_time(a, mid + 1, right, time_taken);
			right = mid - 1; goto TailRecurse;
		}
	}
	end = clock();
	time_taken = double(end) - double(start);
}

void countingSort_time(int a[], int n, double& time_taken)
{
	time_taken = 0;
	clock_t start, end;
	start = clock();
	int* b = new int[n];
	int max = a[0], min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		else if (a[i] < min)
			min = a[i]; 
	}
	int count = max - min + 1;
	int* count_arr = new int[count];
	memset(count_arr, 0, count * sizeof(int)); //Set all elements's value of array is 0
	for (int i = 0; i < n; i++)
		count_arr[a[i] - min]++;
	for (int i = 1; i < count; i++)
		count_arr[i] += count_arr[i - 1];
	for (int i = 0; i < n; i++)
	{
		b[count_arr[a[i] - min] - 1] = a[i];
		count_arr[a[i] - min]--;
	}
	memcpy(a, b, n * sizeof(int));	//copy ouput array to given array
	delete[]b;
	delete[]count_arr;
	end = clock();
	time_taken = double(end) - double(start);
}
void countingSort_comp(int a[], int n, double& count_comp)
{
	count_comp = 0;
	int* b = new int[n];
	int max = a[0], min = a[0];
	for (int i = 1; ++count_comp && i < n; i++)
	{
		if (++count_comp && a[i] > max)
			max = a[i];
		else if (++count_comp && a[i] < min)
			min = a[i];
	}
	int count = max - min + 1;
	int* count_arr = new int[count];
	memset(count_arr, 0, count*sizeof(int));
	for (int i = 0; ++count_comp && i < n; i++)
		count_arr[a[i] - min]++;
	for (int i = 1; ++count_comp && i < count; i++)
		count_arr[i] += count_arr[i - 1];
	for (int i = 0; ++count_comp && i < n; i++)
	{
		b[count_arr[a[i] - min] - 1] = a[i];
		count_arr[a[i] - min]--;
	}
	memcpy(a, b, n * sizeof(int));
	delete[]b;
	delete[]count_arr;
}
void insertionSortCountCompare(int a[], int n, double& count_compare) {
    count_compare = 0;
    for (int i = 1; ++count_compare && i < n; i++) {
        int v = a[i];
        int j = i - 1;
        for (; ++count_compare && j >= 0 && ++count_compare && a[j] > v; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = v;
    }
}

void insertionSortTimeTaken(int a[], int n, double& time_taken) {
    time_taken = 0;
    clock_t start, end;
    start = clock();
    for (int i = 1; i < n; i++) {
        int v = a[i];
        int j = i - 1;
        for (; j >= 0 && a[j] > v; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = v;
    }
    end = clock();
    time_taken = double(end) - double(start);
}

void heaperCountCompare(int a[], int n, int i, double& count_compare) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int root = i;
    if (++count_compare && l < n && ++count_compare && a[root] < a[l]) {
        root = l;
    }
    if (++count_compare && r < n && ++count_compare && a[root] < a[r]) {
        root = r;
    }
    if (++count_compare && root != i) {
        swap(a[root], a[i]);
        heaperCountCompare(a, n, root, count_compare);
    }
}

void heapSortCountCompare(int a[], int n, double& count_compare) {
    count_compare = 0;
    for (int i = n / 2 - 1; ++count_compare && i >= 0; i--) {
        heaperCountCompare(a, n, i, count_compare);
    }
    cout << endl;
    for (int i = n - 1; ++count_compare && i >= 0; i--) {
        swap(a[0], a[i]);
        heaperCountCompare(a, i, 0, count_compare);
    }
}


void heaper(int a[], int n, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int root = i;
    if (l < n && a[root] < a[l]) {
        root = l;
    }
    if (r < n && a[root] < a[r]) {
        root = r;
    }
    if (root != i) {
        swap(a[root], a[i]);
        heaper(a, n, root);
    }
}

void heapSortTimeTaken(int a[], int n, double& time_taken) {
    time_taken = 0;
    clock_t start, end;
    start = clock();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heaper(a, n, i);
    }
    cout << endl;
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heaper(a, i, 0);
    }
    end = clock();
    time_taken = double(end) - double(start);
}

void flashSortCountCompare(int a[], int n, double& count_compare) {
	count_compare = 0;
	int max = 0, min = a[0];
	int m = floor(0.45 * n);
	vector<int> l;
	l.resize(m);
	for (int i = 1; ++count_compare && i < n; i++) {
		if (++count_compare && a[i] < min) {
			min = a[i];
		}
		if (++count_compare && a[i] > a[max]) {
			max = i;
		}
	}
	if (++count_compare && min == a[max]) {
		return;
	}
	double c1 = (double)(m - 1) / (a[max]-min);

	for (int k = 0; ++count_compare && k < m; k++) {
		l[k] = 0;
	}
	for (int j = 0; ++count_compare && j < n; j++) {
		int k = int(c1 * (a[j]-min));
		++l[k];
	}
	for (int p = 1; ++count_compare && p < m; p++) {
		l[p] += l[p-1];
	}

	swap(a[0], a[max]);

	// permutation
	int move = 0, t = 0, flash;
	int j = 0;
	int k = m - 1;

	while (++count_compare && move < (n - 1)) {
		while (++count_compare && j > (l[k] - 1)) {
			++j;
			k = int(c1 * (a[j] - min));
		}
		flash = a[j];
		if (++count_compare && k < 0) break;
		while (++count_compare && j != l[k]) {
			k = int(c1 * (flash - min));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++move;
		}
	}
	//insertion
	for (int i = 1; i < n; i++) {
		int v = a[i];
		int j = i - 1;
		for (; j >= 0 && a[j] > v; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = v;
	}
}


void flashSortTimeTaken(int a[], int n, double& time_taken) {
	time_taken = 0;
	clock_t start, end;
	start = clock();
	int max = 0, min = a[0];
	int m = floor(0.45 * n);
	vector<int> l;
	l.resize(m);
	for (int i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
		}
		if (a[i] > a[max]) {
			max = i;
		}
	}
	if (min == a[max]) {
		return;
	}
	double c1 = (double)(m - 1) / (a[max] - min);

	for (int k = 0; k < m; k++) {
		l[k] = 0;
	}
	for (int j = 0; j < n; j++) {
		int k = int(c1 * (a[j] - min));
		++l[k];
	}
	for (int p = 1; p < m; p++) {
		l[p] = l[p] + l[p - 1];
	}

	swap(a[0], a[max]);

	// permutation
	int move = 0, t = 0, flash;
	int j = 0;
	int k = m - 1;

	while (move < (n - 1)) {
		while (j > (l[k] - 1)) {
			++j;
			k = int(c1 * (a[j] - min));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k]) {
			k = int(c1 * (flash - min));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++move;
		}
	}
	//insertion
	for (int i = 1; i < n; i++) {
		int v = a[i];
		int j = i - 1;
		for (; j >= 0 && a[j] > v; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = v;
	}
	end = clock();
	time_taken = double(end) - double(start);
}

void countSort(int a[], int n, int exp)
{
	int* result = new int[n];
	memset(result, 0, n * sizeof(int));
	int i, bucket[10] = { 0 };

	for (i = 0; i < n; i++)
		bucket[(a[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		bucket[i] += bucket[i - 1];

	for (i = n - 1; i >= 0; i--) {
		result[bucket[(a[i] / exp) % 10] - 1] = a[i];
		bucket[(a[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		a[i] = result[i];
	delete[] result;
}


void radixSortTimeTaken(int a[], int n, double& time_taken)
{
	time_taken = 0;
	clock_t start, end;
	start = clock();
	int maxArr = a[0];
	for (int i = 0; i < n; i++)
		if (maxArr < a[i]) maxArr = a[i];

	for (int exp = 1; maxArr / exp > 0; exp *= 10)
		countSort(a, n, exp);
	end = clock();
	time_taken = double(end) - double(start);
}

void countSortCountCompare(int a[], int n, int exp, double& count_compare)
{
	int* result = new int[n];
	memset(result, 0, n * sizeof(int));
	int i, bucket[10] = { 0 };

	for (i = 0; ++count_compare && i < n; i++)
		bucket[(a[i] / exp) % 10]++;

	for (i = 1; ++count_compare && i < 10; i++)
		bucket[i] += bucket[i - 1];

	for (i = n - 1; ++count_compare && i >= 0; i--) {
		result[bucket[(a[i] / exp) % 10] - 1] = a[i];
		bucket[(a[i] / exp) % 10]--;
	}

	for (i = 0; ++count_compare && i < n; i++)
		a[i] = result[i];
	delete[] result;
}
// Còn Phiên Bản Sài Node 
void radixSortCountCompare(int a[], int n, double& count_compare)
{
	count_compare = 0;
	int maxArr = a[0];
	for (int i = 0; i < n; i++)
		if (++count_compare&& maxArr < a[i]) maxArr = a[i];

	for (int exp = 1; ++count_compare && maxArr / exp > 0; exp *= 10)
		countSortCountCompare(a, n, exp, count_compare);
}
//Bubble Sort
void bubbleSortCountCompare(int a[], int n, double& count_compare)
{
	count_compare = 0;
	for (int i = 0; ++count_compare && i < n; i++) {
		for (int j = 0; ++count_compare && j < n - i; j++) {
			if (++count_compare && a[i] < a[j])
				swap(a[i], a[j]);
		}
	}
}

void bubbleSortTimeTaken(int a[], int n, double& time_taken)
{
	time_taken = 0;
	clock_t start, end;
	start = clock();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (a[i] < a[j])
				swap(a[i], a[j]);
		}
	}
	end = clock();
	time_taken = double(end) - double(start);
}

void shellSortCountCompare(int a[], int n, double& count_compare)
{
	count_compare = 0;
	int interval, i, j, temp;
	for (interval = n / 2; ++count_compare && interval > 0; interval /= 2) {
		for (i = interval; ++count_compare && i < n; i++) {
			temp = a[i];
			for (j = i; ++count_compare && j >= interval && ++count_compare && a[j - interval] > temp; j -= interval) {
				a[j] = a[j - interval];
			}
			a[j] = temp;
		}
	}
}

void shellSortTimeTaken(int a[], int n, double& time_taken)
{
	time_taken = 0;
	clock_t start, end;
	start = clock();
	int interval, i, j, temp;
	for (interval = n / 2; interval > 0; interval /= 2) {
		for (i = interval; i < n; i++) {
			temp = a[i];
			for (j = i; j >= interval && a[j - interval] > temp; j -= interval) {
				a[j] = a[j - interval];
			}
			a[j] = temp;
		}
	}
	end = clock();
	time_taken = double(end) - double(start);
}

//Source: https://codelearn.io/learning/cau-truc-du-lieu-va-giai-thuat/853804
void mergeCountCompare(int arr[], int l, int m, int r, double& count_compare)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int* L = new int[n1], * R = new int[n2];
	for (i = 0; ++count_compare && i < n1; i++) {
		L[i] = arr[l + i];
	}
	for (j = 0; ++count_compare && j < n2; j++) {
		R[j] = arr[m + 1 + j];
	}
	i = 0;
	j = 0;
	k = l;
	while (++count_compare && i < n1 && ++count_compare && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (++count_compare && i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (++count_compare && j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;
}

void mergeTimeTaken(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int* L = new int[n1], * R = new int[n2];
	for (i = 0; i < n1; i++) {
		L[i] = arr[l + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = arr[m + 1 + j];
	}
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;
}

void mergeSortCountCompare(int a[], int l, int r, double& count_compare)
{

	if (++count_compare && l < r) {
		int m = l + (r - l) / 2;
		mergeSortCountCompare(a, l, m, count_compare);
		mergeSortCountCompare(a, m + 1, r, count_compare);
		mergeCountCompare(a, l, m, r, count_compare);
	}
}


void mergeSortTimeTaken(int a[], int l, int r, double& time_taken)
{
	clock_t start, end;
	start = clock();
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSortTimeTaken(a, l, m, time_taken);
		mergeSortTimeTaken(a, m + 1, r, time_taken);
		mergeTimeTaken(a, l, m, r);
	}
	end = clock();
	time_taken = (double(end) - double(start));
}


void shakerSortCountCompare(int a[], int n, double& count_compare)
{
	count_compare = 0;
	int left = 0;
	int right = n - 1;
	int k = 0;
	for (int i = left; ++count_compare && i <= right; i++)
	{
		bool swapped_check = false;
		//day max ve cuoi mang
		for (int j = left; ++count_compare && j < right; j++)
			if (++count_compare && a[j] > a[j + 1])
			{
				swapped_check = true;
				swap(a[j], a[j + 1]);
				k = j;
			}
		if (++count_compare && !swapped_check)
			return;
		right = k;
		//day min ve dau mang
		swapped_check = false;
		for (int j = right; ++count_compare && j > left; j--)
			if (++count_compare && a[j] < a[j - 1])
			{
				swapped_check = true;
				swap(a[j], a[j - 1]);
				k = j;
			}
		if (++count_compare && !swapped_check)
			return;
		left = k;
	}
}


void shakerSortTimeTaken(int a[], int n, double& time_taken)
{
	time_taken = 0;
	clock_t start, end;
	start = clock();
	int left = 0;
	int right = n - 1;
	int k = 0;
	for (int i = left; i <= right; i++)
	{
		bool swapped_check = false;
		//day max ve cuoi mang
		for (int j = left; j < right; j++)
			if (a[j] > a[j + 1])
			{
				swapped_check = true;
				swap(a[j], a[j + 1]);
				k = j;
			}
		if (!swapped_check)
			break;
		right = k;
		//day min ve dau mang
		swapped_check = false;
		for (int j = right; j > left; j--)
			if (a[j] < a[j - 1])
			{
				swapped_check = true;
				swap(a[j], a[j - 1]);
				k = j;
			}
		if (!swapped_check)
			break;
		left = k;
	}
	end = clock();
	time_taken = double(end) - double(start);
}
