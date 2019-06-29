
The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.

Input: 
First line contains number of test cases T. First line of each test case contains an integer value N denoting the number of days, followed by an array of stock prices of N days. 

Output:
For each testcase, output all the days with profit in a single line. And if there is no profit then print "No Profit".

User Task:
The task is to complete the function stockBuySell() which finds the days of buying and selling stock and print them. The newline is automatically added by the driver code.

Constraints:
1 <= T <= 100
2 <= N <= 103
0 <= Ai <= 104

Example
Input:
3
7
100 180 260 310 40 535 695
10
23 13 25 29 33 19 34 45 65 67
5
4 2 2 2 4

Output:
(0 3) (4 6)
(1 4) (5 9)
(3 4)

Explanation:
Testcase 1: We can buy stock on day 0, and sell it on 3rd day, which will give us maximum profit.

Note: Output format is as follows - (buy_day sell_day) (buy_day sell_day)


/*



Sol: 

void stockBuySell(int a[], int n)
{
    
    vector<int>v(n+1,1);
    vector<pair<int,int>>ans;
    int flag=0;
    for(int i=1;i<n+1;i++)
    {
        if(a[i]<=a[i-1])
        {
            v[i]=-1;
        }
    }
    v[n]=-1;
    
    for(int i=1;i<n+1;i++)
    {
        if(v[i]!=-1)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        int minv=a[0];
        int mini=0;
        for(int i=1;i<n+1;i++)
        {
                if(v[i]>0)
                {
                     if(a[i]<minv)
                    {
                        minv=a[i];
                        mini=i;
                    }
                }
        
                else
                {
                    
                         if(mini!=(i-1))
                         {
                             ans.push_back(make_pair(mini,i-1));
                         }
                         while(v[i]==-1)
                         {
                             i++;
                         }
                         i--;
                         minv=a[i];
                         mini=i;
                     
                }
        }
    
        for(auto x:ans)
        {
         cout<<"("<<x.first<<" "<<x.second<<")"<<" ";
        }
    }
    else
    {
        cout<<"No Profit";
    }
    
    
}


