int Solution::maxSubArray(const vector<int> &A) {
    
    int maxSoFar = 0, overallMax = 0, check = 0, k = 0, min;
    
    for(int i = 0; i < A.size(); i++){
        maxSoFar = maxSoFar + A[i];
        if(maxSoFar < 0){
            maxSoFar = 0;
        }
        if(maxSoFar > overallMax){
            overallMax = maxSoFar;
        }
        if(A[i] < 0){
            k++;
            if(k == 1){
                min = A[i];
            }
            if(A[i] > min){
                min = A[i];
            }
            check++;
        }
    }
    
    if(check == A.size()){
        overallMax = min; 
    }
    
    return overallMax;
}
