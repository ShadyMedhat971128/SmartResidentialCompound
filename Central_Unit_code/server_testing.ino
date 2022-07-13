
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "Crypto.h"
#include "compound_macros.h"
// define the server ip
IPAddress local_IP(192, 168, 1, 1);
IPAddress gateway(192, 168, 0, 80);
IPAddress subnet(255, 255, 255, 0);
// server name and password
const char* ssid = "TESTING";
const char* password = "12345678";
WiFiUDP Udp;

unsigned int localUdpPort = 4210; // local port to listen on
char incomingPacket[255]; // buffer for incoming packets
//char replyPacekt[] = "Message received"; // a reply string to send back
int len = 0;
/*
  given the cipher nymber num in te crypto.h (a => num = 7)
  key_shared = Ya => a^(Xa)
  hey_cipher = Xa
*/
#define mac_size 4
#define n  16 // size of the message

//char key_cipher =0;// DH(q, num); //Xa
//char key_shared =0;// pow(num, key_cipher); //Ya
//char key_seq = 27; // pow(Yb , Xa);

//// encryption standered data


void setup() {
  Serial.begin(9600);
  //Serial.println();
  //Serial.println();
  WiFi.softAPConfig(local_IP, gateway, subnet) ? "AP Configured" : "Configuration Failed!";
  //Serial.print("Setting Soft-AP ... ");
  WiFi.softAP(ssid, password) ? "AP Ready" : "Failed!";
  //Serial.println();
 // Serial.print("Soft-AP IP address: ");
  //Serial.println();
  WiFi.softAPIP();
  
  Udp.begin(localUdpPort);
  //Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
    //char macro[] ={property_1 , problem , uitily,gas_problem,0 ,0,0,0,0,0,0,0};
   //Serial.println(display_message(macro));//serial print macr => message
}
int packetSize = 0;
void loop() {
  char secret_key = 27; // pow(Yb , Xa);
  char output[n] = {0};

  // share the key

  // wait for packet recieving
  //    while(!packetSize){
  //     packetSize = Udp.parsePacket();
  //     }
  //     // read the packet
  //     len = Udp.read(incomingPacket, 255);
  //    if (len > 0)
  //    {
  //      incomingPacket[len] = 0;
  //    }
  //    Serial.printf("UDP packet contents: %s\n", incomingPacket);//get the key
  //     // generate the key
  //     key_cipher = DH(q, num); //Xa
  //     key_shared = pow(num, key_cipher); //Ya
  //     // send key_shared
  //     Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
  //     Udp.write(key_shared);
  //     Udp.endPacket();
  //     // generate the key
  //    char key_seq = pow((char) *incomingPacket, key_cipher);
  //recieve the message
  
  packetSize = 0;
  while (!packetSize) {
    packetSize = Udp.parsePacket();
  }
  // read the packet
  len = Udp.read(incomingPacket, 255);
  if (len > 0)
  {
    incomingPacket[len] = 0;
  }
  
  //Serial.printf("UDP packet contents: %s\n", incomingPacket);//get the key
  //Serial.println("incomingPacket :");
  Serial.print(incomingPacket);
  Serial.print(",");
  //Serial.print(" the message after decryption : ");
  //start decrryption
  //for (int index = 0 ; index < n ; index += 16 )
  //{
   
    //Serial.println(index/16);

  //}
  //char macro[] ={property_1 , problem , uitily,gas_problem,0 ,0,0,0,0,0,0,0};
  //Serial.println(display_message(macro));//serial print macr => message
  Decrypt ( incomingPacket , secret_key, output);
  //Serial.println("output :");
  //Serial.print(",");
  Serial.print(display_message(output));
  Serial.print(",");
  Serial.print(output);
  Serial.println("");
  
  //space_lines();
  delay(2000);
}
void Decrypt (char* incomingPacket ,char secret_key,char* output)
{
 char REC_key_AES[16];
  char REC_key_MAC[16];
  // encryption standered data
  char Oindex = 0;
  char Iindex = 0;
 sequence_key_generator(REC_key_AES, REC_key_MAC, mac_size, secret_key);
    //char state[16] = { 0 };
    char message_t[16];
    for (int i = 0; i < 16; i++)
    {
      message_t[i] = incomingPacket[i];
    }
    //Serial.println("message_t :");
    //Serial.println(message_t);
    aes_enc_dec(message_t, REC_key_AES, 1);
    //Serial.println("message_t :2");
    //Serial.println(message_t);
    //decryption testing
    char data[16];
    char temp_data[16];
    char mac[mac_size];
    // separate the mac from the message
    separete_mac(message_t, data, mac, (char)sizeof(message_t), mac_size);

    //generate the mac from the message again
    copyArray(data, temp_data, (char)sizeof(data));

    // compare the mac
    if (macCompare(temp_data, mac, REC_key_MAC, (char)sizeof(data), mac_size))
    {
      //Serial.println("message recieved successfully");
    }
    for (char i = 0; i < 12; i++)
    {
      output[Oindex] = data[i];
      Oindex++;
    }
}
void space_lines()
{
  Serial.println("");
  Serial.println("//----------------------------------------------------------------------------//");
  Serial.println("");
  Serial.println("//----------------------------------------------------------------------------//");
  Serial.println("");
}
