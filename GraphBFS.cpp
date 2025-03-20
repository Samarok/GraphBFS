#include <iostream>
#include <vector>
#include <deque>
#include <fstream>

void BFS(std::vector <std::vector <int>> graph, std::vector <int> &distance, int start) //функция для обхода в ширену
{
    std::deque <int> queue; //очередь для последовательного обхода соседей
    queue.push_back(start);
    while (queue.size() != 0)
    {
        for (int i = 0; i < graph[queue[0]].size(); i++)
        {
            if (distance[graph[queue[0]][i]] == -1)
            {
                queue.push_back(graph[queue[0]][i]);
                distance[graph[queue[0]][i]] = distance[queue[0]] + 1;
            }
        }
        queue.pop_front();
    }
}

int main()
{
    int count_vert, count_edg, start_vert;  //кол-во вершин, кол-во рёбер, стартовая точка для обхода
    std::ifstream input("graph.txt");   //считывание граффа из файла "graph.txt"
    input >> count_vert >> count_edg;
    std::vector <std::vector <int>> graph(count_vert);  //vector для сохранения графа
    std::vector <int> distance(count_vert, -1); //vector для сохрание растояния то start_vert до каждой вершины

    int a, b;
    for (int i = 0; i < count_edg; i++) //заполнение graph
    {
        input >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    input >> start_vert;
    distance[start_vert] = 0;

    BFS(graph, distance, start_vert);

    for (int i = 0; i < count_vert; i++) std::cout << distance[i] <<"\n";
}
