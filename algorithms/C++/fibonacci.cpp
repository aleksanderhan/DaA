#include <Python.h>
#include <math.h>

// 128-bit integer
struct I128 {
    unsigned char I128[128]; 
};

// Fast doubling fibonacci algortihm
long long* fdfib(int n) {
    static long long res[2];
    if (n == 0) {
        res[0] = 0;
        res[1] = 1;
        return res;
    } else {
        long long *a = fdfib(n/2);
        long long b = a[0]*(a[1]*2 - a[0]);
        long long c = a[0]*a[0] + a[1]*a[1];
        if (n%2 == 0) {
            res[0] = b;
            res[1] = c;
            return res;
        } else {
            res[0] = c;
            res[1] = b + c;
            return res;
        }
    }
}
