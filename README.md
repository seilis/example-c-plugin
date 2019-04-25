# C Plugin Example
This is a simple example making a plugin in C.

## Build
Compiling is simple since we're using autotools:
```
autoreconf -i
./configure
make
```
If you wish to install, you can issue the final:
```
make install
```

## Run the example
After building, you can run the example program with:
```
./plugintest
```
