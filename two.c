#include <stdint.h>
#include "tsi_struct.h"  // Zawiera definicję struktury register_info
#include <stdio.h>
#include <stdlib.h>
#include <sys/neutrino.h>
#include <hw/pci.h>
#include <sys/mman.h>

// to Big Endian
uint32_t to_big_endian(uint32_t val) {
    return ((val >> 24) & 0x000000FF) | ((val >> 8) & 0x0000FF00) | ((val << 8) & 0x00FF0000) | ((val << 24) & 0xFF000000);
}

// Starting Address Master //
void set_starting_upper_address(volatile struct register_info *regs, uint32_t address, int master_index) {
    switch (master_index) {
        case 0:
            regs->OTSAU0 = to_big_endian(address);  // starting upper address master 0
            break;
        default:
            // Wrong master_index
            break;
    }
}
void set_starting_lower_address(volatile struct register_info *regs, uint32_t address, int master_index) {
    switch (master_index) {
        case 0:
            regs->OTSAL0 = to_big_endian(address);   // starting lower address master 0
            break;
        default:
            // Wrong master_index
            break;
    }
}
//************************//

// Ending Address Master
void set_ending_upper_address(volatile struct register_info *regs, uint32_t address, int master_index) {
    switch (master_index) {
        case 0:
            regs->OTEAU0 = to_big_endian(address);  // ending upper address master 0
            break;
        default:
            // Wrong master_index
            break;
    }
}
void set_ending_lower_address(volatile struct register_info *regs, uint32_t address, int master_index) {
    switch (master_index) {
        case 0:
            regs->OTEAL0 = to_big_endian(address);   // ending lower address master 0
            break;
        default:
            // Wrong master_index
            break;
    }
}
//************************//

// Offset Address Master
void set_offset_upper_address(volatile struct register_info *regs, uint32_t address, int master_index) {
    switch (master_index) {
        case 0:
            regs->OTOFU0 = to_big_endian(address);  // offset upper address master 0
            break;
        default:
            // Wrong master_index
            break;
    }
}
void set_offset_lower_address(volatile struct register_info *regs, uint32_t address, int master_index) {
    switch (master_index) {
        case 0:
            regs->OTOFL0 = to_big_endian(address);   // offset lower address master 0
            break;
        default:
            // Wrong master_index
            break;
    }
}
//************************//
// Attribute Address Master
void set_attribute_address(volatile struct register_info *regs, uint32_t address, int master_index) {
    switch (master_index) {
        case 0:
            regs->OTAT0 = to_big_endian(address);   // starting lower address master 0
            break;
        default:
            // Wrong master_index
            break;
    }
}

//************************//

void* set_master (
            volatile struct register_info *regs,
            int master_index,

            uint32_t starting_upper_address,
            uint32_t starting_lower_address,

            uint32_t ending_upper_address,
            uint32_t ending_lower_address,

            uint32_t offset_upper_address,
            uint32_t offset_lower_address,

            uint32_t attribute_address

            ){

    uint64_t addr_start_full;
    uint64_t addr_end_full;
    uint64_t addr;

	switch (master_index) {
        case 0:
            //***//
            set_starting_upper_address(regs, starting_upper_address, master_index);
            set_starting_lower_address(regs, starting_lower_address, master_index);
            //***//
            set_ending_upper_address(regs, ending_upper_address, master_index);
            set_ending_lower_address(regs, ending_lower_address, master_index);
            //***//
            set_offset_upper_address(regs, offset_upper_address, master_index);
            offset_lower_address = starting_lower_address * (-1);
            set_offset_lower_address(regs, offset_lower_address, master_index);
            //***//
            set_attribute_address(regs, attribute_address, master_index);

            addr_start_full = (starting_upper_address<<31) + (starting_lower_address); // łączenie
            addr_end_full = (ending_upper_address<<31) + (ending_lower_address);       // łączenie
            addr = addr_end_full - addr_start_full;

            uint32_t d32;
            d32 = to_big_endian(regs->OTAT0);            // Convert the value from OTAT0 register to big-endian format
            d32 |= 0x80000000;                           // Set MSB to 1,  OR with the mask 0x80000000
            regs->OTAT0 = to_big_endian(d32);            // Convert the modified value back to big-endian format and store it in OTAT0

            return mmap_device_memory( NULL, ending_lower_address - starting_lower_address, PROT_READ|PROT_WRITE|PROT_NOCACHE, MAP_SHARED, addr_start_full );
            break;    
        default:
            // Wrong master_index
            break;
    }
	return NULL;
}
