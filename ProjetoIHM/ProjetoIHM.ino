/*
 * Projeto IHM com teclado matricial e display de 7 segmentos
 * Foi utilizado uma ESP32 de 38 pinos para o desenvolvimento do projeto
 * Projeto desenvolvido por discentes de Sistemas Microprocessados do Curso de Engenharia de controle e automação (IFG - Goiânia)
 */


/*  Pinos de cada segmento A  B  C  D  E  F  G  dp */
const int segmentos[8] = {22,23,25,33,32,19,21,26};

/* Matriz de desenho dos digitos e caracteres no display */
const int digitos[5][4][8] = 
/*            Coluna1                 Coluna2                    Coluna3                 Coluna4          */
{ { {1, 0, 0, 1, 1, 1, 1, 1}, {0, 0, 1, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 1, 1, 0, 1},{0, 0, 0, 1, 0, 0, 0, 0} },/*LinhaA*/
  { {1, 0, 0, 1, 1, 0, 0, 1}, {0, 1, 0, 0, 1, 0, 0, 1}, {0, 1, 0, 0, 0, 0, 0, 1},{1, 1, 0, 0, 0, 0, 0, 0} },/*LinhaB*/
  { {0, 0, 0, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 1, 1, 0, 0, 1},{0, 1, 1, 0, 0, 0, 1, 0} },/*LinhaC*/
  { {1, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 1}, {1, 0, 0, 1, 0, 0, 0, 0},{1, 0, 0, 0, 0, 1, 0, 0} },/*LinhaD*/
  {{1, 1, 1, 1, 1, 1, 1, 1}}/*Display limpo*/ };

 /* Representação visual da matriz de desenho dos digitos e caracteres no display       
          coluna1      coluna2      coluna3      coluna4  
linhaA |     1     |      2     |      3     |      A      |
linhaB |     4     |      5     |      6     |      B      |
linhaC |     7     |      8     |      9     |      C      |
linhaD |     *     |      2     |      #     |      D      |*/


/*Pinos das linhas e colunas do teclado matricial*/
const int colunas[4]={5, 4, 2, 15};
const int linhas[4]= {27,14,12,13};

/*Mostra no display o caractere de acordo com a linha e coluna
 Ex: linha = 1 e coluna = 0 é o numero 4 (lembre-se que a contagem inicia em 0)*/
void showDisplay(int linha = 4, int coluna=0) { 
   for(int i=0;i<=7;i++){
      digitalWrite(segmentos[i], digitos[linha][coluna][i]);
   }
}

void setup() {
  
  /*Este ciclo for intera todos pinos do display e os coloca como saida (output)
    E logo apos setar como saida, desliga o led, para que o display inicie desligado*/
  for(int i=0;i<=7;i++){
      pinMode(segmentos[i] , OUTPUT); /* seta todos as portas que estão os leds do display como saída */
      digitalWrite(segmentos[i], 1);
   }

  /*Este ciclo for intera todos pinos do teclado 
   Colocando todos os pinos das linhas como saida (output) e os pinos das colunas como entrada (input)
   E logo apos setar como saida as linhas, seta nivel logico baixo nas linhas*/
  for(int i=0;i<=3;i++){
   pinMode(linhas[i], OUTPUT); // seta todos as linhas do teclado como saída 
   pinMode(colunas[i], INPUT); // seta todos as colunas do teclado como entrada
   digitalWrite(linhas[i], LOW);
  }
}

void loop() {
  /*Aqui temos dois ciclos for aninhados, o ciclo externo intera todas as linhas do teclado
    E o cliclo interno intera todas as colunas do teclado*/
  for (int linha = 0; linha <= 3; linha++) {
    
    /*A cada vez que o ciclo externo passa por uma linha ele a coloca em nivel logico alto
     para que se caso uma tecla nessa linha seja precionada, o pino da coluna corresponte a tecla
     feche contato e conduza nivel logico alto*/
    digitalWrite(linhas[linha], HIGH);

    /*cliclo interno intera todas as colunas do teclado*/
    for (int coluna = 0; coluna <= 3; coluna++) {

      /*Se como supracitado uma tecla dessa coluna for pressionada, o pino corresponte a tecla
       fecha contato e conduz nivel logico alto, sendo assim enviamos a linha e a coluna pressionada
       Para a funçao que imprime os caracteres no display*/
      if(digitalRead(colunas[coluna])){
        showDisplay(linha,coluna);

        /*Este delay de meio segundo evita o efeito bounce, onde o microcontrolador pode reconhecer
         que a mesma tecla está sendo pressionada mais de uma vez*/
        delay(500);
       }
      }

    /*colocamos a linha em que o ciclo for está interando em nivel logico baixo, para que seja realizada
      a varredura na proxima linha*/
    digitalWrite(linhas[linha], LOW);

    /*Se a linha que o ciclo for acabou de interar é a ultima linha do teclado, retornamos para a primeira linha*/
    if (linha == 3) {
      linha = -1;
    }
  }
}
