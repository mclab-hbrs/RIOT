#include "net/ipv6/addr.h"
#include "net/sock/tcp.h"
#include "lwip.h"
#include "lwip/netif.h"

#define DEFAULT_NETIF 1U


int send_tcp(sock_tcp_ep_t *remote, char *data, uint16_t data_len) {
    sock_tcp_t sock;
    sock_tcp_ep_t ep;
    ssize_t written_bytes;
    char remote_addr[IPV6_ADDR_MAX_STR_LEN] = {0,};
    
    switch (sock_tcp_connect(&sock, remote, 0, SOCK_FLAGS_REUSE_EP)) {
        case 0:
            puts("Connection established.");
            break;
        case -EADDRINUSE:
            puts("The source port is already in use.");
            return 2;
        case -ECONNREFUSED:
            puts("Connection refused.");
            return 2;
        case -EAFNOSUPPORT:
            puts("The transport protocol version is not supported.");
            return 2;
        case -EINVAL:
            puts("Remote address or used interface invalid.");
            return 2;
        case -ENETUNREACH:
            puts("Network is unreachable.");
            return 2;
        case -ENOMEM:
            puts("Not enough memory available.");
            return 2;
        case -EPERM:
            puts("Connection is not permitted, check firewall.");
            return 2;
        case -ETIMEDOUT:
            puts("Connection timed out.");
            return 2;
        default:
            puts("An unknown error occured.");
    }

    if (!sock_tcp_get_remote(&sock, &ep)) {
        ipv6_addr_to_str(remote_addr, (ipv6_addr_t*) &ep.addr.ipv6, IPV6_ADDR_MAX_STR_LEN);
        printf("Connection open to remote %s\n", remote_addr);
    } else {
        puts("Could not fetch information about remote!");
        return 3;
    }

    written_bytes = sock_tcp_write(&sock, data, data_len);

    if (written_bytes == data_len) {
        puts("Data was sent successfully.");
    } else {
        switch (written_bytes) {
            case -ECONNABORTED:
                puts("Connection was aboarted.");
                return 4;
            case -ECONNRESET:
                puts("Connection was resetted.");
                return 4;
            case -ENOMEM:
                puts("Not enough memory available for sending.");
                return 4;
            case -ENOTCONN:
                puts("Connection is not established.");
                return 4;
            default:
                puts("Not all data could be written.");
        }
    }
    
    puts("Disconnecting.");
    sock_tcp_disconnect(&sock);
    
    return 0;
}

void tcp6_init(void){
    puts("Initialize LWIP");
    lwip_bootstrap();
    // xtimer_init();
}

int tcp6_cmd(int argc, char **argv) {
    sock_tcp_ep_t remote = {.family = AF_INET6,
                            .netif = DEFAULT_NETIF};
    uint16_t data_len;
    
    if (argc != 4) {
        printf("usage: %s <addr> <port> <data> \n", argv[0]);
        return 1;
    }

    if (!ipv6_addr_from_str( (ipv6_addr_t*) &remote.addr.ipv6, argv[1])) {
        puts("IPv6 address is invalid.");
        return 1;
    }

    remote.port = atoi(argv[2]);

    // Shell gives value zero terminated
    data_len = strlen(argv[3]);

    return send_tcp(&remote, argv[3], data_len);
}