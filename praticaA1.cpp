#include <iostream>
#include <string> -- ler sem inline
using namespace std;
struct mercadoria
{
	int codigo;
	char nome[50];
	float preco;
	int quantidade;
};
int total;
struct mercadoria tab[20];

void cadastro();
void listar();
void reajuste();
void vendas();
void compras();
int pesquisa(int);

int main()
{
	int opcao;
	do
	{
		cout << " *** Menu de opcoes" << endl;
		cout << "1) Cadastro" <<endl;
		cout << "2) Lista" << endl;
		cout << "3) Reajuste" << endl;
		cout << "4) Vendas" << endl;
		cout << "5) Compras" << endl;
		cout << " FIM! Isso é tudo pessoal" << endl;
		cout << " Qual é sua opcao?" << endl;
		cin >> opcao;
		switch(opcao);
		{
			case 1: cadastro();
			break;
			case 2: listar();
			break;
			case 3: reajuste();
			break;
			case 4: vendas();
			break;
			case 5: compras();
			break;
		};
	} while(opcao =! 6);
}
void cadastro(){
	cout << " *** Cadastro ***" << endl;
	cout << " Informe o codigo" << endl;
	cin >> tab[total].codigo;
	cout << " Informe o nome" << endl;
	cin.getline(tab[total].nome,50);
	cout << " Informe o preco" << endl;
	cin.getline(tab[total].preco, 50);
	cout << "Informe a Quantidade" << endl;
	cin.getline(tab[total].quantidade,50);
	total++;
}
void listar(){
	int i=0;
	cout << " *** Listagem ***" << endl;
	while (i <total)
	{
		cout << tab[i].codigo << " - " << tab[i].nome << " - " << tab[i].preco << " - " << tab[i].quantidade << endl;
		i++
	}
}
int pesquisa(int cod){
	int i=0;
	while ((i<total) && (tab[i].codigo != cod))
	{
		i++;
	}
	if (i <total)
	{
		return i;
	}
	else
	{
		return -1;
	}
}
void reajuste()
{
	int i, cod;
	float percentual;
	cout << " *** Reajuste do preco ***" << endl;
	cout << " informe o codigo: " << endl;
	cin >> cod;
	cout << " Informe o percentual de aumento: " << endl;
	cin >> percentual;
	i = pesquisa(cod);
	if (i != -1)
	{
		tab[i].preco = tab[i].preco + ((tab[i].preco * percentual / 100));
	}
	else
	{
		cout << " Codigo nao encontrado" << endl;
	}
}
void compras()
{
	int i, cod, qtd;
	cout << " *** Compra ***" << endl;
	cout << " ** Informe o codigo ***" << endl;
	cin >> qtd;
	i = pesquisa(cod);
	if ( i != -1)
	{
		cout << " Informe a quantidade comprada: ";
		cin >> qtd;
		tab[i].quantidade = tab[i].quantidade + qtd;
	}
	else
	{
		cout << " Codigo nao encontrado" << endl;
	}
}
void vendas()
{
	int i, cod, qtd;
	float valor;
	cout << " *** Vendas ***" << endl;
	cout << " Informe o codigo: ";
	cin >> cod;
	i = pesquisa(cod);
	if (i != -1)
	{
		cout << " Informe a quantidade vendida" << endl;
		cin >> qtd;
		if (tab[i].quantidade >= qtd)
		{
			tab[i].quantidade = tab[i].quantidade - qtd;
			valor = qtd * tab[i].preco;
			cout << " Valor a receber: " << valor << endl;
		}
		else
		{
			cout << " Nao tem a quantidade disponivel" << endl;
		}
	}
	else
	{
		cout << " Codigo nao encontrado" << endl;
	}
}
