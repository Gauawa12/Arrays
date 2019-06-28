
Given an array A[] of N positive integers which can contain integers from 1 to N where elements can be repeated or can be 
absent from the array. Your task is to count frequency of all elements from 1 to N.

Note: Expected time complexity is O(n) with O(1) extra space.

Input Format:
First line of input contains an integer T denoting the number of test cases. For each test case, first line contains an
integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the
elements of the array.

Output Format:
For each test case, output N space-separated integers denoting the frequency of each element from 1 to N.

Your Task:
You need to complete the function printfrequency and print frequency of each element. The newline is automatically added by
the driver code.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
1 <= A[i] <= 106

Example:
Input:
2
5
2 3 2 3 5
4
3 3 3 3

Output:
0 2 2 0 1
0 0 4 0

Explanation:
Testcase 1: Counting frequencies of each array elements, we have:
1 occurring 0 times.
2 occurring 2 times.
3 occurring 2 times.
4 occurring 0 times.
5 occurring 1 time.


Sol 1: 

void printfrequency(int a[], int n)
{ 
	for(int i=0;i<n;i++)
	{
	    while(a[i]!=i+1)
	    {
	        if(a[a[i]-1]==a[i])
	        {
	            break;
	        }
	        else
	        {
	            swap(a[i],a[a[i]-1]);
	        }
	        
	    }
	}
	for(int i=0;i<n;i++)
	{
	    if(a[i]!=(i+1))
	    {
	        a[i]=(-1)*a[i];
	    }
	    else
	    {
	        a[i]=1;
	    }
	}
	for(int i=0;i<n;i++)
	{
	    if(a[i]<0)
	    {
	        a[abs(a[i])-1]++;
	        a[i]=0;
	    }
	}
	for(int i=0;i<n;i++)
	{
	    cout<<a[i]<<" ";
	}
	
} 



// Optimized Approach
/*
first subtract 1 from all elements to get them in range.
Suppose a[i]=5 then add n to the a[5], so all the indexes which are absent will always be less than n, as you are adding on
the go the original value can be accessed by a[a[i]%n]
Finally print by taking integer division.
*/
void printfrequency(int a[], int n)
{ 
	for(int i=0;i<n;i++)
	{
	    a[i]--;
	}
	for(int i=0;i<n;i++)
	{
	    a[a[i]%n]+=n;
	}
	
	for(int i=0;i<n;i++)
	{
	    if(a[i]<n)
	    {
	        cout<<"0"<<" ";
	    }
	    else
	    {
	        cout<<floor(a[i]/n)<<" ";
	    }
	}
	
} 

