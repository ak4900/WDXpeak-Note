// three method 
// first two - recursive
// third one - dp

int f[9999];

int getCount(int n)
{
    if (n == 1) {
        return 1;
    }
    
    if (n == 2) {
        return 2;
    }
    
    if (n == 3) {
        return 4;
    }
    
    return getCount(n-1)+getCount(n-2)+getCount(n-3);
}

int getCount1(int n)
{
    if (n < 0) {
        return 0;
    }
    else if (n== 0)
    {
        return 1;
    }
    else
    {
        return getCount1(n-1)+getCount1(n-2)+getCount1(n-3);
    }
    
    return getCount(n-1)+getCount(n-2)+getCount(n-3);
}

int getCount2(int n)
{
    f[1] = 1;
    f[2] = 2;
    f[3] = 4;
    
    if (n <= 3) {
        return f[n];
    }
    else{
        for (int i = 4; i <= n; i++) {
            f[i] = f[i-1] + f[i-2] + f[i-3];
        }
    }
    
    return f[n];
}