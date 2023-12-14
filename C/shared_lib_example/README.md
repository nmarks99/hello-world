Current directory for this example:
```
├── README.md
├── foo.c
├── foo.h
└── main.c
```

1. Compile library into an object file with "-fPIC" flag. This creates a "foo.o" file
```
gcc -c -fpic foo.c
```

2. Create a shared library from the object file. This creates a libfoo.so
```
gcc -shared -o libfoo.so foo.o
```

3. Link an executable with the shared library. `-L.` says to look in the current directory,
`-lfoo` says to link a file called libfoo.so.
```
gcc -L. -o test main.c -lfoo
```

4. Make the library available at runtime.
- Option A: Add project directory to `$LD_LIBRARY_PATH` environment variable
    - `export LD_LIBARY_PATH=.:$LD_LIBRARY_PATH`
- Option B: Use rpath
    - `gcc -L./ -Wl,-rpath=./ -o test main.c -lfoo`
