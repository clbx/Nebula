# Nebula
A variable architecture education tool for testing programs against different aspects of CPU architectures. 

This is a spiritual successor to [Cosmic](https://github.com/clbx/Cosmic) but is a more useful and less esoteric tool. It does not use the same instruction set a Cosmic, instead using an even simpler instruction set and does not bother with machine code itself.

Nebula (for now) does not store instructions in any kind of accessible memory instead directly reads the assembly instead of translating into machine code. 

The goal of this software is not to write a complete and useful program, but to easier illustrate how a CPU works cycle by cycle.


### How to Run:

## Linux

Get SDL2 through your distributions Package Manager and run ``make`` on the makefile

## macOS

Install SDL2 through your favorite package manager, if you're having issues, I use brew

```
brew install sdl2
make
```

## Windows

Download VirtualBox, pick your favorite linux distribution, and follow the linux instructions. 