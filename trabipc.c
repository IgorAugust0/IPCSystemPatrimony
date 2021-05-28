#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> //Para a função getch();
#define MAX_PATRIMONIOS 50
typedef struct{
    char nome[50];
    char data[12];
    int ativo; //0->inativo...1->ativo;
    int id;
    char marca[50];
    char setor[50];
    char status[50];
    //manutencao
    char tecnico[50];
    char datamanutencao[12];
    char descricao_status[100];
    //movimentacao
    char data_transferencia[12];
    char data_retorno[12];
    char setor_origem [50];
    char setor_destino [50];
    int status_transferencia;               //Se for igual a 1 o patrimonio deve ser mostrado, se for 0 não
} patrimonio;

patrimonio patrimonios[MAX_PATRIMONIOS];    //Vetor de patrimonios usando a struct patrimonio
                                            //MAX_PATRIMONIOS define o limite da quantidade de patrimonios

void cadastrar(){
	char nome[50];
    char data[12];
    int id;
    char marca[50];
    char setor[50];
    char tecnico[50];
    char datamanutencao[12];
    char status[50];
    int ativo;
    int op=1;
    system("cls"); //Limpa o terminal


    while(op!=0){

        FILE *pat_arq; //Cria o ponteiro para o arquivo

        pat_arq = fopen("arquivo_patrimonios.txt","a"); //Abre o arquivo no modo de adição de dados "a"
        //Caso o arquivo não exista, criará um novo

        printf("*-------------------------*\n");
        printf("| Cadastrar um Patrimonio |\n");
        printf("*-------------------------*\n");
        printf("ID: ");
        scanf("%d",&id);
        printf("\nNome: ");
        scanf("%s",&nome);
        printf("\nSetor: ");
        scanf("%s",&setor);
        printf("\nData de aquisicao: ");
        scanf("%s",&data);
        printf("\nMarca: ");
        scanf("%s",&marca);
        for (int i = 0;i< MAX_PATRIMONIOS;i++){
            if (patrimonios[i].ativo==0){                   //0->inativo...1->ativo - usar na baixa de patrimonios
                patrimonios[i].id = id;
                strcpy(patrimonios[i].data, data);
                strcpy(patrimonios[i].nome, nome);
                strcpy(patrimonios[i].marca, marca);
                strcpy(patrimonios[i].status, "OK!");
                strcpy(patrimonios[i].setor, setor);
                patrimonios[i].ativo=1;

                //Registra os dados no arquivo
                fprintf(pat_arq, "\nId:        #%d\n", id);
                fprintf(pat_arq, "Nome:      %s\n", nome);
                fprintf(pat_arq, "Setor:     %s\n", setor);
                fprintf(pat_arq, "Aquisição: %s\n", data);
                fprintf(pat_arq, "Marca:     %s\n\n", marca);
                fprintf(pat_arq,"--------------------------\n");

                fclose(pat_arq);      //Fecha o arquivo

                printf("\nCadastro realizado com sucesso!\n");
                break;}}
        printf("\n1 - Continuar\n0 - Sair\n");
        scanf("%d",&op);}}

void inventario(){
    int id,d;
    system("cls");
    printf("*----------------------------*\n");
    printf("| Inventario de Patrimonios  |\n");
    printf("*----------------------------*\n");
    for (int i = 0; i < MAX_PATRIMONIOS; i++){
        if (patrimonios[i].ativo==1){
        printf("\n---------------");
        printf("\nID:   #%d",patrimonios[i].id);
        printf("\nNome: %s\n\n",patrimonios[i].nome);
        }}
        printf("Digite qualquer tecla para continuar\n\n");
        getch();} //pausa na tela até uma tecla ser digitada

void mostra1(){
    int id;
    int op = 1;
    system("cls");
    while(op!=0){
        printf("*-------------------------------------*\n");
        printf("| Exibir um Patrimonio detalhadamente |\n");
        printf("*-------------------------------------*\n");
        printf("\nDigite o id do patrimonio: #\n");
        scanf("%d",&id);
        for(int i = 0 ; i < MAX_PATRIMONIOS; i++){
        if (patrimonios[i].id == id){
            printf("\n---------------");
            printf("\nID:     #%d",patrimonios[i].id);
            printf("\nNome:   %s",patrimonios[i].nome);
            printf("\nData:   %s",patrimonios[i].data);
            printf("\nSetor:  %s",patrimonios[i].setor);
            printf("\nMarca:  %s",patrimonios[i].marca);
            printf("\nStatus: %s\n",patrimonios[i].status);
        }
        }printf("\n\nDeseja pesquisar outro Patrimonio?\n0 - Nao\n1 - Sim\n");
    scanf("%d",&op);
    }}

