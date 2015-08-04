#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

void *mmap(void *addr, size_t length, int prot, int flags,
	   int fd, off_t offset) {
	if (addr != NULL) {
		return MAP_FAILED;
	}

	size_t page_length = (length + 4095) &~ 4095;
	void *ptr = valloc(page_length);
	if (ptr == NULL) {
		return MAP_FAILED;
	}
	return ptr;
}

int munmap(void *addr, size_t length) {
	if (addr == NULL) {
		return -1;
	}

	free(addr);
	return 0;
}
