

Given K sorted arrays arranged in form of a matrix. The task is to merge them. You need to complete mergeKArrays() function which takes 2 arguments, an arr[k][k] 2D Matrix containing k sorted arrays and an integer k denoting the number of sorted arrays. The function should return a pointer to the merged sorted arrays.

Input:
The first line of input contains the number of test cases, then T test cases follows. Each test case will contain an integer N denoting the number of sorted arrays. Then in the next line contains all the elements of the array separated by space.

Output:
The output will be the sorted merged array.

User Task:
The task is to complete the function mergeKArrays() which takes two arguments, and returns pointer to the modified array.

Constraints:
1 <= T <= 50
1 <= N <= 103
1 <= K <= 10

Example:
Input:
1
3
1 2 3 4 5 6 7 8 9 

Output:
1 2 3 4 5 6 7 8 9

Explanation:
Testcase 1:
Above test case has 3 sorted arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],

             [4, 5, 6],

             [7, 8, 9]]
The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].


Sol:

// function should return an pointer to output array int*
// of size k*k
int *mergeKArrays(int a[][N], int k)
{
    int *ans=new int[k*k];
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    for(int i=0;i<k;i++)
    {
        pq.push(make_pair(a[i][0],make_pair(i,0)));
    }
    int x=0;
    while(!pq.empty())
    {
        auto t=pq.top();
        pq.pop();
        ans[x]=t.first;
        x++;
        int i=t.second.first;
        int j=t.second.second;
        if(j<k-1)
        {
            pq.push(make_pair(a[i][j+1],make_pair(i,j+1)));
        }
        
    }
    return ans;
}

