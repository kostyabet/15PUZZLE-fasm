# 15 PUZZLE

<img src="redme_picks\15puzzle.png" width="250">

![Static Badge](https://img.shields.io/badge/Flat_Assembler-1.73.32-blue)
![Static Badge](https://img.shields.io/badge/Fasm_Editor-2.0-yellow)
![Static Badge](https://img.shields.io/badge/OllyDbg-1.10-red)

<h3>Flat assembler 15 PUZZLE game for MS-DOS.</h3>

## Content
- [Download](#download)
- [Using](#using)
- [Project structure](#project-structure)
- [Code Refactoring](#code-refactoring)
- [Gratitude](#gratitude)

## Download

You can use last release version for playing in puzzle.

| ⚠️ **Attention**                                                                                                                                                                                                                                                  |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| This project was done on FASM in <a href="https://wiki.osdev.org/Real_Mode">`real processor mode`</a> under `MS-DOS`. Since there was no page addressing before, the executable file of the program will not run on modern operating systems `Windows 8, 10, 11.` |

The executable file has the format `*.com` format and any com file executor under Windows is required to run it.
You can use `DOSBox`.

1. Install <a href="https://www.dosbox.com">`DOSBox`</a> on your computer. Use <a href="https://www.dosbox.com/download.php?main=1">this link</a>.
2. Install `*.com` file from release.

## Using

1. Place the `DOSBox` executable file and the `*.com` executable file in the same directory.
2. Left-click the `*.com` file and drag it onto the `DOSBox` executable.
3. Play!!!

## Project Structure

```plaintext
├── Units       
│   ├── System / Sound / Random / Mouse / Game    # System - main blocks code                 
│   │   │                                         # Sound - all sounds code
│   │   ├── *.c     # Source code                 # Random - random functions
│   │   ├── *.di    # Data initialized            # Mouse - mouse functions
│   │   ├── *.du    # Data uninitialized          # Game - game alghoritms
│   │   └── *.h     # Includes / macros
│   │
│   └── Draw    # All frontend
│       │
│       ├── Digits / Fonts / Letters         # Digits - all digits drawing
│       │   │                                # Fonts - main screens drawing
│       │   ├── *.c     # Source code        # Letters - all EN Alphabet drawing
│       │   ├── *.di    # Data initialized           
│       │   ├── *.du    # Data uninitialized                
│       │   └── *.h     # Includes / macros          
│       │
│       ├── Color.di    # Data initialized            
│       └── Draw.h      # Includes / macros
│
└── Tag.asm # The executable file of the project
```

## Code Refactoring

If you want to refactor the code, then you can use several possible tools. But to implement any of them, you need a FASM compiler.
1. Install FASM on your computer by <a href="https://flatassembler.net/download.php">this link</a>.
2. Copy `proc16.inc` on the following path `~\FASM\INCLUDE\MACRO`.
   - `proc16.inc` - macro file for fasm. This file includes the ability to create local parameters in routines and use calling conventions.
3. Open `FASMW.exe` and you can start coding.

But if you won't write code more comfortable you can use `FASM Editor 2.0`.
4. Install `FASM Editor 2.0` by <a href="https://fasmworld.ru/instrumenty/fasm-editor-2-0/">this link</a>.
5. Start `FEditor.exe`.
6. First of all go `Services\Settings`.
   - FASM: put way to `FASM.exe`;
   - INC: put way to `INCLUDE` folder;
   - DBG: put way to `*.exe` debugger.

### Debugger

You can use `Olly Dbg`. Install by <a href="https://www.ollydbg.de/">this link</a>. 

## Gratitude
### If you liked this project, please put a star on this repository!!!