#pragma once

#include "halley/text/halleystring.h"
#include <iostream>

namespace Halley
{
	class Path
	{
	public:
		Path();
		Path(const char* name);
		Path(const std::string& name);
		Path(const String& name);

		Path& operator=(const std::string& other);
		Path& operator=(const String& other);

		Path getRoot() const;
		Path getFilename() const;
		Path getStem() const;
		String getExtension() const;
		String getString() const;

		Path parentPath() const;
		Path replaceExtension(String newExtension) const;

		Path operator/(const char* other) const;
		Path operator/(const Path& other) const;
		Path operator/(const String& other) const;
		Path operator/(const std::string& other) const;

		bool operator==(const char* other) const;
		bool operator==(const String& other) const;
		bool operator==(const Path& other) const;

		bool operator!=(const Path& other) const;

		std::string string() const;

	private:
		std::vector<String> pathParts;
		void normalise();
		void setPath(const String& value);

		explicit Path(std::vector<String> parts);
	};

	std::ostream& operator<<(std::ostream& os, const Path& p);
}
