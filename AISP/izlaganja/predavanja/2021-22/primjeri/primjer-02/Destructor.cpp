#include <iostream>
using namespace std;

class File {
 private:
   FILE *fp = nullptr;

 public:
   File(char *name, char *mode) { fp = fopen(name, mode); }
   void writeByte(unsigned char c) { fwrite(&c, sizeof(c), 1, fp); }
   unsigned char readByte() {
      unsigned char c;
      fread(&c, sizeof(c), 1, fp);
      return c;
   }
   void seek(int pos) { fseek(fp, pos, SEEK_SET); }
   ~File() {
      if (fp)
         fclose(fp);
   }
};

int main(void) {
   File f("test.txt", "w+");
   f.writeByte('A');
   f.seek(0);
   cout << f.readByte();
   return 0;
}