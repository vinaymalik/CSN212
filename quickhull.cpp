#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> iPair;

set<iPair> hull;
 
int find_side(iPair a, iPair b, iPair p)
{
    int val = (p.second - a.second) * (b.first - a.first) - (b.second - a.second) * (p.first - a.first);
 	if (val == 0) return 0;
    if (val < 0) return -1;
    return 1;
}
int dist(iPair p, iPair q)
{
    return (p.second - q.second) * (p.second - q.second) + (p.first - q.first) * (p.first - q.first);
}

int linedistSq(iPair a, iPair b, iPair p)
{
    return abs((p.second - a.second) * (b.first - a.first) - (b.second - a.second) * (p.first - a.first));
}
void quickHull(iPair A[], int n, iPair a, iPair b, int side)
{
    int index = -1;
    int max_distSq = 0;
    for (int i=0; i<n; i++)
    {
        int temp = linedistSq(a, b, A[i]);
        if (find_side(a, b, A[i]) == side && temp > max_distSq)
        {
            index = i;
            max_distSq = temp;
        }
    }
    if (index == -1)
    {
        hull.insert(a);
        hull.insert(b);
        return;
    }
 
    quickHull(A, n, A[index], a, -find_side(A[index], a, b));
    quickHull(A, n, A[index], b, -find_side(A[index], b, a));
}
 
void printHull(iPair A[], int n)
{
    if (n<3){
        cout << "Convex hull isnot possible"<<endl;
        return;
    }
    int minofx = 0, maxofx = 0;
    for (int i=1; i<n; i++)
    {
        if (A[i].first < A[minofx].first)
            minofx = i;
        if (A[i].first > A[maxofx].first)
            maxofx = i;
    }
    quickHull(A, n, A[minofx], A[maxofx], 1);
    quickHull(A, n, A[minofx], A[maxofx], -1);
 
    cout<<"The convex hull contains "<<hull.size()<<" points on it"<<endl;
	for(int i=0;i<hull.size();i++){
        cout<<"("<<(*hull.begin()).first<<", "<<(*hull.begin()).second<< \") ";
    
    }
    return;
}
 
// Driver code
int main()
{
    iPair A[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
               {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(A)/sizeof(A[0]);
    printHull(A, n);
    return 0;
}
