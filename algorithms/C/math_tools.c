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

// Returns the n-th fibonacci number
static PyObject* fib(PyObject* self, PyObject* args)
{
    int n;
    if (!PyArg_ParseTuple(args, "i", &n)) {
      return NULL;
    }

    long long *res = fdfib(n);
    return Py_BuildValue("l", res[0]);
}

// Returns list of the first n fibonacci numbers
static PyObject* fiblist(PyObject* self, PyObject* args)
{
    int n;
    if (!PyArg_ParseTuple(args, "i", &n)) {
      return NULL;
    }

    return Py_BuildValue("l", 1);
}

// Method Mapping Table
static PyMethodDef module_funcs[] = {
    {"fib", (PyCFunction)fib, METH_VARARGS, "Returns the n-th fibonacci number"},
    {"fiblist", (PyCFunction)fib, METH_VARARGS, "Returns list of the first n fibonacci numbers"},
    {NULL, NULL, 0, NULL} 
};

// Initialization Function
void initmath_tools(void) 
{
    Py_InitModule3("math_tools", module_funcs, "Various mathematical algorithms");
}