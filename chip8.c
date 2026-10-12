#include "chip8.h"

const char *bit_rep[16] = {
    [ 0] = "0000", [ 1] = "0001", [ 2] = "0010", [ 3] = "0011",
    [ 4] = "0100", [ 5] = "0101", [ 6] = "0110", [ 7] = "0111",
    [ 8] = "1000", [ 9] = "1001", [10] = "1010", [11] = "1011",
    [12] = "1100", [13] = "1101", [14] = "1110", [15] = "1111",
};

void print_byte(uint8_t byte)
{
    printf("%s%s \n", bit_rep[byte >> 4], bit_rep[byte & 0x0F]);
}

void get_timediff(){
    LARGE_INTEGER tick1, tick2, freq;
    QueryPerformanceCounter(&tick1);

    for(long i = 0; i < 500000000; i++);

    QueryPerformanceCounter(&tick2);

    QueryPerformanceFrequency(&freq);

    double diffTick = (double)(tick2.QuadPart - tick1.QuadPart) / freq.QuadPart;

    printf("time elapsed: %.2f s", diffTick);
}


void boot_up(CPU* cpu_ptr, FILE *file_ptr){
    cpu_ptr->PC = startROM;
    file_ptr = fopen("petdog.ch8", "rb");
    uint8_t ROM[sizeROM] = {0};
    int currentSize = fread(ROM, sizeof(ROM[0]), sizeROM, file_ptr);
    int j = startROM;
    for(int i = 0; i < currentSize; i++){
        cpu_ptr->Memory[j] = ROM[i];
        print_byte(cpu_ptr->Memory[j]);
        j++;
    }
    fclose(file_ptr);
}

void fetch(CPU* cpu_ptr){
    if(cpu_ptr->PC <= sizeMEM){
        cpu_ptr->instruction = cpu_ptr->Memory[cpu_ptr->PC];
        cpu_ptr->instruction = cpu_ptr->instruction << 8;
        printf("%d",cpu_ptr->instruction);
        cpu_ptr->PC++;
        cpu_ptr->instruction |= cpu_ptr->Memory[cpu_ptr->PC];
        printf("%d",cpu_ptr->instruction);
        cpu_ptr->PC++;
    } else {
        cpu_ptr->PC = startROM;
    }
    
}
void execute(CPU* cpu_ptr){
    uint16_t nnn = cpu_ptr->instruction & 0x0111;
    uint8_t n = cpu_ptr->instruction & 0x0001;
    uint8_t x = (cpu_ptr->instruction & 0x0100) >> 16;
    uint8_t y = (cpu_ptr->instruction & 0x0010) >> 8;
    uint8_t kk = cpu_ptr->instruction & 0x0011;

    switch(cpu_ptr->instruction){
        case 0x00E0:

            break;
        case (0x1000 || nnn):
            cpu_ptr->PC = nnn;
            break;

        
    }

}