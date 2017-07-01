/* Copyright kishanrao
 * Near-range traffic assist device initial source code
 * */
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
/* TODO: initialize hardware
 * Register with WiFi and LoRa library
 * Define protocol and information elements
 * Encode protocol
 * */
int main(){
  int clientSocket, portNum, nBytes, i = 0;
  char buffer[5][1024];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;
  printf("NRTAD gateway\n");
  printf("Welcome BTP: location Hudson circle\n");
  printf("Enter the message that needs to be broadcasted\n");
  /*Create UDP socket*/
  clientSocket = socket(PF_INET, SOCK_DGRAM, 0);
  
  /*Configure settings in address struct*/
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(54321);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  
  snprintf(buffer[0],1024,"BTP: Turn off engines, long wait");
  snprintf(buffer[1],1024,"BTP: Vehicle #5678, no helmet, fined");
  snprintf(buffer[2],1024,"BTP: Vehicles towards KRMarket, make way for ambulance");
  snprintf(buffer[3],1024,"BTP: Vehicle #9999, follow lane");
  snprintf(buffer[4],1024,"BTP: No horn");
  /*Initialize size variable to be used later on*/
  addr_size = sizeof serverAddr;

  while(1){
    /*printf("Type a sentence to send to server:\n");
    fgets(buffer,1024,stdin);
    printf("You typed: %s",buffer);*/

    nBytes = strlen(buffer[i]) + 1;
    /*Send message to server*/
    sendto(clientSocket,buffer[i],nBytes,0,(struct sockaddr *)&serverAddr,addr_size);
    /*Receive message from server
    nBytes = recvfrom(clientSocket,buffer,1024,0,NULL, NULL);

    printf("Received from server: %s\n",buffer);*/
    i++;
    if (i >=5 ) break;
  }

  return 0;
}
