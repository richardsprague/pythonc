#include <Python.h>

// This is a simple demo of how to write a C module that can be called from Python
// borrowed from: https://tutorialedge.net/python/python-c-extensions-tutorial/#our-fibonacci-function
// In this example, the module is called 'myModule'.
// If you want to call it e.g 'something', replace all occurrences of 'myModule' with 'something'
// The order in which these C functions are written matters.

// Function 1: A simple 'hello world' function
static PyObject* helloworld(PyObject* self, PyObject* args)
{
    printf("Hello World\n");
    return Py_None;
}


// Function 2: A C fibonacci implementation
// this is nothing special and looks exactly
// like a normal C version of fibonacci would look
int Cfib(int n)
{
    if (n < 2)
        return n;
    else
        return Cfib(n-1)+Cfib(n-2);
}


// Our Python binding to our C function
// This will take one and only one non-keyword argument
static PyObject* fib(PyObject* self, PyObject* args)
{
    // instantiate our `n` value
    int n;
    // if our `n` value
    if(!PyArg_ParseTuple(args, "i", &n))
        return NULL;
    // return our computed fib number
    return Py_BuildValue("i", Cfib(n));
}

// Our Module's Function Definition struct
// Add new methods with another '{ ... }` section and the following format
// { "methodname", c function to call, number of args, "comment string" }
// We require this `NULL` to signal the end of our method
// definition
static PyMethodDef myMethods[] = {
    { "helloworld", helloworld, METH_NOARGS, "Prints Hello World" },
    { "fib",fib,1,"calculate fibonacci value"},
    { NULL, NULL, 0, NULL }
};

// Our Module Definition struct
static struct PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT,
    "myModule",  /* name of module */
    "Test Module", /* module documentation, may be NULL */
    -1, /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    myMethods
};

// Initializes our module using our above struct
PyMODINIT_FUNC PyInit_myModule(void)
{
    return PyModule_Create(&myModule);
}
