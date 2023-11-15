void testDFS()
{
    graph_list g(5);
    g.addelement(0, 1);
    g.addelement(0, 2);
    g.addelement(1, 3);
    g.addelement(1, 4);
    g.addelement(2, 4);
    g.addelement(3, 5);
    g.addelement(4, 5);

    cout << "DFS traversal starting from vertex 0: ";
    g.DFS(0);
    // Expected output: 0 1 3 5 4 2

    cout << "DFS traversal starting from vertex 1: ";
    g.DFS(1);
    // Expected output: 1 0 2 4 5 3
}