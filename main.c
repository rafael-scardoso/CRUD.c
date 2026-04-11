#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define TAMG 100
#define TAMM 50
#define TAMP 16
#define TAMPP 10
#define LABPF "laburban108.txt" //produtofinal
#define LABCOMP "laburban108.txt" //componentes
#define LABMP "laburban108.txt" //matéria prima



typedef struct  {
    int id; // id de cadastro da material-prima
    char nome[TAMM]; // nome do material
}Material;


typedef struct {
    int id; // id de cadastro e o id da peça
    float tFabrica, peso; //tempo de produção e o peso de material usado
    char nome[TAMPP];
    Material material;
}Componente; 

typedef struct {
    int id; // id de cadastro e o id da materia-prima
    char nome[TAMG];
    Componente componentes[10];
}Produto; 

//int total=0; //tamanho do vetor de cadastro
//Produto *cadastro; // vetor de cadastro

void ler(char buffer[], int tamanho){
    fgets(buffer, tamanho, stdin);
    buffer[strcspn(buffer,"\n")] = '\0';
}


void cadastrarProduto(){

    Produto p;

    printf("Digite o ID do produto: ");
    scan("%d",p.id);
    printf("Digite o nome do produto: ");
    ler(p.nome,TAMG);
    printf("Digite a quantidade de componentes o produto possui (até 10): ");
    int num;
    scanf("%d",num);
    if(num>10){
        printf("Número acima de 10. Programa será encerrado!");
        return 1;
    }
    for (int i=0;i>10;i++){
        printf("Digite o ID primeiro componente: ");
        scanf("d",&p.componentes[i].id);
    }
        
    /*FILE *arquivo = fopen(LABPF, "a");
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo\n");
        return;
    }
    fprintf(arquivo,"%s;%s;%d;%.2f;%.1f\n",
            p.idProduto,
            p.nomeProduto);           
    fclose(arquivo);*/
}
void cadastrarComponente(){

    Componente c;

    printf("Digite o ID do componente: ");
    scan("%d",c.id);
    printf("Digite o nome do componente: ");
    ler(c.nome,TAMG);
    printf("Digite o id do material: ");
    scanf("%d",c.material.id);
    printf("Digite o peso: ");
    scanf("%f",c.peso);
    printf("Digite tempo de fabricação [min]: ");
    scanf("%f",c.tFabrica);
    printf("Componente cadastrado!");
    printf("%d\n%s\n%f de %d\n%f min",c.id,c.nome,c.peso,c.material.id,c.tFabrica);

}

int inserirMenu(){
    printf("\nEscolha a opção desejada\n");
    printf("1- Cadastrar matéria prima\n");
    printf("2- Cadastrar componente\n");
    printf("3- Cadastrar produto final\n");
    printf("1- Cadastrar embalagem\n");
    printf("4- Alterar produto\n");
    printf("5- Calculadora rápida de valor do produto para shopee\n");
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
            case 2:
            break;
            
            case 0: 
                exit(1);
            break;
        }


        
    } while (menu != 0);

    
    
    
    fclose(arquivo);

}