#ifndef SLAVE_H
#define SLAVE_H

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
