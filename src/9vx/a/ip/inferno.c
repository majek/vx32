#include	"u.h"
#include	"lib.h"
#include	"mem.h"
#include	"dat.h"
#include	"fns.h"
#include	"error.h"
#include	"ip.h"

/*
 *  some hacks for commonality twixt inferno and plan9
 */

char*
commonuser(void)
{
	return up->user;
}

Chan*
commonfdtochan(int fd, int mode, int a, int b)
{
	return fdtochan(fd, mode, a, b);
}

char*
commonerror(void)
{
	return up->errstr;
}

char*
bootp(Ipifc* _)
{
	return "unimplmented";
}

int
bootpread(char* _, ulong __, int ___)
{
	return	0;
}

Medium tripmedium =
{
	"trip",
};
