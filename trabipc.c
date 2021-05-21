#include <stdio.h>
#include <stdlib.h>
#define MAX_PATRIMONIOS 50
typedef struct{
    char nome[50];
    int data;
    int ativo; //0->inativo...1->ativo;
    int id;
    char marca[50];
    char setor[50];
    char tecnico[50];
    int datamanutencao;
    char status[50];
} patrimonio;

patrimonio patrimonios[MAX_PATRIMONIOS]; //lista dos patrimonios usando a struct patrimonio
//MAX_PATRIMONIOS define o limite da quantidade de patrimonios

void cadastrar(/*"struct patrimonio T[]" <- não segue o template*/){
	char nome[50];
    int data;
    int id;
    char marca[50];
    char setor[50];
    char tecnico[50];
    int datamanutencao;
    char status[50];
    int ativo;
    int op=1;
    system("cls"); //limpa o terminal
    while(op!=0){
        printf("-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("Cadastrar um Patrimonio: \n");
        printf("-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("ID: ");
        scanf("%d",&id);
        printf("\nNome: ");
        scanf("%s",&nome);
        printf("\nSetor: ");
        scanf("%s",&setor);
        printf("\nData: ");
        scanf("%d",&data);
        printf("\nMarca: ");
        scanf("%s",&marca);
        printf("\nStatus: ");
        scanf("%s",&status);
        if (strcmp (status, "manutencao")== 0){
            printf("\nTecnico responsavel: ");
            scanf("%s",&tecnico);
            printf("\nInicio da manutencao: ");
            scanf("%d",&datamanutencao);
        }
        for (int i = 0;i< MAX_PATRIMONIOS;i++){
            if (patrimonios[i].ativo==0){ //0->inativo...1->ativo - usar na baixa de patrimonios
                patrimonios[i].data = data;
                patrimonios[i].id = id;
                strcpy(patrimonios[i].nome, nome);
                strcpy(patrimonios[i].marca, marca);
                strcpy(patrimonios[i].status, status);
                strcpy(patrimonios[i].setor, setor);
                strcpy(patrimonios[i].tecnico, tecnico);
                patrimonios[i].datamanutencao = datamanutencao;
                patrimonios[i].ativo=1;
                break;}}
        printf("\n1 - Continuar\n0 - Sair\n");
        scanf("%d",&op);}}

void inventario(/*"struct patrimonio T[]" <- não segue o template*/){
    int id;
    system("cls");
    printf("-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("Inventario de Patrimonios: \n");
    printf("-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    for (int i = 0; i < MAX_PATRIMONIOS; i++){
        if (patrimonios[i].ativo==1){
        printf("\n---------------");
        printf("\nNumero N.%d",i+1);
        printf("\nID: #%d",patrimonios[i].id);
        printf("\nNome: %s\n\n",patrimonios[i].nome);}}}

void mostra1(/*"struct patrimonio T[]" <- não segue o template*/){
    int id;
    int op = 1;
    system("cls");
    while(op!=0){
        printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
        printf("Exibir um Patrimonio detalhadamente: \n");
        printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
        printf("\nDigite o id do patrimonio: #\n");
        scanf("%d",&id);
        for(int i = 0 ; i < MAX_PATRIMONIOS; i++){
        if (patrimonios[i].id == id){
            printf("\n---------------");
            printf("\nNumero %d",i+1);
            printf("\nID: #%d",patrimonios[i].id);
            printf("\nNome: %s",patrimonios[i].nome);
            printf("\nData: %d",patrimonios[i].data);
            printf("\nSetor: %s",patrimonios[i].setor);
            printf("\nMarca: %s",patrimonios[i].marca);
            printf("\nStatus: %s",patrimonios[i].status);
            if (strcmp (patrimonios[i].status, "manutencao")== 0){
            printf("\nTecnico: %s",patrimonios[i].tecnico);
            printf("\nData Manutencao: %d",patrimonios[i].datamanutencao);
        }
        }
    }printf("\n\nDeseja pesquisar outro Patrimonio?\n0 - Nao\n1 - Sim\n");
    scanf("%d",&op);}}

void baixa(/*"struct patrimonio T[]" <- não segue o template*/){
    system("cls");
    printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
    printf("Efetuar Baixa de um Patrimonio: \n");
    printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
    int id;
    inventario();
    printf("Digite o ID do patrimonio a ser removido: #");
    scanf("%d",&id);
    for(int i = 0 ; i < MAX_PATRIMONIOS; i++){
        if(patrimonios[i].id==id){
        strcpy(patrimonios[i].status,"inativo"); //torna o status patrimonio como inativo
        patrimonios[i].ativo=0; //tira o patrimonio do inventario (ainda é possivel acessar pelo mostra1())
        printf("\nBaixa efetuada com sucesso!\n\n");
}}}

void menu(){
	int opcao;
	/*"struct patrimonio T[30]" <- não segue o template*/
	while(1){
        printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-");
		printf("\nBem vindo ao Sistema de controle do patrimonios dos equipamentos da UFU!\n");
        printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
		printf("\n1- Cadastrar Patrimonio");
		printf("\n2- Inventario de patrimonios");
		printf("\n3- Mostrar um Patrimonio detalhadamente");
        printf("\n4- Efetuar Baixa de um Patrimonio");
		printf("\n9- Sair ");
		printf("\n\nDigite opcao: ");
		scanf("%d", &opcao);
		if(opcao == 1) cadastrar();
		if(opcao == 2) inventario();
		if(opcao == 3) mostra1();
		if(opcao == 4) baixa();
		//if(opcao == 5) edicao();
		//if(opcao == 6) reg_movimentacao();
		//if(opcao == 7) manutencao();
		//if(opcao == 8) reg_recebimento();
		if(opcao == 9) return;}}

int main(){
	menu();
}
