#include <iostream>
#include <graphics.h>
#include <stdio.h>
using namespace std;
class Queue_operations
{
    public:
    int front1;
    int rear1;
    int queue1[200][2];
    Queue_operations()
    {
        front1 = 0;
        rear1 = 0;
    }
    void Add_queue(int item1,int item2)
    {
        if (rear1 >= 200)
        {
            cout<<"Queue is full";
        }
        else
        {
            queue1[rear1][0] = item1;
            queue1[rear1][1] = item2;
            rear1++;
        }
    }
    void Delete_queue(int *item)
    {
        if (front1 == rear1)
        {
            cout<<"Queue is empty";
        }
        else
        {
            item[0] = queue1[front1][0];
            item[1] = queue1[front1][1];
            queue1[front1][0] = 0;
            queue1[front1][1] = 0;
            front1++;
        }
    }
};
bool Shortest_path()
{
    int gd=DETECT;
    int gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");



    int m;
    int n;
    cout<<"Enter the row size of the maze : ";
    cin>>m;
    cout<<"Enter the column size of the maze : ";
    cin>>n;



    //creating maze in graphics.h
    for (int i=0 ; i<m+2 ; i++)
    {
        for (int j=0 ; j<n+2 ; j++)
        {
            rectangle(40 +i*40,40+j*40,80+i*40,80+j*40);
        }
    }






    //wall construction
    int GRID[m+2][n+2];
    for (int x=0 ; x<=m+1 ; x++)
    {
        GRID[0][x] = 1;
        GRID[m+1][x] = 1;
        setfillstyle(SOLID_FILL,DARKGRAY);
        floodfill(60,60+x*40,WHITE);
        if (m == 1)
        {
            floodfill(70*(m+1),70+x*40,WHITE);
        }
        else if (m == 2)
        {
            floodfill(55*(m+1),55+x*40,WHITE);
        }
        else if ((m>=3) && (m<=5))
        {
            floodfill(51*(m+1),51+x*40,WHITE);
        }
        else if ((m>=6) && (m<=10))
        {
            floodfill(47*(m+1),47+x*40,WHITE);
        }
    }
    for (int y=0 ; y<=n+1 ; y++)
    {
        GRID[y][0] = 1;
        GRID[y][n+1] = 1;
        setfillstyle(SOLID_FILL,DARKGRAY);
        floodfill(60+y*40,60,WHITE);
        if (n == 1)
        {
            floodfill(70+y*40,70*(n+1),WHITE);
        }
        else if (n == 2)
        {
            floodfill(55+y*40,55*(n+1),WHITE);
        }
        else if ((n>=3) && (n<=5))
        {
            floodfill(51+y*40,51*(n+1),WHITE);
        }
        else if ((n>=6) && (n<=10))
        {
            floodfill(47+y*40,47*(n+1),WHITE);
        }
    }







    //getting input from user if its a way or wall and displaying using grpahics.h
    cout<<"(Enter 0 for way and 1 for wall)\n"<<endl;
    for (int i=1 ; i<=m ; i++)
    {
        for (int j=1 ; j<=n ; j++)
        {
            cout<<"("<<i<<","<<j<<") : ";
            cin>>GRID[i][j];
            if (GRID[i][j] == 1)
            {
                setfillstyle(SOLID_FILL,DARKGRAY);


                int temp_i=0;
                if (i==1)
                    temp_i=70;
                else if (i==2)
                    temp_i = 55;
                else if ((i>=3) && (i<=5))
                    temp_i = 51;
                else if ((i>=6) && (i<=10))
                    temp_i = 47;


                int temp_j=0;
                if (j==1)
                    temp_j=70;
                else if (j==2)
                    temp_j = 55;
                else if ((j>=3) && (j<=5))
                    temp_j = 51;
                else if ((j>=6) && (j<=10))
                    temp_j = 47;


                floodfill(temp_j+j*40,temp_i+i*40,WHITE);
            }
        }
    }




    //creating object and initialising
    int offset[8][2] = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
    int here[2] = {1,1};
    int neighbour[2];
    GRID[1][1] = 2;
    Queue_operations Obj;





    //main logic
    while(true)
    {
        for (int i=0 ; i<=7 ; i++)
        {
            neighbour[0] = here[0] + offset[i][0];
            neighbour[1] = here[1] + offset[i][1];
            if (GRID[neighbour[0]][neighbour[1]] == 0)
            {


                GRID[neighbour[0]][neighbour[1]] = GRID[here[0]][here[1]] + 1;


                if ((neighbour[0] == m) && (neighbour[1] == n))
                {
                    break;
                }
                //cout<<"x";
                Obj.Add_queue(neighbour[0],neighbour[1]);
            }
        }
        if ((neighbour[0] == m) && (neighbour[1] == n))
        {
            break;
        }
        if (Obj.front1 == Obj.rear1)
        {
            return 0;
        }
        //cout<<"y";
        Obj.Delete_queue(here);
    }



    here[0] = m;
    here[1] = n;
    int pathlength = (GRID[m][n]-2);
    int path[pathlength+1][2];


    for (int i=pathlength ; i>=0 ; i--)
    {
        path[i][0] = here[0];
        path[i][1] = here[1];
        for (int j=0 ; j<=7 ; j++)
        {
            //cout<<"6";
            neighbour[0] = here[0] + offset[j][0];
            neighbour[1] = here[1] + offset[j][1];
            if (GRID[neighbour[0]][neighbour[1]] == (GRID[here[0]][here[1]] - 1))
            {
                break;
            }
        }


        here[0] = neighbour[0];
        here[1] = neighbour[1];
        //path[i][0] = here[0];
        //path[i][1] = here[1];
    }
    //path[0][0] = 1;
    //path[0][1] = 1;



    cout<<"Pathlength : "<<pathlength<<endl;
    cout<<"Path "<<endl;
    for (int i=0 ; i<pathlength+1 ; i++)
    {
        cout<<path[i][0]<<"\t"<<path[i][1]<<endl;
    }
    getch();
    closegraph();
    return 1;
}
int main()
{
    bool x = Shortest_path();
    if (x == 1)
    {
        cout<<"Shortest path is found";
    }
    else
    {
        cout<<"No path ";
    }
}
