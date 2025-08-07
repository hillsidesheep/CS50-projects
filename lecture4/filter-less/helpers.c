#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Return the min
int min(int a, int b)
{
    return (a < b) ? a : b;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int rgbtRed =  round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int rgbtGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int rgbtBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            image[i][j].rgbtRed = min(rgbtRed, 255);
            image[i][j].rgbtGreen = min(rgbtGreen, 255);
            image[i][j].rgbtBlue = min(rgbtBlue, 255);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        RGBTRIPLE temp [width];

        for (int j = 0; j < width; j++)
        {
            temp[j] = image[i][j];
        }

        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[width - j - 1];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    // 遍历每个像素
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            int count = 0;  // 记录有效邻域像素的数量

            // 遍历3x3邻域
            for (int di = -1; di <= 1; di++)
             {  // di：行偏移（-1, 0, +1）
                int ni = i + di;  // 邻域像素的行坐标
                for (int dj = -1; dj <= 1; dj++)
                 {  // dj：列偏移（-1, 0, +1）
                    int nj = j + dj;  // 邻域像素的列坐标

                    // 检查邻域像素是否在图像范围内
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        // 累加每个通道的值
                        sumRed += copy[ni][nj].rgbtRed;
                        sumGreen += copy[ni][nj].rgbtGreen;
                        sumBlue += copy[ni][nj].rgbtBlue;
                        count++;  // 有效像素数量+1
                    }
                }
            }

            // 计算平均值（四舍五入到整数）
            image[i][j].rgbtRed = round((float)sumRed / count);
            image[i][j].rgbtGreen = round((float)sumGreen / count);
            image[i][j].rgbtBlue = round((float)sumBlue / count);
        }
    }
    return;
}
