#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>

  int main(){
    std::vector<std::string> v(2);
    v[0] = "bok ";
    v[1] = "ti ";
    v.push_back("kak ");
    v.insert(v.begin(),"?");

    std::reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
      std::cout << "v[" << i << "] = " << v[i] <<"\n";
  }
