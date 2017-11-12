#ifndef _MEMORY_MONITOR_H_
#define _MEMORY_MONITOR_H_

typedef struct MemoryMonitor {
	int sum;
	void (*showUsedMemory)(struct MemoryMonitor* monitor);
} monitor;

monitor* MemoryMonitor();

#endif

