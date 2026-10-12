#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <windows.h>
#define sizeMEM 4096
#define sizeROM 3584
#define startROM 512
#define freqInst 700

typedef struct{
    uint16_t instruction;
    uint16_t Index;
    uint16_t PC;
    uint8_t SP;
    uint8_t V[16];
    uint8_t DT;
    uint8_t ST;    
    uint16_t Stack[16];
    bool Keyboard[16];
    bool frameBuffer[64][32];
    uint8_t Memory[sizeMEM];
}CPU;

void boot_up(CPU* cpu_ptr, FILE *file_ptr);
void print_byte(uint8_t byte);
extern const char *bit_rep[16];
void get_timediff();
void fetch(CPU* cpu_ptr);
void execute(CPU* cpu_ptr);