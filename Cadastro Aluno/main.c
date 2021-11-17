/*
Escreva um programa que leia os dados dos alunos de um curso, sabendo que para cada aluno são informados:

Matricula;
Data de Nascimento;
Média Individual;
O programa deve disponibilizar ao usuário as seguintes funcionalidade

Incluir aluno: inclui os dados do aluno na lista.
Consultar Aluno: exibe os dados do aluno identificado pela matricula
Exibir alunos do curso: exibe os dados dos alunos do curso e informa a média geral
Excluir Aluno: exclui um aluno identificado pela matricula e exibe os dados desse aluno
Encerrar
Para isso, devem ser implementadas as seguintes funções:

INCLUIR : recebe os dados do aluno e os inclui na lista;
EXCLUIR: recebe a matricula do aluno, o exclui da lista e retorna seus dados;
CONSULTAR: recebe a matricula do aluno e retorna os dados deste aluno. Caso a matricula não seja localizada, retorna -1 como matricula;*/

#include <stdio.h>
#include <stdlib.h>


typedef struct aluno{
    int matricula;
    char data[20];
    float media;
    struct aluno *prox;  
} Aluno;

Aluno *inicio_lista;

///Inicializa a lista com Null
void inicia_lista_aluno(){
    inicio_lista = NULL;
}

///Inclui o aluno no inicio
int incluir_aluno(){
    Aluno *aluno;
    aluno = (Aluno *) malloc(sizeof(Aluno));

    if (aluno == NULL){
        return 0;
    }

    printf("-------------------\n");
    printf(" Cadastro de Aluno \n");
    printf("-------------------\n");

    printf("Matricula: ");
    scanf("%d", &aluno->matricula);
    fflush(stdin);
    printf("Data de nascimento: ");
    scanf("%s[^\n]", aluno->data);
    fflush(stdin);
    printf("Media: ");
    scanf("%f", &aluno->media);
    fflush(stdin);
    aluno->prox = NULL;

    if (inicio_lista == NULL) {
        inicio_lista = aluno;
    }else{
        aluno->prox = inicio_lista;
        inicio_lista = aluno;
    }

    system("cls");
    return 1;
}

///Pesquisa o aluno pela matricula
int pesquisar_aluno(){

    int matricula_digitada;
    printf("Digite a matricula: ");
    scanf("%d", &matricula_digitada);
    fflush(stdin);

    Aluno *listaaluno;

    if (inicio_lista == NULL) {
        return 0;  
    }

    listaaluno = inicio_lista;

    while(listaaluno != NULL){
        if(listaaluno->matricula == matricula_digitada){
            printf("--------------------\n");
            printf("Matricula = %d\n", listaaluno->matricula);
            printf("Data de nascimento = %s\n", &listaaluno->data);
            printf("Media = %f\n", listaaluno->media);
            printf("--------------------\n");
            return 1;
        }else{
            listaaluno = listaaluno->prox;
        }
    }

    if (listaaluno == NULL){
        return -1;
    }
  
}

///Exibi a lista de alunos cadastrados
int exibir_aluno(){
    Aluno *listaaluno;

    if (inicio_lista == NULL) {
        return 0;
    }

    listaaluno = inicio_lista;

    while (listaaluno != NULL) {
        printf("--------------------\n");
        printf("Matricula = %d\n", listaaluno->matricula);
        printf("Data de nascimento = %s\n", listaaluno->data);
        printf("Media = %.2f\n", listaaluno->media);
        printf("--------------------\n");
        listaaluno = listaaluno->prox;
    }

    return 1;
}

///Exclui o aluno usando a matricula com referencia 
int excluir_aluno(){
    int matricula_digitada;
    printf("Digite a matricula: ");
    scanf("%d", &matricula_digitada);
    fflush(stdin);

    Aluno *listaaluno;
    Aluno *anterioraluno;

    if (inicio_lista == NULL) {
        return -1;  
    }

    listaaluno = inicio_lista;
    anterioraluno = inicio_lista;

    while(listaaluno != NULL){
        if(listaaluno->matricula == matricula_digitada){
            printf("--------------------\n");
            printf("Matricula = %d\n", listaaluno->matricula);
            printf("Data de nascimento = %s\n", &listaaluno->data);
            printf("Media = %f\n", listaaluno->media);
            printf("--------------------\n");

            if(listaaluno == inicio_lista){
                inicio_lista = inicio_lista -> prox;
                free(listaaluno);
                return 1;
            }else {
                anterioraluno -> prox = listaaluno -> prox;
                free(listaaluno);
                return 1;
            }
        }else{
            listaaluno = listaaluno->prox;
        }
    }

    if (listaaluno == NULL){
        return 0;
    }
}

int main (void){

    int op = 0;
    int resultado = 0;

    inicia_lista_aluno();

    while (op!=5) {

        printf("\n------------------\n");
        printf("       Menu       \n");
        printf("------------------\n");
        printf("1)Cadatro de aluno\n");
        printf("2)Consulta de aluno\n");
        printf("3)Exibir alunos\n");
        printf("4)Excluir aluno\n");
        printf("5)Sair\n");
        scanf("%d", &op);
        system("cls");

        switch (op) {
        case 1:
            resultado = incluir_aluno();

            if (resultado == 1){
                printf("Aluno inserido com sucesso\n");
                printf("Aperte enter para abrir o menu");
                getchar();
                system("cls");
            }else{
                printf("Ocorreu um erro!!");
            }
        break;
        case 2:
            resultado = pesquisar_aluno();

            if(resultado == 0){
                printf("Lista vazia");
            }
            if(resultado == -1){
                printf("Matricula = -1\n");
                printf("Aluno nao encontrado");
            }else if(resultado == 1){
                printf("Aluno encontrado\n");
                printf("Aperte enter para abrir o menu");
                getchar();
                system("cls");
            }
        break;
        case 3:
            resultado = exibir_aluno();

            if (resultado == 0){
                printf("Lista Vazia");
            }else{
                printf("Fim Lista\n");
                printf("Aperte enter para abrir o menu");
                getchar();
                getchar();
                system("cls");
            }
        break;
        case 4:
            resultado = excluir_aluno();

            if(resultado == -1){
                printf("Lista vazia");
            }
            if(resultado == 0){
                printf("Aluno não encontrado");
            }else{
                printf("Aluno removido\n");
                printf("Aperte enter para abrir o menu");
                getchar();
                system("cls");
            }
        break;
        }
    }
    
}