#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "memorymonitor.h"

void showUsedMemory(struct MemoryMonitor* monitor) {
	printf("\n\n%d bytes", monitor->sum);
}

/**
 * Return new instance by Lexical Analizer.
 */
monitor* MemoryMonitor()
{
    monitor* new = (monitor*)malloc(sizeof(monitor));

    new->showUsedMemory = showUsedMemory;
    return new;
}
