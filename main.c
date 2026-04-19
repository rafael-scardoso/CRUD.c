#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define TAMG 100
#define TAMM 50
#define TAMP 16
#define TAMPP 10
#define BDPF "bd_pf.txt" //produtofinal
#define BDCOMP "bd_comp.txt" //componentes
#define BDMP "bd_mp.txt" //matéria prima
#define IMPOSTO 0.04
#define TAXAPLAT 0.2
#define TAXAFIXAXPLAT 4
#define MAGEMLUCRO 0.3
#define EMBALAGEMTESTE 3


typedef struct  {
    int id; // id de cadastro da material-prima
    char nome[TAMM],cor[TAMM],marca[TAMM]; // nome do material
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


void ler(char buffer[], int tamanho){
    fgets(buffer, tamanho, stdin);
    buffer[strcspn(buffer,"\n")] = '\0';
}

void cadastrarMaterial(Material **vetorMaterial, int *tamanhoVetorM) {
    Material m;

    printf("Digite o ID da matérial-prima: ");
    scanf("%d", &m.id);
    printf("Digite o nome do material: ");
    ler(m.nome, TAMG);
    printf("Digite a marca: ");
    ler(m.marca, TAMM);
    printf("Digite a cor: ");
    ler(m.cor, TAMM);
    
    (*tamanhoVetorM)++;
    Material *temp = realloc(*vetorMaterial, *tamanhoVetorM * sizeof(Material));
    if (temp == NULL) {
        printf("Erro ao realocar memória!\n");
        (*tamanhoVetorM)--;
        return;
    }

    *vetorMaterial = temp;
    (*vetorMaterial)[*tamanhoVetorM - 1] = m;

    printf("Componente cadastrado!\n");
}


void cadastrarComponente(Componente **vetorComponente, int *tamanhoVetorC) {
    Componente c;

    printf("Digite o ID do componente: ");
    scanf("%d", &c.id);
    printf("Digite o nome do componente: ");
    ler(c.nome, TAMG);
    printf("Digite o id do material: ");
    scanf("%d", &c.material.id);
    printf("Digite o peso: ");
    scanf("%f", &c.peso);
    printf("Digite tempo de fabricação [min]: ");
    scanf("%f", &c.tFabrica);

    (*tamanhoVetorC)++;
    Componente *temp = realloc(*vetorComponente, *tamanhoVetorC * sizeof(Componente));
    if (temp == NULL) {
        printf("Erro ao realocar memória!\n");
        (*tamanhoVetorC)--;
        return;
    }

    *vetorComponente = temp;
    (*vetorComponente)[*tamanhoVetorC - 1] = c;

    printf("Componente cadastrado!\n");
}

void cadastrarProduto(Produto **vetorProduto, int *tamanhoVetorP){

    Produto p;

    printf("Digite o ID do produto: ");
    scanf("%d",&p.id);
    printf("Digite o nome do produto: ");
    ler(p.nome,TAMG);
    printf("Digite a quantidade de componentes o produto possui (até 10): ");
    int num;
    scanf("%d",&num);
    if(num>10){
        printf("Número acima de 10. Programa será encerrado!");
        exit (1) ;
    }
    for (int i=0;i<num;i++){
        printf("Digite o ID primeiro componente: ");
        scanf("%d",&p.componentes[i].id);
    }   
    (*tamanhoVetorP)++;
    Produto *temp = realloc(*vetorProduto, *tamanhoVetorP * sizeof(Produto));
    if (temp == NULL) {
        printf("Erro ao realocar memória!\n");
        (*tamanhoVetorP)--;
        return;
    }

    *vetorProduto = temp;
    (*vetorProduto)[*tamanhoVetorP - 1] = p;       
}

int inserirMenu(){
    printf("\nEscolha a opção desejada\n");
    printf("1- Cadastrar matéria prima\n");
    printf("2- Cadastrar componente\n");
    printf("3- Cadastrar produto final\n");
    printf("4- Cadastrar embalagem\n");
    printf("5- Alterar produto\n");
    printf("6- Calculadora rápida de valor do produto para shopee\n");
    printf("0- Fechar Programa\n");
    int menu;
    scanf("%d",&menu);
    getchar();
    

    return menu;
}

void calcularPreco(){
    
    float preco,custo;
    printf("Digite o custo do produto: ");
    scanf("%f",&custo);

    preco=(custo+TAXAFIXAXPLAT+EMBALAGEMTESTE)/(1-TAXAPLAT-IMPOSTO-MAGEMLUCRO);
    
    printf("O custo para venda no shopee é de %.2f",preco);
    
    return; 
}


int main(){

    int menu;
    setlocale(LC_ALL, "Portuguese");
  
        Material *vetorMaterial = malloc(sizeof(Material));
        Componente *vetorComponente = malloc(sizeof(Componente));
        Produto *vetorProduto = malloc(sizeof(Produto));
        int tamanhoVetorM = 0;  
        int tamanhoVetorC = 0;
        int tamanhoVetorP = 0;  


    
    printf("------------------------------------------------------ \n");
    printf("Bem vindo ao cadastro de produtos \n");
    
    

    
    do {
        menu = inserirMenu();
        switch (menu) {
            case 1:
                cadastrarMaterial(&vetorMaterial, &tamanhoVetorM);
                break;
            case 2:
                cadastrarComponente(&vetorComponente, &tamanhoVetorC);
                break;
            case 3:
                cadastrarProduto(&vetorProduto, &tamanhoVetorP);
                break;
            case 6:
                calcularPreco();
                break;
            case 0:
                printf("Até mais\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (menu != 0);

    
    
    
    
    free(vetorMaterial);
    free(vetorComponente);
    free(vetorProduto);
}
