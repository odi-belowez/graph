
#include <stdio.h>
#include <set>
#include "graph.h"

// A vertexes color is the indication of it's component
void dfs(std::vector<std::vector<int>>& matrix, std::vector<int>& colors, int v, int c) {
    colors[v] = c;
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[v][i] && !colors[i]) {
            dfs(matrix, colors, i, c);
        }
    }
}

int main()
{
    Graph g;
    //g.LoadForTest1();
    // g.LoadForTest2();
    //g.LoadForTest3();  // contains cycle
    g.LoadForTest4();  // contains cycle
    //g.LoadForTest5();

    g.Print(stdout, "initial graph\n");

    // solve you problem here
    FILE* test = fopen("output.txt", "w");
    std::vector<std::vector<int>> matrix = g.getUnorientedMatrix();
    std::vector<int> colors(matrix.size(), 0);
    int currcol = 1;
    for (int i = 0; i < matrix.size(); i++) {
        if (!colors[i]) {
            dfs(matrix, colors, i, currcol++);
        }
    }
    std::set<int> starts = g.startIds();
    fprintf(test, "%d components \n", currcol - 1);
    for (int i = 1; i < currcol; i++) {
        fprintf(test, "The id's of the  start vertices in the %d component:\n", i);
        for (int j = 0; j < colors.size(); j++) {
            if (colors[j] == i && starts.count(j + 1)) {
                fprintf(test, "%d ", j + 1);
            }
        }
        fprintf(test, "\n");
    }
    fclose(test);
    return 0;
}
