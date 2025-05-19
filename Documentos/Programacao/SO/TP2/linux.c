//Caua Guenrick Alves 23.2.4002
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

//funcao que contem todos os comandos Linux
void comandosLinux(char comando[]){

}



int main(){
    printf("Ola, Sou Cauã Guenrick, RA. 23.2.4002, e esta é a disciplina BCC264 2025-2");
    printf("\nDigiteum comando: ");
    
    char comando[21];

    //looping de comando
    do
    {
        scanf(comando);
        if (strcmp(comando) == "exit")
        {
            printf("\nEncerrando... ");
            break;
        }
        
        comandosLinux(comando);

    } while (1);
    

    return 0;
}