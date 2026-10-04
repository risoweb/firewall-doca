# Firewall DOCA

![Firewall DOCA](./assets/image_c4a47331(1).jpg)

Firewall em linguagem C, com regras de filtragem de pacotes, suporte a portas e protocolos e execução em ambiente Docker.

## Visão geral

Firewall simples que:

- armazena regras de entrada e saída;
- verifica pacotes com base em IP, porta e protocolo;
- permite bloquear ou permitir tráfego;
- demonstra uso de estruturas em C para regras e inspeção de redes;
- pode ser executado localmente ou via Docker.

## Funcionalidades

- ✅ Gerenciamento de regras de firewall;
- ✅ Política de exemplo com regras permitidas;
- ✅ Verificação de pacotes por IP de origem/destino;
- ✅ Suporte a portas e protocolo TCP;
- ✅ Estrutura modular em C;
- ✅ Pronto para build com Make;
- ✅ Compatível com execução em container Docker.

## Estrutura do projeto

```text
firewall-doca/
├── include/
│   └── firewall.h
├── src/
│   ├── firewall.c
│   └── main.c
├── assets/
│   └── firewall-doca-banner.png
├── Dockerfile
├── Makefile
├── README.md
└── .gitignore
```

## Requisitos

- GCC
- Make
- Ubuntu/Debian ou ambiente Linux equivalente
- Docker (opcional, para execução em container)

## Como compilar

```bash
make clean
make all
```

## Como executar localmente

```bash
make run
```

## Como executar com Docker

```bash
docker build -t firewall-doca .
docker run --rm firewall-doca
```

## Exemplo de saída

```text
=== FIREWALL DOCA (Prototipo em C) ===

=== TESTANDO PACOTES ===
Pacote 1: PERMITIDO
Pacote 2: BLOQUEADO

Programa finalizado.
```

## Observações

Este projeto é um protótipo didático. Ele foi pensado para demonstrar a lógica de firewall em C e pode ser expandido com:

- regras dinâmicas em memória;
- suporte a UDP;
- validação de IPv4 em formato decimal e string;
- persistência das regras em arquivo;
- interface CLI mais avançada.

## Contribuição

Contribuições são bem-vindas. Para melhorias, abra uma issue ou envie um pull request com uma descrição clara do problema e da solução.

## Licença

Este projeto é disponibilizado como exemplo educacional para fins de estudo e demonstração.
