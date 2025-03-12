/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:35:41 by ycho2             #+#    #+#             */
/*   Updated: 2025/03/12 18:06:39 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data *data_ori = new Data();
	data_ori->num = 42;
	Data *data_cnv = Serializer::deserialize(Serializer::serialize(data_ori));
	std::cout<<std::endl<<std::endl;
	std::cout<<"Original: "<<data_ori->num<<std::endl
		<<"Converted: "<<data_cnv->num<<std::endl;
	std::cout<<std::endl<<std::endl;
	delete(data_ori);
	return (0);
}