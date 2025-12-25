#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	if(argc < 2){
		printf("PORT SCANNER\n");
		printf("./port_scanner TARGET_IP\n");
	} else {
		char *ip = argv[1];

		struct sockaddr_in target;
		target.sin_family = AF_INET;
		target.sin_addr.s_addr = inet_addr(ip);

		int port;

		for(port = 0; port < 65535; port++){
			target.sin_port = htons(port);

			int sock = socket(AF_INET, SOCK_STREAM, 0);

			if(connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0){
				printf("PORT %d [OPEN]\n", port);
			}
			close(sock);
		}

	}
	return 0;
}
