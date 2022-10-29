export default function binarySearch(A,p,r,v){
    // This takes as input a sorted array A and searched for a value v within it.
    if (p>r){
        return -1;
    }
    const m = Math.floor((p+r)/2);
    if (A[m]===v){
        return m;
    }
    else if (A[m]<v){
        return binarySearch(A,m+1,r,v);
    }
    else {
        return binarySearch(A,p,m,v);
    }
}