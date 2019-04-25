#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef char*(*serdes_func_t)(int);
typedef serdes_func_t (*register_serdes_t)(void);

serdes_func_t get_serdes(char* libname) {
	void* handle = dlopen(libname, RTLD_LAZY);
	if (handle == NULL) {
		printf("Unable to open library %s", libname);
		exit(1);
	}

	char* error = NULL;
	register_serdes_t serdes = (register_serdes_t)dlsym(handle, "register_serdes");
	error = dlerror();
	if (error != NULL) {
		printf("%s\n", error);
	}
	return serdes();
}

int main() {
	serdes_func_t serdes[2] = {0};

	printf("Doing plugins\n\n");

	serdes[0] = get_serdes("./.libs/libxmlplugin.so");
	serdes[1] = get_serdes("./.libs/libjsonplugin.so");

	char* tmp = (*serdes[0])(5);
	printf(tmp);
	printf("\n");
	tmp = (*serdes[1])(5);
	printf(tmp);
	printf("\n");
	return 0;
}
