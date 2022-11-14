#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <mutex>
#include <thread>

void log(const std::string& msg) {
  static std::mutex mutex;
  std::lock_guard<std::mutex> lock(mutex);
  std::ofstream file("mylog.txt", std::ofstream::app);  // may throw...
  file << msg << std::endl;  // may throw 
}

void task(){
  std::ostringstream oss;
  oss << "task: " <<std::this_thread::get_id() <<" says hello!";
  log(oss.str());
}

main(){
  std::vector<std::thread> vec;
  for (int i=0; i<10; ++i){
    vec.push_back(std::thread(task));
  }
  for (int i=0; i<10; ++i){
    vec[i].join();
  }
}
