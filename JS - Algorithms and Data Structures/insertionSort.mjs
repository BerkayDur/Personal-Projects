export default function insertionSort(A){
    // Insertion Sort Algorithm that sort an array A of numbers in ascending order and returns the Array A
    // Note that this function modifies the Array A instead of returning a new array
    for (let j=1; j<A.length;j++){
        let key = A[j];
        let i = j-1;
        while (i>=0 && A[i]>key){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
    return A;
}