#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct N
{
	char c[1024];
}; 
typedef struct N str;
struct Node
{
	int num;
	struct Node *prox;
}; 
typedef struct Node node;

int erro = false;

void inicia(node *LISTA)
{
	LISTA->prox = NULL;
}

int vazia(node *LISTA)
{
	if(LISTA->prox == NULL)
		return 1;
	else
		return 0;
}

void insereFim(node *LISTA, int num)
{
	node *novo;
	novo = (node *) malloc(sizeof(node));
	if(!novo)
	{
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	novo->num = num;
	novo->prox = NULL;
	
	if(vazia(LISTA))
		LISTA->prox=novo;
	else
	{
		node *tmp = LISTA->prox;
		
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		
		tmp->prox = novo;
	}
}

void exibe(node *LISTA)
{
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}
	
	node *tmp;
	tmp = LISTA->prox;
	
	while( tmp != NULL)
	{
		printf("%d\n", tmp->num);
		tmp = tmp->prox;
	}
	printf("\n");
}

int tamanho(node *LISTA)
{
	int tamanho = 0;
	if(vazia(LISTA)){
		return tamanho;
	}
	node *tmp;
	tmp = LISTA->prox;
	
	while( tmp != NULL)
	{
		tamanho++;
		tmp = tmp->prox;
	}
	return tamanho;
}

int mapper(node *indice, node *tam)
{
	int endereco = 0;
	int mult;
	node *tmp_indice;
	tmp_indice = indice->prox;
	node *tmp_tamanho;
	tmp_tamanho = tam->prox;

	for (int i = 0; i < tamanho(tam); i++)
	{
		
		if ((tmp_indice->num >= tmp_tamanho->num) || 
		(tmp_indice->num*(-1) > tmp_tamanho->num) || 
		(tamanho(indice) != tamanho(tam)))
		{
			erro = true;
			printf("\nFalha de segmentação. Tá fodido pra achar o erro...\n");
			exit(1);
		}
		if(tmp_indice->num < 0)
		{
			tmp_indice->num = tmp_tamanho->num + tmp_indice->num;
		}
		tmp_indice = tmp_indice->prox;
		tmp_tamanho = tmp_tamanho->prox;
	}

	tmp_indice = indice->prox;
	tmp_tamanho = tam->prox;

	node *aux = tam->prox;

	for(int i = 0; i < tamanho(tam) - 1; i++)
	{
		mult = tmp_indice->num;
		for(int j = i; j < tamanho(tam) - 1; j++)
		{
			mult = mult*tmp_tamanho->num;
			tmp_tamanho = tmp_tamanho->prox;
		}
		tmp_tamanho = aux;
		endereco += mult;
		tmp_indice = tmp_indice->prox;
		aux = aux->prox;
	}

	int val;
	tmp_indice = indice->prox;
	for(int i = 0; i < tamanho(tam); i++)
	{
		val = tmp_indice->num;
		tmp_indice = tmp_indice->prox;
	}

	endereco += val;

	return endereco;
}
	char temp_string_EXP_35[6];
	char temp_string_EXP_40[6];
	char temp_string_EXP_65[37];
	char temp_string_EXP_66[2];
	char temp_string_EXP_67[2];
	char temp_string_EXP_76[11];
	char temp_string_EXP_78[6];
	int temp_boolean_EXP_18;
	int temp_boolean_EXP_24;
	int temp_boolean_EXP_30;
	int temp_boolean_EXP_46;
	int temp_boolean_EXP_52;
	int temp_boolean_EXP_58;
	int temp_boolean_EXP_62;
	int temp_boolean_x_77;
	int temp_int_EXP_10;
	int temp_int_EXP_11;
	int temp_int_EXP_12;
	int temp_int_EXP_15;
	int temp_int_EXP_17;
	int temp_int_EXP_1;
	int temp_int_EXP_21;
	int temp_int_EXP_23;
	int temp_int_EXP_27;
	int temp_int_EXP_29;
	int temp_int_EXP_2;
	int temp_int_EXP_33;
	int temp_int_EXP_34;
	int temp_int_EXP_36;
	int temp_int_EXP_38;
	int temp_int_EXP_39;
	int temp_int_EXP_3;
	int temp_int_EXP_41;
	int temp_int_EXP_43;
	int temp_int_EXP_45;
	int temp_int_EXP_49;
	int temp_int_EXP_4;
	int temp_int_EXP_51;
	int temp_int_EXP_55;
	int temp_int_EXP_57;
	int temp_int_EXP_5;
	int temp_int_EXP_61;
	int temp_int_EXP_68;
	int temp_int_EXP_69;
	int temp_int_EXP_70;
	int temp_int_EXP_72;
	int temp_int_EXP_73;
	int temp_int_EXP_74;
	int temp_int_EXP_79;
	int temp_int_EXP_8;
	int temp_int_EXP_9;
	int temp_int_i_16;
	int temp_int_i_44;
	int temp_int_j_22;
	int temp_int_j_50;
	int temp_int_k_28;
	int temp_int_k_56;

