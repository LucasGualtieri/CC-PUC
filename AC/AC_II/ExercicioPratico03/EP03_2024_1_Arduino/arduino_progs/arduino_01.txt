/*
  Programa 01
  Liga todos os Leds
 */

// Definiçao de valores para variáveis  
int led10 = 10;
int led11 = 11;
int led12 = 12;
int led13 = 13;


// Rotina executada 1 vez e que em geral configura entradas e saídas 
void setup() {                
  // configura os pinos como saídas DIGITAIS.
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);
  pinMode(led13, OUTPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led10, HIGH);   // Faz a saída do respectivo Led ser alta ou High)
  delay(100);               // espera por 100 ms
  digitalWrite(led11, HIGH);   // Faz a saída do respectivo Led ser alta ou High)
  delay(100);               // espera por 100 ms
  digitalWrite(led12, HIGH);   // Faz a saída do respectivo Led ser alta ou High)
  delay(100);               // espera por 100 ms
  digitalWrite(led13, HIGH);   // Faz a saída do respectivo Led ser alta ou High)
  delay(100);               // espera por 100 ms

  digitalWrite(led10, LOW);   // Faz a saída do respectivo Led ser baixa ou Low)
  delay(100);               // espera por 100 ms
  digitalWrite(led11, LOW);   // Faz a saída do respectivo Led ser baixa ou Low)
  delay(100);               // espera por 100 ms
  digitalWrite(led12, LOW);   // Faz a saída do respectivo Led ser baixa ou Low)
  delay(100);               // espera por 100 ms
  digitalWrite(led13, LOW);   // Faz a saída do respectivo Led ser baixa ou Low)
  delay(100);               // espera por 100 ms
  
}
