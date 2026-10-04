typedef enum { REG_RW, REG_RO, REG_W1C, REG_RC } RegKind;
typedef struct { 
    uint32_t off;
    RegKind kind;
    uint32_t value;
} Reg;

uint32_t reg_read(Reg *bank, size_t n, uint32_t off){
    for (size_t i = 0; i < n; i++) {
        if (bank[i].off == off) {
            uint32_t temp = bank[i].value;
            if (bank[i].kind == REG_RC) {
                bank[i].value = 0;
            }
            return temp;
        }
    }
    return 0;
}

void reg_write(Reg *bank, size_t n, uint32_t off, uint32_t v){
        for (size_t i = 0; i < n; i++) {
        if (bank[i].off == off) {
            switch (bank[i].kind) {
                case REG_RW:
                    bank[i].value = v;
                    break;
                case REG_RO:
                    break;
                case REG_W1C:
                    bank[i].value &= ~v;
                    break;
                case REG_RC:
                    bank[i].value = v;
                    break;
            }
            return;    
}
