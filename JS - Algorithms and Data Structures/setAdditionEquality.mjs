export default function setAdditionEquality(A, x){
    // This takes as input an ordered set A and a value x. If the sum of 2 set numbers in A add to x
    // then return true, else return false.
    let [i, j] = [0, A.length-1];
    while (i<=j){
        const result = A[i] + A[j];
        if (result === x){
            return true;
        }
        else if (result > x){
            j--;
        }
        else if (result < x){
            i++;
        }
    }
    return false;
}