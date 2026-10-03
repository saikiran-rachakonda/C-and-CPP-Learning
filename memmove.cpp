void *my_memmove(void *dst, const void *src, size_t n) {
	if(n==0 || dst == src) {
		return dst;
	}

	uint8_t *d = (uint8_t *) dst;
	const uint8_t *s = (const uint8_t *) src;

	if(d > s && d < s+n ) {
		while(n > 0) {
			n--;
			d[n] = s[n] ;
		}
	} else {
		for(size_t i = 0 ; i<n; i++){
			d[i] = s[i] ;
		}
	}
	return dst;
}
