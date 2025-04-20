# hex-generator

A simple utility to generate every hex number between two given ones.

Example:
0x0000 0x0010 would generate:

0x0000
0x0001
0x0002
0x0003
0x0004
0x0005
0x0006
0x0007
0x0008
0x0009
0x000A
0x000B
0x000C
0x000D
0x000E
0x000F
0x0010

(16 values)

# Building from source
Since this program is just one C file, building is extremely simple.
```
gcc main.c -o hex-generate
```
(or whatever your favourite C compiler is)

And... that's it.
I suppose if you really wanted to make this easier to use, you could
export this into your .bashrc so you can use it in any directory.

# How to use?
( This wasn't tested on Windows but I'm pretty sure it will work just the same. )

This takes three arguments.

```
hex-generate 0x0000 0x0010 output.txt
```

Argument 1: The start hex value.
Argument 2: The ending hex value.
Argument 3: Filename to write to.
(Warning) this calls ```fopen(filename, "w");```, so if you pass the name of a file
that already exists in the current working directory, this program will overwrite the contents of said file.

Basically, this is mostly self-explanatory.

# Why did you make this?
Because one of my projects is working with Unicode characters,
and I needed a quick way to generate a bunch of Unicode codepoints so I don't
have to manually type 800+ characters.
