#ifndef EPOLL_H
#define EPOLL_H

#include <sys/epoll.h>
#include <sys/timerfd.h>
#include <sys/eventfd.h>
#define LIBUS_SOCKET_READABLE EPOLLIN
#define LIBUS_SOCKET_WRITABLE EPOLLOUT

struct us_loop {
    int num_polls;
    int epfd;
    struct us_timer *sweep_timer;
    struct epoll_event ready_events[1024];

    // todo: common items should lie in common struct! eventing/common.h
    int last_write_failed;
    struct us_socket_context *head;
    void *recv_buf;
};

struct us_poll {
    struct {
        int fd : 28;
        unsigned int poll_type : 4;
    } state;
};

#endif // EPOLL_H
