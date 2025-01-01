# SQLite Todo App

Simple TODO-list manager that uses SQLite database and shows off the
singleton and iterator pattern.

## Compilation

### Windows

```Desktop Development with C++``` needs to be installed in Visual Studio.

Run from ```Developer Command Prompt for VS 2022```.

```sh
cmake --preset windows

```

Open the Visual Studio solution in the build folder or run:
```
cmake --build build --parallel
```

### MacOS

CMake and XCode is required.

```sh
cmake --preset mac
```

Open the XCode project placed in the build directory.

## Credits

- [SQLitePlus library](https://github.com/yuqian5/SQLitePlus)
