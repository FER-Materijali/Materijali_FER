#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#define JMBGSIZE 13
#define NAMESIZE 14
struct record {
   char JMBG[JMBGSIZE + 1];
   char surname[NAMESIZE + 1];
};

#define BLOCK 512L                              // BLOCK size on disk
#define N 350                                  // Expected number of records:
#define C ((int)(BLOCK / sizeof(struct record))) // Number of records for a row in hash table
#define M                                                                      \
   ((int)(N / C * 1.3)) // Nomber of rows in hash, capacity 30% larger than minimum:
/*
#define C 1
#define M 5
*/

void DisplayErrorAndExit(char *message) {
   std::cout << message << "\n";
   exit(1);
}

class HashInFile {
 private:
   FILE *ft;
   struct record row[C];

   int Address(char JMBG[], int prime) {
      int i, a, b, c, address;
      char overlapResult[4 + 1];
      overlapResult[4] = '\0';
      // Overlap method
      for (i = 0; i < 4; i++)
         overlapResult[i] = JMBG[i + 4];
      a = atoi(overlapResult);
      for (i = 0; i < 4; i++)
         overlapResult[i] = JMBG[3 - i];
      b = atoi(overlapResult);
      for (i = 0; i < 4; i++)
         overlapResult[i] = JMBG[11 - i];
      c = atoi(overlapResult);
      // Division
      address = (a + b + c) % prime;
      std::cout << "Value " << (a + b + c) << " gives this address: " << address << " \n";
      return address;
   }

 public:
   int CalculatePrime(int m) {
      int i, prime, end;
      std:cout << "Seek largest prime <= " << m << "\n";
      prime = m + 1;
      do {
         prime--;
         end = (int)pow((double)prime, (double)0.5);
         for (i = end; i > 0; i--) {
            std::cout << prime << "/" << i;
            if (prime % i == 0)
               break;
         }
      } while (i != 1);
      return prime;
   }

   int CheckJMBGValidity(char JMBG[]) {
      int i, controlNumber;
      long sum;
      char weightArray[12 + 1] = "765432765432";
      sum = 0;
      for (i = 0; i < 12; i++) {
         sum += (JMBG[i] - '0') * (weightArray[i] - '0');
      }
      controlNumber = 11 - (sum % 11);
      if (controlNumber == 10)
         controlNumber = -1; // pogr. kontrolna znamenka
      if (controlNumber == 11)
         controlNumber = 0;
      return controlNumber;
   }

   void Empty() {
      int i;
      for (i = 0; i < C; i++)
         row[i].JMBG[0] = '\0';
      for (i = 0; i < M; i++) {
         fseek(ft, i * BLOCK, SEEK_SET);
         fwrite(row, sizeof(row), 1, ft);
      }
      std::cout << "\nHash table emptied N="<< N <<", C=" << C << ", M=" << M;
      std::cout << "\nRow size = " << sizeof(row) << "\n";
   }

   int Add(struct record inputRecord, int prime) {
      int i, j, start;
      i = Address(inputRecord.JMBG, prime);
      // Remember initially calculated address
      start = i;
      do { // Repeat until record is added into position or the file is full
         // Read all existing entries from a row 
         fseek(ft, i * BLOCK, SEEK_SET);
         fread(row, sizeof(row), 1, ft);
         for (j = 0; j < C; j++) {
            if (row[j].JMBG[0] != '\0') {
               // If an entry is empty
               std::cout << "Already existing JMBG =";
               std::cout << row[j].JMBG << "\n";
               if (strncmp(row[j].JMBG, inputRecord.JMBG, JMBGSIZE) == 0) {
                  // If the existing JMBG is identical to  inputRecordnom
                  std::cout << "There is already a record with JMBG " << inputRecord.JMBG << "\n";
                  return 1;
               }
            } else {
               // Write inputRecord into the empty slot
               row[j] = inputRecord;
               fseek(ft, i * BLOCK, SEEK_SET);
               std::cout << "Row " << i << " - added as entry nr." << j;
               fwrite(row, sizeof(row), 1, ft);
               return 1;
            }
         }
         // There is not space in the row, cyclically process the next row
         i = (i + 1) % M;
         std::cout << "No space, next row = " << i;
      } while (i != start); // Do until not back to the initial row
      return 0;           // No rows contain free space for the record
   }

