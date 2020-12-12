//
// Created by protobit on 11/12/2020.
//

#ifndef GBCPP_MACROS_H
#define GBCPP_MACROS_H

#include "../common/common.hpp"
#include <functional>

class decoder {
    std::function<void(int64_t,flags*,registers*,registers16*)> op_array[0xFF];
public:
    void registerOps() {
#define startOpcode(number) op_array[number] = [](int64_t extra,flags* flags,registers* regs,registers16* reg16){
#define opCode(code) code;
#define endOpcode() };
#include "opcodes.inl"
#undef startOpcode
#undef opCode
#undef endOpcode
    }
    void runInstruction(int index,int64_t extra,flags* flags,registers* regs,registers16* reg16) {
        op_array[index](extra,flags,regs,reg16);
    }
};
#endif //GBCPP_MACROS_H
