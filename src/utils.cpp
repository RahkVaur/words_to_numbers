/*
 * utils.cpp
 *
 *  Created on: 8 sept 2022
 *      Author: tecnobit
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <sstream>

#include "utils.h"

/**
 * Anonymous namespace makes variables and methods inside it
 * visible only to this translation unit
 */
namespace
{
	std::set<char> two_side_special_ch = {
		'\'',
		'-'
	};

	std::set<char> one_side_special_ch = {
		'.',
		','
	};
}


void ltrim( std::string& string )
{
	string.erase( string.begin(), std::find_if( string.begin(), string.end(), []( unsigned char c ) {
		return std::isgraph( c );
	} ) );
}

void rtrim( std::string& string )
{
	string.erase( std::find_if( string.rbegin(), string.rend(), []( unsigned char c ) {
		return std::isgraph( c );
	} ).base(), string.end() );
}

void trim( std::string& string )
{
	ltrim( string );
	rtrim( string );
}

void split_special_ch( const std::string& word, std::vector<std::string>& split_text )
{
	std::string tmp;

	for( auto ch : word )
	{
		if( !isalpha( ch ) )
		{
			split_text.push_back( tmp );
			split_text.push_back( std::string( 1, ch ) );

			tmp.clear();
		}
		else
		{
			tmp.push_back( ch );
		}
	}

	if( !tmp.empty() )
	{
		split_text.push_back( tmp );
	}
}

void join_special_ch( std::string& text )
{
	for( auto it = text.begin(); it != text.end(); )
	{
		if( two_side_special_ch.find( *it ) != two_side_special_ch.end() )
		{
			if( std::next( it ) != text.end() )
			{
				text.erase( std::next( it ) );
			}

			text.erase( std::prev( it ) );
		}
		else if( one_side_special_ch.find( *it ) != one_side_special_ch.end() )
		{
			text.erase( std::prev( it ) );
		}
		else
		{
			it++;
		}
	}
}

void split_text( const std::string& text, std::vector<std::string>& split_text,
				 const char delimiter )
{
	std::istringstream ss( text );
	std::string word;

	if( !text.empty() )
	{
		while( std::getline( ss, word, delimiter ) )
		{
			split_special_ch( word, split_text );
		}
	}
}

void join_text( const std::vector<std::string>& split_text, std::string& text,
				const char* delimiter )
{
	if( !text.empty() )
	{
		text.clear();
	}

	std::ostringstream ss;

	std::copy( split_text.begin(), split_text.end(),
			   std::ostream_iterator<std::string>( ss, delimiter ) );

	text = ss.str();

	if( !text.empty() )
	{
		text.pop_back();
	}

	join_special_ch( text );
}
