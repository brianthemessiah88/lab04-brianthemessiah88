// numDucks.cpp 
// Giovanni Gasparini edited from P Conrad, Winter 2015
// Example program to read from file and count occurences

#include <iostream> // for printf()
#include <cstdlib> // for exit(), perror()
#include <fstream> // for ifstream
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
  int numDucks = 0;
  int numAnimals = 0;
  int notDucks = 0;
  string wordFromFile;
  if (argc!=2) {
    // if argc is not 2, print an error message and exit
    cerr << "Usage: "<< argv[0] << " inputFile" << endl;
    exit(1); // defined in cstdlib
  }
  ifstream myfile;
  myfile.open (argv[1]);
  if (myfile.is_open()){
    while (myfile){
      getline(myfile, wordFromFile);
      if (wordFromFile == "duck"){
        numDucks++;
      }
      else{
        notDucks++;
      }
      numAnimals++;
    }
  }
  myfile.close();
  cout<< "Report for " << argv[1]<<":"<<endl;
  cout<<"   Animal count:    "<< numAnimals-1<<endl;
  cout<<"   Duck count:      "<<numDucks<<endl;
  cout<<"   Non duck count:  "<<notDucks-1<<endl;
  return 0;
}
