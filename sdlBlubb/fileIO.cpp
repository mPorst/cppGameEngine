#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "fileIO.h"

#include <iostream>
#include <fstream>
#include <glew\glew.h>

/// function readFullFile tested for functionality 04.12.2016
std::string readFullFile(char* filename) {
	// create fstream object to create a file stream for readout
	std::fstream fileStream; 
	// create string to pushback the data and return
	std::string fileContent, temp;
	// open the file in read-only mode
	fileStream.open(filename, std::fstream::in);
	// readout loop: line by line
	while (fileStream.eof() != GL_TRUE)
	{
		std::getline(fileStream, temp); // getline
		fileContent.append(temp).append("\n"); // append to return string
	}
	return fileContent;
}

void writeToFile(char* filename, char* text) {
	
}