//Author: Michael Fu
//date:
//description: this program creates a max heap that can input from both files and the command line

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;


void printTree(int* heap, int index, int depth);
int main(){
  int* heap = new int[100];
  char inpt[15];

  for(int i = 0;i<100;i++){
    heap[i] = i;
  }

  printTree(heap, 1, 0);
}




void printTree(int* heap, int index, int depth){
  //Go through the right
  if(index*2+1 <= 100 && heap[index*2+1] != 0){
    
    printTree(heap, index*2+1, depth+1);
  }

  //Print with right amount of tabs
  for(int i = 0; i<depth-1; i++){
    cout << "\t";

    
  }
  if(index%2==0 && index != 1){
    cout << "\\_____";
  } else if (index%2==1 && index != 1){
    cout << "/▔▔▔▔▔";
  }
    cout << heap[index] << endl;

  //Go through the left
  if(index*2 <= 100 && heap[index*2] != 0){
    
    printTree(heap, index*2, depth+1);
  }
}