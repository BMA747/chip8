#include "chip8.h"

int main(){
    CPU cpu = {0};
    FILE file = {0};
    boot_up(&cpu, &file);

    fetch(&cpu);
    execute(&cpu);

    return 0;
}
