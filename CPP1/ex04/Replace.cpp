/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:10:18 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/08 16:35:04 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <iostream>
#include <cstdlib>

Replace::Replace(std::string inFilename)
{
	this->inFilename = inFilename;
	this->outFilename = inFilename.append(".replace");
}

Replace::~Replace(void)
{
}

bool	Replace::open(void)
{
	inFile.open(inFilename.c_str());
	if (inFile.fail())
		return (false);
	outFile.open(outFilename.c_str());
	if (inFile.fail())
		return (false);
	return (true);
}

void	Replace::close(void)
{
	inFile.close();
	outFile.close();
}

std::string	Replace::readFile(void)
{
	std::string	fileContent;
	std::string	buffer;
	
	try
	{
		while (1)
		{
			if (!std::getline(inFile, buffer) && inFile.unget().get() != '\n')
				break;
			fileContent.append(buffer);
			if (inFile.unget().get() == '\n')
				fileContent += inFile.unget().get();
//			if (!fileContent.empty())
//				fileContent.append("\n");
		}
		inFile.clear();
	}
	catch(...)
	{
		std::cerr << "Failed reading the file" << '\n';
		exit(1);
	}
	return (fileContent);
}

void	Replace::replace(std::string s1, std::string s2)
{
	std::string	fileContent;
	int 		pos = 0;
	int 		next = 0;
	
	if (!this->open())
	{
		std::cerr << "Failed opening of the files" << std::endl;
		exit(1);
	}
	fileContent = readFile();
	while (!s1.empty() && (next = fileContent.find(s1, pos)) != (int)std::string::npos)
	{
		outFile << fileContent.substr(pos, next - pos);
		pos += next - pos + s1.length();
		outFile << s2;
	}
	outFile << fileContent.substr(pos, fileContent.length() - pos);
	this->close();
}