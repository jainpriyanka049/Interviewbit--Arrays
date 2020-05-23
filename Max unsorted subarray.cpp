/*

You are given an array (zero indexed) of N non-negative integers, A0, A1 ,�, AN-1.
Find the minimum sub array Al, Al+1 ,�, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
If A is already sorted, output -1.

Example :

Input 1:

A = [1, 3, 2, 4, 5]

Return: [1, 2]

Input 2:

A = [1, 2, 3, 4, 5]

Return: [-1]
In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.

*/

vector<int> Solution::subUnsort(vector<int> &A) {
    int n=A.size();
    vector<int>res;
    int s=-1,e=-1;
    for(int i=0;i<n-1;i++){
        if(A[i]>A[i+1]){
            s=i;
            break;
        }
    }
    if(s==-1){
        res.push_back(-1);
        return res;
    }
    for(int i=n-1;i>0;i--){
        if(A[i]<A[i-1]){
            e=i;
            break;
        }
    }
   // cout<<s<<" "<<e<<endl;
    int minm=A[s],maxm=A[s];
    for(int i=s+1;i<=e;i++){
        if(A[i]<minm)
         minm=A[i];
        else if(A[i]>maxm)
         maxm=A[i];
    }
    for(int i=0;i<s;i++){
        if(A[i]>minm){
         s=i;
         break;
        }
    }
    for(int i=n-1;i>e;i--){
        if(A[i]<maxm){
         e=i;
         break;
        }
    }
    res.push_back(s);
    res.push_back(e);
    return res;
}