   void Print() {
      // Print the contents of the whole hash
      int i, j;
      std::cout << "Hash table contents \n";
      for (i = 0; i < M; i++) {
         fseek(ft, i * BLOCK, SEEK_SET);
         fread(row, sizeof(row), 1, ft);
         for (j = 0; j < C; j++) {
            if (row[j].JMBG[0] != '\0') {
               // If entry is not empty
               std::cout <<"Record at address:" << i;
               std::cout << row[j].JMBG << " " << row[j].surname << "\n";
            }
         }
      }
   }

   int Get(char mbr[], int prime, struct record *inputRecord) {
      int i, j, start;
      i = Address(mbr, prime);
      // Remember the initially calculated address      
      start = i;
      do { // Repeat until the record is not found or the record do es not exist
         std::cout << "Reading record nr. %d\n";
         fseek(ft, i * BLOCK, SEEK_SET);
         fread(row, sizeof(row), 1, ft);
         for (j = 0; j < C; j++) {
            if (row[j].JMBG[0] != '\0') {
               // If record is not empty
               std::cout << "Already exists JMBG - row nr. " << j << "value=" << row[j].JMBG << "\n";
               if (strcmp(row[j].JMBG, mbr) == 0) {
                  // If current recors is identical to inputRecord
                  *inputRecord = row[j];
                  return 1;
               }
            } else {
               // Record not found
               return 0;
            }
         }
         // row is full, cyclically go to the next one
         i = (i + 1) % M;
      } while (i != start); // Do until not back to the initial row
      return 0;           // All rows have been examined, the record is not found 
   }

   HashInFile(char *fileName) {
      if ((ft = fopen(fileName, "w+")) == NULL)
         DisplayErrorAndExit("File cannot be opened. Exiting");
   }
   ~HashInFile() { fclose(ft); }
};

struct record inputRecord;

int main() {
   FILE *fi;
   char mbr[JMBGSIZE + 1];
   int prime;
   if ((fi = fopen("Hash\\inputForHashInFile.txt", "r")) == NULL)
      DisplayErrorAndExit("File cannot be opened: \"inputForHashInFile\"");
   std::cout << "inputRecord size is " << sizeof(struct record) + "\n";
   HashInFile h("table");
   h.Empty();
   h.Print();
   // Odredi prime broj za dijeljenje
   prime = h.CalculatePrime(M);
   std::cout << "\nPrime number for division =" << prime << "\n";
   // Sequentially read JMBG, surname, name - until there is data
   getchar();
   while (fscanf(fi, "%13s%s", inputRecord.JMBG, inputRecord.surname) != EOF) {
      std::cout << "\nRecord to be added to hash table: " << inputRecord.JMBG << " " << inputRecord.surname << "\n";
      if (h.CheckJMBGValidity(inputRecord.JMBG) == atoi(&inputRecord.JMBG[12])) {
         // Check if control number if correct
         if (!h.Add(inputRecord, prime))
            DisplayErrorAndExit("Table is full\n");
      } else {
         std::cout << "Invalid JMBG " << inputRecord.JMBG;
         std::cout <<"Control number needs to be " << h.CheckJMBGValidity(inputRecord.JMBG) << "\n";
      }
      printf("\n");
   }
   fclose(fi);
   getchar();
   h.Print();
   while (1) {
      std::cout << "Enter JMBG >";
      scanf("%s", mbr);
      if (h.Get(mbr, prime, &inputRecord)) {
         std::cout << inputRecord.JMBG << " " << inputRecord.surname << "\n";
      } else {
         std::cout << "JMBG " << mbr << " does not exists in the hash table\n";
         break;
      }
   }
   return 0;
}