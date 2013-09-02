#include <stdio.h>
#define RED 0
#define GREEN 1
#define BLUE 2

void rotate(int image[200][200][3],
           int* x,
           int* y,
           int* max);
int main()
{
    int x, y, max;
    int image[200][200][3];
    rotate(image,
           &x,
           &y,
           &max);
    return 0;    
}
void rotate(int image[200][200][3],
           int* x,
           int* y,
           int* max)
{
    int temp;
    int image_out[*x][*y][3];
    int currentx, currenty, channel = 0;
    FILE *pFile = fopen("image.ppm", "r");
    fseek(pFile, 3, SEEK_SET);
    fscanf(pFile, "%d", x);
    fscanf(pFile, "%d", y);
    fscanf(pFile, "%d", max);
    for (currentx = 0; currentx < *x; currentx++){
        for (currenty = 0; currenty < *y; currenty++){
            for (channel = 0; channel < 3; channel++){
                
                 image_out[currenty][currentx][channel] = fscanf(pFile,"%d", &temp); //rotating image
             }
        }
    }
    for (currentx = 0; currentx < *x; currentx++){
        for (currenty = 0; currenty < *y; currenty++){
            for (channel = 0; channel < 3; channel++){
                
                 image_out[currenty][currentx][channel] = image[currentx][currenty][channel]; //rotating image
             }
        }
    }
    fclose(pFile);
    //writing file

    pFile = fopen("output.ppm", "w");

    fprintf(pFile, "P3\n"); //write p3
    fprintf(pFile, "%d  %d\n", *x, *y);
    fprintf(pFile, "%d\n", *max);
    
    
    for (currentx = 0; currentx < *x; currentx++){
        for (currenty = 0; currenty < *y; currenty++){
            for (channel = 0; channel < 3; channel++){
                 if(channel == 2){
                     fprintf(pFile, "%d\n", image_out[currentx][currenty][channel]);
                 }
                 fprintf(pFile, "%d ", image_out[currentx][currenty][channel]);
            }
        }
    }
    
   fclose(pFile);
}
