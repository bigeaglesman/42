/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:59:56 by ycho2             #+#    #+#             */
/*   Updated: 2025/01/10 17:44:05 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char** argv)
{
	if (argc == 1)
		std::cout<<"* LOUD AND UBEARABLE FEEDBACK NOISE *"<<std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
			{
				if (argv[i][j] >= 97 && argv[i][j] <= 122)
					std::cout<<(char)(argv[i][j]-32);
				else
					std::cout<<argv[i][j];
			}
		}
		std::cout<<std::endl;
	}
}