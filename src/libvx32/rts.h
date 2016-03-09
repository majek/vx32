
extern const char *vx_rts_S_start_ptr, *vx_rts_S_end_ptr;
extern const char vx_run_S_start[];
extern const char vx_run_S_end[];

extern void (*vxrun_gentrap)();
extern void (*vxrun_lookup_backpatch)();
extern void (*vxrun_lookup_indirect)();
extern void (*vxrun_lookup_backpatch)();

extern void (*vxrun_near_return)();
