You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.
Note: Expected solution in O(n) time using constant extra space.

Input:
First line consists of T test cases. First line of every test case consists of N, denoting the number of elements in array. Second line of every test case consists of elements in array.

Output:
Single line output, print the smallest positive number missing.

User Task:
The task is to complete the function missingNumber() which returns the smallest positive missing number in the array.

Constraints:
1 <= T <= 100
1 <= N <= 106
-106 <= arr[i] <= 106

Example:
Input:
2
5
1 2 3 4 5
5
0 -10 1 3 -20
Output:
6
2

Explanation:
Testcase 1: Smallest positive missing number is 6.
Testcase 2: Smallest positive missing number is 2.


Sol : 

int getnum(int a[],int n)
{
    for(int i=0;i<n;i++)
    {   if(a[abs(a[i])-1]>0 && (abs(a[i])) - 1 < n ){
        a[abs(a[i])-1]=(-1)*a[abs(a[i])-1];}
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>0)
        {
            return i+1;
        }
    }
    return n+1;
}


int missingNumber(int a[], int n) { 
    
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<=0)
        {
            swap(a[i],a[j]);
            j++;
        }
    }
    
    int ans=getnum(a+j,n-j);
    return ans;
    
} 

Sol 2: nlogn approach

int missingNumber(int arr[], int n) { 
    
   sort(arr,arr+n);
   int m=1;
   for(int i=0;i<n;i++)
   {
       if(arr[i]==m)
       {
           m++;
       }
   }
   if(m==arr[n-1])
   {
       return m+1;
   }
   else
   {
       return m;
   }
    
