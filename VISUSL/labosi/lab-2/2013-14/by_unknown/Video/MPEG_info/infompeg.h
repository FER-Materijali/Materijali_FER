/*
 * Header file for InfoMPEG
 * Copyright (C) 1993 Dennis Lee
 */

/* #define BORLAND */
#define MAX_FILES         200
#define MAX_CYCLE_LEN     1000
#define ULONG             unsigned long

typedef enum {NO, YES}     yes_or_no;
typedef enum {FALSE, TRUE} boolean;

typedef struct {
    long sum_frames;       /* number of frames of one type */
    long sum_frame_len;    /* number of bytes for all frames of one type */
    } frame_type_sums;

typedef struct {
    enum {I=1,P,B} frame_type;
    long frame_len;
    } frame_info;

typedef struct {
    char name[40];
    long size;
    char resolution[15];
    short frames;
    char frame_types_found[5];
    short compression;
    } file_info;

long file_offset;
long total_frames;
long height, width;
short report_info_type;
short previous_frame;
char frame_types[5]={' ','I','P','B'};
char frame_cycle[MAX_CYCLE_LEN];
short cycle_len;
boolean cycle_exists;
frame_type_sums frame_sums[3];
ULONG tot_len=0;          /* total uncompressed length of all MPEG streams */
short num_files;
file_info files[MAX_FILES];

#ifdef BORLAND
  char *get_path(char *);
  void expand_cmd_line(short *, char ***);
#endif

void usage(void);
void get_name(char *);
void get_stream_res(FILE *);
void get_frame_info(yes_or_no, FILE *);
void next_start_code(FILE *);
void init_vars(void);
void report_info(char *, FILE *);
void sort_files(short, short);
void report_comparison(void);
