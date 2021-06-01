pub struct Memory{
    memory: Vec<u64>,
}

impl Memory {
    pub fn new(capacity: usize) -> self{
        let mut memory = Vec::with_capacity(capacity: usize)
    }

    pub fn readMemory(index: u64) -> u64{
        memory[index];
    }

    pub fn writeMemory(index: u64, value u64){
        memory[index] = value;
    }
}
