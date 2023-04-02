//Criando as structs
struct Quantidades{
  int8_t quant1;
  int8_t quant2;
  int8_t quant3;
  int8_t valorSub[3];
};

struct Valor{
  int8_t valor;
};

//Criando e adiconando valores a estruturas dos tipos criandos anteriormente
Quantidades frutas = {10, 8, 6, {2, 4, 8}};
Valor fome = {100};

void setup() {
  //Inicializando o monitor serial
  Serial.begin(9600);
}

void loop() {
  //Chamando a função printStruct e passando como parâmentros as estrutras frutas e fome
  printStruct(frutas, fome);
}

//Esta função pega as estrutras passadas como referência, desta forma é possível alterar os
//dados da estrutura pura criada anteriormente e não de uma cópia criada no momento
//Desta forma esta função apresenta os dados da estrutura, e chama a função reduzir para que as
//alterações sejam feitas
void printStruct(Quantidades& q, Valor& v){
  for(int i = 0; i < 3; i++){
    Serial.print("quant1 = ");
    Serial.println(q.quant1);

    Serial.print("qunat2 = ");
    Serial.println(q.quant2);

    Serial.print("quant3 = ");
    Serial.println(q.quant3);

    Serial.print("Valor =");
    Serial.println(v.valor);

    Serial.print("index = ");
    Serial.println(i);

    reduzir(q, v, i);
    delay(2000);
  }
}

//Esta função diminui o valor de v.valor de acordo com o indice do array q.valorSub[i]
//Após esta redução, é diminuida a quantidade de cada q.quant seguindo como lódigca o indice
//para decidir qual quant terá seu valor reduzido
void reduzir(Quantidades& q, Valor& v, int8_t index){
  v.valor = v.valor - q.valorSub[index];
  switch(index){
    case 0:
      q.quant1 = q.quant1 - 1;
    break;

    case 1:
      q.quant2 = q.quant2 - 1;
    break;

    case 2:
      q.quant3 = q.quant3 - 1;
    break;

    default:
      Serial.println("Valor inserido não existe");
    break;
  }
}