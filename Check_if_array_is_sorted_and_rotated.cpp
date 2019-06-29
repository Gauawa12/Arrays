
Given an array arr[] of N distinct integers, check if this array is Sorted (non-increasing or non-decreasing) and Rotated 
counter-clockwise. Note that input array may be sorted in either increasing or decreasing order, then rotated.
A sorted array is not considered as sorted and rotated, i.e., there should be at least one rotation.

Input:
The first line of input contains number of testcases T. Each testcase contains 2 lines, the first line contains N, the
number of elements in array, and second line contains N space separated elements of array.

Output:
Print "Yes" if the given array is sorted and rotated, else Print "No", without Inverted commas.

User Task:
The task is to complete the function checkRotatedAndSorted() which checks if an array is sorted and rotated clockwise.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= A[i] <= 106

Example:
Input:5
4
3 4 1 2
3
1 2 3
4
10 20 30 14
5
30 20 10 50 35
5
30 20 10 50 25

Output:
Yes
No
No
Yes
No

Explanation:
Testcase 1: The array is sorted (1, 2, 3, 4) and rotated twice (3, 4, 1, 2).
Testcase 2: The array is sorted (1, 2, 3) is not rotated.
Testcase 3: The array is sorted (10, 20, 30, 14) is not sorted and rotated as 14 is greater than 10.


Sol : 

bool checkRotatedAndSorted(int a[], int n){
    
    int ma=0,mi=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[ma])
        {
            ma=i;
        }
        if(a[i]<a[mi])
        {
            mi=i;
        }
    }
    if(mi==0 && ma==(n-1))
    {
        return false;
    }
    if(mi>ma)//increasing sorted
    {
        int x=mi;
        mi--;
        while(x%n!=mi)
        {
            if(a[(x+1)%n]<a[x%n])
            {
                return false;
            }
            else
            {
                x++;
            }
        }
        return true;
    }
    else
    {
        int x=ma;
        ma--;
        while(x%n!=ma)
        {
            if(a[(x+1)%n]>a[x%n])
            {
                return false;
            }
            else
            {
                x++;
            }
        }
        return true;
    }
    
}

/*
O(n)
if the array was sorted then starting from minimum element to maximum element it should satisfy the increasing or decreasing 
property. So find the minindex(mi) and maxindex(ma). If mi>ma it means that the array was sorted in increasing order hence use 
modulus property to check till ma. Similarly if ma>mi it means sorted in decreasing order.
*/
