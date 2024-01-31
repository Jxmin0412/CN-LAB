#include <stdio.h>

int main()
{
    int count, src_router, i, j, k, w, v, min;
    int cost_matrix[100][100], dist[100], last[100];
    int flag[100]; // visted ? 1:0

    // Input: Number of routers, cost matrix, and source router
    printf("\nEnter the number of routers: ");
    scanf("%d", &count);

    printf("\nEnter the cost matrix values:\n");
    for (i = 0; i < count; i++)
    {
        for (j = 0; j < count; j++)
        {
            scanf("%d", &cost_matrix[i][j]);
            // Handling negative values in the cost matrix
            if (cost_matrix[i][j] < 0)
                cost_matrix[i][j] = 1000; // Assume a large positive value for simplicity
        }
    }

    printf("\nEnter the source router: ");
    scanf("%d", &src_router);

    // Initialization
    for (v = 0; v < count; v++)
    {
        flag[v] = 0;
        last[v] = src_router;
        dist[v] = cost_matrix[src_router][v];
    }

    flag[src_router] = 1;

    // Dijkstra's Algorithm
    for (i = 0; i < count; i++)
    {
        min = 1000; // Initialize to a large positive value

        // Find the unvisited router with the minimum distance
        for (w = 0; w < count; w++)
        {
            if (!flag[w])
            {
                if (dist[w] < min)
                {
                    v = w;
                    min = dist[w];
                }
            }
        }

        // Mark the selected router as visited
        flag[v] = 1;

        // Update distances and last routers for adjacent routers
        for (w = 0; w < count; w++)
        {
            if (!flag[w])
            {
                if (min + cost_matrix[v][w] < dist[w])
                {
                    dist[w] = min + cost_matrix[v][w];
                    last[w] = v;
                }
            }
        }
    }

    // Output: Print shortest paths and their costs
    for (i = 0; i < count; i++)
    {
        printf("\n%d ==> %d: Path taken: %d", src_router, i, i);
        w = i;

        // Print the path taken
        while (w != src_router)
        {
            printf(" <-- %d", last[w]);
            w = last[w];
        }

        printf("\nShortest path cost: %d", dist[i]);
    }

    return 0;
}

/*
Expected output
---------------

Enter the number of routers: 4

Enter the cost matrix values:
1 2 3 4
1 0 2 3
1 2 0 7
1 2 3 0

Enter the source router: 1

1 ==> 0: Path taken: 0 <-- 1
Shortest path cost: 1
1 ==> 1: Path taken: 1
Shortest path cost: 0
1 ==> 2: Path taken: 2 <-- 1
Shortest path cost: 2
1 ==> 3: Path taken: 3 <-- 1
Shortest path cost: 3%
*/