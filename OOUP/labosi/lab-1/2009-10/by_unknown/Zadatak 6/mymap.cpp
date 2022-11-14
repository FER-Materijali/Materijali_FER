#include <iostream>
#include <string>
#include <map>
#include <fstream>
using std::ifstream;


int main() {
    typedef std::map <std::string, int> MyMap;
    MyMap wordcounts;
    std::string s,p;
    ifstream indata; int max=0;
    
    indata.open("upute.txt");
    
    while (!indata.eof()) {
          indata >> s;
          if (wordcounts.find(s) == wordcounts.end())
             wordcounts.insert(std::make_pair(s,1));
          else
              ++wordcounts[s];
    }
    
    MyMap::iterator it=wordcounts.begin();
    while (it != wordcounts.end()) {
          if(max<it->second) {max = it->second; p=it->first;}
          std::cout << it->first<<' ' << it->second <<"\n";
          ++it;
          }
      std::cout<<"\nNajcesca rijec: "<<p<<" \nbroj ponavljanja: "<<max;    
}
