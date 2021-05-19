/*
 * JTMOS LIBC - stdio.h
 *
 * Parts borrowed from original creation of Colin Peters <colin@bird.fu.is.saga-u.ac.jp>.
 *
 * (C) 2002 by Jari Tuominen(jari@vunet.org)
 */
//
#ifndef __INCLUDED_JTMOS_STDIO_H__
#define __INCLUDED_JTMOS_STDIO_H__

// Make sure we are not taken as linux platform...
#undef linux

// Hey, we really don't have utime!
#define NO_UTIME

//
#ifndef JTMOS
#define JTMOS
#endif
/*#ifndef MODERN
#define MODERN
#endif
#ifndef UNIX
#define UNIX
#endif*/

// DJGPP/MSDOS compatibility
// (OBSOLETE, we aim into UNIX compliance ;-)
//#define DJGPP
//#define MSDOS
//#define TURBOC

//
#include <basdef.h>
#include <jtmos/buffer.h>
#include <jtmos/console.h>
#include <jtmos/ansiwin.h>
#include <jtmos/process.h>
#include <jtmos/io.h>
#include <jtmos/cpu.h>
#include <jtmos/printf.h>
#include <jtmos/string.h>
#include <jtmos/stdarg.h>
#include <jtmos/malloc.h>
#include <jtmos/fixal.h>
#include <jtmos/file.h>
#include <jtmos/cpu.h> // nop disable enable, etcz..
#include <jtmos/jtmkeys.h> // key code settings
#include <jtmos/communication.h> // communication (SerialGet/SerialPut)
#include <jtmos/network.h>
#include <jtmos/graosClient.h>
#include <jtmos/tcp.h>
#include <jtmos/ip.h>
#include <jtmos/dirtype.h>
#include <ctype.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdlib.h>
// console.h  io.h      printf.h   scanmem.h  stdarg.h
// hexdump.h  malloc.h  process.h  sprintf.h  string.h

//
/* Returned by various functions on end of file condition or error. */
#define	EOF	(-1)

//
#ifndef _FILE_DEFXX5
#define _FILE_DEFXX5
//typedef char* FILE;
#endif

/*
 * The maximum length of a file name. You should use GetVolumeInformation
 * instead of this constant. But hey, this works.
 *
 * NOTE: This is used in the structure _finddata_t (see io.h) so changing it
 *       is probably not a good idea.
 */
#define	FILENAME_MAX	(260)

/*
 * The maximum number of files that may be open at once. I have set this to
 * a conservative number. The actual value may be higher.
 */
#define FOPEN_MAX	(20)

/*
 * The buffer size as used by setbuf such that it is equivalent to
 * (void) setvbuf(fileSetBuffer, caBuffer, _IOFBF, BUFSIZ).
 */
#define	BUFSIZ	512


/* Constants for nOrigin indicating the position relative to which fseek
 * sets the file position. Enclosed in ifdefs because io.h could also
 * define them. (Though not anymore since io.h includes this file now.) */
#ifndef	SEEK_SET
#define SEEK_SET	(0)
#endif

#ifndef	SEEK_CUR
#define	SEEK_CUR	(1)
#endif

#ifndef	SEEK_END
#define SEEK_END	(2)
#endif



//
//extern void puts(const char *);
extern void init_libc(void);

//
FILE *fopen (const char *path, const char *mode);
int fclose( FILE *stream);
int remove(const char *pathname);
void perror(const char *s);

//
extern FILE *stdout,*stdin,*stderr;

//
#endif

//