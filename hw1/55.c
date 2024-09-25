#include <stdio.h>
#include <stdlib.h>

/* Function to simulate the movement of the two robots 
and detect if they collide
*/
void simulate(int M, int N, int X1, int Y1, int E1, int N1, int F1, 
              int X2, int Y2, int E2, int N2, int F2){
        
    int time = 0;

    // movement counter for each robot
    int r1_north_steps = 0, r1_east_steps = 0;
    int r2_north_steps = 0, r2_east_steps = 0;

    int initial_X1 = X1, initial_Y1 = Y1;
    int initial_X2 = X2, initial_Y2 = Y2;

    while (F1 > 0 || F2 > 0){
        if (X1 == X2 && Y1 == Y2){
            printf("robots explode at time %d\n", time);
            return;
        }

        // Move first robot 1 step
        if (F1 > 0){
            if (r1_north_steps < N1){
                Y1 = (Y1 + 1) % N;
                r1_north_steps++;
            } else if (r1_east_steps < E1){
                X1 = (X1 + 1) % M;
                r1_east_steps++;
            } 

            if (r1_north_steps == N1 && r1_east_steps == E1){
                r1_north_steps = 0;
                r1_east_steps = 0;
            }

            F1--; // decrease one unit of fuel (F1)
        }

        // Move second robot 1 step
        if (F2 > 0){
            if (r2_east_steps < E2){
                X2 = (X2 + 1) % M;
                r2_east_steps++;
            } else if (r2_north_steps < N2){
                Y2 = (Y2 + 1) % N;
                r2_north_steps++;
            }

            if (r2_north_steps == N2 && r2_east_steps == E2){
                r2_north_steps = 0;
                r2_east_steps = 0;
            }

            F2--; // decrease one unit of fuel (F2)
        }

        // Increment time step
        time++;

        if (X1 == X2 && Y1 == Y2){
            printf("robots explode at time %d\n", time);
            return;
        }
    }

    // If the loop ends without a collision
    printf("robots will not explode\n");
}

int main()
{
    int M, N;
    int X1, Y1, E1, N1, F1;
    int X2, Y2, E2, N2, F2;

    scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &M, &N, &X1, &Y1, &E1, &N1, &F1, &X2, &Y2, &E2, &N2, &F2);
    simulate(M, N, X1, Y1, E1, N1, F1, X2, Y2, E2, N2, F2);

    return 0;
}