#include <GL/glut.h>
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

// Global variables
const int N = 380;
int vec[N], compares, exchanges;
string sortName;

// File containting the alogrithms
#include "algorithm.h"

void initGL(){

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

}

void display(){

  visual(vec);
  int arr[N];
  sortName = "selection sort";
  compares = 0, exchanges = 0;
  for (int i = 0; i < N; i++)
    arr[i] = vec[i];
  selectionSort sel(arr, N);
  sleep(1);

  compares = 0, exchanges = 0;
  sortName = "shell sort";
  for (int i = 0; i < N; i++)
    arr[i] = vec[i];
  shellSort shell(arr, N);
  sleep(1);

  compares = 0, exchanges = 0;
  sortName = "quick sort";
  for (int i = 0; i < N; i++)
    arr[i] = vec[i];
  quickSort quick(arr, N);
  sleep(1);

  compares = 0, exchanges = 0;
  sortName = "merge sort";
  for (int i = 0; i < N; i++)
    arr[i] = vec[i];
  mergeSort merge(arr, N);
  sleep(1);
  
  compares = 0, exchanges = 0;
  sortName = "insertion sort";
  for (int i = 0; i < N; i++)
    arr[i] = vec[i];
  insertionSort sort(arr, N);
  sleep(1);

}

void visual(int *arr){

  glClear(GL_COLOR_BUFFER_BIT); 
  drawBitmapString(700, 770, sortName);
  drawBitmapString(700, 750, "Number of Comparisons:" + to_string(compares));
  drawBitmapString(700, 730, "Number of Exchanges:" + to_string(exchanges));
  glColor3f(0.0f, 1.0f, 0.0f); // green

  // drawing bars 
  for (int i = 0; i < N; i++){
    glRecti(4 * i, 100, 4 * i + 3, 100 + arr[i]);
  }
  
  glFlush();
  usleep(150);
  
}

void drawBitmapString(float x, float y, string s){

  glColor3f(1.0f, 1.0f, 1.0f); // sets color of the text
  glRasterPos2f(x, y);         // screen coordinate at which text will appear
  int length = s.size();

  // writing charater by charater on the screen
  for (int i = 0; i < length; i++){
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
  }

}


int main(int argc, char **argv){

  // Generating random array
  srand((unsigned)time(0));
  for (int i = 0; i < N; i++){
    vec[i] = (rand() % 600);
  }

  glutInit(&argc, argv);                    
  glutInitWindowSize(1536, 864);            
  glutCreateWindow("Algorithm Visualizer"); 
  glutInitWindowPosition(0, 100);           
  glutDisplayFunc(display);                 
  initGL();                                 // initializing GL
  gluOrtho2D(0, 1536, 0, 864);              
  glutMainLoop();                           // infinite loop which will run till the visualizer program ends

  return 0;
}