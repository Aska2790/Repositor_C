/***************************************
 * ********Аннаев Арслан****************
 * ***ProblemSet4(Ш++) pset4/resize.c**
 * **Увеличение размера файла BMP******
 * *************************************
 * ************************************/

/**************************************
 * *****Разбор задания ****************
****1. Открыть входящий файл
****2. Создать новый файл 
****3. Увеличить значения заголовков на n
****4. Обновить информацию заголовков в исходящем файле
****5. Переписать увеличеную матрицу файла в новый файл
****6. Закрыть оба файла
***********************************/
       
#include <stdio.h>          // стандартная библиотека ввода вывода
#include <stdlib.h>         // библиотека для atoi() abs()
#include "bmp.h"            // заголовок структуры BMP

//===================================================================================================

int main(int argc, char *argv[])
{
    // если вызов программы не имеет 4 аргументов 
    if (argc != 4 )
    {
        printf("Usage: ./resize n infile outfile \n");  // инсрукция по вызову программы
        return 1;
    }

    int num =  atoi(argv[1]);           // размер шага для увеличения 
    char *infile =  argv[2];            // имя источник
    char *outfile = argv[3];            // имя конечный файл

    if (num  > 100)
    {
        printf(" must n < 100\n");
        return 1;
    }
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
    
    BITMAPFILEHEADER bf, bf_copy;                       // информация о заголовке файла
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);     // считывание заловка файла
    BITMAPINFOHEADER bi, bi_copy;                       // мета информация файла
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);     // считывание информации файла
   
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
    
    bf_copy = bf;                               // копируем заголовки
    bi_copy = bi;                               // копируем мета информацию

    bi_copy.biWidth = bi.biWidth*num;           // увеличиваем ширину исходящего файла
    bi_copy.biHeight =bi.biHeight*num;          // увеличиваем высоту исходящего файла
    
    // отступ для кратности 4-м (требования формата)
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;           // старое значение для входящего файла
    int padding_copy = (4 - (bi_copy.biWidth * sizeof(RGBTRIPLE)) % 4) % 4; // новое значение для исходящего файла

    // меняем значения заголовком нового файла
    bi_copy.biSizeImage = abs(bi_copy.biHeight)*(bi_copy.biWidth*sizeof(RGBTRIPLE) + padding_copy);
    bf_copy.bfSize = (bf.bfSize - bi.biSizeImage)+ bi_copy.biSizeImage;  
    
    fwrite(&bf_copy, sizeof(BITMAPFILEHEADER), 1, outptr);  // запись в исходящий файл заголовка файла
    fwrite(&bi_copy, sizeof(BITMAPINFOHEADER), 1, outptr);   // запись в исходящий файл информации о файле

//===================================================================================================    
    // проход по входящему файлу (по всей высоте входящего файла)
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // повторяем на коэфициент увеличения, цикл для копирования scanline
        for(int f =1; f <= num; f++)
        {
            // проходим по всей ширине входящего файл
            for (int j = 0; j < bi.biWidth; j++)
            {
                RGBTRIPLE triple;                               // временная структура для считывания и запис
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);    // считываем с входящего файла
                
                for(int k =0; k <num; k++)              // повторяем на коэфициент увеличения, цикл для копирования структуры
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
            
            // добавляем количества нулей для сохранения формата 
            for (int l = 0; l < padding_copy; l++)
                fputc(0x00, outptr);
            
            
            if (f < num)     // последняя итерация не возвращает указатель
            // возвращаем указатель на начало scanline
            fseek(inptr, -bi.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);
        }
        // не учитывать отступы и возвращать указатель на новую строку(высоты файла)
        fseek(inptr, padding, SEEK_CUR);
    }
//===================================================================================================
    fclose(inptr);      // закрытие входящего файла
    fclose(outptr);     // закрытие исходящего файла
    return 0;
}
//===================================================================================================