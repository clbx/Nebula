/**
 * 
 *  As I am envisioning it right now, an instruction in Nebula will be signifigantly more complicated than an instruction is in Cosmic, or basically 
 * any other simulator/emulator. Due to the fact that facets about the processor can and will change, each instruction will probably need to know how to execute
 * under each different condition. This will add overhead to the implementation of Instructions which is why there are only 16.
 * 
 * 
 * 
 */
#include <string>

class Instruction{
    public:
        std::string mnemonic;
        std::string* operands;
 

};