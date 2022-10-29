export default function findMaxSubarrayBruteForce(A, low=0, high=A.length){
    let [leftIndex, rightIndex, highestSum] = [0,0,-Infinity];
    for (let i=low; i<high; i++){
        let sum=0;
        for (let j=i; j<high; j++){
            sum+=A[j];
            if (sum> highestSum){
                highestSum=sum;
                leftIndex=i;
                rightIndex=j;
            }
        }
    }
    return {maxLeft:leftIndex, maxRight:rightIndex, sum:highestSum};
}
