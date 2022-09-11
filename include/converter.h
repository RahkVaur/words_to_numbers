#ifndef CONVERTER_H_
#define CONVERTER_H_

#include <string>

/**
 * @brief
 * This function takes an input text, splits it into words,
 * transforms written numbers into its numeric counterpart
 * and then joins the resulting strings.
 * 
 * @param[in] in_string Input text.
 * @param[out] out_string Output text.
 * 
 * @return void
 * 
 * @exception Throws runtime error when a number is greater than 10^9
 */
void convert_numbers_in_text( const std::string& in_string, std::string& out_string );

#endif /* CONVERTER_H_ */
