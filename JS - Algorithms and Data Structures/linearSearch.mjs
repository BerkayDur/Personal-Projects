export default function linearSearch(A, v){
    // This function takes as input an Array, A, that we will search for the value v.
    // If this array contains the value, v, we will return the index of the first instance of that value.
    // If v is not in A then return -1.
    for (let i=0;i<A.length;i++){
        if (A[i]===v){
            return i;
        }
    }
    return -1;
}