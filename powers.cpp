bool is_pow2(uint32_t v) {
	return (v>0) && ( (v & (v-1)) == 0) ;
}
uint32_t round_up_pow2(uint32_t v){
	if(v==0) return 1;
	uint32_t ret = 1;
	while(ret<v){
		ret = ret << 1 ;
	}
	return ret;
}
