#include <iostream>

#define CPU_AWK_FMT 

struct CPUInfo
{
    char name[16];
    uint64_t user;
    uint64_t nice;
    uint64_t system;
    uint64_t idle;
    uint64_t iowait;
    uint64_t irq;
    uint64_t softirq;
};

int main()
{
    int cpu_count = 0;
    CPUInfo *cpu[32];
    FILE *fp = popen("cat /proc/stat | grep cpu | awk \'{print \"\"$1\" \"$2\" \"$3\" \"$4\" \"$5\" \"$6\" \"$7\" \"$8\"\"}\'", "r");
    if(fp == nullptr){
        printf("error");
        return 0;
    }

    while(1){
        cpu[cpu_count] = new CPUInfo();
        if(fscanf(fp, "%s %lu %lu %lu %lu %lu %lu %lu",
            cpu[cpu_count]->name, &cpu[cpu_count]->user, &cpu[cpu_count]->nice, &cpu[cpu_count]->system, 
            &cpu[cpu_count]->idle, &cpu[cpu_count]->iowait, &cpu[cpu_count]->irq, &cpu[cpu_count]->softirq) != 8)
        {
            break;
        };
        cpu_count++;
    }
    printf("%d", cpu_count);
}
