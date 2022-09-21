# Sorting Project

- Made with C/C++
- Includes Selection Sort, Insertion Sort, Bubble Sort, Shaker Sort, Shell Sort, Heap
  Sort, Merge Sort, Quick Sort, Counting Sort, Radix Sort, and Flash Sort.
- This is a Project of **Data Structures & Algorithms Subject**

# Requirements

- Install [C/C++](https://visualstudio.microsoft.com/vs/features/cplusplus/)

# Deployment

### **Algorithm Mode**

- Command 1: Run a sorting algorithm on the given input data
  - Prototype: [Execution file] -a [Algorithm] [Given input] [Output parameter(s)]
  - Ex: a.exe -a radix-sort input.txt -both

```
% a.exe -a [Algorithm] [Input file] [Output param]
```

- Command 2: Run a sorting algorithm on the data generated automatically with specified
  size and order - Prototype: [Execution file] -a [Algorithm] [Input size] [Input order]
  [Output parameter(s)] - Ex: a.exe -a selection-sort 50 -rand -time

```
% a.exe -a [Algorithm] [Input size] [Input order] [Output Param]
```

- Command 3: Run a sorting algorithm on ALL data arrangements of a specified size.
  - Prototype: [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]
  - Ex: a.exe -a binary-insertion-sort 70000 -comp

```
% a.exe -a [Algorithm] [Input size] [Output Param]
```

### **Comparison Mode**

- Command 4: Run two sorting algorithms on the given input.
  - Prototype: [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]
  - Ex: a.exe -c heap-sort merge-sort input.txt

```
% a.exe -c [Algorithm1] [Algorithm2] [Input file]
```

- Command 5: Run two sorting algorithms on the data generated automatically.
  - Prototype: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size]
    [Input order]
  - Ex: a.exe -c quick-sort merge-sort 100000 -nsorted

```
% a.exe -c [Algorithm1] [Algorithm2] [Input size] [Input order]
```

Thanks for watching

Author: Nguyễn Thái Hiệp
