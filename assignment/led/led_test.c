#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int fd;
	char str[4] = "";
	if(argc != 2) {
		printf("invalid usage.\n");
		printf("usage1: %s on\n", argv[0]);
		printf("usage2: %s off\n", argv[0]);
		printf("usage3: %s state\n", argv[0]);
		return 1;
	}

	fd = open("/dev/bbb_gpio0", O_RDWR);

	if(strcmp(argv[1], "on") == 0) {
		write(fd, "1", 1);
		printf("Led ON\n");
	}
	else if(strcmp(argv[1], "off") == 0) {
		write(fd, "0", 1);
		printf("Led OFF\n");
	}
	else if(strcmp(argv[1], "state") == 0) {
		read(fd, str, 1);
		printf("Led State = %c\n", str[0]);
	} else { 
		printf("invalid usage.\n");
		printf("usage1: %s on\n", argv[0]);
		printf("usage2: %s off\n", argv[0]);
		printf("usage3: %s state\n", argv[0]);
		return 1;
	}

	close(fd);
	return 0;
}






