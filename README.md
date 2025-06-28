# 🔄 Problema Produtor/Consumidor em C

Este projeto implementa o clássico problema do **Produtor e Consumidor** usando a linguagem C. Dois processos compartilham um arquivo (`buffer.txt`) para produzir e consumir valores inteiros aleatórios. O controle de concorrência é feito através de um **arquivo de trava (`buffer.txt.lock`)**, impedindo acesso simultâneo.

## 📌 Objetivo

- Simular dois processos (produtor e consumidor) acessando a mesma área de memória (representada por um arquivo).
- Utilizar `fork()` para criar os processos.
- Controlar a concorrência com uso de travas de acesso (`.lock`).
- Exibir o comportamento dos processos em tempo real.

## ⚙️ Tecnologias Utilizadas

- Linguagem C
- Chamada de sistema `fork()`
- Manipulação de arquivos (`fopen`, `fscanf`, `fprintf`)
- Comandos de sistema (`remove`, `rename`, `sleep`)
- Geração de números aleatórios (`rand()`)

## 📁 Estrutura do Projeto

- `produtor_consumidor.c` → Código-fonte principal
- `buffer.txt` → Arquivo que armazena os dados
- `buffer.txt.lock` → Arquivo de controle de acesso (trava)
- `trabalho2.pdf` → Documento com a especificação do projeto

## ▶️ Como Compilar e Executar

```bash
gcc produtor_consumidor.c -o produtor_consumidor
./produtor_consumidor
