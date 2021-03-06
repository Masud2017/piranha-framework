#include "logger.h"

void debug(char* msg) {
	printf("\033[32m--> Debug: %s",msg);
	printf("\033[0m");
}

void error(char* error_msg) {
	printf("\033[31m--> Error: %s",error_msg);
	printf("\033[0m");
}

void warning(char* warning_msg) {
	printf("\033[33m--> Warning: %s",warning_msg);
	printf("\033[0m");
}
