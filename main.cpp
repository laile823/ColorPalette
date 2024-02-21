#include <iostream>
#include <cstring>

using namespace std;

bool all_hex(char*);

int main(int argc, char* argv[]) {
  int valid_colors = 0;

  if(argc < 3){
    cout << "ERR_MISSING: One or more RGB values should be provided as arguments separated by space" << endl;
  }
    else {
      for(int i=1; i < argc; i++) {
        int length = strlen(argv[i]);
        if( (length == 3 || length == 6) && all_hex(argv[i]) ) {
          cout << "#" << argv[i] << endl;
        }
        if(length != 3 && length != 6 ){
            cout << argv[i] << " ERR_LENGTH: RGB values must be either 3 or 6 characters long" << endl;
          }
        if(!all_hex(argv[i])){
          cout << argv[i] << " ERR_VALUE: RGB values must be in 0-f range" << endl;
        }
      }
    }

  return 0;
}

bool all_hex(char* word) {
  for(int i=0; i<strlen(word); i++) {
    if((word[i] >= '0' && word[i] <= '9') || (word[i] >= 'a' && word[i] <= 'f')
      || (word[i] >= 'A' && word[i] <='F')) {
      continue;
    }
    else {
      return false;
    }
  }

  //no non-hex characters found
  return true;
}
