#include <iostream>
#include <string>
#include "graph.h"
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

void Graph::LoadMatrix(string &filename)
{
    ifstream is;
    is.open(filename); //파일 open
    is >> num;
    weight = new int *[num];
    for (int i = 0; i < num; i++)
        weight[i] = new int[num];
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            is >> weight[i][j];
        }
    }
    is.close();
}
void Graph::PrintMatrix()
{

    for (int i = 0; i < num; i++)
    {
        if (i != 0)
            cout << endl;
        for (int j = 0; j < num; j++)
            cout << weight[i][j] << " ";
    }
}
int Graph::GetSize()
{
    return num;
}

int Graph::shortn()
{
    int mini = 1000;
    int index;
    for (int i = 0; i < num; i++)
    { //최단거리 노드 탐색
        if (mini > dist[i] && in[i] != true)
        {
            mini = dist[i];
            index = i;
        }
    }
    return index;
}

void Graph::Makedist(int s)
{
    dist = new int[num];
    int u, w;
    in = new bool[num];
    dist[s] = 0; /

    for (int i = 0; i < num; i++)
    {
        in[i] = false;
    }

    for (int i = 0; i < num; i++)
    {
        dist[i] = weight[s][i];
    }
    // in[minin]=true; //최단거리 노드 true로 바꿈
    for (int i = 0; i < num; i++)
    {
        int shortnode = shortn();
        // cout<<shortnode<<endl;
        in[shortnode] = true;
        for (int i = 0; i < num; i++)
        {
            if (in[i] != true)
                dist[i] = min(dist[i], dist[shortnode] + weight[shortnode][i]);
        }
    }
}

void Graph::PrintShortestPathWeight(int s)
{
    dist = new int[num];
    int u, w;
    in = new bool[num];
    dist[s] = 0;

    for (int i = 0; i < num; i++)
    {
        in[i] = false;
    }

    for (int i = 0; i < num; i++)
    {
        dist[i] = weight[s][i];
    }
    // in[minin]=true; //최단거리 노드 true로 바꿈
    for (int i = 0; i < num; i++)
    {
        int shortnode = shortn();
        // cout<<shortnode<<endl;
        in[shortnode] = true;
        for (int i = 0; i < num; i++)
        {
            if (in[i] != true)
                dist[i] = min(dist[i], dist[shortnode] + weight[shortnode][i]);
        }
    }

    for (int i = 0; i < num; i++)
        cout << dist[i] << endl;
}

void Graph::PrintShortestPath(int s)
{

    dist = new int[num];
    int u, w;
    in = new bool[num];
    dist[s] = 0;
    // vector<int> v;
    vector<int> v[num];
    for (int w = 0; w < num; w++)
    {
        for (int k = 0; k < num; k++)
        {
            for (int i = 0; i < num; i++)
            {
                in[i] = false;
            }

            for (int i = 0; i < num; i++)
            {
                dist[i] = weight[s][i];
            }

            for (int i = 0; i < num; i++)
            {
                int shortnode = shortn();
                in[shortnode] = true;
                v[k].push_back(shortnode);
                
                    for (int i = 0; i < num; i++)
                    {
                        if (in[i] != true)
                        {
                            if (dist[i] > dist[shortnode] + weight[shortnode][i])
                            {
                                dist[i] = dist[shortnode] + weight[shortnode][i];
                            }
                        }
                    }
            }
        }
    }
    for (int i = 1; i < num; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main(void)
{
    Graph g;

    string filename;
    getline(cin, filename);

    g.LoadMatrix(filename);
    g.PrintShortestPath(0);

    return 0;
}