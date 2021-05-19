# Instruction Set

Nebula uses its own extremley reduced instruction set ( 16 instructions! ) . This is to simplify the actual usage and to make devevloping additional subsets of the arch easier. The focus is not on the program, but how it runs. 

### Arithmetic

| Instruction | Meaning      | Example      | Comment                                                    |
| ----------- | ------------ | ------------ | ---------------------------------------------------------- |
| add         | r0 = r1 + r2 | add r0,r1,r2 |                                                            |
| sub         | r0 = r1 - r2 | sub r0,r1,r2 |                                                            |
| mul         | r0 = r1 * r2 | mul r0,r1,r2 |                                                            |
| div         | r0 = r1 / r2 | div r0,r1,r2 | Integer Division. Nothing is done <br />with the remainder |

### Logical

| Instruction | Meaning       | Example      | Comment |
| ----------- | ------------- | ------------ | ------- |
| and         | r0 = r1 & r2  | and r0,r1,r2 |         |
| or          | r0 = r1 \| r2 | or r0,r1,r2  |         |
| xor         | r0 = r1 ⊕ r2  | xor r0,r1,r2 |         |

### Data Manipulation

| Instruction | Meaning      | Example     | Comment                       |
| ----------- | ------------ | ------------| ------------------------------|
| ld          | r0 = mem[r1] | ld r0,r1    | Sets register to memory       |
| st          | mem[r1] = r0 | st r0, r1   | Sets memory to register       |
| ldi         | r0 = #       | ldi r0,1000 | Loads register from immediate |
| sti         | mem[r1] = #  | sti r0,1000 | Sets memory to immediate      |

### Branching

| Instruction | Meaning             | Example       | Comment |
| ----------- | ------------------- | ------------- | ------- |
| jmp         | goto 100            | jmp 100       |         |
| beq         | goto 100 if r0==r1  | beq r0,r1,100 |         |
| bne         | goto 100 if r0!=r1  | bne r0,r1,100 |         |
| bgt         | goto 100 if r0 > r1 | bgt r0,r1,100 |         |
| blt         | goto 100 if r1 > r0 | blt r0,r1,100 |         |

