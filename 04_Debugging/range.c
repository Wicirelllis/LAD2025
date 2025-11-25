#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char *argv[]) {
    int m = 0, n, s = 1;
    switch (argc) {
        case 1:
            printf("help\n");
            return 0;
        case 2:
            n = atoi(argv[1]);
            break;
        case 3:
            m = atoi(argv[1]);
            n = atoi(argv[2]);
            break;
        case 4:
            m = atoi(argv[1]);
            n = atoi(argv[2]);
            s = atoi(argv[3]);
            break;
    }

    for (int i = m; (s > 0 && i < n) || (s < 0 && i > n); i += s)
        printf("%d\n", i);

    return 0;
}
