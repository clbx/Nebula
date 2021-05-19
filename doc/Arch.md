## Architecture

Nebula is a variable architecture, which means that it can run with as little as it takes to be turing complete (A CPU and list of instructions) or as much as a multi-core, multi-cache, large, memory, pipelined, VLIW, super-scalar processor, with many hard disks in a RAID configuration and memory. The simplicity and size of the instruction set makes this variance in architecture a lot more digestable.

The CPU will most likley be a fixed speed. I think this makes sense to avoid complications with things that run independantly of the CPU, and just measure all time in terms of cycles. Instead of a access to memory taking 5ns, it will take 5 cycles. This 1.) Makes the program much easier to manage, and 2.) everything a little more digestable and measureable. 

Here are some of the options that I am planning on implementing at first.

* Pipelining
* Branch Prediction
* Scheduling
* Out of Order Execution
* Multi-Processing
* Threading 
* Caches
* Memory
* Storage
* External Devices

These are all of the things that make up a "basic" computer, and go past Cosmic and its very simple design, and takes a focus on architecture instead of building a more complete product. 
