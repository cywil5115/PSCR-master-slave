#include <stdint.h>
#include "tsi_struct.h"  // Zawiera definicje struktury register_info
#include <stdio.h>
#include <stdlib.h>
#include <sys/neutrino.h>
#include <hw/pci.h>
#include <sys/mman.h>

// to Big Endian (Slave)
uint32_t slave_to_big_endian(uint32_t val) {
    return ((val >> 24) & 0x000000FF) | ((val >> 8) & 0x0000FF00) | ((val << 8) & 0x00FF0000) | ((val << 24) & 0xFF000000);
}
//************************//

// Starting Address Slave //
void set_slave_starting_upper_address(volatile struct register_info *regs, uint32_t address, int slave_index) {
    switch (slave_index) {
        case 0:
            regs->ITSAU0 = slave_to_big_endian(address);  // starting upper address slave 0
            break;
        default:
        	// Wrong slave_index
            break;
    }
}
void set_slave_starting_lower_address(volatile struct register_info *regs, uint32_t address, int slave_index) {
    switch (slave_index) {
        case 0:
            regs->ITSAL0 = slave_to_big_endian(address);   // starting lower address slave 0
            break;
        default:
        	// Wrong slave_index
            break;
    }
}
//************************//

// Ending Address Slave
void set_slave_ending_upper_address(volatile struct register_info *regs, uint32_t address, int slave_index) {
    switch (slave_index) {
        case 0:
            regs->ITEAU0 = slave_to_big_endian(address);  // ending upper address slave 0
            break;
        default:
        	// Wrong slave_index
            break;
    }
}
void set_slave_ending_lower_address(volatile struct register_info *regs, uint32_t address, int slave_index) {
    switch (slave_index) {
        case 0:
            regs->ITEAL0 = slave_to_big_endian(address);   // ending lower address slave 0
            break;
        default:
        	// Wrong slave_index
            break;
    }
}
//************************//

// Offset Address Slave
void set_slave_offset_upper_address(volatile struct register_info *regs, uint32_t address, int slave_index) {
    switch (slave_index) {
        case 0:
            regs->ITOFU0 = slave_to_big_endian(address);  // offset upper address slave 0
            break;
        default:
        	// Wrong slave_index
            break;
    }
}
void set_slave_offset_lower_address(volatile struct register_info *regs, uint32_t address, int slave_index) {
    switch (slave_index) {
        case 0:
            regs->ITOFL0 = slave_to_big_endian(address);   // offset lower address slave 0
            break;
        default:
        	// Wrong slave_index
            break;
    }
}
//************************//

// Attribute Address Slave
void set_slave_attribute_address(volatile struct register_info *regs, uint32_t address, int slave_index) {
    switch (slave_index) {
        case 0:
            regs->ITAT0 = slave_to_big_endian(address);   // attribute address slave 0
            break;
        default:
        	// Wrong slave_index
            break;
    }
}

//************************//

void* set_slave (
            volatile struct register_info *regs,
            int slave_index,

            uint32_t slave_starting_upper_address,
            uint32_t slave_starting_lower_address,

            uint32_t slave_ending_upper_address,
            uint32_t slave_ending_lower_address,

            uint32_t slave_offset_upper_address,
            uint32_t slave_offset_lower_address,

            uint32_t slave_attribute_address

            ){

    uint64_t addr_start_full;
    uint64_t addr_end_full;
    uint64_t addr;

	switch (slave_index) {
        case 0:
            //***//
            set_slave_starting_upper_address(regs, slave_starting_upper_address, slave_index);
            set_slave_starting_lower_address(regs, slave_starting_lower_address, slave_index);
            //***//
            set_slave_ending_upper_address(regs, slave_ending_upper_address, slave_index);
            set_slave_ending_lower_address(regs, slave_ending_lower_address, slave_index);
            //***//
            set_slave_offset_upper_address(regs, slave_offset_upper_address, slave_index);
            slave_offset_lower_address = slave_starting_lower_address * (-1);
            set_slave_offset_lower_address(regs, slave_offset_lower_address, slave_index);
            //***//
            set_slave_attribute_address(regs, slave_attribute_address, slave_index);

            addr_start_full = (slave_starting_upper_address<<31) + (slave_starting_lower_address); // laczenie
            addr_end_full = (slave_ending_upper_address<<31) + (slave_ending_lower_address);       // laczenie
            addr = addr_end_full - addr_start_full;

            uint32_t d32;
            d32 = slave_to_big_endian(regs->ITAT0);// Convert the value from OTAT0 register to big-endian format
            d32 |= 0x80000000;               // Set MSB to 1,  OR with the mask 0x80000000
            regs->ITAT0 = slave_to_big_endian(d32);// Convert the modified value back to big-endian format and store it in OTAT0

            return mmap_device_memory( NULL, slave_ending_lower_address - slave_starting_lower_address, PROT_READ|PROT_WRITE|PROT_NOCACHE, MAP_SHARED, addr_start_full );
            break;    
        default:
            // Wrong slave_index
            break;
    }
	return NULL;
}
