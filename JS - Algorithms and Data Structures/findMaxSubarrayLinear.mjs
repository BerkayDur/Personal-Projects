export default function findMaxSubarrayLinear(A, start=0, end=A.length){
    let [lowIndex, highIndex, totalSum, revolvingSum, revolvingLow] = [0,0,-Infinity, 0, 0];
    for (let i=start;i<end;i++){
        revolvingSum += A[i];
        if (revolvingSum > totalSum){
            lowIndex = revolvingLow;
            highIndex = i;
            totalSum = revolvingSum;
        }
        else if (revolvingSum < 0){
            revolvingSum = 0;
            revolvingLow = i + 1; 
        }
    }
    return totalSum;
}





function reDo(A, low=0, high=A.length){
    let [leftIndex, rightIndex, totalSum] = [0,0,-Infinity];
    let [rSum, rLeftIndex] = [0,0];
    for (let i =0; i<high; i++){
        rSum += A[i];
        if (rSum > totalSum){
            [leftIndex, rightIndex, totalSum] = [rLeftIndex, i, rSum];
        }
        else if (rSum < 0){
            rLeftIndex = i + 1;
            rSum = 0;
        }
    }
    return totalSum
}

console.log(reDo([13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7]));
console.log(findMaxSubarrayLinear([1,-2,2,-1,2,-5]))