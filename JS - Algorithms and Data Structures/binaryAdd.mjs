export default function binaryAdd(A,B){
    // This function expects an array of binary values A and B of the same length.
    // It will then add these and return a new array of the binary values.
    const C = new Array(A.length+1);
    let hold = 0;
    for (let i=A.length-1;i>=0;i--){
        C[i+1] = A[i] + B[i] + hold;
        if (C[i+1]/2>=1){
            C[i+1] -=2;
            hold = 1;
        }
        else {
            hold = 0;
        }
    }
    C[0] = hold;
    return C
}