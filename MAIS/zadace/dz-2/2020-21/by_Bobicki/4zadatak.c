#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#define NUM_OF_GROUPS 16
#define BLOCKS_PER_ROW 32

struct pgm_picture
{
    int width;
    int height;
    unsigned char** pixels;
};

struct point
{
    int x;
    int y;
};

struct pgm_picture read_pgm_file(char* filename);
struct point full_search(struct pgm_picture first_picture, struct pgm_picture second_picture, int block);
void free_picture(struct pgm_picture picture);


int main(int argc, char* argv[])
{
    /* Read block number from input */
    char *p;
    int block;
    errno = 0;
    long arg = strtol(argv[1], &p, 10);
    if (errno != 0 || *p != '\0' || arg > INT_MAX || arg < 0 || arg > 1023) {
        fprintf(stderr, "Please input valid block number!\n");
        exit(-1);
    } else {
        block = arg;    
    }

    /* Read .pgm files from input */
    char* first_filename = NULL;
    char* second_filename = NULL;
    if(argc > 2) {
        first_filename = argv[2];
        if(argc > 3) {
            second_filename = argv[3];
        }
    }
    if(first_filename == NULL) {
        first_filename = "lenna.pgm"; 
    }
    if(second_filename == NULL) {
        second_filename = "lenna1.pgm";
    }

    struct pgm_picture first_picture = read_pgm_file(first_filename);
    struct pgm_picture second_picture = read_pgm_file(second_filename); 
    struct point vector = full_search(first_picture, second_picture, block);
    printf("%d,%d\n", vector.x, vector.y);
    free_picture(first_picture);
    free_picture(second_picture);
    return 0;
}

struct pgm_picture read_pgm_file(char* filename)
{
    struct pgm_picture picture;

    FILE* file = fopen(filename, "rb");
    if(file == NULL) {
        fprintf(stderr, "Please input valid .pgm file names!\n");
        exit(-1);
    }

    /* Read header */
    fscanf(file, "P5\n");
    fscanf(file, "%d\n", &picture.width);
    fscanf(file, "%d\n", &picture.height);
    fscanf(file, "255\n");

    picture.pixels = (unsigned char**)malloc(sizeof(unsigned char*) * picture.height);
    for(int i = 0; i < picture.height; ++i) {
        picture.pixels[i] = (unsigned char*)malloc(sizeof(unsigned char) * picture.width);
        fread(picture.pixels[i], sizeof(unsigned char), picture.width, file);
    }
    fclose(file);
    return picture;
}

struct point full_search(struct pgm_picture first_picture, struct pgm_picture second_picture, int block)
{
    int block_start_x = (block % BLOCKS_PER_ROW) * 16;
    int block_start_y = (block / BLOCKS_PER_ROW) * 16;
    struct point vector = { .x = -16, .y = -16 };
    double mad = INT_MAX;

    for(int i = block_start_y - 16; i <= block_start_y + 16; ++i)
    {
        if(i < 0) continue;
        if(i + 15 >= first_picture.height)
        {
            break;
        }

        for(int j = block_start_x - 16; j <= block_start_x + 16; ++j)
        {
            if(j < 0) continue;
            if(j + 15 >= first_picture.width) 
            {
                break;
            }

            double current_mad = 0;
            for(int y = 0; y < 16; ++y)
            {
                for(int x = 0; x < 16; ++x)
                {
                    current_mad += (double)abs(first_picture.pixels[i + y][j + x] - second_picture.pixels[block_start_y + y][block_start_x + x]) / 256;
                }
            }

            if(current_mad < mad)
            {
                mad = current_mad;
                vector.x = j - block_start_x;
                vector.y = i - block_start_y;
            }
        }
    }
    return vector;
}

void free_picture(struct pgm_picture picture)
{
    for(int i = 0; i < picture.height; ++i)
    {
        free(picture.pixels[i]);
    }
    free(picture.pixels);
}