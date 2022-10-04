#include <iostream>
using namespace std;

// definicao de tipo
struct NO
{
	int valor;
	NO *prox;
};

NO *inicio = NULL;
NO *fim = NULL;

// headers
void menu();
void inicializar();
void insere();
void remove();
//--------------------------

int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 4)
	{
		system("cls"); // somente no windows
		cout << "Menu Fila";
		cout << endl
			 << endl;
		cout << "1 - Inicializar Fila \n";
		cout << "2 - Inserir elemento \n";
		cout << "3 - Remover elemento  \n";
		cout << "4 - Sair \n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1:
			inicializar();
			break;
		case 2:
			insere();
			break;
		case 3:
			remove();
			break;
		case 4:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista j� possuir elementos
	// libera a memoria ocupada
	NO *aux = inicio;
	while (aux != NULL)
	{
		NO *paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	inicio = NULL;
	fim = NULL;
	cout << "Fila inicializada \n";
}

void insere()
{
	// aloca memoria dinamicamente para o novo elemento
	NO *novo = (NO *)malloc(sizeof(NO));

	cout << "Digite o elemento: \n";
	cin >> novo->valor;

	novo->prox = NULL;

	if (inicio == NULL)
	{
		inicio = novo;
		fim = novo;
	}
	else
	{
		cout << "Ultimo elemento: " << fim->valor << endl;
		fim->prox = novo;
		fim = novo;
	}

	cout << "Novo elemento: " << fim->valor << endl;
}

void remove()
{
	if (inicio != NULL)
	{
		cout << inicio->valor << " sera removido" << endl;

		NO *auxiliar = inicio->prox;
		free(inicio);
		inicio = auxiliar;
	}
	else
	{
		cout << "Fila vazia" << endl;
	}
}
