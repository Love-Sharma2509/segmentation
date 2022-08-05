#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;

int sobx[3][3] = {{-1, 0, 1},
				  {-2, 0, 2},
				  {-1, 0, 1}};
int soby[3][3] = {{1, 2, 1},
				  {0, 0, 0},
				  {-1, -2, -1}};

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
    
    ofstream segmentedimage_1("./fused_output_images/avg_fused.pgm", ios::binary);

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
			sumy = 0;

			for (int p = -mr; p <= mr; p++)
			{
				for (int q = -mr; q <= mr; q++)
				{
					// To make sure we don't go out of bounds
					if ((i + p) < 0 || (j + q) < 0 || (i + p) >= height || (j + q) >= width)
						continue;

					sumx += pic[i + p][j + q] * sobx[p + mr][q + mr];
					sumy += pic[i + p][j + q] * soby[p + mr][q + mr];
				}
			}
			x[i][j] = sumx;
			y[i][j] = sumy;
		}
	}


}