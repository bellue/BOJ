#include <iostream>
#include <string.h>
#include <fstream>


class Graph{
public:

int bef;
bool* in;
int num;
int **weight;
int *dist;
int **load;
void LoadMatrix(std::string& filename);//가중치행렬 읽어서 멤버변수로 저장
void PrintMatrix();// 인접행렬 출력
int GetSize(); //행렬의 크기 반환
void PrintShortestPathWeight(int s); //시작 정점 s로부터 나머지 vertex까지의 최단 경로 출력
int shortn();
void PrintShortestPath(int s);   
void Makedist(int s);            // 시작 정점 s로부터 나머지 vertex까지의 최단 경로 출력
};