#define _GNU_SOURCE
#include <stdio.h>

char* serdesJson(int thing) {
	char* out = NULL;
	asprintf(&out, "{\"thing\":%i}", thing);
	return out;
}

typedef char*(*serdes_func_t)(int);


serdes_func_t register_serdes() {
	return serdesJson;
}
