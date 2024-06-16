#ifndef LOGGER_H
#define LOGGER_H

typedef struct Logger Logger;

struct Logger
{
    int     fd;
    void    (* log_msg)(int, const char *);
    void    (* log_val)(int, const void *);
};

Logger  Logger_init(int fd, void (* log_msg)(int, const char *), void (* log_val)(int, const void *));
void    Logger_log_msg(const Logger * logger, const char * msg);
void    Logger_log_val(const Logger * logger, const void * val);

#endif