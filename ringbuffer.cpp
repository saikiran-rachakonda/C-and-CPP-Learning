typedef struct { 
    uint8_t *buf; 
    size_t cap, head, tail; 
} Ring;

void ring_init(Ring *r, uint8_t *mem, size_t cap) {
    if(r == NULL) return ;
    r->buf = mem ;
    r->cap = cap ;
    r->head = 0 ;
    r->tail = 0 ;
}
size_t ring_count(const Ring *r){
    if(r==NULL) return 0;
    return (r->tail) - (r->head) ;
}
bool ring_push(Ring *r, uint8_t v){
    if(r==NULL) return false;
    if(ring_count(r) == r->cap) return false;
    r->buf[r->tail % r->cap] = v;
    r->tail++;
}
bool ring_pop(Ring *r, uint8_t *out){
    if(r==NULL) return false;
    if(ring_count(r) == 0 ) return false;
    *out = r->buf[r->head % r->cap];
    r->head++;
}
