#include "loader.h"

#include <exception>

ImageLoader::ImageLoader(const string &filename) : in(ifstream(filename))
{
    if(!in.is_open())
    {
        throw ios_base::failure("Can not open " + filename);
    }
}

ImageLoader::~ImageLoader()
{
    if(in.is_open())
        in.close();
}

Image ImageLoader::load()
{
    unsigned m,n;
    in >> m >> n;
    Image img(m,n);
    for(unsigned i = 0; i < m; i++)
    {
        for(unsigned j = 0; j < n; j++)
        {
            int pixel;
            in >> pixel;
            img.setPixel(pixel,i,j);
        }
    }
    return img;
}
