#include "offsets.hpp"

#pragma comment(lib,"urlmon.lib") //for url download


int main(int argc, char** argv) {
  
  //Download offsets.json from repo
  const char* url = ("https://raw.githubusercontent.com/GLX-ILLUSION/overwatch-offsets-autoupdater/main/offsets.json");
	URLDownloadToFileA(nullptr, url, "offsets.json", 0, nullptr);
  
  //When the user is authenticated in your loader, you can initialize the offsets.
  
  offsets::initialize();
  
}
