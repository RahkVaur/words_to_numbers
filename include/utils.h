#ifndef UTILS_H_
#define UTILS_H_

#include <string>
#include <vector>

/**
 * @brief
 * This function left trims a string.
 * 
 * @param[in] string String to left trim.
 * 
 * @return void
 */
void ltrim( std::string& string );

/**
 * @brief
 * This function right trims a string.
 * 
 * @param[in] string String to right trim.
 * 
 * @return void
 */
void rtrim( std::string& string );

/**
 * @brief
 * This function trims a string.
 * 
 * @param[in] string String to trim.
 * 
 * @return void
 */
void trim( std::string& string );

/**
 * @brief
 * This function splits words from the special characters
 * and inserts them in the vector provided. For example,
 * the word 'twenty-one' is splitted into 'twenty', '-' 
 * and 'one' 
 * 
 * @param[in] word Word to be splitted from the special characters.
 * @param[out] split_text Vector where the splitted words will be stored.
 * 
 * @return void
 */
void split_special_ch( const std::string& word, std::vector<std::string>& split_text );

/**
 * @brief
 * This function takes a text and erases the spaces between
 * the special characters and the words that form the text.
 * 
 * @param[in] text Text where the special characters will be joined.
 * 
 * @return void
 */
void join_special_ch( std::string& text );

/**
 * @brief
 * This function takes a text and splits it into words looking for
 * a specific delimiter.
 * 
 * @param[in] text Text to be splitted.
 * @param[out] split_text Vector where the splitted words will be stored.
 * @param[in] delimiter Delimiter by which the text will be splitted.
 * 
 * @return void
 */
void split_text( const std::string& text, std::vector<std::string>& split_text,
		         const char delimiter = ' ' );

/**
 * @brief
 * This function takes vector of strings and joins them using a
 * specific delimiter.
 * 
 * @param[in] split_text Vector containing the words to be joined.
 * @param[out] text String where the text will be stored.
 * @param[in] delimiter Delimiter by which the text will be joined.
 * 
 * @return void
 */
void join_text( const std::vector<std::string>& split_text, std::string& text,
				const char* delimiter = " " );

#endif /* UTILS_H_ */
