/*
 *
 */

#ifndef __ZVM_ZPIPES_H__
#define __ZVM_ZPIPES_H__

#include <unistd.h>        // ssize_t

struct pipe_info_t;
typedef struct pipe_info_t* ZVMPIPE;

extern ZVMPIPE zvm_pipe_open(const char *descriptor);
extern int zvm_pipe_close(ZVMPIPE pipe);
extern ssize_t zvm_pipe_read(ZVMPIPE pipe, void *buf, size_t count);
extern ssize_t zvm_pipe_write(ZVMPIPE pipe, void *buf, size_t count);

#endif /* __ZVM_ZPIPES_H__ */
