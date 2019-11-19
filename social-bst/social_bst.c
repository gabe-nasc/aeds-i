#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "social.h"

int main(int argc, char const *argv[])
{
    struct nodeA *head; // Cabeça da BST principal
    int count = 1; // Contador de pessoas
    char cmd[120]; // Comando inserido pelo usuário

    while (1)
    {
        printf(">> ");
        scanf("%[^\n]%*c", cmd);
        puts("");

        // Imprime a lista de comandos suportados
        if (!strcmp(cmd, "help"))
        {
            puts("help - mostra ajuda com comandos");
            puts("new x - adiciona uma nova pessoa (x) na rede");
            puts("del x - deleta uma pessoa (x) da rede");
            puts("bsc x - busca as informações de x");
            puts("nfd x y - adicionar uma nova amizade entre (x) e (y)");
            puts("dfd x y - deleta a amizade entre (x) e (y)");
            puts("chk x y - checar se existe amizade entre (x) e (y)");
            puts("prt - imprime todas as pessoas na rede");
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
            printf("%d\n", consulta_amizade(head, p1, p2));
        }
        else if (!strncmp(cmd, "prt", 3))
        {
            print_ordemA(head);
            puts("");
        }
        else if (!strncmp(cmd, "bsc", 3))
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

            ptr1->amgs = deleteB(ptr1->amgs, p2);
            ptr2->amgs = deleteB(ptr2->amgs, p1);
        }
        else if (!strcmp(cmd, "quit"))
        {
            break;
        }
    }

    return 0;
}