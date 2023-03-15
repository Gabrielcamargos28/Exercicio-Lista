
#include<stdio.h>
#include<stdlib.h>

struct No {
    int valor;
    No *prox;
};

struct Lista {
    No *cabeca, *cauda;

    Lista() {
        cabeca = cauda = NULL;
    }

    bool vazia() {
        return (cabeca == NULL);
    }

    void inserirInicio(int v) {
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = cabeca;
            cabeca = novo;
        }
    }

    void inserirFinal(int v) {
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = NULL;
            cauda->prox = novo;
            cauda = novo;
        }
    }

    void imprimir() {
        /*for (No *aux = cabeca; aux != NULL; aux = aux->prox) */
        No *aux = cabeca;
        while (aux != NULL) {
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }
    }

    int tamanho() {
        int t = 0;
        No *aux = cabeca;
        while (aux != NULL) {
            t++;
            aux = aux->prox;
        }
        return t;
    }

    // Qestao 1 --------------------------------------------------
    void removerUltimos(int n){
        if(tamanho() > n){
            int t = 0;
            No *aux = cabeca;
            while (aux != NULL) {
                t++;
                if(t == (tamanho() - n)){
                    aux->prox = NULL;
                }
                aux = aux->prox;
            }
        }
    }

    // Questao 2 --------------------------------------------------
    void removerSegundoElemento() {
        No *segundoNo;
        if(tamanho() > 1){
            segundoNo = cabeca->prox;
            cabeca->prox = segundoNo->prox;
        }
    }

    // Questao 3 --------------------------------------------------

    // O m�todo receber� como par�metro o m�todo tamanho() na main
    void inserirTamanhoNoFinalDaLista(int v) {
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = NULL;
            cauda->prox = novo;
            cauda = novo;
        }
    }

    // Questao 4 --------------------------------------------------
    void inserirDeUmAteN(int n){
        int i;
        for(i = 1; i <= n; i++){
            No *novo = new No();
            novo->valor = i;
            if (vazia()) {
                novo->prox = NULL;
                cabeca = novo;
                cauda = novo;
            } else {
                novo->prox = NULL;
                cauda->prox = novo;
                cauda = novo;
            }
        }
    }

    // Questao 5 --------------------------------------------------

};



int main() {

    int opcao, nRemover, valor, umAteN;

    Lista l;

    do{
        printf("\nEscolha uma opcao\n1- Remover os ultimos elementos\n2- Remover o segundo elemento\n");
        printf("3- Inserir tamanho no final da lista\n4- Inserir de um ate N\n5- Imprimir\n6- Inserir no final\n7- Sair\n");
        scanf("%d", &opcao);

        switch(opcao){

        case 1:
            system("cls");
            printf("Digite um numero n: ");
            scanf("%d", &nRemover);
            l.removerUltimos(nRemover);
            printf("\nNumeros removidos!\n");
            break;

        case 2:
            system("cls");
            l.removerSegundoElemento();
            printf("\nSegundo elemento removido!\n");
            break;

        case 3:
            system("cls");
            l.inserirTamanhoNoFinalDaLista(l.tamanho());
            printf("\nTamanho inserido!\n");
            break;

        case 4:
            system("cls");
            printf("Digite um numero para inserir ate ele: ");
            scanf("%d", &umAteN);
            l.inserirDeUmAteN(umAteN);
            printf("\nInsercao feita!\n");
            break;

        case 5:
        case 5:
            system("cls");
            l.imprimir();
            break;

        case 6:
            system("cls");
            printf("Digite o numero a ser inserido: ");
            scanf("%d", &valor);
            l.inserirFinal(valor);
            printf("\nNumero inserido!\n");
            break;

        }

    }while(opcao != 7);

    return 0;
}
