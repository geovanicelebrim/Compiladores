#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

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
			printf("Falha de segmentação.\n");
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
	char temp_string_EXP_66[37];
	char temp_string_EXP_67[2];
	char temp_string_EXP_68[2];
	char temp_string_EXP_77[11];
	float temp_float_EXP_35;
	int temp_boolean_EXP_18;
	int temp_boolean_EXP_24;
	int temp_boolean_EXP_30;
	int temp_boolean_EXP_47;
	int temp_boolean_EXP_53;
	int temp_boolean_EXP_59;
	int temp_boolean_EXP_63;
	int temp_int_EXP_0;
	int temp_int_EXP_10;
	int temp_int_EXP_11;
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
	int temp_int_EXP_40;
	int temp_int_EXP_41;
	int temp_int_EXP_42;
	int temp_int_EXP_44;
	int temp_int_EXP_46;
	int temp_int_EXP_4;
	int temp_int_EXP_50;
	int temp_int_EXP_52;
	int temp_int_EXP_56;
	int temp_int_EXP_58;
	int temp_int_EXP_62;
	int temp_int_EXP_69;
	int temp_int_EXP_70;
	int temp_int_EXP_71;
	int temp_int_EXP_73;
	int temp_int_EXP_74;
	int temp_int_EXP_75;
	int temp_int_EXP_7;
	int temp_int_EXP_8;
	int temp_int_EXP_9;
	int temp_int_cont_14;
	int temp_int_i_16;
	int temp_int_i_45;
	int temp_int_j_22;
	int temp_int_j_51;
	int temp_int_k_28;
	int temp_int_k_57;


