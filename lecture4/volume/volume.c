// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        fclose(input);
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t header[HEADER_SIZE];
    int16_t buffer;
    if (fread(header, sizeof(uint8_t), HEADER_SIZE, input) != HEADER_SIZE)
    {
        perror("读取文件头失败");
        fclose(input);
        fclose(output);
        return 1;
    }
    if (fwrite(header, sizeof(uint8_t), HEADER_SIZE, output) != HEADER_SIZE)
    {
        perror("写入文件头失败");
        fclose(input);
        fclose(output);
        return 1;
    }

    while ((fread(&buffer, sizeof(int16_t), 1, input)))
    {
        buffer *= factor;
        if (fwrite(&buffer, sizeof(int16_t), 1, output) != 1)
        {
            perror("写入数据失败");
            fclose(input);
            fclose(output);
            return 1;
        }
    }

    // TODO: Read samples from input file and write updated data to output file

    // Close files
    fclose(input);
    fclose(output);
}
