#include <iostream>
#include <vector>

using namespace std;

void
print_arr(std::vector<int>& A)
{
    for(std::vector<int>::iterator it = A.begin(); it != A.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// void min_heap_insert(std::vector<int>&A, int heapSize, int key)
// {
//     heapSize += 1;
//     A[heapSize] = key;
//     heap_decrease_key(A, heapSize, heapSize, key);
// }



void min_heapify(std::vector<int>& A, int i, int heapSize)
{
    int l = 2*i;
    int r = 2*i+1;
    int smallest = i;
    // std::cout << "A[i]:" << A[i] << ", i:"<< i << ", l:" << l << ", r:" << r << std::endl;
    if(l <= heapSize && A[l] < A[i])
    {
        smallest = l;
    }
    else 
    {
        smallest = i;
    }
    if(r <= heapSize && A[r] < A[smallest])
    {
        smallest = r;
    }
    if(smallest != i)
    {
        std::swap(A[i], A[smallest]);
        min_heapify(A, smallest, heapSize);
    }
}

void
build_min_heap(std::vector<int>& A)
{
    int heapSize = A.size()-1;
    for(int i = int(heapSize/2); i>=1; i--)
    {
        min_heapify(A, i, heapSize);
    }
}


void
heap_sort(std::vector<int>&A, int heapSize)
{
    for(int i = A.size()-1; i >= 2; i--)
    {
        std::swap(A[1], A[i]);
        heapSize -= 1;
        min_heapify(A, 1, heapSize);
    }
}

void heap_increase_key(std::vector<int>&A, int i, int heapSize, int key)
{
    if(key > A[i])
    {
        std::cerr << "New key is greater!" << std::endl;
    }
    A[i] = key;
    while(i>1 && A[int(i/2)] > A[i])
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
int heap_extract_min(std::vector<int>& A, int heapSize)
{
    if(heapSize < 1)
    {
        std::cerr << "Heap underflow!" << std::endl;
    }
    int min = A[1];
    A[1] = A[heapSize];
    heapSize -= 1;
    min_heapify(A, 1, heapSize);
    return min;
}


int
main(int argc, char** argv)
{
    std::vector<int> arr;
    arr.push_back(0);
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(16);
    arr.push_back(9);
    arr.push_back(10);
    arr.push_back(14);
    arr.push_back(8);
    arr.push_back(7);
    
    std::vector<int> minHeap = arr;
    
    std::cout << "Given array: ";
    print_arr(arr);

    build_min_heap(minHeap);
   
    std::cout << "Created heap: ";
    print_arr(minHeap);

    int min = heap_extract_min(minHeap, minHeap.size()-1);

    cout << "min --> "<< min << endl;

    print_arr(minHeap);




    return 0;
}