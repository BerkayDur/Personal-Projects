export default function(testFunc, ...input){
    const start = Date.now();
    testFunc(...input);
    const end = Date.now();
    return end - start;
}