#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

// Number of bytes in .raw block
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "rb");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    int file_count = 0;
    char filename[8];
    FILE *outptr = NULL;
    size_t byte_read; // 声明 byte_read

    while ((byte_read = fread(buffer, sizeof(BYTE), BLOCK_SIZE, inptr)) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) // 天才想法，使用与运算符
        {
            // 如果已有打开的文件，先关闭
            if (outptr != NULL)
            {
                fclose(outptr);
            }

            // 输出图片名字
            sprintf(filename, "%03d.jpg", file_count);
            outptr = fopen(filename, "wb");
            if (outptr == NULL)
            {
                fprintf(stderr, "无法创建文件 %s\n", filename);
                fclose(inptr);
                return 1;
            }
            file_count++;
        }
        if (outptr != NULL)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, outptr);
        }
    }
    if (outptr != NULL)
    {
        fwrite(buffer, sizeof(BYTE), byte_read, outptr);
    }

    fclose(inptr);
    if (outptr != NULL)
    {
        fclose(outptr);
    }
}
