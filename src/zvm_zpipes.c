/*
 *
 */

#include <czmq.h>
#include <zpipes_client.h>
#include "zvm_zpipes.h"

typedef struct pipe_info_t {
    char *broker;
    char *pipe;
    zpipes_client_t *pclient;
} pipe_info_t;


/* __attribute__((constructor)) void init(void); */

/* void */
/* init(void) */
/* { */
/*     zsys_handler_set(NULL); */
/* } */

ZVMPIPE 
zvm_pipe_open(const char *descriptor)
{
    pipe_info_t *pinfo;

    // Descriptor format:
    // <broker>:<pipe_name>
    pinfo = (pipe_info_t *)zmalloc(sizeof(pipe_info_t));

    pinfo->broker = strdup(descriptor);
    if(pinfo->broker) {
        char *del = strchr(pinfo->broker, '|');
        if(del) {
            *del = 0;
            pinfo->pipe = del + 1;
            
            pinfo->pclient = zpipes_client_new(pinfo->broker, pinfo->pipe);
            if(pinfo->pclient)
                return pinfo;
        }
        free(pinfo->broker);
    }
    free(pinfo);

    return NULL;
}

int
zvm_pipe_close(ZVMPIPE pipe)
{
    zpipes_client_destroy(&pipe->pclient);
    if(pipe->broker)
        free(pipe->broker);

    free(pipe);

    return 0;
}

ssize_t
zvm_pipe_read(ZVMPIPE pipe, void *buf, size_t count)
{
    ssize_t size;

    size = zpipes_client_read(pipe->pclient, buf, count, 0);

    if (size < 0) 
        errno = zpipes_client_error(pipe->pclient);

    return size;
}

ssize_t
zvm_pipe_write(ZVMPIPE pipe, void *buf, size_t count)
{
    int size;

    size = zpipes_client_write(pipe->pclient, buf, count, 0);

    if (size < 0)
        errno = zpipes_client_error(pipe->pclient);

    return size;
}

