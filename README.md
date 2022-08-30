# tictoctoe

🖊 A simple tic toc toe made in C++.

```
    1   2   3
 A  O │ X │  
   ───┼───┼───
 B  O │ X │  
   ───┼───┼───
 C    │ X │  

X played at A2
O played at B1
X played at B2
O played at A1
X played at C2

Winner: X
```

**The program will clear the screen every render.**

# Usage

You have to enter the position where you want to place your symbol (X or O).

```
Player X turn

Enter a position (e.g. A2):
```

For win, you need to align 3 of your symbols in a row.

# Building

You can you any build system.

If you want to build with built-in script, you will need `g++`.

## Building with G++

Linux, maxOs :

```bash
$ ./build.sh
```

The built binary is located in `dist/tictoctoe`.

Windows :

```bat
> ./build.bat
```

The built binary is located in `dist/tictoctoe.exe`.
