/***************************************
 * ********Аннаев Арслан****************
 * ***ProblemSet4(Ш++) pset4/whounit.c**
 * ****Работа с пикселя файла  BMP******
 * *************************************
 * ************************************/

/**************************************
 * *****Разбор задания ****************
****1. Открыть входящий файл
****2. Создать новый файл 
****3. Считать структуру входящего файла
****4. Изменить необходимые пиксели
****5. записать измененую структуру в новый файл
****6. Закрыть оба файла
***********************************/
       
#include <stdio.h>                  // стандартная библиотека ввода вывода
#include <stdlib.h>                 // библиотека для abs()
#include "bmp.h"                    // заголовок структуры BMP                                     
int main(int argc, char *argv[])
{
    // если вызов программы не имеет 4 аргументов 
    if (argc != 3) {                                                 
        fprintf(stderr, "Usage: ./copy infile outfile\n");          // инсрукция по вызову программы
        return 1;
    }

   
    char *infile = argv[1];                     // имя файла для считывания
    char *outfile = argv[2];                    // имя файла для записи

//===================================================================================================   
    FILE *inptr = fopen(infile, "r");           // создаем обьект файла для считывания 
    if (inptr == NULL)    {                     // если указатель пустой
        printf("Could not open %s.\n", infile); // сообщение пользователю
        return 2;
    }
    
    FILE *outptr = fopen(outfile, "w");         // создаем обьект файла для записи 
    if (outptr == NULL){                        // если указатель пустой
        fclose(inptr);                          // закрыть входящий файл
        printf( "Could not create\n");          // сообщение пользователю
        return 3;
    }
//===================================================================================================

    BITMAPFILEHEADER bf;                        // информация о заголовке файла
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr); // считывание заловка файла
    BITMAPINFOHEADER bi;                        // мета информация файла
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr); // считывание информации файла
   
    // уточняем версию BMP
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
//===================================================================================================

    
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr); // запись заголовочной информации в исходящий файл 
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr); // запись мета информации в исходящий файл 
    
    // отступ для поддержки формата BMP
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
//===================================================================================================
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            RGBTRIPLE triple;                               // временная структура для считывания и запис
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);    // считываем с входящего файла

            if (triple.rgbtRed == 0xff&& triple.rgbtBlue==0x00 && triple.rgbtGreen==0x00 )
            {
              triple.rgbtGreen =0xff;       // меняем значение элемента пикселя 
              triple.rgbtBlue =0xff;        // меняем значение элемента пикселя
              triple.rgbtRed=0xff;          // меняем значение элемента пикселя
            }
         
            // записываем измененую структуру в исходящий файл
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }

        // не учитывать отступы и возвращать указатель на новую строку(высоты файла)
        fseek(inptr, padding, SEEK_CUR);

        // добавляем количества нулей для сохранения формата 
        for (int k = 0; k < padding; k++){
            fputc(0x00, outptr);
        }
    }
//===================================================================================================
    fclose(inptr);      // закрытие входящего файла
    fclose(outptr);     // закрытие исходящего файла
    return 0;
}
//===================================================================================================
