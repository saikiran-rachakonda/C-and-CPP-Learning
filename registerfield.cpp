uint32_t field_get(uint32_t reg, unsigned shift, unsigned width){
	uint32_t mask ; 
	if(width == 32){
		mask = 0xFFFFFFFF ;
	}
	else {
		mask = (1<<width) - 1 ;
	}
	return (reg>>shift)& mask;
}
uint32_t field_set(uint32_t reg, unsigned shift, unsigned width, uint32_t val){
	uint32_t mask ; 
	if(width == 32){
		mask = 0xFFFFFFFF ;
	}
	else {
		mask = (1<<width) - 1 ;
	}
	val = (val & mask) << shift;
	reg &= ~(mask << shift) ;
	reg = reg | val ;
	return reg;
}

