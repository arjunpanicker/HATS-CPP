#pragma once
#ifndef PREPROCESSING_H
#define PREPROCESSING_H

namespace hats {
	typedef std::vector<std::string> StringList;
	typedef std::pair<std::string, std::vector<std::string>> DataColumn;
	typedef std::vector<DataColumn> DataTable;

	class Preprocessing {
	private:
		std::size_t findSubstringPosition(std::string value, std::string substr);
	public:
		Preprocessing() {}

		~Preprocessing() {}

		/// <summary>
		/// This method converts the provided list of string values into lowercase
		/// </summary>
		/// <param name="values">Vector of string values</param>
		/// <returns>Vector of punctuation removed string</returns>
		StringList toLowercase(StringList values);
		/// <summary>
		/// Converts a string to its lowercase.
		/// </summary>
		/// <param name="value">The string value</param>
		/// <returns>Lowercase converted string</returns>
		std::string toLowercase(std::string value);

		/// <summary>
		/// This method removes punctuations from the list of string values
		/// </summary>
		/// <param name="values">Vector of string values</param>
		/// <returns>Vector of punctuation removed strings</returns>
		StringList removePunctuation(StringList values);
		/// <summary>
		/// Removes punctuations from a string value
		/// </summary>
		/// <param name="value">The string value to remove punctuation from</param>
		/// <returns>Punctuation removed string</returns>
		std::string removePunctuation(std::string value);

		/// <summary>
		/// This method removes the stopwords present in each string in the given
		/// list
		/// </summary>
		/// <param name="values">Vector of string containing stopwords</param>
		/// <returns>A vector of string with shorttext converted</returns>
		StringList removeStopWords(StringList values);
		/// <summary>
		/// This method removes the stopwords present in the string
		/// </summary>
		/// <param name="value">String containing the stopword</param>
		/// <param name="stopWords">(Optional) Vector of stopwords</param>
		/// <returns>A string with short text removed</returns>
		std::string removeStopWords(std::string value, StringList stopWords = {});

		/// <summary>
		/// This method converts the short texts present in the provided list of strings
		/// according to the ST-MRD provided.
		/// </summary>
		/// <param name="values">Vector of short text commands/strings</param>
		/// <returns>A vector of string with shorttext converted</returns>
		StringList convertShortText(StringList values);
		/// <summary>
		/// This method converts the short texts present in the string according
		/// to the ST-MRD provided.
		/// </summary>
		/// <param name="value"></param>
		/// <param name="shorttextData">(Optional) Co</param>
		/// <returns></returns>
		std::string convertShortText(std::string value, DataTable shorttextData = {});
	};
}

#endif // !PREPROCESSING_H
