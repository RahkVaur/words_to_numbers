#include <algorithm>
#include <map>
#include <set>
#include <vector>

#include "converter.h"
#include "utils.h"

/**
 * Anonymous namespace makes variables and methods inside it
 * visible only to this translation unit
 */
namespace
{

std::map<std::string, uint32_t> nums_map = {
	    { "zero",               0 },
	    { "one",                1 },
	    { "two",                2 },
	    { "three",              3 },
	    { "four",               4 },
	    { "five",               5 },
	    { "six",                6 },
	    { "seven",              7 },
	    { "eight",              8 },
	    { "nine",               9 },
	    { "ten",               10 },
	    { "eleven",            11 },
	    { "twelve",            12 },
	    { "thirteen",          13 },
	    { "fourteen",          14 },
	    { "fifteen",           15 },
	    { "sixteen",           16 },
	    { "seventeen",         17 },
	    { "eighteen",          18 },
	    { "nineteen",          19 },
	    { "twenty",            20 },
	    { "thirty",            30 },
	    { "forty",             40 },
	    { "fifty",             50 },
	    { "sixty",             60 },
	    { "seventy",           70 },
	    { "eighty",            80 },
	    { "ninety",            90 },
	    { "hundred",          100 },
	    { "thousand",        1000 },
	    { "million",      1000000 },
	    { "billion",   1000000000 }
};

std::set<std::string> add_nums = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety"
};

std::set<std::string> mult_nums = {
    "thousand",
    "million",
    "billion"
};

std::set<std::string> num_connectors = {
    "and",
    ",",
    "-"
};

/**
 * @brief
 * This function takes a vector of strings, searches for the 
 * numbers written in text form and transforms them into their
 * numeric counterpart, leaving the rest untouched.
 * 
 * @param[in] in_vector Input vector of strings.
 * @param[out] out_vector Output vector of strings.
 * 
 * @return void
 * 
 * @exception Throws runtime error when a number is greater than 10^9
 */
void words2numbers( const std::vector<std::string>& in_vector, std::vector<std::string>& out_vector )
{
    uint32_t number = 0;
    uint32_t partial_number = 0;

    // Lambda function to avoid code repetition
    auto insert_number = [&]() {
        if( number != 0 || partial_number != 0 )
        {
            if( partial_number != 0 )
            {
                number += partial_number;

                partial_number = 0;
            }

            if( number > 1000000000 )
            {
                throw std::runtime_error( "A number is bigger than the limit of 10^9" );
            }

            out_vector.push_back( std::to_string( number ) );

            number = 0;
        }
    };

    bool is_processing_num = false;

    for( size_t i = 0; i < in_vector.size(); i++ )
    {
        auto word = in_vector[i];

        // Check if word is a number
        if( nums_map.find( word ) != nums_map.end() )
        {
            is_processing_num = true;

            // Check if number is a multiplier
            if( mult_nums.find( word ) != mult_nums.end() )
            {
                if( partial_number == 0 )
                {
                    partial_number += 1;
                }
                
                partial_number *= nums_map.at( word );

                number += partial_number;

                partial_number = 0;
            }
            else if( word == "hundred")
            {
                if( partial_number == 0 )
                {
                    partial_number += 1;
                }

                partial_number *= nums_map.at( word );
            }
            else if( add_nums.find( word ) != add_nums.end() )
            {
                partial_number += nums_map.at( word );
            }
        }
        // Check if word is a comma, a hyphen or 'and' in the middle of a number
        else if( is_processing_num && ( num_connectors.find( word ) != num_connectors.end() ) )
        {
            /**
             * Word 'and' or the comma or hyphen characters are often used
             * when writing numbers. We simply ignore them.
             */
            continue;
        }
        else
        {
            /**
             * Word is not a number, so we check if we have a number
             * to insert and then push the word.
             */
            insert_number();

            out_vector.push_back( word );

            is_processing_num = false;
        }
    }

    insert_number();
}

}

void convert_numbers_in_text( const std::string& in_string, std::string& out_string )
{
	std::vector<std::string> in_split_string;
    std::vector<std::string> out_split_string;

	split_text( in_string, in_split_string );

    words2numbers( in_split_string, out_split_string );

    join_text( out_split_string, out_string );
}