#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_GROUPS 16

struct pgm_picture
{
    int width;
    int height;
    unsigned char* pixels;
};

struct pixel_groups
{
    int count[NUM_OF_GROUPS];
};

struct pgm_picture read_pgm_file(char* filename);
struct pixel_groups count_groups(struct pgm_picture picture, int num_of_pixels);
void print_group_count(struct pgm_picture picture, struct pixel_groups groups, int num_of_pixels);


int main(int argc, char* argv[])
{
    struct pgm_picture picture = read_pgm_file(argv[1]);
    int num_of_pixels = picture.width * picture.height;
    struct pixel_groups groups = count_groups(picture, num_of_pixels);
    print_group_count(picture, groups, num_of_pixels);
    free(picture.pixels);
    return 0;
}

struct pgm_picture read_pgm_file(char* filename)
{
    struct pgm_picture picture;

    FILE* file = fopen(filename, "rb");
    if(file == NULL) 
    {
        fprintf(stderr, "Please input valid .pgm file!\n");
        exit(-1);
    }

    /* Read header */
    fscanf(file, "P5\n");
    fscanf(file, "%d\n", &picture.width);
    fscanf(file, "%d\n", &picture.height);
    fscanf(file, "255\n");

    int num_of_pixels = picture.width * picture.height;
    picture.pixels = (unsigned char*)malloc(sizeof(unsigned char) * num_of_pixels);
    fread(picture.pixels, sizeof(unsigned char), num_of_pixels, file);
    fclose(file);
    return picture;
}

struct pixel_groups count_groups(struct pgm_picture picture, int num_of_pixels)
{
    struct pixel_groups groups;
    memset(groups.count, 0, sizeof(int) * NUM_OF_GROUPS);
    for(int i = 0; i < num_of_pixels; ++i)
    {
        ++groups.count[picture.pixels[i] >> 4];
    }
    return groups;
}

void print_group_count(struct pgm_picture picture, struct pixel_groups groups, int num_of_pixels)
{
    for(int i = 0; i < NUM_OF_GROUPS; ++i)
    {
        printf("%d %f\n", i, (double)groups.count[i] / num_of_pixels);
    }
}