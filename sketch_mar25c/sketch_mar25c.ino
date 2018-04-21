void setup(){
    Serial.begin(9600);
    int i;
    for (i = 1;i<=10;i=i+1) {
        Serial.println(i);
    }
}
void loop(){
}
