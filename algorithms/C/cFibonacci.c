#include <Python.h>


// Iterative fibonacci method
static PyObject* ifib(PyObject* self, PyObject* args)
{
    int n;
    if (!PyArg_ParseTuple(args, "i", &n)) {
      return NULL;
    }

    if (n < 0) {
        return Py_BuildValue("i", -1);
    } else if (n == 0)  {
        return Py_BuildValue("i", 0);
    } else if (n == 1) {
        return Py_BuildValue("i", 1);
    } else {
        int i = 2;
        long f = NULL;
        long f_ = 1;
        long f__ = 1;
        while (i < n) {
            f = f_ + f__;
            f__ = f_;
            f_ = f;
            i++;
        }
        return Py_BuildValue("l", f);
    }
}


long _rfib(int n) {
    if (n < 0) {
        return -1;
    } else if (n == 0) {
        long f0 = 0;
        return f0;
    } else if (n == 1) {
        long f1 = 1;
        return f1;
    } else {
        return _rfib(n-1) + _rfib(n-2);
    }
}

// Recursive fibonacci method
static PyObject* rfib(PyObject* self, PyObject* args)
{
    int n;
    if (!PyArg_ParseTuple(args, "i", &n)) {
      return NULL;
    }
    
    return Py_BuildValue("l", _rfib(n));
}

// Method Mapping Table
static PyMethodDef module_funcs[] = {
    {"ifib", (PyCFunction)ifib, METH_VARARGS, "Iterative fibonacci."},
    {"rfib", (PyCFunction)rfib, METH_VARARGS, "Iterative fibonacci."},
    {NULL, NULL, 0, NULL} 
};

// Initialization Function
void initcFibonacci(void) 
{
    Py_InitModule3("cFibonacci", module_funcs, "Different implementations of algorithms to compute fibonacci numbers.");
}