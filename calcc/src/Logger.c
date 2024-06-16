#include "Logger.h"

Logger Logger_init(int fd, void (* log_msg)(int, const char *), void (* log_val)(int, const void *))
{
    return (Logger)
    {
        .fd = fd,
        .log_msg = log_msg,
        .log_val = log_val,
    };
}

void Logger_log_msg(const Logger * logger, const char * msg)
{
    if (logger->log_msg)
    {
        logger->log_msg(logger->fd, msg);
        logger->log_msg(logger->fd, "\n");
    }
}

void Logger_log_val(const Logger * logger, const void * val)
{
    if (logger->log_val)
    {
        logger->log_val(logger->fd, val);
        logger->log_msg(logger->fd, "\n");
    }
}