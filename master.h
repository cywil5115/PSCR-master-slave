#ifndef MASTER_H
#define MASTER_H
#define A16 0x00 //AMODE (Address Mode): This field defines the VMEbus Address mode.
#define A24 0x01  //(1<<0)
#define A32 0x02  //(1<<1)
#define A64 0x04  //(1<<2)

#define USER4 0x0B

#define NON_PRV_ACCESS (0<<4) // 0x00
#define SUP_ACCESS (1<<4) // 0x10

#define PGM_PROGRAM (1<<3) // 0x08
#define PGM_DATA 0x00

#define DBW16 0x00  //VMEbus Data Bus Width
#define DBW32 0x40 // (1<<6) 6 bit od zera liczac


uint32_t to_big_endian(uint32_t val);
void set_starting_upper_address(volatile struct register_info *regs, uint32_t address, int master_index);
void set_starting_lower_address(volatile struct register_info *regs, uint32_t address, int master_index);
void set_ending_upper_address(volatile struct register_info *regs, uint32_t address, int master_index);
void set_ending_lower_address(volatile struct register_info *regs, uint32_t address, int master_index);
void set_offset_upper_address(volatile struct register_info *regs, uint32_t address, int master_index);
void set_offset_lower_address(volatile struct register_info *regs, uint32_t address, int master_index);
void set_attribute_address(volatile struct register_info *regs, uint32_t address, int master_index);
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

            );









#endif /* MASTER_H */
