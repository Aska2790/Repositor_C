/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * 1
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];


// dimensions
int d;


// prototypes
void clear(void);
void greet(void);
void init();
void draw(void);
bool move(int tile);
bool won();
bool checkTile(int a, int b);


//====================================================================================


int main(int argc, string argv[])
{
                                                // проверка корректности вызова программы
    if (argc != 2)                              // если кол. аргументов больше 2
    {
        printf("Usage: fifteen d\n");           // инструкция ввода
        return 1;
    }
                                                // проверка правильности заданного размера 
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)             // значение должно быть в интервале [3 ,9]
    {                                           // инструкция ввода
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();
    
    // initialize the board
    init();
    
    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}


//====================================================================================

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}
//====================================================================================
/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

//====================================================================================

// инициализация матрицы начиная с верхнего левого угла
void init()
{
    int iter = d*d;                     // получаем количество элементов в матрице для итерации 
    iter -= 1;                          // отсчет с нуля поэтому 3*3=9  (0-8)
    
    for(int i = 0; i < d; i++) {        // проход по всем элементам матрицы
        for(int j = 0; j < d; j++) {
           board[i][j] = iter;          // значения итератора присваиваем матрице
           iter--;                      // декремент итератора
        }
    }
    
    if (d % 2 == 0) {                   // для матрицы с четным количеством ячеек 
        board[d-1][d-2] = 2;            // меняем значения 1 и 2 местами
        board[d-1][d-3] = 1;
    }
}
   

//====================================================================================

/** * Prints the board in its current state.*/
void draw()
{
    for(int i =0; i < d; i++){              // проход по всем элементам матрицы
        for(int j =0; j < d; j++)
            printf( "| %2d |",board[i][j]); // вывод в консоль
        printf( "\n\n");
    }
}

//====================================================================================
/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    for(int i =0; i < d; i++)           // проход по всем элементам матрицы
        for(int j =0; j < d; j++)
            if(board[i][j]==tile)       // находим значение введенное пользователем
                if( checkTile(i,j)){    // находим есть ли в окружении ноль(пустая ячейка)
                    return true;        
                }
    return false;
}

//====================================================================================
/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won()
{
    // для победы нужно что бы все элементы были расположены
    // с левого верхнего угла по возрастанию
    
    int iter = 0;                       // итератор  
    for(int i = 0; i < d; i++){         // проход по всем элементам матрицы
        for(int j = 0; j < d; j++){
            if (iter == (d*d)-1)        // пропускаем последнюю ячейку
                continue;
            iter++;             
            if (!(board[i][j] ==iter) ){// сравниваем значения матрицы   
                return false;           // с требуемым значением итератора
            }
        }   
    }
    return true;
}
//====================================================================================
bool checkTile(int a, int b)
{
    
    if (board[a][b+1] == 0 && (b+1 < d)) {  // проверяем есть ли пустое место (ноль) с права
       
        board[a][b+1] = board[a][b];        // перемещаем это значение на место нуля  
        board[a][b] = 0;                    // а ноль на место предыдущего значения
            return true; 
    }
    
    if (board[a][b-1] == 0 && (b-1 >= 0)){  // проверяем есть ли пустое место (ноль) с права
        board[a][b-1] = board[a][b];        // перемещаем это значение на место нуля 
        board[a][b] = 0;                    // а ноль на место предыдущего значения
        return true;
    }
    
    if (board[a+1][b] == 0 && (a+1 < d)){   // проверяем есть ли пустое место (ноль) с права
        board[a+1][b] = board[a][b];        // перемещаем это значение на место нуля 
        board[a][b] = 0;                    // а ноль на место предыдущего значения
        return true; 
    }
    
    if (board[a-1][b] == 0 && (a-1 >=0)){   // проверяем есть ли пустое место (ноль) с права
        board[a-1][b] = board[a][b];        // перемещаем это значение на место нуля 
        board[a][b] = 0;                    // а ноль на место предыдущего значения
        return true; 
    }
    
     return false;                          // если нет пустого места (нуля) то возвращает false
}
//====================================================================================
