#ifndef MASTER_H
#define MASTER_H
#define A16 0x00 //AMODE (Address Mode): This field defines the VMEbus Address mode.
#define A24 0x01  //(1<<0)
#define A32 0x02  //(1<<1)
#define A64 0x04  //(1<<2)

//AMODE (Address Mode): This field defines the VMEbus Address mode.
#define M_A16 0x00
#define M_A24 0x01  //(1<<0)
#define M_A32 0x02  //(1<<1)
#define M_A64 0x04  //(1<<2)
#define M_CR_CSR 0x05
#define M_USER1 0x08
#define M_USER2 0x09
#define M_USER3 0x0A
#define M_USER4 0x0B

// ENABLE
#define M_EN 0x80000000 //the corresponding outbound translation function is enabled
#define M_NOT_EN 0x00000000

//MRPFD (Memory Read Prefetch Disable)
#define M_PREFETCH_DISABLED 0x40000
#define M_PREFETCH 0x00 // a cache line is prefetched when a PCI/X bus memory read burst is received

//PFS (Prefetch Size)
#define M_CACHE2LINES 0x00
#define M_CACHE4LINES 0x10000
#define M_CACHE8LINES 0x20000
#define M_CACHE16LINES 0x30000

//2eSST Transfer Rate
#define M_MB160 0x00
#define M_MB267 0x800
#define M_MB320 0x1000

//VMEbus Transfer Mode
#define M_SCT 0x00
#define M_BLT 0x100
#define M_MBLT 0x200
#define M_TWOeVME 0x300
#define M_TWOeSST 0x400
#define M_TWOeSST_BROADCAST 0x500 // 5<<8

//VMEbus Supervisory Mode
#define M_NON_PRV_ACCESS (0<<5) // 0x00
#define M_SUP_ACCESS (1<<5) // 0x10

//VMEbus Program Mode
#define M_PGM_PROGRAM (1<<4) // 0x08
#define M_PGM_DATA 0x00

//VMEbus Data Bus Width (DBW)
#define M_DBW16 0x00  //VMEbus Data Bus Width
#define M_DBW32 0x40 // (1<<6) 6 bit od zera liczac


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
