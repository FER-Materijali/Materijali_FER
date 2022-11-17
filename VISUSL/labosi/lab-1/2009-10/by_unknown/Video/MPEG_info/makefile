# If the program does not compile with gcc, try cc.
# CC = cc
CC = gcc

CFLAGS = -O

.c.o:
	$(CC) $(CFLAGS) -c $<

O = infompeg.o

infoMPEG : $(O)
	$(CC) -o infoMPEG $(O)
