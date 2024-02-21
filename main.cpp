//Author: Michael Fu
//date:
//description: this program creates a max heap that can input from both files and the command line

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;


void printTree(int* heap, int index, int depth);
void add(int* &heap, int data, int index);
void deleteRoot(int* &heap, int index);


int main(){
  int* heap = new int[100];
  char inpt[15];
  int indexon = 1;
  bool justKeepGoing = true;
  /*
  for(int i = 0;i<100;i++){
    heap[i] = i;
    }*/

  while(justKeepGoing == true){
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "What do you want to do? Add(A), Delete(D), Print(P), and Quit(Q)" << endl;
    char* inputtt = new char[20];
    cin >> inputtt;
    cin.ignore();
    int num = 0;
    if(strcmp(inputtt, "A")==0){
      cout << "Manually(M) or from File(F)" << endl;
      cin >> inputtt;
      cin.ignore();
      if(strcmp(inputtt, "M")==0){
	
	cout << "what number to enter?" << endl;
	cin >> num;
	cin.ignore();
	int size = 1;
	while(heap[size] != 0){
	  size++;
	}
	add(heap, num, size);
      } else if(strcmp(inputtt, "F")==0){
	cout << "what file name? (include .txt)" << endl;
	cin >> inputtt;
	cin.ignore();
	fstream file;
	file.open(inputtt);
	while(file >> num){
	  int size = 1;
	  while(heap[size] != 0){
	    size++;
	  }
	  add(heap, num, size);
	}
	file.close();
      }
    } else if (strcmp(inputtt, "D")==0){
      cout << "just delete the largest element(L) or everything(E)" << endl;
      cin >> inputtt;
      cin.ignore();
      if(strcmp(inputtt, "L")==0){
	deleteRoot(heap, 1);
      } else if (strcmp(inputtt, "E")==0){
        while(heap[1] != 0){
	  deleteRoot(heap, 1);
	}

      }
    
    } else if (strcmp(inputtt, "P")==0){
      printTree(heap, 1, 0);
    } else if (strcmp(inputtt, "Q")==0){
      justKeepGoing = false;
    }

    
    
  }
    

  /*
    int inputt = 0;
    char* fileName = new char[80];
    cin >> fileName;
    cin.ignore();
    fstream file;
    file.open(fileName);
    while(file >> inputt){
      add(heap, inputt, indexon);
      indexon++;
    }
    file.close();
    
    //cin >> inputt;
    //cin.ignore();
    //add(heap, inputt, indexon);
    //indexon++;

    deleteRoot(heap, 1);
    
    cout << "-----------------------------------------------------------------" << endl;
    printTree(heap, 1, 0);
    cout << "-----------------------------------------------------------------" << endl;
  }
  

  printTree(heap, 1, 0);*/
}




void printTree(int* heap, int index, int depth){
  if(heap[1]==0){
    cout << "empty database" << endl;
    return;
  }

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


void add(int* &heap, int data, int index){
  if(index>1){
    heap[index] = data;
    int parentData = heap[index/2];
    if(data > parentData){
      heap[index/2] = data;
      heap[index] = parentData;
      add(heap, data, index/2);
    }
  } else {
    heap[index] = data;
  }
}


void deleteRoot(int* &heap, int index){
  int size = 1;
  while(heap[size] != 0){
    size++;
  }

  size = size-1;

  cout << "value: " << heap[1] << endl;
  heap[1] = heap[size];
  heap[size] = 0;

  int tempy = 1;
  while(heap[tempy] < heap[tempy * 2] || heap[tempy] < heap[tempy*2+1]){
    if(heap[tempy*2] > heap[tempy*2+1]){
      int temp = heap[tempy];
      heap[tempy] = heap[tempy*2];
      heap[tempy*2] = temp;
      tempy = tempy*2;
    } else if(heap[tempy*2] < heap[tempy*2+1]){
      int temp = heap[tempy];
      heap[tempy] = heap[tempy*2+1];
      heap[tempy*2+1] = temp;
      tempy = tempy*2;
    }
    
  }
  
}
