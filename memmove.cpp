void *my_memmove(void *dst, const void *src, size_t n) {
	if(n==0 || dst == src) {
		return dst;
	}
	// if there is an overlap.
	if(d > s && d < s+n ) {
		while(n > 0) {
			n--;
			d[n] = s[n] ;
		}
	} else {
		for(int i = 0 ; i<n; i++){
			d[i] = s[i] ;
		}
	}
	return dst;
}
