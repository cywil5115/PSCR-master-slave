#ifndef SLAVE_H
#define SLAVE_H

// ENABLE
#define S_EN 0x80000000
#define S_NOT_EN 0x00000000

/* TH (Threshold): This field sets a threshold for when read-ahead prefetching resumes. If set,
prefetching resumes once the FIFO is half empty. If cleared, prefetching resumes once the
FIFO is completely empty.*/
#define S_TH_ON 0x40000
#define S_TH_OFF 0x00000

// VFS (Virtual FIFO Size)
#define S_FIFO64 0x00000
#define S_FIFO128 0x10000
#define S_FIFO256 0x20000
#define S_FIFO512 0x30000

//2eSSTM (2eSSTM)
/*These bits define the 2eSST transfer rates the corresponding VME
Slave responds to. If SST320 is enabled, the VME Slave also responds to SST267 and
SST160. If SST267 is enabled, the VME Slave also responds to SST160.*/
#define S_SST160 0x0000
#define S_SST267 0x1000
#define S_SST320 0x2000

// 2eSSTB (2eSSTB): If set, the corresponding VME Slave responds to 2eSST broadcast cycles.
#define S_TWOeSSTB_ON 0x800
#define S_TWOeSSTB_OFF 0x000

//2eSST (2eSST): If set, the corresponding VME Slave responds to standard 2eSST cycles.
#define S_TWOeSST_ON 0x400
#define S_TWOeSST_OFF 0x000

//2eVME (2eVME): If set, the corresponding VME Slave responds to 2eVME cycles.
#define S_TWOeVME_ON 0x200
#define S_TWOeVME_OFF 0x000

//MBLT (MBLT): If set, the corresponding VME Slave responds to MBLT cycles.
#define S_MBLT_ON 0x100
#define S_MBLT_OFF 0x000

//BLT (BLT): If set, the corresponding VME Slave responds to BLT cycles.
#define S_BLT_ON 0x80
#define S_BLT_OFF 0x00

//AS (Address Space): These bits define the address space the corresponding VME Slave responds to.
#define S_A16 (0<<4)
#define S_A24 0x10
#define S_A32 0x20
#define S_A64 0x40

// SUPR (Supervisor): If set, the corresponding VME Slave is enabled to respond to VMEbus supervisor access cycles.
#define S_SUPR_ON 0x08
#define S_SUPR_OFF 0x00

//NPRIV (Non-privileged): If set, the corresponding VME Slave is enabled to respond to non-privileged access cycles.
#define S_NPRIV_ON 0x04
#define S_NPRIV_OFF 0x00

// PGM (Program): If set, the corresponding VME Slave is enabled to respond to VMEbus program access cycles.
#define S_PGM_ON 0x02
#define S_PGM_OFF 0x00

// DATA (Data): If set, the corresponding VME Slave is enabled to respond to VMEbus data access cycles
#define S_DATA_ON 0x01
#define S_DATA_OFF 0x00

uint32_t slave_to_big_endian(uint32_t val);
void set_slave_starting_upper_address(volatile struct register_info *regs, uint32_t address, int slave_index);
void set_slave_starting_lower_address(volatile struct register_info *regs, uint32_t address, int slave_index);
void set_slave_ending_upper_address(volatile struct register_info *regs, uint32_t address, int slave_index);
void set_slave_ending_lower_address(volatile struct register_info *regs, uint32_t address, int slave_index);
void set_slave_offset_upper_address(volatile struct register_info *regs, uint32_t address, int slave_index);
void set_slave_offset_lower_address(volatile struct register_info *regs, uint32_t address, int slave_index);
void set_slave_attribute_address(volatile struct register_info *regs, uint32_t address, int slave_index);
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

            );








#endif /* SLAVE_H */
