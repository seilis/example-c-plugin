#define _GNU_SOURCE
#include <stdio.h>

char* serdesXML(int thing) {
	char* out = NULL;
	asprintf(&out, "<thing>%i</thing>", thing);
	return out;
}

typedef char*(*serdes_func_t)(int);


serdes_func_t register_serdes() {
	return serdesXML;
}
