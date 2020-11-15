#ifndef __INCLUDED_filedescriptor_H__
#define __INCLUDED_filedescriptor_H__

//
#include "kernel32.h"
#include "jtmfsfe.h"

// Max. amount of file descriptors
#define N_MAX_FD        250

// JTMOS file descriptor(fd)
typedef struct
{
	// Current offset.
	// O_DIRECTORY, O_CREAT, etc.
	int offset;
	// Current flags.
	int flags;
	// Current file name(+path).
	char name[256];
	// Bytes have been written on the file?
	int written;

	//
	int max_offset_peek;

        // owner PID
        int op;
        // is free?
        char isFree;
	// FD code
	int fd;

        // more parameters
        int v1,v2,v3,v4;
        char *p1,*p2,*p3,*p4;

	// A) On which directory the file is at. (DIRECTORY BLOCK #)
	// B) If file has data, on which bloc is it? (DATA BLOCK #)
	// C) On which device this file resides? (DEVICE #)
	DWORD db, datablock;
	int dnr;

	// Socket handle (if this is a socket descriptor)
	// A socket handle is used in receiving data from
	// a socket, or transmitting data to an open socket.
	int socketHandle;

	//
	FILE *f;
	
	// - EXTENSION:
        // Directory walking structure
        DIRWALK dw;
}FILEDES;

// File Descriptor Data Base
typedef struct
{
        int amount;
        FILEDES **fd;
}FDDB;

//
FDDB fddb;

//
FILEDES *NewFD(void);
void init_filedes(void);
int new_filedes(void);
int NEW_FILE_DESCRIPTOR(void *path, void *p1,void *p2, int v1,int v2);
int deallocate_proc_filedes(int pid);
int isValidFD(int fd);
int FreeFD(fd);
FILEDES *get_filedesptr(int fd);
void changeFDOwner(int fd, int pid);

#endif

