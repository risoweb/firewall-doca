#include <stdio.h>
#include "../include/firewall.h"

int main(void) {
    printf("=== FIREWALL DOCA (Prototipo em C) ===\n\n");

    /* Inicializa o firewall */
    firewall_init();

    /* Cria algumas regras de exemplo */
    FirewallRule rule1 = {
        .src_ip = 192168001001,  /* 192.168.1.1 */
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
        .src_ip = 192168001001,
        .dst_ip = 10000000001,
        .src_port = 5000,
        .dst_port = 80,
        .protocol = 6
    };
    printf("Pacote 1: %s\n", firewall_check_packet(&pkt1) ? "PERMITIDO" : "BLOQUEADO");

    Packet pkt2 = {
        .src_ip = 172160000001,
        .dst_ip = 8080808080,
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
