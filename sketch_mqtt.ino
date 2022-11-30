
#define sensor A0
int valor = 0;
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char *ssid = "flan";
const char *password = "Manzana2135";
const char* mqtt_server = "broker.hivemq.com"; // Este es el address en mqtt dash
const char* keyDevice = "";
WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("OK");
  }
//void callback(char* topic, byte* payload, unsigned int length) {
//}


void reconnect() {

  if (!client.connected()) {

    if (client.connect(keyDevice,"","")){//Servidor broker es el usuario y prueba12 la contraseña en mqtt dash
      Serial.println("connected");
      client.subscribe("as/humedad"); // Topico al momento de crear el boton
    } else {
      delay(5000);
    }
  }
}
void setup() {
  Serial.begin(115200);
  Serial.println("iniciando");
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  //client.setCallback(callback);  
  
}

void loop()
{
  if (!client.connected())
  {
    reconnect();
  }
  client.loop();
  
  valor =map(analogRead(sensor),0,1023,100,0);
  Serial.print("El valor sensor de la humedad es: ");
  Serial.println(valor);
  delay(2000);
  client.publish("as/humedad",String(valor).c_str()); 
}