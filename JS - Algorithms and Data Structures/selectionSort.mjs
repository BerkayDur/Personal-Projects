export default function selectionSort(A){
    // Function takes as input an Array, A, that it sorts and returns. (It modifies the array A).
    for (let i=0; i<A.length-1; i++){
        let smallest = i;
        
        for (let j=i+1;j<A.length;j++){
            if (A[j]<A[smallest]){
                smallest = j;
            }
        }
        [A[i], A[smallest]] = [A[smallest], A[i]];
    }
    return A;
}