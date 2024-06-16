#ifndef IO_H
#define IO_H

void    io_msg(int fd, const char * msg);
int     io_error(const char * msg);
void    io_dbg_complex(int fd, const void * z);
void    io_pprint_complex(int fd, const void * z);

#endif