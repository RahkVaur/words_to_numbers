#include <algorithm>
#include <iostream>

#include "converter.h"

int main( int argc, char* argv[] )
{
    if( argc != 2 )
    {
        std::cout << "Usage: NumberConverter <message>" << std::endl
                  << "       - message: string to be converted" << std::endl;
    }
    else
    {
        const std::string in_string = argv[1];
        std::string out_string;

        try
        {
            convert_numbers_in_text( in_string, out_string );

            std::cout << out_string << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }


	return 0;
}
