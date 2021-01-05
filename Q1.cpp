#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;
};

class linklist
{
public:
    node* head;
    linklist()
    {
        head = NULL;
    }

    void push(int key)
    {
        node* temp = new node;
        temp->data = key;
        temp->next = head;
        head = temp;
    }
    void display()
    {
        node* temp = new node;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

};

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
int** Adj_Matrix(int **matrix,int**array,int M, int N)
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

linklist* Adj_List(int** matrix, int N)
{
    linklist* l = NULL;
    l = new linklist[N + 1];
    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < N + 1; j++)
        {
            if (matrix[i][j] == 1)
            {
                l[i].push(j);
            }
        }
    }
    cout << endl;
    cout << "Adjacency List Created Successfully" << endl;
    return l;
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

void print_adj_list(linklist *l,int N)
{
    cout << endl;
    cout << "Following is the Required Adjacency List" << endl;
    for (int i = 0; i < N + 1; i++)
    {
        cout << i << "| ";
        l[i].display();
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
    linklist* l = NULL;
    int x = 0, y = 0;
    while (1)
    {
        cout << "Press 1 to input Number of Vertices and Edges" << endl;
        cout << "Press 2 to Input edges" << endl;
        cout << "Press 3 to create Adjacency matrix " << endl;
        cout << "Press 4 to create Adjacency List" << endl;
        cout << "Press 5 to print Adjacency matrix" << endl;
        cout << "Press 6 to print Adjacency List" << endl;
        cout << "Press 7 to end" << endl;
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

            matrix=Adj_Matrix(matrix, array, M, N);
        }
        else if (loopInput == 4)
        {

            l =Adj_List(matrix, N);
        }
        else if (loopInput == 5)
        {
           
            print_adj_matrix(matrix, M, N);
        }
        else if (loopInput == 6)
        {

            print_adj_list(l,N);
        }

        else if (loopInput == 7)
        {
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}

