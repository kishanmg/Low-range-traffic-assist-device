/* copyright kishanrao
 * Near-range traffic assist device initial source code
 * */
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

/* todo: Initialize hardware, identify user 
 * register with WiFi and LoRa libraries
 * listen to Wifi and LoRa signals 
 * Decode protocol messages */
int main(){
  int udpSocket, nBytes;
  char buffer[1024];
  struct sockaddr_in serverAddr, clientAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size, client_addr_size;
  int i;

  /*Create UDP socket*/
  udpSocket = socket(PF_INET, SOCK_DGRAM, 0);

  /*Configure settings in address struct*/
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(54321);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  /*Bind socket with address struct*/
  bind(udpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
  printf("NRTAD: Welcome user #KA04xxxxx\n");
  printf("Listening to nearby signals\n");
  /*Initialize size variable to be used later on*/
  addr_size = sizeof serverStorage;
  while(1){
    /* Try to receive any incoming UDP datagram. Address and port of 
 *       requesting client will be stored on serverStorage variable */
    nBytes = recvfrom(udpSocket,buffer,1024,0,(struct sockaddr *)&serverStorage, &addr_size);
    /* TODO: convert protocol messages to readable format, identify source */
    /*Convert message received to uppercase*/
    for(i=0;i<nBytes-1;i++)
      buffer[i] = toupper(buffer[i]);

    /*Send uppercase message back to client, using serverStorage as the address*/
  //  sendto(udpSocket,buffer,nBytes,0,(struct sockaddr *)&serverStorage,addr_size);
    printf("%s\n",buffer);
    buffer[0] = 0;
  }

  return 0;
}
