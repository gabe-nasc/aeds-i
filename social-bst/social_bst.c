#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "social.h"

int main(int argc, char const *argv[])
{
    struct nodeA *head; // Cabeça da BST principal
    int count = 1; // Contador de pessoas
    char cmd[120]; // Comando inserido pelo usuário

    puts("Binary Seach Tree - Social Network");
    puts("Digite 'help' para ver todos os comandos");
    while (1)
    {
        printf(">> ");
        scanf(" %[^\n]%*c", cmd);

        // Imprime a lista de comandos suportados
        if (!strcmp(cmd, "help"))
        {
            puts("help - Mostra ajuda com comandos");
            puts("new x - Adiciona uma nova pessoa (x) na rede");
            puts("del x - Deleta uma pessoa (x) da rede");
            puts("src x - Busca as informações de x");
            puts("nfd x y - Adiciona uma nova amizade entre (x) e (y)");
            puts("dfd x y - Deleta a amizade entre (x) e (y)");
            puts("chk x y - Verifica se existe amizade entre (x) e (y)");
            puts("prt - Imprime todas as pessoas na rede");
            puts("quit - Sair do programa");
        }
        //
        else if (!strncmp(cmd, "new", 3))
        {
            if (head == NULL)
            {
                head = allocA(count, cmd+4);
            }
            else
            {
                insertA(head, count, cmd+4);
            }
            printf("%s cadastrado.\nID: %d\n", cmd+4, count);
            count += 1;
        }
        else if (!strncmp(cmd, "nfd", 3))
        {
            int p1, p2;
            sscanf(cmd, "%*s %d %d", &p1, &p2);
            insertB(head, p1, p2);
        }
        else if (!strncmp(cmd, "chk", 3))
        {
            int p1, p2;
            sscanf(cmd, "%*s %d %d", &p1, &p2);
            int res = consulta_amizade(head, p1, p2);
            if (res)
            {
                puts("Há amizade entre os dois.");
            }
            else
            {
                puts("Não há amizade entre os dois.");
            }
        }

        else if (!strncmp(cmd, "prt", 3))
        {
            print_ordemA(head);
            puts("");
        }
        else if (!strncmp(cmd, "src", 3))
        {

            int p1;
            sscanf(cmd, "%*s %d", &p1);
            info(head, p1);
        }
        else if (!strncmp(cmd, "del", 3))
        {

            int p1;
            sscanf(cmd, "%*s %d", &p1);
            head = deleteA(head, p1);
            deleteAmgs(head, p1);
        }
        else if (!strncmp(cmd, "dfd", 3))
        {

            int p1, p2;
            sscanf(cmd, "%*s %d %d", &p1, &p2);

            struct nodeA *ptr1 = find(head, p1);
            struct nodeA *ptr2 = find(head, p2);

            if (ptr1 == NULL && ptr2 == NULL)
            {
                printf("%d e %d não encontrados\n", p1, p2);
                continue;
            }

            if (ptr1 == NULL)
            {
                printf("%d não encontrado\n", p1);
                continue;
            }
            
            if (ptr2 == NULL)
            {
                printf("%d não encontrado\n", p2);
                continue;
            }

            ptr1->amgs = deleteB(ptr1->amgs, p2);
            ptr2->amgs = deleteB(ptr2->amgs, p1);
        }
        else if (!strcmp(cmd, "quit"))
        {
            break;
        }
    }
    memset(cmd, 0, sizeof(cmd));
    return 0;
}