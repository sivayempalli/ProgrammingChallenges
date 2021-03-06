//----------------------------------------------------------------------------------------
/*
Table of Contents
// Comparison Sorts 
1. BubbleSort, T(n) = O(n^2), S(n) = O(1)
2. MergeSort Array, T(n) = O(nlogn), S(n) = O(nlogn) 
3. QuickSort Array, T(n) = O(n^2), S(n) = O(1)
4. Randomized Quicksort, T(n) = O(n^2), S(n) = O(1)
5. HeapSort, T(n) = O(nlogn), S(n) = O(1)
// Non-Comparison Sort 
6. Counting Sort, T(n,k) = O(k + n), S(n,k) = O(k + n) 
7. Radix Sort, T(n,k,d) = O(d(k + n)), S(n,k) = O(k + n) 
8. Binary Search, T(n) = O(logn), S(n) = O(1)
9. Given a sorted array of integers, find range at which a target value exist. T(n) = O(nlgn), S(n) = O(1)
//----------------------------------------------------------------------------------------
// TODO 
MergeSort LinkedList
QuickSort LinkedList
Insertion Sort
Selection Sort
TimSort (Make sure you include the bug fixes) 
BucketSort (Improves 
PigeonSort (A special case of Counting Sort with lists) // Note: The one you came up with, but use linked list to make it a stable sort 

Given an array with only 3 integers, (0,1,2). sort the entire array using only a single pass => T(n) = O(n) and constant space S(n) = O(1)
    Note: Not counting sort as not most optimal solution
    Hints: One pointer at far end left marking non 0's to replace, one pointer at far end right marking non 2's to replace. 
           One pointer starting from left most to right most and replacing.  
           Each time swap occurs, the end pointer move inwards whereas the iterating pointer stays the same. 
            Iterating pointer only increases if it sees a 1
            Loop terminates when iterating pointer passes a 2

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row
    O(log(mn)) (use binary search)
	
Given a list  of papers with their number of citations [3,2,5] => Paper 1 has 3 citations, paper 3 has 5 citations, calculate the H-index in O(n)
    Hint: Use bucket sort
*/
//----------------------------------------------------------------------------------------
/* //
// 1 Bubble sort
// Time Complexity, T(n) = O(n^2)
// Space Complexity, S(n) = O(1)
#include <stdlib.h>
#include <stdio.h>

// NOTE: PRINTF for double is "%f" NOT "%d"

void swap(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp; // b = temp NOT b = a!!
    return;
}

void bubblesort(double * array, int n)
{
    if ((array == NULL) || (n<=1))
        return;
    int i = 0;
    int j = 0;
    for ( i = n-1; i>= 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            if (array[j] > array[j+1])
            {
                printf("\n %f %f \n",array[j], array[j+1] );
                swap(array[j], array[j+1]);
                printf(" \n %f %f \n",array[j], array[j+1] );

            }
            // else do nothing
        }
    }
}

int main(void)
{
    double * haha;
    haha = (double *) malloc(sizeof(double) * 4);
    haha[0] = 3.3;
    haha[1] =5.6;
    haha[2] = 4.7;
    haha[3] = 2.0;
    int i = 0;

    for(i = 0; i < 4; i++)
    {
        printf("%f ", haha[i]);
    }
    bubblesort(haha, 4);
    for(i = 0; i < 4; i++)
    {
        printf("%f ", haha[i]);
    }
    printf("\n");
}
// */
//----------------------------------------------------------------------------------------
/*
// Practice 2: Template Bubble Sort
// Time Complexity, T(n) = O(n^2)
// Space Complexity, S(n) = O(1)

#include <iostream>
using namespace std;

template <class X>
void bubblesort(X ab[], int n);

template <class X>
void swap(X ab[], int a, int b);
int main(void)
{
    int ab[5] = {2,1,4,3,5};
    bubblesort(ab, sizeof(ab)/sizeof(ab[0]));
    for (int i = 0; i < 5; i++)
    {
        cout << ab[i] << endl;
    }
    return 0;
}

template <class X>
void bubblesort(X ab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (ab[j] > ab[j+1])
            {
                swap(ab, j, j+1);
            }
        }
    }
}

template <class X>
void swap(X ab[], int a, int b)
{
    X temp = ab[a];
    ab[a] = ab[b];
    ab[b] = temp;
}
// */
//----------------------------------------------------------------------------------------
/* //
// 2 MergeSort Array, T(n) = O(nlogn), S(n) = O(nlogn) 
// Time Complexity, T(n) = O(nlogn)
// Space Complexity, S(n) = O(nlogn)
// OMG, it works perfectly on first trial!!
// only 1 mistake of not closing curly braces properly due to nested else and for =D =D =D
// Note: Update: Fixed small mistake that q is either n/2 or n/2+1 depending on whether n is odd or even
//      This was updated on 6th February 2015

// Time Complexity:Xilinx's Vivado HLS 2.
// a[n] = 2a[n/2] + n + n  = 2a[n/2] + 2n
// From Master's Thm. Case 2
// This is O(nlgn)

// Space Complexity:
// Space Complexity, S(n) = O(3n) = O(n) as explained by myself here.
// http://stackoverflow.com/questions/10342890/merge-sort-time-and-space-complexity/28641693#28641693
// These calculations below is false unless the code executes in parallel. Sequential code would only
// take O(3n) as explained above.
// n * (n/2)+(n/2) * (n/4)+(n/4)+(n/4)+(n/4) * ... * (1)*n  = n+n+...+n = n(logn)
// Space complexity is also O(nlgn)


#include <iostream>
using namespace std;

template <class X>
void mergesort(X a[], int n);

int main(void)
{
    int ab[5] = {4,3,2,6,9};
    mergesort(ab, 5);
    for (int i = 0; i < 5; i++)
    {
        cout <<ab[i] <<endl;
    }
    return 0;
}

template <class X>
void mergesort(X a[], int n)
{
    if (n==1)
    {
        return;
    }
    int q, p;
    q = n/2;
    p = n/2;
    //if(n % 2 == 1) p++; // increment by 1
    if(n & 0x1) p++; // increment by 1
        // note: doing and operator is much faster in hardware than calculating the mod (%)
    X b[q];
    int i = 0;
    for (i = 0; i < q; i++)
    {
        b[i] = a[i];
    }
    mergesort(b, i);
    // do mergesort here to save space
    // http://stackoverflow.com/questions/10342890/merge-sort-time-and-space-complexity/28641693#28641693

    // After returning from previous mergesort only do you create the next array.
    X c[p];
    int k = 0;
    for (int j = q; j < n; j++)
    {
        c[k] = a[j];
        k++;
    }
    mergesort(c, k);
    int r, s, t;
    t = 0; r = 0; s = 0;
    while( (r!=q) && (s!= p))
    {
        if (b[r] <= c[s])
        {
            a[t] = b[r];
            r++;
        }
        else
        {
            a[t] = c[s];
            s++;
        }
        t++;
    }
    if ( r==q)
    {
        while(s!=p)
        {
            a[t] = c[s];
            s++;
            t++;
        }
    }
    else
    {
        while(r != q)
        {
            a[t] = b[r];
            r++;
            t++;
        }
    }
    return;
}
// */
//----------------------------------------------------------------------------------------
/* //
// 3 QuickSort Array (A stable sort)
// Time Complexity, T(n) = O(n^2) worst case, O(nlgn) Average case (or as long as constant partition ratio)
// Space Complexity, S(n) = O(1) note: sorts in place
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void swapQuickSort(int *p, int l, int r);
int quickSort(int *p, int l, int r);

int main(void)
{
    int n = 5;
    int *p = (int*) malloc(sizeof(int)*n);
    p[0] = 5;
    p[1] = 4;
    p[2] = 3;
    p[3] = 2;
    p[4] = 1;
    int i = 0;
    cout <<"Before Sorting"<<endl;
    for(i = 0; i < n; i++)
    {
        cout<< p[i] << " ";
    }
    cout << endl;
    quickSort(p, 0, n-1);
    cout <<"After Sorting"<<endl;
    for(i = 0; i < n; i++)
    {
        cout<< p[i] << " ";
    }
    cout << endl;
}

// Note: l >= r for this to work
int quickSort(int *p, int l, int r)
{
    int n = r-l;
    if (n <= 0) return -1; // stop the recursion
    // Partition into 2 sub problems
    int pivot = r;
    int left = l;
    int right = l;
    for(right = l; right<pivot; right++)
    {
        if (p[right] < p[pivot])
        {
            swapQuickSort(p, left, right);
            left++;
        }
    }
    swapQuickSort(p, left, pivot);
    quickSort(p, l, left-1);
    quickSort(p,left+1, pivot); // note: pivot = r
    return 0;
}

void swapQuickSort(int *p, int l, int r)
{
    int temp = p[l];
    p[l] = p[r];
    p[r] = temp;
    return;
}
// */
//----------------------------------------------------------------------------------------------------
/* //
// 4 Randomized QuickSort (A stable sort) (higher chance to get average case than worst case)
// Time Complexity: O(n^2) worst case, O(nlgn) Average case (or as long as constant partition ratio)
// Space Complexity: O(1) note: sorts in place
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // to initalize random with time()

using namespace std;

void swapRandomizedQuickSort(int *p, int l, int r);
int randomizedQuickSort(int *p, int l, int r);

int main(void)
{
    int n = 5;
    int *p = (int*) malloc(sizeof(int)*n);
    p[0] = 5;
    p[1] = 4;
    p[2] = 3;
    p[3] = 2;
    p[4] = 1;
    int i = 0;
    cout <<"Before Sorting"<<endl;
    for(i = 0; i < n; i++)
    {
        cout<< p[i] << " ";
    }
    cout << endl;
    randomizedQuickSort(p, 0, n-1);
    cout <<"After Sorting"<<endl;
    for(i = 0; i < n; i++)
    {
        cout<< p[i] << " ";
    }
    cout << endl;
}

// Note: l >= r for this to work
int randomizedQuickSort(int *p, int l, int r)
{
    int n = r-l;
    if (n <= 0) return -1; // stop the recursion
    // Partition into 2 sub problems
    time_t t;
    srand((unsigned) time(&t));
    int pivot = (rand() % (r+1-l)) + l; // anywhere from l to  r
    swapRandomizedQuickSort(p, pivot, r); // swap value to right
    pivot = r; // use new pivot
    int left = l;
    int right = l;
    for(right = l; right<pivot; right++)
    {
        if (p[right] < p[pivot])
        {
            swapRandomizedQuickSort(p, left, right);
            left++;
        }
    }
    swapRandomizedQuickSort(p, left, pivot);
    randomizedQuickSort(p, l, left-1);
    randomizedQuickSort(p,left+1, pivot);
    return 0;
}

void swapRandomizedQuickSort(int *p, int l, int r)
{
    int temp = p[l];
    p[l] = p[r];
    p[r] = temp;
    return;
}
// */
//----------------------------------------------------------------------------------------------------
/* // 
// 5 HeapSort
// Time Complexity, T(n) = O(nlogn)
// Space Complexity, S(n) = O(1)
#include <cmath> // for log2()
#include <iostream> 
using namespace std; 

// true => sort ascending order, false => sort descending order
int * heapSort(int * a, int size, bool ascOrDesc);
// true => Build a max heap, false => Build a min heap
int * buildHeap(int * a, int size, bool maxOrMin); 
int * heapify (int * a, int index, int size, bool maxOrMin);
void swap(int* a, int* b);

int main(void)
{
    int n = 10;
    int * a = new int[n];
    for (int i = 0; i < n; i++)
    {
        if (i%2)
            a[i] = i * 3; 
        else 
            a[i] = i * 2; 
                
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Sort ascending" << endl;
    heapSort(a,n,true);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Sort descending" << endl;
    heapSort(a,n,false);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0; 
}

int * heapSort(int * a, int size, bool ascOrDesc)
{
    // First, build a heap. 
    // If ascending, need to build a maxHeap, if descending, need to build a minHeap
    buildHeap(a, size, ascOrDesc);
    // Now, sort it 
    for(int i = size - 1; i >= 0; i--)
    {
        // first swap the root element (currMax) with the last,
        swap(&a[0], &a[i]);
        // and heapify the root element downwards
        heapify(a, 0, i, ascOrDesc);
    }
    return a;
}

// O(n) 
int * buildHeap(int * a, int size, bool maxOrMin)
{
    // calculate finalIndex that you need to begin with since there is no point starting from the leaves
    int finalIndex = floor(log2(size));  
    finalIndex = pow(2,finalIndex) - 2;
    for (int i = finalIndex; i >= 0; i--)
    {
        // heapify from that index onwards
        a = heapify(a, i, size, maxOrMin);
    }
    return a; 
}

// Assumes the binary heap below this node is indeed a binary heap 
// T(n) = O(logn)
int * heapify (int * a, int index, int size, bool maxOrMin)
{
    // Get index of left and right child
    int left = 2*index + 1; 
    int right = 2*index + 2; 
    // Mistake: Declared smallest and largest within if statement instead of here so that below can access
    int smallest = -1;
    int largest =  -1;
    if(left < size && right < size) 
    {
        // if want largest to be on top 
        if (maxOrMin)
        {
            int larger = a[left] >= a[right] ? left : right;
            largest = a[index] >= a[larger] ? index : larger;
        }
        else 
        {
            int smaller = a[left] <= a[right] ? left : right;
            smallest = a[index] <= a[smaller] ? index : smaller;
        }
    }
    else if (left < size) 
    {
        if (maxOrMin)
        {
            largest = a[index] >= a[left] ? index : left;
        }
        else 
        {
            smallest = a[index] <= a[left] ? index : left;
        }
    }
    else if (right < size) 
    {
        if (maxOrMin)
        {
            largest = a[index] >= a[right] ? index : right;
        }
        else 
        {
            smallest = a[index] <= a[left] ? index : left;
        }
    }
    // Else, if no child, just return it
    else 
    {
        return a;
    }
    // If has any child
    if (maxOrMin)
    {
        if(largest != index) 
        {
            swap (&a[largest], &a[index]);
            // Recursively heapify 
            heapify(a, largest, size, maxOrMin);
        }
        // Return a at the end
        return a; 
    }
    else
    {
        if(smallest != index) 
        {
            swap (&a[smallest], &a[index]);
            // Recursively heapify 
            heapify(a,smallest, size, maxOrMin);
        }
        return a; 
    }
}

void swap(int* a, int* b)
{
    int temp = *a; 
    *a = *b;
    *b = temp;
    return;
}
// */
//----------------------------------------------------------------------------------------------------
/* //
// 6 Counting Sort (A stable sort)
// Requirement: All numbers are integers in range 0 to k
// Time Complexity, T(n,k) = O(k+n)
// Space Complexity: T(n,k) = O(k+n)

#include <stdio.h>
#include <stdlib.h> // for malloc
#include <time.h> // for time()
#include <iostream>
#include <cmath>
using namespace std;

void countingSort(int* p, int n, int k);

int main(void)
{
    int n = 8;
    int k = 20; // max range of integer values
    int *p = (int *) malloc(sizeof(int) * n);
    int i = 0;
    time_t t;
    srand((unsigned) time(&t)); // initialize random number genrator
    for(i = 0; i < n; i++)
    {
        p[i] = rand() %k;
    }

    cout << "Before Sorting" << endl;
    for(i = 0; i < n; i++)
    {
        cout<< p[i] <<" ";
    }
    cout << endl;
    countingSort(p, n, k);
    cout << "After Sorting" << endl;
    for(i = 0; i < n; i++)
    {
        cout<< p[i] <<" ";
    }
    cout << endl;
}

void countingSort(int* p, int n, int k)
{
    int *q;
    int *sorted;
    sorted = (int*) malloc(sizeof(int) * (n+1));

    q = (int*) malloc(sizeof(int) * (k+1));
    int i = 0;
    // initialize count of all numbers to 0
    for (i = 0; i <= k; i++)
    {
        q[i] = 0;
    }
    // initialize the sorted for all numbers to 0
    for (i = 0; i < n; i++)
    {
        sorted[i] = 0;
    }
    // Store all values
    for(i = 0; i< n; i++)
    {
        q[p[i]]++; // increment that value
    }
    for(i = 1; i<= k; i++)
    {
        q[i] = q[i] + q[i-1]; // Make it cumulative
    }
    // Sort it
    for(i = n-1; i>= 0; i--) // Note: need start from n-1 to 0 to ensure stability
    {
        sorted[q[p[i]]] = p[i]; // start from last value of p , store that point into sorted
        q[p[i]]--;
    }

    // Finally, copy sorted back to original array
    for (i = 0; i < n; i++)
    {
        p[i] = sorted[i+1]; // note: sorted starts from 1 to N including N, it doesn't contain anything at 0.
    }
    return;
}
// */
//----------------------------------------------------------------------------------------------------
/* //
// 7 Radix Sort
// Counting Sort (A stable sort)
// Requirement: All numbers are integers in range 0 to k
// Time Complexity, T(n,k,d) = O(d(k+n))
// Space Complexity, S(n,k,d) O(k+n)

#include <stdio.h>
#include <stdlib.h> // for malloc
#include <time.h> // for time()
#include <iostream>
#include <cmath>
using namespace std;

void countingSortForRadixSort(int* p, int n, int k, int d);
void radixSort(int* p, int n, int k, int d);


int main(void)
{
    int n = 8;
    int k = 10; // max range of integer values ( 0 to k-1)
    int *p = (int *) malloc(sizeof(int) * n);
    int d = 5; // max number of digits for each value
    int i = 0;
    time_t t;
    srand((unsigned) time(&t)); // initialize random number genrator
    int powerfactor = 1;
    for (i = 0; i < d; i++)
    {
        powerfactor *= 10;
    }
    for(i = 0; i < n; i++)
    {
        p[i] = rand() % powerfactor;
    }

    cout << "Before Sorting" << endl;
    for(i = 0; i < n; i++)
    {
        cout<< p[i] <<" ";
    }
    cout << endl;
    radixSort(p, n, k, d);
    cout << "After Sorting" << endl;
    for(i = 0; i < n; i++)
    {
        cout<< p[i] <<" ";
    }
    cout << endl;
    free(p);
}

void radixSort(int* p, int n, int k, int d)
{
    int i = 0;
    cout<<endl;
    for(i = 1; i <= d; i++)
    {
        countingSortForRadixSort(p, n, k, i);
        // For debugging
        int j = 0;
        cout <<"Step " << i <<":"<<endl;
        for(j = 0; j < n; j++)
        {
            cout<< p[j] <<" ";
        }
        cout << endl;
    }
    cout<<endl;
}


void countingSortForRadixSort(int* p, int n, int k, int d)
{
    int *q;
    int *sorted;
    sorted = (int*) malloc(sizeof(int) * (n+1));

    q = (int*) malloc(sizeof(int) * (k+1));
    int i = 0;
    // initialize count of all numbers to 0
    for (i = 0; i <= k; i++)
    {
        q[i] = 0;
    }
    // initialize the sorted for all numbers to 0
    for (i = 0; i < n; i++)
    {
        sorted[i] = 0;
    }
    int powerFactor = 1;
    double shift = 10.0;
    for (i = 0; i < d; i++)
    {
        powerFactor*=10;
        shift *= 0.1;
    }
//cout << "powerFactor" << powerFactor << " shift" << shift << endl;
    // Store all values
    for(i = 0; i< n; i++)
    {
//int op = p[i] %powerFactor;
//cout << " pi is " << p[i] << " op is " << op << " after shifting is " << (p[i]%powerFactor)*shift << endl;
        int m = floor((p[i]%powerFactor)*shift);
//cout << "m is " << m << endl;
        q[m]++; // increment that value
    }
    for(i = 1; i<= k; i++)
    {
        q[i] = q[i] + q[i-1]; // Make it cumulative
    }
    // Sort it
    for(i = n-1; i>= 0; i--) // Note: need start from n-1 to 0 to ensure stability which is needed for radix sort
    {
        int m = floor((p[i]%powerFactor)*shift);
        sorted[q[m]] = p[i]; // start from last value of p , store that point into sorted
        q[m]--;
    }

    // Finally, copy sorted back to original array
    for (i = 0; i < n; i++)
    {
        p[i] = sorted[i+1]; // note: sorted starts from 1 to N including N, it doesn't contain anything at 0.
    }
    free(sorted);
    free(q);
    return;
}
// */
//----------------------------------------------------------------------------------------------------
/* //
// 8 Binary Search
// Time Complexity, T(n) = O(logn)
// Space Complexity, S(n) = O(1)

template <class X>
int binarySearch(X a[], X element, int n);


// returns index of found element or -1 if not found
// a[] contains sorted array to be search
// element is the element being looked for
// n is the total number of elements in sorted array
template <class X>
int binarySearch(X a[], X element, int n)
{
    int first = 0;
    int last = n -1;
    while (first != last)
    {
        if (element <= a[(first+last)/2])
        {
            last  = (first+last)/2 ;
        }
        else // element >= a[(first+last)/2]
        {
            first = (first+last)/2 +  1;
        }
    }
    // Here, either the value is found or it doesn't exist
    if(element == a[first])
    {
        return first;
    }
    else
    {
        return -1;
    }
}
// */
//----------------------------------------------------------------------------------------------------
// 9 Given a sorted array of integers, find range at which a target value exist. 
// Time Complexity, T(n) = O(nlgn)
// Space Complexity, S(n) = O(1)
//---------------------------------
/*
Given a sorted array of integers, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

Question: 

Can there be (-) values?
0-indexing or 1-indexing? 

Function Prototype: 
  	  vector<int> searchRange(vector<int>& nums, int target); 

TEST_VALUE: 
	[5,8,8,9], 8 => [1,2] 
	[5], 5 => [0,0]
	[5,5,7], 7 => [2,2]
	[], 1 => [-1,-1] 

Algorithm: 
	binary search once and find the left most point 
	if found, binary search 2nd time to find right most point
	else return [-1,-1]
and return the range. 

Implementation:
TEST!
*/
//---------------------------------
/* // 
#include <cstdlib>
#include <vector> 
#include <iostream> 
using namespace std; 

int binarySearch(vector<int>& nums, int target, int begin, int end, bool left)
{
	if(end < begin) return -1; 
    int mid = (end - begin)/2 + begin; 
    if(left)
    {
        if(nums[mid] == target && (mid == 0 || nums[mid-1] != target))
        {
            return mid; 
        }
        else if ( nums[mid] >= target)
        {
            end = mid - 1;  
        }
        else
        {
                begin = mid + 1; 
        }
        return binarySearch(nums, target, begin, end, left); 
    }
    else
    {
        if(nums[mid] == target && ((mid == nums.size()-1)  || nums[mid+1] != target))
        {
            return mid; 
        }
        else if ( nums[mid] <= target)
        {
            begin = mid + 1; 
        }
        else
        {
            end = mid - 1;  
        }
        return binarySearch(nums, target, begin, end, left); 
    }
}

vector<int> searchRange(vector<int>& nums, int target)
{
    vector<int> result(2,-1); 
	if(nums.size() == 0) return result; 
    // Search for left most index 
    int left = binarySearch(nums, target, 0, nums.size()-1, true); 
    if(left == -1) return result;  
    result[0] = left; // 1 
    int right = binarySearch(nums, target, 0, nums.size()-1, false); 
    result[1] = right; // 2 
    return result; 
}

int main(void)
{
	vector<int> nums = {5,7,7,8,8,9}; // C++ 11 feature 
	int target = 8; 
	vector<int> result = searchRange(nums, target); 
	for(int i = 0; i < result.size(); i++)
	{
        cout << result[i] << " ";
    }
    cout << endl; 
    return 0; 
}
// */`
//----------------------------------------------------------------------------------------------------
