#include <stdio.h>
#include <stdint.h>

#include <arpa/inet.h> // ntohs
// --> network-order (big-endian == Motorola) to host endianess

#include "quickdraw.h"

const char *filename = "abscab.pict";





int main(int argc, char **argv) {

    FILE *fd = fopen(filename, "rb");
    if (!fd) {
        printf("failed to open file '%s'\n", filename);
        return -1;
    }

    // skip 512 byte header
    fseek(fd, 512, SEEK_SET);

    int16_t picSize = 0;
    if (fread(&picSize, 1, sizeof(picSize), fd) != sizeof(picSize)) {
        printf("failed to read picSize\n");
        return -1;
    }
    picSize = ntohs(picSize);

    printf("picSize = %d\n", picSize);

    Rect picRect;
    if (fread(&picRect, 1, sizeof(picRect), fd) != sizeof(picRect)) {
        printf("failed to read picRect\n");
        return -1;
    }
    picRect.top    = ntohs(picRect.top);
    picRect.left   = ntohs(picRect.left);
    picRect.bottom = ntohs(picRect.bottom);
    picRect.right  = ntohs(picRect.right);

    printf("   top = %d\n", picRect.top);
    printf("  left = %d\n", picRect.left);
    printf("bottom = %d\n", picRect.bottom);
    printf(" right = %d\n", picRect.right);

    char opcode = 0;
    while (opcode != OP_EndOfPicture) {

        // read next opcode
        fread(&opcode, 1, 1, fd);


    }

    fclose(fd);

    return 0;
}
