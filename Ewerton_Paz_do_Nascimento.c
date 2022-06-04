#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define NUMERO_PRATO 5
#define AT_PRATO 40

// Definição dos tipos
typedef struct pilha{
    int tam;
    int lim;
    char dado[1 + NUMERO_PRATO][AT_PRATO];
} Pilha;

// Funções auxiliares
int desempilhar(Pilha*);
int empilhar(const char*, Pilha*);
int topo(Pilha*,char*);
int mostrar(Pilha*, const char*);

// Função principal
int main(void) {
	setlocale(LC_ALL, "Portuguese");
	printf("******************* Empilhando os pratos: *******************\n");
    const char* pratos[] = {"(1)Vermelho","(2)Verde","(3)Azul","(4)Branco","(5)Laranja"};
    Pilha primeira_Pilha = {.tam = 0, .lim = NUMERO_PRATO};
    int res = 0;
    
    for (int i = 0; i < NUMERO_PRATO; i += 1) {
        res = empilhar((const char*)pratos[i], &primeira_Pilha);
        mostrar(&primeira_Pilha, "\nEmpilhando...");
        if (res < 1) break;
    }
    
    printf("\n\n**************** Desempilhando os pratos e colocando na outra pilha: ****************\n");
// Retira os pratos e os colocam na segunda pilha
    Pilha invertida = {.tam = 0, .lim = NUMERO_PRATO};
    char prato[AT_PRATO];  
    for (int i = primeira_Pilha.tam; i > 0; i -= 1) {
        topo(&primeira_Pilha, prato);
        mostrar(&primeira_Pilha, "\nDesempilhando...");
        desempilhar(&primeira_Pilha);
        empilhar(prato, &invertida);
    }
    mostrar(&primeira_Pilha, "\n\n******************** Resultado Final ********************\n\nResultado final da pilha original");
    mostrar(&invertida, "\nResultado final da nova pilha invertida");
    return 0;
}

// Função para inserir os pratos
int empilhar(const char* dado, Pilha* p) {
    p->tam += 1;
    if (p->tam > p->lim) {
        p->tam -= 1;
        return -3;
    }
    strcpy(p->dado[p->tam], dado);
    return p->tam;
}

// Função que retira os pratos da pilha
int desempilhar(Pilha* p) {
    if (p == NULL) return -1;
    if (p->tam == 0) return -2;
    p->tam -= 1;
    return p->tam;
}

// Função que copia o valor do topo da pilha
int topo(Pilha* p, char* dado) {
    if (p->tam == 0) return -2;
    strcpy(dado, p->dado[p->tam]);
    return 0;
}

// Função que mostra o resultado das pilhas
int mostrar(Pilha* p, const char* dado) {
    if (dado != NULL) printf("%s\n", dado);
    printf("%d prato(s)\n\n", p->tam);
    printf("Base->");
    for (int i = 1; i < p->tam; i += 1)
    printf("  %s", p->dado[i]);
    printf("  %s", p->dado[p->tam]);
    printf("  <-Topo\n");
    return 0;  	
}
