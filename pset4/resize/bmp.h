/**
 * BMP-related data types based on Microsoft's own.
 */

#include <stdint.h>


typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;
typedef uint16_t WORD;


 */
typedef struct 
{ 
    WORD bfType;            // Разметка БМП формата
    DWORD bfSize;           // Размер файла в байтах.
    WORD bfReserved1;       // Зарезервированы и должны содержать ноль.
    WORD bfReserved2;       // Зарезервированы и должны содержать ноль.
    DWORD bfOffBits;        // Положение пиксельных данных относительно начала данной структуры (в байтах).
} __attribute__((__packed__)) 
BITMAPFILEHEADER; 

typedef struct
{
    DWORD biSize;           // Размер данной структуры в байтах, указывающий также на версию структуры
    LONG biWidth;           // Ширина растра в пикселях. Указывается целым числом со знаком. Ноль и отрицательные не документированы.
    LONG biHeight;          // Целое число со знаком, содержащее два параметра: высота растра в пикселях (абсолютное значение числа)
                            // и порядок следования строк в двумерных массивах (знак числа). Нулевое значение не документировано. 
    WORD biPlanes;          //	В BMP допустимо только значение 1. Это поле используется в значках и курсорах Windows.
    WORD biBitCount;        // Количество бит на пиксель
    DWORD biCompression;    //	Указывает на способ хранения пикселей 
    DWORD biSizeImage;      // Размер пиксельных данных в байтах. Может быть обнулено если хранение осуществляется двумерным массивом
    LONG biXPelsPerMeter;   // Количество пикселей на метр по горизонтали и вертикали 
    LONG biYPelsPerMeter; 
    DWORD biClrUsed;        // Размер таблицы цветов в ячейках.
    DWORD biClrImportant;   // Количество ячеек от начала таблицы цветов до последней используемой
} __attribute__((__packed__))
BITMAPINFOHEADER; 


typedef struct
{
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;
