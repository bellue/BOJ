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
void LoadMatrix(std::string& filename);//����ġ��� �о ��������� ����
void PrintMatrix();// ������� ���
int GetSize(); //����� ũ�� ��ȯ
void PrintShortestPathWeight(int s); //���� ���� s�κ��� ������ vertex������ �ִ� ��� ���
int shortn();
void PrintShortestPath(int s);   
void Makedist(int s);            // ���� ���� s�κ��� ������ vertex������ �ִ� ��� ���
};