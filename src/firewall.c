#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/firewall.h"

#define MAX_RULES 100

/* Tabela de regras */
static FirewallRule rules[MAX_RULES];
static int rule_count = 0;

/* Inicializa o firewall */
void firewall_init(void) {
    rule_count = 0;
    printf("[FIREWALL] Inicializado com capacidade para %d regras\n", MAX_RULES);
}

/* Verifica se um pacote é permitido pelas regras */
bool firewall_check_packet(const Packet *pkt) {
    if (pkt == NULL) {
        return false;
    }

    /* Por padrão, nega (política de deny-all) */
    for (int i = 0; i < rule_count; i++) {
        FirewallRule *rule = &rules[i];

        /* Verifica se o pacote corresponde à regra */
        if ((rule->src_ip == 0 || rule->src_ip == pkt->src_ip) &&
            (rule->dst_ip == 0 || rule->dst_ip == pkt->dst_ip) &&
            (rule->src_port == 0 || rule->src_port == pkt->src_port) &&
            (rule->dst_port == 0 || rule->dst_port == pkt->dst_port) &&
            (rule->protocol == 0 || rule->protocol == pkt->protocol)) {

            return rule->allow;
        }
    }

    /* Se nenhuma regra corresponder, nega por padrão */
    return false;
}

/* Adiciona uma regra */
void firewall_add_rule(const FirewallRule *rule) {
    if (rule_count >= MAX_RULES) {
        printf("[FIREWALL] Tabela de regras cheia!\n");
        return;
    }

    memcpy(&rules[rule_count], rule, sizeof(FirewallRule));
    rule_count++;
    printf("[FIREWALL] Regra adicionada (total: %d)\n", rule_count);
}

/* Imprime todas as regras */
void firewall_print_rules(void) {
    printf("\n=== REGRAS DO FIREWALL ===\n");
    for (int i = 0; i < rule_count; i++) {
        printf("Regra %d:\n", i + 1);
        printf("  Src IP: %u | Dst IP: %u\n", rules[i].src_ip, rules[i].dst_ip);
        printf("  Src Port: %u | Dst Port: %u\n", rules[i].src_port, rules[i].dst_port);
        printf("  Protocolo: %u | Ação: %s\n", rules[i].protocol, 
               rules[i].allow ? "PERMITIR" : "BLOQUEAR");
    }
    printf("========================\n\n");
}

/* Limpa o firewall */
void firewall_cleanup(void) {
    rule_count = 0;
    printf("[FIREWALL] Limpado\n");
}