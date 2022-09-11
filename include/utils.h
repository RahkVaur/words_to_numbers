#ifndef UTILS_H_
#define UTILS_H_

#include <string>
#include <vector>

void split_text( const std::string& text, std::vector<std::string>& split_text,
		         const char delimiter = ' ' );

void join_text( const std::vector<std::string>& split_text, std::string& text,
				const char* delimiter = " " );

#endif /* UTILS_H_ */