void temp_void_fun_0()
{
		temp_int_EXP_1 = 2;
	temp_int_EXP_2 = 2;
	temp_int_EXP_3 = temp_int_EXP_1 * temp_int_EXP_2;

	temp_int_EXP_4 = 2;
	temp_int_EXP_5 = temp_int_EXP_3 * temp_int_EXP_4;

	
	node *temp_Label_7;
	temp_Label_7 = (node *) malloc(sizeof(node));
	inicia(temp_Label_7);
	if(!temp_Label_7) cout << "Sem memoria disponivel!\n";
	insereFim(temp_Label_7, temp_int_EXP_1);
	insereFim(temp_Label_7, temp_int_EXP_2);
	insereFim(temp_Label_7, temp_int_EXP_4);

	str temp_string_vet_6[temp_int_EXP_5];


	temp_int_EXP_8 = 2;
	temp_int_EXP_9 = 2;
	temp_int_EXP_10 = temp_int_EXP_8 * temp_int_EXP_9;

	temp_int_EXP_11 = 2;
	temp_int_EXP_12 = temp_int_EXP_10 * temp_int_EXP_11;

	
	node *temp_Label_14;
	temp_Label_14 = (node *) malloc(sizeof(node));
	inicia(temp_Label_14);
	if(!temp_Label_14) cout << "Sem memoria disponivel!\n";
	insereFim(temp_Label_14, temp_int_EXP_8);
	insereFim(temp_Label_14, temp_int_EXP_9);
	insereFim(temp_Label_14, temp_int_EXP_11);

	str temp_string_vet2_13[temp_int_EXP_12];


	
	temp_int_EXP_15 = 0;
	temp_int_i_16 = temp_int_EXP_15;
temp_Label_20:
	
	temp_int_EXP_17 = 2;
	temp_boolean_EXP_18 = temp_int_i_16 < temp_int_EXP_17;
	temp_boolean_EXP_18 = !temp_boolean_EXP_18;
	if(temp_boolean_EXP_18) goto temp_Label_19;
	
	temp_int_EXP_21 = 0;
	temp_int_j_22 = temp_int_EXP_21;
temp_Label_26:
	
	temp_int_EXP_23 = 2;
	temp_boolean_EXP_24 = temp_int_j_22 < temp_int_EXP_23;
	temp_boolean_EXP_24 = !temp_boolean_EXP_24;
	if(temp_boolean_EXP_24) goto temp_Label_25;
	
	temp_int_EXP_27 = 0;
	temp_int_k_28 = temp_int_EXP_27;
temp_Label_32:
	
	temp_int_EXP_29 = 2;
	temp_boolean_EXP_30 = temp_int_k_28 < temp_int_EXP_29;
	temp_boolean_EXP_30 = !temp_boolean_EXP_30;
	if(temp_boolean_EXP_30) goto temp_Label_31;
	strcpy(temp_string_EXP_35, "Hello ");
	
	node *temp_Label_37;
	temp_Label_37 = (node *) malloc(sizeof(node));
	inicia(temp_Label_37);
	if(!temp_Label_37) cout << "Sem memoria disponivel!\n";
	insereFim(temp_Label_37, temp_int_i_16);
	insereFim(temp_Label_37, temp_int_j_22);
	insereFim(temp_Label_37, temp_int_k_28);
	temp_int_EXP_36 = mapper(temp_Label_37, temp_Label_7);
	strcpy(temp_string_vet_6[temp_int_EXP_36].c, temp_string_EXP_35);

	strcpy(temp_string_EXP_40, "world!");
	
	node *temp_Label_42;
	temp_Label_42 = (node *) malloc(sizeof(node));
	inicia(temp_Label_42);
	if(!temp_Label_42) cout << "Sem memoria disponivel!\n";
	insereFim(temp_Label_42, temp_int_i_16);
	insereFim(temp_Label_42, temp_int_j_22);
	insereFim(temp_Label_42, temp_int_k_28);
	temp_int_EXP_41 = mapper(temp_Label_42, temp_Label_14);
	strcpy(temp_string_vet2_13[temp_int_EXP_41].c, temp_string_EXP_40);

	temp_int_k_28 = temp_int_k_28 + 1;

	goto temp_Label_32;

temp_Label_31:

	temp_int_j_22 = temp_int_j_22 + 1;

	goto temp_Label_26;

temp_Label_25:

	temp_int_i_16 = temp_int_i_16 + 1;

	goto temp_Label_20;

temp_Label_19:


	
	temp_int_EXP_43 = 0;
	temp_int_i_44 = temp_int_EXP_43;
temp_Label_48:
	
	temp_int_EXP_45 = 2;
	temp_boolean_EXP_46 = temp_int_i_44 < temp_int_EXP_45;
	temp_boolean_EXP_46 = !temp_boolean_EXP_46;
	if(temp_boolean_EXP_46) goto temp_Label_47;
	
	temp_int_EXP_49 = 0;
	temp_int_j_50 = temp_int_EXP_49;
temp_Label_54:
	
	temp_int_EXP_51 = 2;
	temp_boolean_EXP_52 = temp_int_j_50 < temp_int_EXP_51;
	temp_boolean_EXP_52 = !temp_boolean_EXP_52;
	if(temp_boolean_EXP_52) goto temp_Label_53;
	
	temp_int_EXP_55 = 0;
	temp_int_k_56 = temp_int_EXP_55;
temp_Label_60:
	
	temp_int_EXP_57 = 2;
	temp_boolean_EXP_58 = temp_int_k_56 < temp_int_EXP_57;
	temp_boolean_EXP_58 = !temp_boolean_EXP_58;
	if(temp_boolean_EXP_58) goto temp_Label_59;
	temp_int_EXP_61 = 1;
	temp_boolean_EXP_62 = temp_int_i_44 == temp_int_EXP_61;
	temp_boolean_EXP_62 = !temp_boolean_EXP_62;
	if(temp_boolean_EXP_62) goto temp_Label_64;
	strcpy(temp_string_EXP_65, "Saindo pelo superBreak com o indice: ");
	cout << temp_string_EXP_65;

	cout << temp_int_i_44;

	strcpy(temp_string_EXP_66, ", ");
	cout << temp_string_EXP_66;

	cout << temp_int_j_50;

	strcpy(temp_string_EXP_67, ", ");
	cout << temp_string_EXP_67;

	cout << temp_int_k_56;

	cout << endl;

	goto temp_Label_47;

goto temp_Label_63;
temp_Label_64:
temp_Label_63:

	
	node *temp_Label_71;
	temp_Label_71 = (node *) malloc(sizeof(node));
	inicia(temp_Label_71);
	if(!temp_Label_71) cout << "Sem memoria disponivel!\n";
	insereFim(temp_Label_71, temp_int_i_44);
	insereFim(temp_Label_71, temp_int_j_50);
	insereFim(temp_Label_71, temp_int_k_56);
	temp_int_EXP_70 = mapper(temp_Label_71, temp_Label_7);
	
	cout << temp_string_vet_6[temp_int_EXP_70].c;

	
	node *temp_Label_75;
	temp_Label_75 = (node *) malloc(sizeof(node));
	inicia(temp_Label_75);
	if(!temp_Label_75) cout << "Sem memoria disponivel!\n";
	insereFim(temp_Label_75, temp_int_i_44);
	insereFim(temp_Label_75, temp_int_j_50);
	insereFim(temp_Label_75, temp_int_k_56);
	temp_int_EXP_74 = mapper(temp_Label_75, temp_Label_14);
	
	cout << temp_string_vet2_13[temp_int_EXP_74].c;

	cout << endl;

	strcpy(temp_string_EXP_76, "-----------");
	cout << temp_string_EXP_76;

	cout << endl;

	temp_int_k_56 = temp_int_k_56 + 1;

	goto temp_Label_60;

temp_Label_59:

	temp_int_j_50 = temp_int_j_50 + 1;

	goto temp_Label_54;

temp_Label_53:

	temp_int_i_44 = temp_int_i_44 + 1;

	goto temp_Label_48;

temp_Label_47:

	return;
}


int main(void)
{
	temp_boolean_x_77 = 1;
	cin >> temp_string_EXP_78;
	temp_int_EXP_79 = strcmp(temp_string_EXP_78, "true" );
	if(!temp_int_EXP_79 == 0) goto temp_Label_80;
	temp_boolean_x_77 = 1;
	goto temp_Label_82;
temp_Label_80:
	temp_int_EXP_79 = strcmp(temp_string_EXP_78, "false" );
	if(!temp_int_EXP_79 == 0) goto temp_Label_81;
	temp_boolean_x_77 = 0;
	goto temp_Label_82;
temp_Label_81:
	cout << "Valor: " << temp_string_EXP_78 << " inválido!\n";
	exit(1);
temp_Label_82:
	
	if(temp_boolean_x_77) cout << "true";
	if(!temp_boolean_x_77) cout << "false";

	cout << endl;

	return 0;
}

