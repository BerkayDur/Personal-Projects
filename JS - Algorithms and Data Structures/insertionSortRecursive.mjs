export default function insertionSortRecursive(A,n=A.length){
    if (n===1){
        return;
    }
    insertionSortRecursive(A,n-1);
    const key = A[n-1];
    let i = n-2;
    while (i>=0 && A[i]>key){
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = key;
}