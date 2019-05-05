This example is based on [a tutorial](https://tutorialedge.net/python/python-c-extensions-tutorial/#our-fibonacci-function) by Elliot Forbes.

The C code is in `pythonc.c`.

Get the whole thing to run by typing the following in the command line:

```sh
$ python setup.py install
$ python setup.py build
```

After it's built, you'll have a new module you can call from within Python:

```python
>>> import myModule
>>> myModule.helloworld()
>>> myModule.fib(10)

```

If you want to change anything, see the comments in `python.c` and `setup.py`

Full documentation on how to extend Python with C is at [docs.python.org](https://docs.python.org/3.7/extending/extending.html)