void baixa(){
    system("cls");
    printf("*--------------------------------*\n");
    printf("| Efetuar Baixa de um Patrimonio | \n");
    printf("*--------------------------------*\n");
    int id;
    inventario();
    printf("Digite o ID do patrimonio a ser removido: #");
    scanf("%d",&id);
    for(int i = 0 ; i < MAX_PATRIMONIOS; i++){
        if(patrimonios[i].id==id){
        strcpy(patrimonios[i].status,"Indisponivel");            //torna o status patrimonio como inativo
        patrimonios[i].ativo=0;                             //tira o patrimonio do inventario (ainda ? possivel acessar pelo mostra1())
        printf("\nBaixa efetuada com sucesso!\n\n");
}}}

void movimentacao(){
    system("cls");
    printf("*-----------------------*\n");
    printf("| Transferir Patrimonio |\n");
    printf("*-----------------------*\n");
    int id,op=1;
    char setor_destino[50];
    char data_transferencia[12];
    char data_retorno[12];
    while(op==1){
    printf("Digite o ID do patrimonio que foi movido: #");
    scanf("%d",&id);
    for(int i = 0 ; i < MAX_PATRIMONIOS; i++){
        if(patrimonios[i].id==id && strcmp(patrimonios[i].status,"Indisponivel")==0){
            printf("[ERRO] Nao foi possivel encontrar este patrimonio. Verique o inventario.");
           }
        else if(patrimonios[i].id==id){
        printf("\nEscolha uma opcao:\n");
        printf("1-Transferencia Definitiva:\n");
        printf("2-Transferencia provisoria:\n");
        printf("3-Declarar retorno:\n");
        int opc;
        scanf("%d", &opc);
        if (opc == 1){
            printf("\nData de Transferencia: ");
            scanf("%s",&data_transferencia);
            printf("\nSetor de destino: ");
            scanf("%s",&setor_destino);
            for(int i = 0 ; i < MAX_PATRIMONIOS; i++){
                if(patrimonios[i].id==id){
                strcpy(patrimonios[i].data_transferencia,data_transferencia);
                strcpy(patrimonios[i].setor,setor_destino);
                patrimonios[i].status_transferencia = 1;                   //mostra que ja foi transferido
                strcpy(patrimonios[i].setor_origem,patrimonios[i].setor_origem);
                printf("\nTransferencia efetuada com sucesso!\n\n");}
        }}
        if (opc == 2){
            printf("\nData de Transferencia: ");
            scanf("%s",&data_transferencia);
            printf("\nData de retorno: ");
            scanf("%s",&data_retorno);
            printf("\nSetor de destino: ");
            scanf("%s",&setor_destino);

            for(int i = 0 ; i < MAX_PATRIMONIOS; i++){
                if(patrimonios[i].id==id){
                strcpy(patrimonios[i].data_transferencia,data_transferencia);
                strcpy(patrimonios[i].setor_destino,setor_destino);
                strcpy(patrimonios[i].setor_origem,patrimonios[i].setor);
                strcpy(patrimonios[i].data_retorno,data_retorno);
                patrimonios[i].status_transferencia = 1;
                strcpy(patrimonios[i].status,"Transferido Provisoriamente");
                printf("\nTransferencia efetuada com sucesso!\n\n");}
        }}
               if (opc ==3){
                for(int i = 0 ; i < MAX_PATRIMONIOS; i++){
                if(patrimonios[i].id==id){
                strcpy(patrimonios[i].status,"OK!");
                patrimonios[i].status_transferencia = 0;}}
                printf("\nRetorno efetuado com sucesso!\n\n");}
}}      printf("\n1 - Continuar\n0 - Sair\n");
        scanf("%d",&op);}}


void menu(){
	int opcao;
	while(1){
        system("cls");
        printf("\n*---------------------------------------------------------------------------*");
		printf("\n| Bem vindo ao Sistema de controle do patrimonios dos equipamentos da UFU! |");
        printf("\n*---------------------------------------------------------------------------*");
		printf("\n1- Cadastrar Patrimonio");
		printf("\n2- Inventario de patrimonios");
		printf("\n3- Mostrar um Patrimonio detalhadamente");
        printf("\n4- Efetuar Baixa de um Patrimonio");
        printf("\n6- Efetuar Transferencia");
		printf("\n0- Sair ");
		printf("\n\nDigite uma  opcao: ");
		scanf("%d", &opcao);
		if(opcao == 1) cadastrar();
		if(opcao == 2) inventario();
		if(opcao == 3) mostra1();
		if(opcao == 4) baixa();
		//if(opcao == 5) edicao();
        if(opcao == 6) movimentacao();
	   	//if(opcao == 7) reg_movimentacao();
		//if(opcao == 8) manutencao();
		//if(opcao == 9) reg_recebimento();
		if(opcao == 0) return;}}

int main(){
	menu();
}
