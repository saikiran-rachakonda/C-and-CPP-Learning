#define ST_BUSY (1u << 0 )

int wait_not_bust(volatile uint32_t *status, uint32_t timeout){

	if(status == NULL) return -1;
	while(timeout > 0 ){
		if((*status & ST_BUSY) == 0){
			return 0 ;
		}
		timeout--;
	}
	if((*status & ST_BUSY) == 0){
		return 0;
	}
	return -1;
}
