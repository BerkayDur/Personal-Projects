function maxCrossingSubarray(A, low=0, mid=Math.floor((A.length + low)/2), high=A.length){
    let [leftSum, rightSum] = [-Infinity, -Infinity];
    let [maxLeft, maxRight] = [0,0];
    for (let sum=0, i=mid-1; i>=0;i--){
        sum += A[i];
        if (sum >= leftSum){
            leftSum = sum;
            maxLeft = i;
        }
    }
    for (let sum=0, j=mid; j<high; j++){
        sum += A[j];
        if (sum >= rightSum){
            rightSum = sum;
            maxRight = j;
        }
    }
    return {maxLeft, maxRight, sum:leftSum+rightSum};
}


export default function findMaxSubarray(A, low=0, high=A.length){
    if (high === low + 1){
        return {maxLeft:low, maxRight:high, sum:A[low]};
    }
    else {
        const mid = Math.floor((low+high)/2);
        const {maxLeft:leftLow, maxRight:leftHigh, sum:leftSum} = findMaxSubarray(A, low, mid);
        const {maxLeft:rightLow, maxRight:rightHigh, sum:rightSum} = findMaxSubarray(A, mid, high);
        const {maxLeft:crossLow, maxRight:crossHigh, sum:crossSum} = maxCrossingSubarray(A, low, mid, high);
        if (leftSum>= rightSum && leftSum>=crossSum){
            return {maxLeft:leftLow, maxRight:leftHigh, sum:leftSum};
        }
        else if (rightSum>= leftSum && rightSum>=crossSum){
            return {maxLeft:rightLow, maxRight:rightHigh, sum:rightSum};
        }
        else {
            return {maxLeft:crossLow, maxRight:crossHigh, sum:crossSum};
        }
    }
}

