
#include <stdio.h>
#include <string.h>

enum kind {
    TEMPERATURE,
    HUMIDITY,
    STATUS
};

struct reading {
    enum kind type;

    union {
        float celsius;
        int percent;
        char status[8];
    } value;
};

void show(struct reading *r)
{
    switch (r->type)
    {
        case TEMPERATURE:
            printf("Temp %.1f C\n", r->value.celsius);
            break;

        case HUMIDITY:
            printf("Humidity %d %%\n", r->value.percent);
            break;

        case STATUS:
            printf("Status %s\n", r->value.status);
            break;
    }
}

int main()
{
    struct reading log[3];
    int i;

    log[0].type = TEMPERATURE;
    log[0].value.celsius = 31.5f;

    log[1].type = HUMIDITY;
    log[1].value.percent = 68;

    log[2].type = STATUS;
    strcpy(log[2].value.status, "OK");

    printf("sizeof union = %lu, sizeof struct reading = %lu\n",
           (unsigned long)sizeof(log[0].value),
           (unsigned long)sizeof(log[0]));

    for (i = 0; i < 3; i++)
    {
        show(&log[i]);
    }

    return 0;
}

