#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "ports.h"
#include "driver/vga.h"
#include "driver/serial.h"
#include "driver/pci.h"

void hcf(void)
{
    for (;;)
    {
        asm("hlt");
    }
}

void kernel_main(void) 
{
    vga_init();
    serial_init();
    
    serial_print("\n64-bit kernel running!\n\n");
    
    vga_print("64-bit kernel running!\n\n");

    pci_init();
    
    serial_print("\nKernel initialization complete.\n");
    
    hcf();
}