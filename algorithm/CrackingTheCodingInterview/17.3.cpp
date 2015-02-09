int NumZeros(int n){
    if(n < 0) return -1;
    int num = 0;
    while((n /= 5) > 0){
        num += n;
    }
    return num;
}