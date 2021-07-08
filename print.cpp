#include "Header.h"
#include <cstring>
using namespace std;

void print_2(char* argv[], double count_compare, double time_taken)
{
	if (strcmp(argv[1], "-a") == 0)
	{
		cout << "ALGORITHM MODE" << endl;
		cout << "Algorithm: " << argv[2] << endl;
		cout << "Input size: " << argv[3] << endl;
		string inputOrd;
		if (strcmp(argv[4], "-rand") == 0) inputOrd = "Randomized data";
		if (strcmp(argv[4], "-sorted") == 0) inputOrd = "Sorted data";
		if (strcmp(argv[4], "-rev") == 0) inputOrd = "Reverse sorted data";
		if (strcmp(argv[4], "-nsorted") == 0) inputOrd = "Nearly sorted data";
		cout << "Input order: " << inputOrd << endl;
		cout << "============================" << endl;
		if (strcmp(argv[5], "-comp") == 0)
		{
			cout << "Comparisions: " << count_compare << endl;
			cout << "Running time: Not required" <<endl;
		}
		if (strcmp(argv[5], "-time") == 0)
		{
			cout << "Comparisions: Not required" << endl;
			cout << "Running time: " << time_taken << " miliSec" << endl;
		}
		if (strcmp(argv[5], "-both") == 0)
		{
			cout << "Comparisions: " << count_compare << endl;
			cout << "Running time: " << time_taken << " miliSec" << endl;
		}
	}
}
void print_1(char* argv[], int n, double count_compare, double time_taken)
{
	if (strcmp(argv[1], "-a") == 0)
	{
		cout << "ALGORITHM MODE" << endl;
		cout << "Algorithm: " << argv[2] << endl;
		cout << "Input file: " << argv[3] << endl;
	}
	cout << "Input size: " << n << endl;
	cout << "============================" << endl;
	if (strcmp(argv[4], "-comp") == 0)
	{
		cout << "Comparisions: " << count_compare << endl;
		cout << "Running time: Not required" << endl;
	}
	if (strcmp(argv[4], "-time") == 0)
	{
		cout << "Comparisions: Not required" << endl;
		cout << "Running time: " << time_taken << " miliSec" << endl;
	}
	if (strcmp(argv[4], "-both") == 0)
	{
		cout << "Comparisions: " << count_compare << endl;
		cout << "Running time: " << time_taken << " miliSec" << endl;
	}
}
void print_3(char* argv[], double count_compare, double time_taken, int inputOrder)
{
	string inputOrd;
	if (inputOrder == 0) inputOrd = "Randomized data";
	if (inputOrder == 1) inputOrd = "Sorted data";
	if (inputOrder == 2) inputOrd = "Reverse sorted data";
	if (inputOrder == 3) inputOrd = "Nearly sorted data";
	cout << endl;
	cout << "Input order: " << inputOrd << endl;
	cout << "==================================" << endl;
	if (strcmp(argv[4], "-comp") == 0)
	{
		cout << "Comparisions: " << count_compare << endl;
		cout << "Running time: Not required" << endl;
	}
	if (strcmp(argv[4], "-time") == 0)
	{
		cout << "Comparisions: Not required" << endl;
		cout << "Running time: " << time_taken << " miliSec" << endl;
	}
	if (strcmp(argv[4], "-both") == 0)
	{
		cout << "Comparisions: " << count_compare << endl;
		cout << "Running time: " << time_taken << " miliSec" << endl;
	}
}
void print_5(char* argv[], double count_compare4, double time_taken4, double count_compare5, double time_taken5)
{
	if (strcmp(argv[1], "-c") == 0) {
		cout << "COMPARE MODE" << endl;
		cout << "Algorithm: " << argv[2] << " | " << argv[3] << endl;
		cout << "Input size: " << argv[4] << endl;
		string inputOrd;
		if (strcmp(argv[5], "-rand") == 0) inputOrd = "Randomized data";
		if (strcmp(argv[5], "-sorted") == 0) inputOrd = "Sorted data";
		if (strcmp(argv[5], "-rev") == 0) inputOrd = "Reverse sorted data";
		if (strcmp(argv[5], "-nsorted") == 0) inputOrd = "Nearly sorted data";
		cout << "Input order: " << inputOrd << endl;
		cout << "==================================" << endl;
		cout << "Comparisions: " << count_compare4 << " | " << count_compare5 << endl;
		cout << "Running time: " << time_taken4 << " miliSec" << " | " << time_taken5 << " miliSec" << endl;
	}
}

void print_4(char* argv[], int n, double count_compare4, double time_taken4, double count_compare5, double time_taken5)
{
	if (strcmp(argv[1], "-c") == 0) {
		cout << "COMPARE MODE" << endl;
		cout << "Algorithm: " << argv[2] << " | " << argv[3] << endl;
		cout << "Input file: " << argv[4] << endl;
		cout << "Input size: " << n << endl;
		cout << "==================================" << endl;
		cout << "Comparisions: " << count_compare4 << " | " << count_compare5 << endl;
		cout << "Running time: " << time_taken4 << " miliSec" << " | " << time_taken5 << " miliSec" << endl;
	}
}
void writeFile(int a[], int n, string file_name)
{
	ofstream f;
	f.open(file_name);
	f << n << endl;
	for (int i = 0; i < n; i++)
	{
		f << a[i] << " ";
	}
	f.close();
}
bool readFile(int*& a, int& n, string file_name)
{
	ifstream f;
	f.open(file_name);
	if (!f.is_open())
	{
		return false;
	}
	f >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		f >> a[i];
	}
	return true;
}
