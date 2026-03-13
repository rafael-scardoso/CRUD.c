#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define TAMG 100
#define TAMP 16
#define TAM 50
#define LAB "laburban108.txt"

typedef struct {

    int idMaterial; // id de cadastro e o id da materia-prima
    float tFabrica, pesoMaterial; //tempo de produção e o peso de material usado
    char nomeProduto[TAM],idProduto[TAMP];
}Produto; 

typedef struct  {
    int idMaterial; // id de cadastro da material-prima
    char nomeMaterial[TAM]; // nome do material
    
}Material;

int total=0; //tamanho do vetor de cadastro
Produto *cadastro; // vetor de cadastro

void ler(char buffer[], int tamanho){

    
    fgets(buffer, tamanho, stdin);

    buffer[strcspn(buffer,"\n")] = '\0';
    
}


void cadastrar(){

    Produto p;

    printf("Digite o ID do produto: ");
    ler(p.idProduto,TAM);

    printf("Digite o nome do produto: ");
    ler(p.nomeProduto,TAM);

    printf("Digite o ID da matéria-prima: ");
    scanf("%d",&p.idMaterial);

    printf("Digite o peso de matéria-prima: ");
    scanf("%f",&p.pesoMaterial);

    printf("Digite o tempo de fabricação em horas: ");
    scanf("%f",&p.tFabrica);
    getchar();
    
    FILE *arquivo = fopen(LAB, "a");

    if(arquivo == NULL){
        printf("Erro ao abrir arquivo\n");
        return;
    }

    fprintf(arquivo,"%s;%s;%d;%.2f;%.1f\n",
            p.idProduto,
            p.nomeProduto,
            p.idMaterial,
            p.pesoMaterial,
            p.tFabrica);

    fclose(arquivo);
}


int inserirMenu(){
    printf("\nEscolha a opção desejada\n");
    printf("1- Cadastrar produto\n");
    printf("2- Alterar produto\n");
    printf("3- Calcular valor do produto\n");
    printf("0- Fechar Programa\n");
    int menu;
    scanf("%d",&menu);
    getchar();
    

    return menu;
}


int main(){

    int menu;
    setlocale(LC_ALL, "Portuguese");

    FILE *arquivo = fopen(LAB, "r+"); // bloco verifica se o arquivo existe. se não existe, ele é criado e adicionado cabeçalho
    if(arquivo == NULL){
    arquivo = fopen(LAB, "w");
    fputs("ID;NOME;MATERIAL;PESO;TEMPO\n",arquivo);
    fclose(arquivo);  
    }
    printf("------------------------------------------------------ \n");
    printf("Bem vindo ao cadastro de produtos da Lab Urban 10\n");
   
       

    
    do {
        
        menu=inserirMenu();
        switch (menu) {
            case 1: 
                cadastrar();
            break;
           
            case 2: break;
            
            case 0: 
                exit(1);
            break;
        }


        
    } while (menu != 0);

    
    
    
    fclose(arquivo);

}