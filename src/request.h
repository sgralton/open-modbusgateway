#ifndef REQUEST_H
#define REQUEST_H

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>

#include <mosquitto.h>

typedef struct {
    struct mosquitto *mosq;

    uint8_t format;
    unsigned long long int cookie;
    uint8_t ip_type;
    char serial_device_id[32];
    char ip[64];
    char port[8];
    uint16_t timeout;
    uint8_t slave_id;
    uint8_t function;
    uint32_t register_addr;
    uint16_t register_count;
    uint16_t data[123];

    char response_topic[1024];
} request_t;

#define IP_TYPE_IPV4 0
#define IP_TYPE_IPV6 1
#define IP_TYPE_HOSTNAME 2

#define MAX_REQUEST_THREADS 20 // TODO: Make this configurable

char *
join_regs_str(const uint16_t datalen, const uint16_t *data, const char *sep);

void *handle_request(void *arg);

#endif
