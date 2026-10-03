#include <stdio.h>
#include "../include/firewall.h"

int main(void) {
    printf("=== FIREWALL DOCA (Prototipo em C) ===\n\n");

    /* Inicializa o firewall */
    firewall_init();

    /* Cria algumas regras de exemplo */
    FirewallRule rule1 = {
        .src_ip = (192 << 24) | (168 << 16) | (1 << 8) | 1,  /* 192.168.1.1 */
        .dst_ip = 0,              /* Qualquer destino */
        .src_port = 0,            /* Qualquer porta origem */
        .dst_port = 80,           /* Porta HTTP */
        .protocol = 6,            /* TCP */
        .allow = true
    };

    FirewallRule rule2 = {
        .src_ip = 0,              /* Qualquer origem */
        .dst_ip = 0,              /* Qualquer destino */
        .src_port = 0,
        .dst_port = 443,          /* Porta HTTPS */
        .protocol = 6,            /* TCP */
        .allow = true
    };

    /* Adiciona as regras */
    firewall_add_rule(&rule1);
    firewall_add_rule(&rule2);

    /* Imprime as regras */
    firewall_print_rules();

    /* Testa alguns pacotes */
    printf("=== TESTANDO PACOTES ===\n");

    Packet pkt1 = {
        .src_ip = (192 << 24) | (168 << 16) | (1 << 8) | 1,  /* 192.168.1.1 */
        .dst_ip = (10 << 24) | (0 << 16) | (0 << 8) | 1,     /* 10.0.0.1 */
        .src_port = 5000,
        .dst_port = 80,
        .protocol = 6
    };
    printf("Pacote 1: %s\n", firewall_check_packet(&pkt1) ? "PERMITIDO" : "BLOQUEADO");

    Packet pkt2 = {
        .src_ip = (172 << 24) | (16 << 16) | (0 << 8) | 1,   /* 172.16.0.1 */
        .dst_ip = (8 << 24) | (8 << 16) | (8 << 8) | 8,      /* 8.8.8.8 */
        .src_port = 3000,
        .dst_port = 22,
        .protocol = 6
    };
    printf("Pacote 2: %s\n", firewall_check_packet(&pkt2) ? "PERMITIDO" : "BLOQUEADO");

    /* Limpa */
    firewall_cleanup();
    printf("\nPrograma finalizado.\n");

    return 0;
}
