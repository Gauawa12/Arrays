
Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] <= A[j].

Input:
The first line contains an integer T, depicting total number of test cases.  Then T test case follows. First line of each test case contains an integer N denoting the size of the array. Next line contains N space separated integeres denoting the elements of the array.

Output:
Print the maximum difference of the indexes i and j in a separtate line.

User Task:
The task is to complete the function maxIndexDiff() which finds and returns maximum index difference. Printing the output will be handled by driver code.

Constraints:
1 ≤ T ≤ 1000
1 ≤ N ≤ 107
0 ≤ A[i] ≤ 1018

Example:
Input:
2
2
1 10
9
34 8 10 3 2 80 30 33 1

Output:
1
6

Explanation:
Testcase 1:  In the given array A[1] < A[7] satisfying the required condition(A[i] <= A[j]) thus giving the maximum difference of j - i which is 6(7-1).


Sol:

int maxIndexDiff(int a[], int n) 
{ 
    
    int l[n];
    l[0]=a[0];
    for(int i=1;i<n;i++)
    {
        l[i]=min(l[i-1],a[i]);
    }
    int r[n];
    r[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        r[i]=max(r[i+1],a[i]);
    }
    int i=0,j=0;
    int ans=0;
    while(i<n && j<n)
    {
        if(r[j]>=l[i])
        {
            ans=max(ans,(j-i));
            j++;
        }
        else
        {
            i=i+1;
        }
    }
    return ans;
    
}
