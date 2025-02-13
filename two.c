#include <stdint.h>
#include "tsi_struct.h"  // Zawiera definicję struktury register_info

// READ DATA
uint32_t read_register(volatile struct register_info *regs, uint32_t address) {
    return *(volatile uint32_t *)address;
}

// WRITE DATA
void write_register(volatile struct register_info *regs, uint32_t address, uint32_t value) {
    *(volatile uint32_t *)address = value;
}

// Starting Address Master
void set_starting_address(volatile struct register_info *regs, uint32_t address, int master_index) {
    switch (master_index) {
        case 0:
            regs->OTSAU0 = address;  // starting address master 0
            break;
        case 1:
            regs->OTSAU1 = address;  // starting address master 1
            break;
        case 2:
            regs->OTSAU2 = address;  // starting address master 2
            break;
        case 3:
            regs->OTSAU3 = address;  // starting address master 3
            break;
        case 4:
            regs->OTSAU4 = address;  // starting address master 4
            break;
        case 5:
            regs->OTSAU5 = address;  // starting address master 5
            break;
        case 6:
            regs->OTSAU6 = address;  // starting address master 6
            break;
        case 7:
            regs->OTSAU7 = address;  // starting address master 7
            break;
        default:
            // Wrong master_index
            break;
    }
}

// Ending Address Master
void set_ending_address(volatile struct register_info *regs, uint32_t address, int master_index) {
    switch (master_index) {
        case 0:
            regs->OTSAL0 = address;  // ending address master 0
            break;
        case 1:
            regs->OTSAL1 = address;  // ending address master 1
            break;
        case 2:
            regs->OTSAL2 = address;  // ending address master 2
            break;
        case 3:
            regs->OTSAL3 = address;  // ending address master 3
            break;
        case 4:
            regs->OTSAL4 = address;  // ending address master 4
            break;
        case 5:
            regs->OTSAL5 = address;  // ending address master 5
            break;
        case 6:
            regs->OTSAL6 = address;  // ending address master 6
            break;
        case 7:
            regs->OTSAL7 = address;  // ending address master 7
            break;
        default:
            // Wrong master_index
            break;
    }
}

// Data Address Master
void set_data_address(volatile struct register_info *regs, uint32_t address, int master_index) {
    switch (master_index) {
        case 0:
            regs->OTEAU0 = address;  // data address master 0
            break;
        case 1:
            regs->OTEAU1 = address;  // data address master 1
            break;
        case 2:
            regs->OTEAU2 = address;  // data address master 2
            break;
        case 3:
            regs->OTEAU3 = address;  // data address master 3
            break;
        case 4:
            regs->OTEAU4 = address;  // data address master 4
            break;
        case 5:
            regs->OTEAU5 = address;  // data address master 5
            break;
        case 6:
            regs->OTEAU6 = address;  // data address master 6
            break;
        case 7:
            regs->OTEAU7 = address;  // data address master 7
            break;
        default:
            // Wrong master_index
            break;
    }
}

// Data Ending Address Master
void set_data_ending_address(volatile struct register_info *regs, uint32_t address, int master_index) {
    switch (master_index) {
        case 0:
            regs->OTEAL0 = address;  // data ending address master 0
            break;
        case 1:
            regs->OTEAL1 = address;  // data ending address master 1
            break;
        case 2:
            regs->OTEAL2 = address;  // data ending address master 2
            break;
        case 3:
            regs->OTEAL3 = address;  // data ending address master 3
            break;
        case 4:
            regs->OTEAL4 = address;  // data ending address master 4
            break;
        case 5:
            regs->OTEAL5 = address;  // data ending address master 5
            break;
        case 6:
            regs->OTEAL6 = address;  // data ending address master 6
            break;
        case 7:
            regs->OTEAL7 = address;  // data ending address master 7
            break;
        default:
            // Wrong master_index
            break;
    }
}

// Data Transfer Start Address Master
void set_transfer_start_address(volatile struct register_info *regs, uint32_t address, int master_index) {
    switch (master_index) {
        case 0:
            regs->OTOFU0 = address;  // transfer start address master 0
            break;
        case 1:
            regs->OTOFU1 = address;  // transfer start address master 1
            break;
        case 2:
            regs->OTOFU2 = address;  // transfer start address master 2
            break;
        case 3:
            regs->OTOFU3 = address;  // transfer start address master 3
            break;
        case 4:
            regs->OTOFU4 = address;  // transfer start address master 4
            break;
        case 5:
            regs->OTOFU5 = address;  // transfer start address master 5
            break;
        case 6:
            regs->OTOFU6 = address;  // transfer start address master 6
            break;
        case 7:
            regs->OTOFU7 = address;  // transfer start address master 7
            break;
        default:
            // Wrong master_index
            break;
    }
}

// Data Transfer End Address Master
void set_transfer_end_address(volatile struct register_info *regs, uint32_t address, int master_index) {
    switch (master_index) {
        case 0:
            regs->OTOFL0 = address;  // transfer end address master 0
            break;
        case 1:
            regs->OTOFL1 = address;  // transfer end address master 1
            break;
        case 2:
            regs->OTOFL2 = address;  // transfer end address master 2
            break;
        case 3:
            regs->OTOFL3 = address;  // transfer end address master 3
            break;
        case 4:
            regs->OTOFL4 = address;  // transfer end address master 4
            break;
        case 5:
            regs->OTOFL5 = address;  // transfer end address master 5
            break;
        case 6:
            regs->OTOFL6 = address;  // transfer end address master 6
            break;
        case 7:
            regs->OTOFL7 = address;  // transfer end address master 7
            break;
        default:
            // Wrong master_index
            break;
    }
}

// to Big Endian
uint32_t to_big_endian(uint32_t val) {
    return ((val >> 24) & 0x000000FF) | ((val >> 8) & 0x0000FF00) | ((val << 8) & 0x00FF0000) | ((val << 24) & 0xFF000000);
}

