#pragma once
#ifndef CONFIG_H
#define CONFIG_H

namespace hats {
	namespace base {
		const std::string LANGUAGE = "en";
	}

	namespace files {
		/// <summary>
		/// Data Preprocessing files
		/// </summary>
		const std::string SOURCE_DATASET_FILENAME = ".\\dataset\\home_auto_dataset.csv";
		const std::string SMS_TRANSLATION_FILENAME = ".\\dataset\\translations_data\\sms_translations.csv";
		const std::string MULTILINGUAL_TRANSLATION_FILENAME = ".\\dataset\\translations_data\\translations_data.csv";
		const std::string STOPWORDS_FILENAME = ".\\dataset\\preprocessing_data\\stop_words.txt";

		/// <summary>
		/// Data Saving files
		/// </summary>
		const std::string NEW_DATASET_FILENAME = ".\\dataset\\hats_data.csv";


		const std::string FILE_OPEN_ERROR = "Could not open files";
	}
}

#endif // !CONFIG_H

