void setup() {
  pinMode(13, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  digitalWrite(6, 1);
  digitalWrite(9, 1);
  digitalWrite(11, 0);
  digitalWrite(12, 0);
  digitalWrite(8, 0);
  digitalWrite(7, 0);
  
  // put your setup code here, to run once:

}

const int pp = 12;
const int pt = 11;
const int lp = 8;
const int lt = 7;

/*
 * 

en1 = d6
in1=d12
in2=d11

en2=d9
in3=d8
in4=d7
 */
char dane;
void loop() {
  if(Serial.available()){
    dane = Serial.read();
  }

  switch (dane){
    case 'P':
      jazdaP();
      break;
    case 'T':
      jazdaT();
      break;    
    case 'R':
      jazdaR();
      break;
    case 'L':
      jazdaL();
      break;
    default:
      Stop();
      break;  
  }
}


void Stop(){
  digitalWrite(pp, 0);
  digitalWrite(pt, 0);
  digitalWrite(lp, 0);
  digitalWrite(lt, 0);
}

void jazdaP(){
  digitalWrite(pp, 1);
  digitalWrite(pt, 0);
  digitalWrite(lp, 1);
  digitalWrite(lt, 0);
}

void jazdaT(){
  digitalWrite(pp, 0);
  digitalWrite(pt, 1);
  digitalWrite(lp, 0);
  digitalWrite(lt, 1);
}
void jazdaR(){
  digitalWrite(pp, 0);
  digitalWrite(pt, 1);
  digitalWrite(lp, 1);
  digitalWrite(lt, 0);
}

void jazdaL(){
  digitalWrite(pp, 1);
  digitalWrite(pt, 0);
  digitalWrite(lp, 0);
  digitalWrite(lt, 1);
}
