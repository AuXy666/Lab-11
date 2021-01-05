#include <iostream>
using namespace std;
string color[6] = { "red","green","blue","purple","green","yellow" };

int** input(int **array,int M,int N,int cols)
{
    array = new int* [M];
    for (int i = 0; i < M; ++i)
        array[i] = new int[cols];

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            while (1)
            {
                cin >> array[i][j];
                if (array[i][j] > N)
                {
                    cout << "Value Entered Greater then Given Vertices, Try Again" << endl;
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return array;
}
int** Directed_Graph(int **matrix,int**array,int M, int N)
{
    int x, y;
    matrix = new int* [N + 1];
    for (int i = 0; i < N + 1; ++i)
        matrix[i] = new int[N + 1];

    for (int i = 0; i < N + 1; i++)
    {

        for (int j = 0; j < N + 1; j++)
        {
            matrix[i][j] = 0;
        }
    }


    for (int i = 0; i < M; i++)
    {



        x = array[i][0];
        y = array[i][1];

        matrix[x][y] = 1;
        matrix[y][x] = 1;
    }
    cout << endl;
    cout << "Adjacency Matrix Created Successfully" << endl;
    return matrix;
}
int** UnDirected_Graph(int** matrix, int** array, int M, int N)
{
    int x, y;
    matrix = new int* [N + 1];
    for (int i = 0; i < N + 1; ++i)
        matrix[i] = new int[N + 1];

    for (int i = 0; i < N + 1; i++)
    {

        for (int j = 0; j < N + 1; j++)
        {
            matrix[i][j] = 0;
        }
    }


    for (int i = 0; i < M; i++)
    {



        x = array[i][0];
        y = array[i][1];

        matrix[x][y] = 1;
    }
    cout << endl;
    cout << "Adjacency Matrix Created Successfully" << endl;
    return matrix;
}
int** Weighted_Graph(int** matrix, int** array,int* weight, int M, int N)
{
    int x, y;
    matrix = new int* [N + 1];
    for (int i = 0; i < N + 1; ++i)
        matrix[i] = new int[N + 1];

    for (int i = 0; i < N + 1; i++)
    {

        for (int j = 0; j < N + 1; j++)
        {
            matrix[i][j] = 0;
        }
    }


    for (int i = 0; i < M; i++)
    {



        x = array[i][0];
        y = array[i][1];

        matrix[x][y] = weight[i];
        matrix[y][x] = weight[i];
    }
    cout << endl;
    cout << "Adjacency Matrix Created Successfully" << endl;
    return matrix;
}
int** Bipartite_Matrix(int** matrix, int** array, int M, int N)
{
    int x, y;
    matrix = new int* [N + 1];
    for (int i = 0; i < N + 1; ++i)
        matrix[i] = new int[N + 1];

    for (int i = 0; i < N + 1; i++)
    {

        for (int j = 0; j < N + 1; j++)
        {
            matrix[i][j] = 0;
        }
    }


    for (int i = 0; i < M; i++)
    {



        x = array[i][0];
        y = array[i][1];

        matrix[x][y] = 1;
        matrix[y][x] = 1;
    }
    cout << endl;
    cout << "Adjacency Matrix Created Successfully" << endl;
    bool checker = false;
    int colorCounter = 0;
    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < N + 1; j++)
        {

            if (matrix[i][j] == 1)
            {

                checker = true;
            }
            else
            {
                checker = false;
            }
        }
        if (checker == true)
        {
            colorCounter++;
        }
        cout << i << " " << color[colorCounter] << endl;
    }
    return matrix;
}
void print_adj_matrix(int**matrix,int M, int N)
{
    cout << endl;
    cout << "Following is the Required Adjacency Matrix" << endl;

    cout << "  | ";
    for (int i = 0; i < N + 1; i++)
    {
        cout << i << " | ";
    }
    cout << endl ;
    for (int i = 0; i < N + 1; i++)
    {
        cout << i << " | ";
        for (int j = 0; j < N + 1; j++)
        {
            

            cout << matrix[i][j] << "   ";
        }
        cout << endl;
    }
}

int main()
{

    int loopInput = 0;
    int N = 0, M = 0;
    int cols = 2;     
    int** array = NULL;
    int** matrix = NULL;
    int* weight = NULL;
    int x = 0, y = 0;
    while (1)
    {
        cout << "Press 1 to input Number of Vertices and Edges" << endl;
        cout << "Press 2 to Input edges" << endl;
        cout << "Press 3 to create UnDirected Graph's Adjacency matrix and print it " << endl;
        cout << "Press 4 to create Directed Graph's Adjacency matrix and print it " << endl;
        cout << "Press 5 to create Weighted Graph's Adjacency matrix and print it " << endl;
        cout << "Press 6 to create Non Weighted Graph's Adjacency matrix and print it " << endl;
        cout << "Press 7 to create Bipartite Graph's Adjacency matrix and print it " << endl;
        cout << "Press 8 to create Complete Graph's Adjacency matrix and print it " << endl;
        cout << "Press 9 to end" << endl;
        cin >> loopInput;
        if (loopInput == 1)
        {
            cout << "Enter Number of Vertices (0-N)= ";
            cin >> N;
            cout << "Enter Number of Edges = ";
            cin >> M;
        }
        else if (loopInput == 2)
        {
            
            array=input(array, M, N, cols);

        }
        else if (loopInput == 3)
        {

            matrix=Directed_Graph(matrix, array, M, N);
            print_adj_matrix(matrix, M, N);
        }
        else if (loopInput == 4)
        {

            matrix = UnDirected_Graph(matrix, array, M, N);
            print_adj_matrix(matrix, M, N);
        }
        else if (loopInput == 5)
        {
           
            weight = new int[M];
            cout << "Enter Weight for following edges" << endl;
            for (int i = 0; i < M; i++)
            {
                cout << array[i][0] << " "; 
                cout << array[i][1] << endl;
            }
            for (int i = 0; i < M; i++)
            {
                cin >> weight[i];
            }
            matrix = Weighted_Graph(matrix, array, weight, M, N);
            print_adj_matrix(matrix, M, N);
        }
        else if (loopInput == 6)
        {
            matrix = Directed_Graph(matrix, array, M, N);
            print_adj_matrix(matrix, M, N);
            
        }
        else if (loopInput == 7)
        {
            matrix = Bipartite_Matrix(matrix, array, M, N);
            print_adj_matrix(matrix, M, N);

        }
        else if (loopInput == 8)
        {
            matrix = Directed_Graph(matrix, array, M, N);
            print_adj_matrix(matrix, M, N);
        }

        else if (loopInput == 9)
        {
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
