#pragma once
#ifndef CONFIG_H
#define CONFIG_H
#include <string>

namespace hats {
	namespace base {
		const std::string LANGUAGE = "en";
	}

	namespace files {
		/// <summary>
		/// Data Preprocessing files
		/// </summary>
		const std::string SOURCE_DATASET_FILENAME = "../../../doc/dataset/home_auto_dataset.csv";
		const std::string SMS_TRANSLATION_FILENAME = "../../../doc/dataset/translations_data/sms_translations.csv";
		const std::string MULTILINGUAL_TRANSLATION_FILENAME = "../../../doc/dataset/translations_data/translations_data.csv";
		const std::string STOPWORDS_FILENAME = "../../../doc/dataset/preprocessing_data/stop_words.txt";

		/// <summary>
		/// Data Saving files
		/// </summary>
		const std::string NEW_DATASET_FILENAME = "../../../doc/dataset/hats_data.csv";


		const std::string FILE_OPEN_ERROR = "Could not open files";
	}
}

#endif // !CONFIG_H

