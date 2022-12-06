#include <iostream>
#include <vector>

void
print_arr(std::vector<int>& A)
{
    for(std::vector<int>::iterator it = A.begin(); it != A.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void
max_heapify(std::vector<int>& A, int i, int heapSize)
{
    int l = 2*i;
    int r = 2*i+1;
    int largest = i;
    // std::cout << "A[i]:" << A[i] << ", i:"<< i << ", l:" << l << ", r:" << r << std::endl;
    if(l <= heapSize && A[l] > A[i])
    {
        largest = l;
    }
    else 
    {
        largest = i;
    }
    if(r <= heapSize && A[r] > A[largest])
    {
        largest = r;
    }
    if(largest != i)
    {
        std::swap(A[i], A[largest]);
        max_heapify(A, largest, heapSize);
    }
}

void
build_max_heap(std::vector<int>& A)
{
    int heapSize = A.size()-1;
    for(int i = int(A.size()/2); i>=1; i--)
    {
        max_heapify(A, i, heapSize);
    }
}

void
heap_sort(std::vector<int>&A, int heapSize)
{
    for(int i = A.size()-1; i >= 2; i--)
    {
        std::swap(A[1], A[i]);
        heapSize -= 1;
        max_heapify(A, 1, heapSize);
    }
}

void
heap_increase_key(std::vector<int>&A, int i, int heapSize, int key)
{
    if(key < A[i])
    {
        std::cerr << "New key is smaller!" << std::endl;
    }
    A[i] = key;
    while(i>1 && A[int(i/2)] < A[i])
    {
        std::swap(A[i], A[int(i/2)]);
        i = int(i/2);
    }
}

int
heap_maximum(std::vector<int>& A)
{
    return A[1];
}

int
heap_extract_max(std::vector<int>& A, int heapSize)
{
    if(heapSize < 1)
    {
        std::cerr << "Heap underflow!" << std::endl;
    }
    int max = A[1];
    A[1] = A[heapSize];
    heapSize -= 1;
    max_heapify(A, 1, heapSize);
    return max;
}

void max_heap_insert(std::vector<int>&A, int heapSize, int key)
{
    heapSize += 1;
    A.push_back(-INT32_MAX);
    heap_increase_key(A, heapSize, heapSize, key);
}

int
main(int argc, char** argv)
{
    std::vector<int> arr = {0,4,1,3,2,16,9,10,14,8,7};
    std::vector<int> maxHeap = arr;
    std::vector<int> arrSorted = arr;
    std::vector<int> arrIncreased = arr;
    std::vector<int> inserted = arr;

    std::cout << "Given array: ";
    print_arr(arr);

    build_max_heap(maxHeap);
    build_max_heap(arrSorted);
    build_max_heap(arrIncreased);
    build_max_heap(inserted);
    std::cout << "Created heap: ";
    print_arr(maxHeap);

    heap_sort(arrSorted, arrSorted.size()-1);
    std::cout << "Sorted heap: ";
    print_arr(arrSorted);

    heap_increase_key(arrIncreased, 9, arrIncreased.size()-1, 15);
    std::cout << "Increased key, value(node:9)->15: ";
    print_arr(arrIncreased);

    max_heap_insert(inserted, inserted.size()-1, 15);
    std::cout << "Inserted key, value=15: ";
    print_arr(inserted);

    return 0;
}