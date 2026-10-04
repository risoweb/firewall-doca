#ifndef FIREWALL_H
#define FIREWALL_H

#include <stdint.h>
#include <stdbool.h>

/* Estrutura para representar uma regra de firewall */
typedef struct {
    uint32_t src_ip;      /* IP de origem */
    uint32_t dst_ip;      /* IP de destino */
    uint16_t src_port;    /* Porta de origem */
    uint16_t dst_port;    /* Porta de destino */
    uint8_t protocol;     /* Protocolo (TCP=6, UDP=17) */
    bool allow;           /* true = permitir, false = bloquear */
} FirewallRule;

/* Estrutura para representar um pacote */
typedef struct {
    uint32_t src_ip;
    uint32_t dst_ip;
    uint16_t src_port;
    uint16_t dst_port;
    uint8_t protocol;
} Packet;

/* Funções públicas */
void firewall_init(void);
bool firewall_check_packet(const Packet *pkt);
void firewall_add_rule(const FirewallRule *rule);
void firewall_print_rules(void);
void firewall_cleanup(void);

#endif /* FIREWALL_H */