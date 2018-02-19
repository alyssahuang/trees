#include "connect.h"

int execute (int s, char *cmd) {
  fprintf(stdout, "Passed into execute: %s\n\n", cmd);

  return 0;
}

int parse (int s, char *msg, char* name) {
  char *target = msg;
  fprintf(stdout, "WHAT THE ACTUAL FUCK: %s\n", msg);
  //check whether the msg was targetted for this client. If no, then silently drop the packet by returning 0

  char *cmd = strchr(msg, ':');
  if (cmd == NULL) {
    printf("Incorrect formatting. Reference: TARGET: command");
    return -1;
  }
//add strtok 

  //adjust the cmd pointer to the start of the actual command
  //adjust the terminated character to the end of the command
  //print a local statement detailing what command was recieved

  execute (s, cmd);
  return 0;
}


int init_channel (char *ip, int port, char *name) {
  char msg[CMD_LENGTH];
  struct sockaddr_in server;

  server.sin_addr.s_addr = inet_addr(ip);//convert the ip to network byte order
  server.sin_family = AF_INET;//set the server's communications domain
  server.sin_port = htons(port);//convert port to network byte order

  int channel = socket(AF_INET, SOCK_STREAM, 0);//define a SOCK_STREAM socket

  if(channel < 0) {
    perror ("socket:");
    exit(1);
  }
  struct sockaddr *nooo = (struct sockaddr *) &server;
  int connection_status = connect(channel, nooo, sizeof(server));//use the defined channel to connect the slave to the master server

  if (connection_status < 0) {
    perror ("connect:");
    exit(1);
  }
  snprintf(msg, CMD_LENGTH, "%s", "helppppp");
  //send a greeting message back to master by loading a string into msg (hint: snprintf will come in handy)
  respond (channel, msg);
  return channel;
}