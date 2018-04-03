#include <iostream>
#include <ctime>
#include <cstdlib>
#include "jogadores_implementacao.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
	int i, jogadores,n,maior,menor,ultimo, vencedor;
	
	/** LEITURA DE JOGADORES E O NUMERO LIMITE */

	cout << "Número de jogadores no game: ";
	cin >> jogadores;
	cout << "\nNúmero a ser estabelecido: ";
	cin >> n;

	/** VARIAVEIS CRIADAS DEPOIS DEVIDO A ATRIBUIÇAO POSTERIOR DOS VALORES */

	int sn[jogadores] ;
	int pontos[jogadores];
	int contador_de_zero = jogadores;
	int contador_desclassificacao = jogadores;

	menor = n;
	maior = 1;

	/** TEMPO DA MAQUINA PARA AUXILIAR NA CRIAÇAO DO NUMERO ALEATORIO*/

	srand(time(0));

	/** ZERANDO TODO OS PONTOS */

	for(i=1;i<=jogadores;i++){
		pontos[i] = 0;
	}

	
	/** LOOPING PARA IR PARA A PROXIMA RODADA */
	n_rodada:

	/** REATRIBUIÇAO DE VALORES */

	contador_de_zero = jogadores;
	contador_desclassificacao = jogadores;

	/** CRIAÇAO DO FOR PARA CALCULAR OS PONTOS DE CADA JOGADOR NA RODADA */

	for(i=1; i<=jogadores;i++){
		
		if(pontos[i] < n && pontos[i] >= 0){
		cout << "\nJogador " << i << ", jogar os dois dados? [1/0]";
		cin >> sn[i];
		/** CRIAÇAO DO NUMERO ALEATORIO (OS 2 DADOS SOMADOS) */
		/** UTILIZAÇAO DO 1 E 0 PARA O JOGADOR INFORMAR SE DESEJA JOGAR OS DADOS OU NAO */
		if(sn[i] == 1){
			pontos[i] += 2+(rand()%11); 
			
		}
		else{
			contador_de_zero--;
		}
		cout << "\n" << pontos[i] << endl;
		
	}
		/** VERIFICANDO QUAL A MAIOR PONTUAÇAO */
		if(pontos[i] < n && pontos[i] > maior){
		
			maior = pontos[i];
			vencedor = i;
		}

		/** VERIFICANDO QUAL A MENOR PONTUAÇAO */

		if(pontos[i] < n && pontos[i] < menor){
		
			menor = pontos[i];
			ultimo = i;
		}

		/** DESCLASSIFICAÇAO DO JOGADOR CASO A SOMA DOS DADOS JOGADOS ULTRAPASSE O VALOR LIMITE ESTABELECIDO */

		if(pontos[i] > n || pontos[i] < 0){
			cout << "\nO jogador " << i << " foi desclassificado\n" << endl;
			
			contador_desclassificacao -= 1;
			contador_de_zero -= 1;
		}

		/** CASO A SOMA DOS DADOS ATINJA O VALOR LIMITE ESTABELECIDO, O JOGADOR GANHA! */
		
		if(pontos[i] == n){
			cout << "\nO jogador " << i << " venceu o jogo!\n" << endl;
			exit(0);

		}

		/** SE TODOS COLOCAREM ZERO NA RODADA, O VENCEDOR SERÁ O DE MAIOR SOMA DOS DADOS */

		if(contador_de_zero == 0){
			cout << "\nO jogador " << vencedor << " ganhou o jogo!" << endl;
			exit(0);
		}

		
		/** CASO O CONTADOR DE DESCLASSIFICAÇAO DIMINUA ATÉ CHEGAR A 1 (SIGNIFICA Q 3 JOGADORES FORAM DESCLASSIFICADOS) O Q RESTA GANHA O JOGO */

		if(contador_desclassificacao == 1 ){
			cout << "\nO jogador " << ultimo << " ganhou o jogo!" << endl;
			exit(0);
		}

		if(contador_desclassificacao == 0){
			cout << "\nTodos os jogadores foram desclassificados, nao houve vencedores!\n" << endl;
			exit(0);
		}

	}

	

	/** IMPRESSAO DO VENCEDOR DA RODADA E FIM DA RODADA */
	
	if(pontos[vencedor] < n){
	cout << "\nO vencedor da rodada foi o jogador " << vencedor << endl;
	cout << "\n-------------------------FIM DA RODADA-------------------------\n" << endl;
	}
	goto n_rodada;

	return 0;
}









