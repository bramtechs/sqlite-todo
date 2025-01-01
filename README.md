# SQLite Todo App

A simple TODO-list manager that uses an SQLite database and shows off the
command, singleton and iterator pattern. Written in modern C++.

## Compilation

### Windows

```Desktop Development with C++``` needs to be installed for Visual Studio.

Run with ```Developer Command Prompt for VS 2022```:

```cmd
cmake --preset windows

```

Open the Visual Studio solution in the build folder or run:
```cmd
cmake --build build --parallel
call build\Debug\sqlite_todo.exe
```

### MacOS (Untested)

CMake and XCode is required.

```sh
cmake --preset mac
```

Open the XCode project placed in the build directory.

## Credits

- [SQLitePlus library](https://github.com/yuqian5/SQLitePlus)
- [SQLite C library](https://www.sqlite.org/)
