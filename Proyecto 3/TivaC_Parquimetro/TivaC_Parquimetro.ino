

#define green0 PF_3
#define red0 PB_3
#define green1 PC_4
#define red1 PC_5
#define green2 PC_6
#define red2 PC_7
#define green3 PD_6
#define red3 PD_7

void setup() {
  // put your setup code here, to run once:
  pinMode(PD_0, INPUT);
  pinMode(PD_1, INPUT);
  pinMode(PD_2, INPUT);
  pinMode(PD_3, INPUT);

  pinMode(green0, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(green3, OUTPUT);

  pinMode(red0, OUTPUT);
  pinMode(red0, OUTPUT);
  pinMode(red0, OUTPUT);
  pinMode(red0, OUTPUT);

  Serial.begin(9600);
}

int p0 = 0;
int p1 = 0;
int p2 = 0;
int p3 = 0;

void loop() {
  // put your main code here, to run repeatedly: 
  p0 = digitalRead(PD_0);
  p1 = digitalRead(PD_1);
  p2 = digitalRead(PD_2);
  p3 = digitalRead(PD_3);

  digitalWrite(green0,p0);
  digitalWrite(red0,!p0);

  digitalWrite(green1,p1);
  digitalWrite(red1,!p1);

  digitalWrite(green2,p2);
  digitalWrite(red2,!p2);

  digitalWrite(green3,p3);
  digitalWrite(red3,!p3);
  
  Serial.print("P 0:  ");
  Serial.println(p0);
  
}
