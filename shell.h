
#ifndef SHELL
#define SHELL
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h> 
#include "DynArray.h"
struct Shell {
	bool isRunning;
	pid_t pid;
	char* pidString;
	char* cwd;
	char* homeDirectory;
	int status;
	int signalTerminated;
	bool lastExitedByStatus;
	bool lastExitedBySignal;
	int backgroundProcessesRunning;
	struct DynArray* backgroundPIDs;
};


void shellInputLoop();

void handleShellArgument(char* argument,struct Shell*);




void initShell(struct Shell*);

void freeShell(struct Shell*);

void printStatus(struct Shell*);

void checkForZombies(struct Shell*);
void killAllProcesses(struct Shell*);


#endif