int main(void)
{
	temp_int_EXP_0 = 2;
	temp_int_EXP_1 = 2;
	temp_int_EXP_2 = temp_int_EXP_0 * temp_int_EXP_1;

	temp_int_EXP_3 = 2;
	temp_int_EXP_4 = temp_int_EXP_2 * temp_int_EXP_3;

	
	node *temp_Label_6;
	temp_Label_6 = (node *) malloc(sizeof(node));
	inicia(temp_Label_6);
	if(!temp_Label_6) cout << "Sem memoria disponivel!\n";
	insereFim(temp_Label_6, temp_int_EXP_0);
	insereFim(temp_Label_6, temp_int_EXP_1);
	insereFim(temp_Label_6, temp_int_EXP_3);

	int temp_int_vet_5[temp_int_EXP_4];


	temp_int_EXP_7 = 2;
	temp_int_EXP_8 = 2;
	temp_int_EXP_9 = temp_int_EXP_7 * temp_int_EXP_8;

	temp_int_EXP_10 = 2;
	temp_int_EXP_11 = temp_int_EXP_9 * temp_int_EXP_10;

	
	node *temp_Label_13;
	temp_Label_13 = (node *) malloc(sizeof(node));
	inicia(temp_Label_13);
	if(!temp_Label_13) cout << "Sem memoria disponivel!\n";
	insereFim(temp_Label_13, temp_int_EXP_7);
	insereFim(temp_Label_13, temp_int_EXP_8);
	insereFim(temp_Label_13, temp_int_EXP_10);

	int temp_int_vet2_12[temp_int_EXP_11];

	temp_int_cont_14 = 0;

	
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
	temp_float_EXP_35 = (float)temp_int_cont_14;
	
	node *temp_Label_37;
	temp_Label_37 = (node *) malloc(sizeof(node));
	inicia(temp_Label_37);
	if(!temp_Label_37) cout << "Sem memoria disponivel!\n";
	insereFim(temp_Label_37, temp_int_i_16);
	insereFim(temp_Label_37, temp_int_j_22);
	insereFim(temp_Label_37, temp_int_k_28);
	temp_int_EXP_36 = mapper(temp_Label_37, temp_Label_6);
	temp_int_vet_5[temp_int_EXP_36] = (int)temp_float_EXP_35;;

	temp_int_EXP_40 = 2;
	temp_int_EXP_41 = temp_int_EXP_40 * temp_int_cont_14;
	
	node *temp_Label_43;
	temp_Label_43 = (node *) malloc(sizeof(node));
	inicia(temp_Label_43);
	if(!temp_Label_43) cout << "Sem memoria disponivel!\n";
	insereFim(temp_Label_43, temp_int_i_16);
	insereFim(temp_Label_43, temp_int_j_22);
	insereFim(temp_Label_43, temp_int_k_28);
	temp_int_EXP_42 = mapper(temp_Label_43, temp_Label_13);
	temp_int_vet2_12[temp_int_EXP_42] = temp_int_EXP_41;

	temp_int_cont_14 = temp_int_cont_14 + 1;

	temp_int_k_28 = temp_int_k_28 + 1;

	goto temp_Label_32;

temp_Label_31:

	temp_int_j_22 = temp_int_j_22 + 1;

	goto temp_Label_26;

temp_Label_25:

	temp_int_i_16 = temp_int_i_16 + 1;

	goto temp_Label_20;

temp_Label_19:


	
	temp_int_EXP_44 = 0;
	temp_int_i_45 = temp_int_EXP_44;
temp_Label_49:
	
	temp_int_EXP_46 = 2;
	temp_boolean_EXP_47 = temp_int_i_45 < temp_int_EXP_46;
	temp_boolean_EXP_47 = !temp_boolean_EXP_47;
	if(temp_boolean_EXP_47) goto temp_Label_48;
	
	temp_int_EXP_50 = 0;
	temp_int_j_51 = temp_int_EXP_50;
temp_Label_55:
	
	temp_int_EXP_52 = 2;
	temp_boolean_EXP_53 = temp_int_j_51 < temp_int_EXP_52;
	temp_boolean_EXP_53 = !temp_boolean_EXP_53;
	if(temp_boolean_EXP_53) goto temp_Label_54;
	
	temp_int_EXP_56 = 0;
	temp_int_k_57 = temp_int_EXP_56;
temp_Label_61:
	
	temp_int_EXP_58 = 2;
	temp_boolean_EXP_59 = temp_int_k_57 < temp_int_EXP_58;
	temp_boolean_EXP_59 = !temp_boolean_EXP_59;
	if(temp_boolean_EXP_59) goto temp_Label_60;
	temp_int_EXP_62 = 1;
	temp_boolean_EXP_63 = temp_int_j_51 == temp_int_EXP_62;
	temp_boolean_EXP_63 = !temp_boolean_EXP_63;
	if(temp_boolean_EXP_63) goto temp_Label_65;
	strcpy(temp_string_EXP_66, "Saindo pelo superBreak com o indice: ");
	cout << temp_string_EXP_66;

	cout << temp_int_i_45;

	strcpy(temp_string_EXP_67, ", ");
	cout << temp_string_EXP_67;

	cout << temp_int_j_51;

	strcpy(temp_string_EXP_68, ", ");
	cout << temp_string_EXP_68;

	cout << temp_int_k_57;

	cout << endl;

	goto temp_Label_48;

goto temp_Label_64;
temp_Label_65:
temp_Label_64:;

	
	node *temp_Label_72;
	temp_Label_72 = (node *) malloc(sizeof(node));
	inicia(temp_Label_72);
	if(!temp_Label_72) cout << "Sem memoria disponivel!\n";
	insereFim(temp_Label_72, temp_int_i_45);
	insereFim(temp_Label_72, temp_int_j_51);
	insereFim(temp_Label_72, temp_int_k_57);
	temp_int_EXP_71 = mapper(temp_Label_72, temp_Label_6);
	
	cout << temp_int_vet_5[temp_int_EXP_71];

	cout << endl;;

	
	node *temp_Label_76;
	temp_Label_76 = (node *) malloc(sizeof(node));
	inicia(temp_Label_76);
	if(!temp_Label_76) cout << "Sem memoria disponivel!\n";
	insereFim(temp_Label_76, temp_int_i_45);
	insereFim(temp_Label_76, temp_int_j_51);
	insereFim(temp_Label_76, temp_int_k_57);
	temp_int_EXP_75 = mapper(temp_Label_76, temp_Label_13);
	
	cout << temp_int_vet2_12[temp_int_EXP_75];

	cout << endl;

	strcpy(temp_string_EXP_77, "-----------");
	cout << temp_string_EXP_77;

	cout << endl;

	temp_int_k_57 = temp_int_k_57 + 1;

	goto temp_Label_61;

temp_Label_60:

	temp_int_j_51 = temp_int_j_51 + 1;

	goto temp_Label_55;

temp_Label_54:

	temp_int_i_45 = temp_int_i_45 + 1;

	goto temp_Label_49;

temp_Label_48:

	return 0;
}

