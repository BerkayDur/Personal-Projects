function merge(A,p,q,r){
    const [n1, n2] = [q-p, r-q];
    const [L, R] = [new Array(n1), new Array(n2)];
    for (let i = 0; i<n1; i++){
        L[i] = A[p+i];
    }
    for (let j=0; j<n2; j++){
        R[j] = A[q+j];
    }
    let [i,j] = [0,0];
    for (let k = p; k<r; k++){
        if (j>=n2 || L[i]<=R[j]){
            A[k] = L[i++];
        }
        else {
            A[k] = R[j++];
        }
    }
    return A;
}

export default function mergeSort(A, p, r){
    if (p+1<r){
        const q = Math.floor((p+r)/2);
        mergeSort(A,p,q);
        mergeSort(A,q,r);
        merge(A,p,q,r);
    }

}