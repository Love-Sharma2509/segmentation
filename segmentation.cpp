

#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;

int sobx[3][3] = {{-1, 0, 1},
				  {-2, 0, 2},
				  {-1, 0, 1}};

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cout << argc << endl;
        cout << "proper syntax: ./a.out <input flename1> <input filename2>";
        return 0;
    }

    // Exit program if file doesn't open
    string filename(argv[1]);
    string path = "./input_images/" + filename;
    ifstream infile(path, ios::binary);



    if (!infile.is_open())
        {
            cout << "File " << path << " not found in directory." << endl;
            return 0;
        }
    
    ofstream segmentedimage_1("./segmented_images/result_image.pgm", ios::binary);

    char buffer[1024], buffer2[1024];
    int width, height, intensity;
    double pic[height][width], x[height][width], y[height][width], sumx, sumy ;
    infile >> buffer >> width >> height >> intensity;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            pic[i][j] = (int)infile.get();
        }
    }
    int mr=1;
    for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			sumx = 0;

			for (int p = -mr; p <= mr; p++)
			{
				for (int q = -mr; q <= mr; q++)
				{
					// To make sure we don't go out of bounds
					if ((i + p) < 0 || (j + q) < 0 || (i + p) >= height || (j + q) >= width)
						continue;

					sumx += pic[i + p][j + q] * sobx[p + mr][q + mr];
				}
			}
			x[i][j] = sumx;
		}
	}
    int mid_x,mid_y,dis1,dis2,dis3,dis4,min,min1;
    //dis1 and dis2 are for x-axis and dis3 and dis4 are for y-axis
    //dis stands for distance to calculate the nearest intensity=255
    mid_x=width/2;
    mid_y=height/2;
    min=sqrt(pow(mid_x,2)+pow(mid_y,2));
    min1=sqrt(pow(mid_x,2)+pow(mid_y,2));
    for(int i=mid_x;i>=0;i--)
    {
        for(int j=mid_y;j>=0;j--)
        {
            dis1=sqrt(pow(i,2)+pow(j,2));
            if(x[i][j]==255 && min > dis1)
            {
                min=dis1;
            }
        }
    }
    for(int i=mid_x;i<=width;i++)
    {
        for(int j=mid_y;j<=height;j++)
        {
            dis2=sqrt(pow(i,2)+pow(j,2));
            if(x[i][j]==255 && min1 > dis2)
            {
                min1=dis2;
            }
        }
    }
}