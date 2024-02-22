//Author: Michael Fu
//date:
//description: this program creates a max heap that can input from both files and the command line

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;


//function prototypes
void printTree(int* heap, int index, int depth);
void add(int* &heap, int data, int index);
void deleteRoot(int* &heap, int index);


int main(){
  //create the heap and other variables
  int* heap = new int[100];
  char inpt[15];
  int indexon = 1;
  bool justKeepGoing = true;
  

  
  while(justKeepGoing == true){
    //ask for what they want to do and input it into inputtt
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "What do you want to do? Add(A), Delete(D), Print(P), and Quit(Q)" << endl;
    char* inputtt = new char[20];
    cin >> inputtt;
    cin.ignore();
    int num = 0;
    
    if(strcmp(inputtt, "A")==0){
      //if they input, A, then ask for if they want to add manually or by file
      cout << "Manually(M) or from File(F)" << endl;
      cin >> inputtt;
      cin.ignore();
      if(strcmp(inputtt, "M")==0){

	//if they want manually, input what number they want to enter, then find what index is the next empty spot (size)
	cout << "what number to enter?" << endl;
	cin >> num;
	cin.ignore();
	int size = 1;
	while(heap[size] != 0){
	  size++;
	}
	//then call the add function with the heap, the number they want to add, and the size (index of the next empty spot)
	add(heap, num, size);
      } else if(strcmp(inputtt, "F")==0){
	//if they want to use a file to input numbers, ask for the file name and open an fstream file and loop through the file, calling the add function each time with the same logic as the maually adding a number.
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
	//close the file
	file.close();
      }
    } else if (strcmp(inputtt, "D")==0){
      //if they wanted to delete, ask if they want to delete the largest element (root) or everything
      cout << "just delete the largest element(L) or everything(E)" << endl;
      cin >> inputtt;
      cin.ignore();
      if(strcmp(inputtt, "L")==0){
	//if they want to delete the largest one, just call the deleteRoot function once
	deleteRoot(heap, 1);
      } else if (strcmp(inputtt, "E")==0){
	//otherwise, while the heaps first element isn't zero, repeatedly call the deleteRoot function
        while(heap[1] != 0){
	  deleteRoot(heap, 1);
	}

      }
    
    } else if (strcmp(inputtt, "P")==0){
      //if they put P, then call the print function
      printTree(heap, 1, 0);
    } else if (strcmp(inputtt, "Q")==0){
      //if they put Q, then set justKeepGoing to false
      justKeepGoing = false;
    }

    
    
  }
    
}



//print the tree function
void printTree(int* heap, int index, int depth){
  if(heap[1]==0){
    //if the database is empty, print so
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
  //add some symbols in there to make the tree easy to follow
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


//for the add function, if the temporary given index is greater than 0, then set the value at the temporary index to data. then get the value for the data of the parent node and if it's bigger, then swap the two and recursively call the function with the new index of the data we want to add. If the index does equal 1, then we are at the node and set that value to the data.
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


//for the delete root function, find the index of the last element. Then subtract 1 from it because we are removing 1 of the values (root). Then, set the biggest element to the last element in the list, and set the position of where the last elemtn was to 0. then, while one of the nodes children is larger, then swap it with the larger one and keep going until the tree is resorted. 
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
