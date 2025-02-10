/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:20:17 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/10 16:59:21 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
	if (argc != 4 || std::strlen(argv[1]) == 0
		|| std::strlen(argv[2]) == 0 || std::strlen(argv[3]) == 0)
	{
		std::cout<<"Wrong Argument"<<std::endl;
		return (1);
	}
	std::ifstream inFile(argv[1]);
	
	if (!inFile.is_open())
	{
		std::cout<<"Unable to open file"<<std::endl;
		return (1);
	}
	else
	{
		std::ofstream outFile(std::string(argv[1]).append(".replace"));
		if (outFile.is_open())
		{
			std::string line;
			std::string s1 = std::string(argv[2]);
			int s1Len = s1.length();
			std::string s2 = std::string(argv[3]);
			int startFlag = 0;
			while (std::getline(inFile, line))
			{
				if (startFlag)
					outFile<<std::endl;
				else
					startFlag = 1;
				size_t pos = 0;
				std::string newLine;
				int lineIndex = 0;
				while ((pos = line.find(s1, lineIndex)) != std::string::npos)
				{
					newLine += line.substr(lineIndex, pos - lineIndex);
					lineIndex = pos + s1Len;
					newLine += s2;
				}
				newLine += line.substr(lineIndex, line.length() - lineIndex +1);
				outFile<<newLine;
			}
			outFile.close();
		}
	}
	inFile.close();
}
