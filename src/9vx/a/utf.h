/*
 * The authors of this software are Rob Pike and Ken Thompson.
 *              Copyright (c) 1998-2002 by Lucent Technologies.
 * Permission to use, copy, modify, and distribute this software for any
 * purpose without fee is hereby granted, provided that this entire notice
 * is included in all copies of any software which is or includes a copy
 * or modification of this software and in all copies of the supporting
 * documentation for such software.
 * THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTY.  IN PARTICULAR, NEITHER THE AUTHORS NOR LUCENT TECHNOLOGIES MAKE ANY
 * REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY
 * OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 */
#ifndef _UTF_H_
#define _UTF_H_ 1
#if defined(__cplusplus)
extern "C" { 
#endif

enum
{
	UTFmax		= 4,		/* maximum bytes per rune */
	Runesync	= 0x80,		/* cannot represent part of a UTF sequence (<) */
	Runeself	= 0x80,		/* rune and UTF sequences are the same (<) */
	Runeerror	= 0xFFFD,	/* decoding error in UTF */
	Runemax		= 0x10FFFF,	/* 21-bit rune */
	Runemask	= 0x1FFFFF,	/* bits used by runes (see grep) */
};

/* Edit .+1,/^$/ | cfn $PLAN9/src/lib9/utf/?*.c | grep -v static |grep -v __ */
int		chartorune(Rune *rune, char *str);
int		fullrune(char *str, int n);
int		isalpharune(Rune c);
int		islowerrune(Rune c);
int		isspacerune(Rune c);
int		istitlerune(Rune c);
int		isupperrune(Rune c);
int		runelen(long c);
int		runenlen(Rune *r, int nrune);
Rune*		runestrcat(Rune *s1, Rune *s2);
Rune*		runestrchr(Rune *s, Rune c);
int		runestrcmp(Rune *s1, Rune *s2);
Rune*		runestrcpy(Rune *s1, Rune *s2);
Rune*		runestrdup(Rune *s) ;
Rune*		runestrecpy(Rune *s1, Rune *es1, Rune *s2);
long		runestrlen(Rune *s);
Rune*		runestrncat(Rune *s1, Rune *s2, long n);
int		runestrncmp(Rune *s1, Rune *s2, long n);
Rune*		runestrncpy(Rune *s1, Rune *s2, long n);
Rune*		runestrrchr(Rune *s, Rune c);
Rune*		runestrstr(Rune *s1, Rune *s2);
int		runetochar(char *str, Rune *rune);
Rune		tolowerrune(Rune c);
Rune		totitlerune(Rune c);
Rune		toupperrune(Rune c);
char*		utfecpy(char *to, char *e, char *from);
int		utflen(char *s);
int		utfnlen(char *s, long m);
char*		utfrrune(char *s, long c);
char*		utfrune(char *s, long c);
char*		utfutf(char *s1, char *s2);

#if defined(__cplusplus)
}
#endif
#endif
