/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:20:17 by ycho2             #+#    #+#             */
/*   Updated: 2025/02/12 12:38:02 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cout<<"Wrong Argument"<<std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	int s1_len = s1.length();
	int s2_len = s2.length();
	int filename_len = filename.length();
	if (filename_len == 0 || s1_len == 0|| s2_len == 0)
	{
		std::cout<<"argv length 0"<<std::endl;
		return (1);
	}
	std::ifstream in_file(argv[1]);
	
	if (!in_file.is_open())
	{
		std::cout<<"Unable to open file"<<std::endl;
		return (1);
	}
	else
	{
		std::ofstream out_file((std::string(argv[1]).append(".replace")).c_str());
		if (out_file.is_open())
		{
			std::string line;
			int startFlag = 0;
			while (std::getline(in_file, line))
			{
				if (startFlag)
					out_file<<std::endl;
				else
					startFlag = 1;
				size_t pos = 0;
				while ((pos = line.find(s1, pos)) != std::string::npos)
				{
					line.erase(pos, s1_len);
					line.insert(pos, s2);
					pos += s2_len;
				}
				out_file<<line;
				if (in_file.eof())
					break;
				out_file<<std::endl;
			}
			out_file.close();
		}
		else
		{
			std::cout<<"out_file open error"<<std::endl;
			in_file.close();
			return (1);
		}
	}
	in_file.close();
	return (0);
}
