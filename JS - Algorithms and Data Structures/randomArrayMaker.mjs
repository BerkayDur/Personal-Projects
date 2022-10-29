function randomNumber(low, high){
    return Math.floor(Math.random()*(high-low+1)) + low;
}

export default function randomArrayMaker(low, high, size){
    let A = new Array(0);
    for (let i=0; i<size;i++){
        A.push(randomNumber(low,high));
    }
    return A;
}