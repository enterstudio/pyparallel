#include "Python.h"

#define _LOAD(n) do {                                                          \
    PyObject *mod;                                                             \
    extern PyObject *PyInit_##n();                                             \
    mod = PyInit_##n();                                                        \
    if (!mod)                                                                  \
        return 0;                                                              \
    if (PyModule_AddObject(m, #n, mod))                                        \
        return 0;                                                              \
} while (0)

#define _LOAD_CPP(n) do {                                                      \
    PyObject *mod;                                                             \
    extern PyObject *_load_##n();                                              \
    mod = _load_##n();                                                         \
    if (!mod)                                                                  \
        return 0;                                                              \
    if (PyModule_AddObject(m, #n, mod))                                        \
        return 0;                                                              \
} while (0)

int
_load_cython_windows_modules(PyObject *m)
{
    _LOAD(base);
    _LOAD(types);
    _LOAD(constants);
    //_LOAD(rtl);
    _LOAD(processthreads);
    _LOAD(user);
    //_LOAD(adv);
    _LOAD(avrt);
    _LOAD(threadpool);
    _LOAD_CPP(gdiplus);
    return 1;
}

/* vim:set ts=8 sw=4 sts=4 tw=80 et nospell:                                  */
