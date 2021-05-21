/**
 * 
 * Mainboard in this case is about as symbolic as it gets. All other components will hook into this and communicate via the "mainboard"
 * 
 * Since instructions are not stored in any physical place on the system (program code does not exist in any type of memory) the instruction list is a
 * member of the mainboard and is its only set component since the mainboard can technically exist without a CPU, It just won't be doing much. 
 * 
 */

#include "instruction.hpp"
#include "cpu.hpp"

class Mainboard{
    public:
        Instruction* InstructionList;

        void addCPU();
    
    private:    
        CPU cpu;

    



};