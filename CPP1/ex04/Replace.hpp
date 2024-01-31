/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluzi <bluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:50:10 by bluzi             #+#    #+#             */
/*   Updated: 2023/10/08 16:27:00 by bluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP


#include <string>
#include <fstream>

class Replace
{
	private:
		std::string		inFilename;
		std::string		outFilename;
		std::ifstream	inFile;
		std::ofstream	outFile;
		
		bool	open(void);
		void	close(void);
		std::string	readFile(void);

	public:
		Replace(std::string inFilename);
		~Replace(void);

		void	replace(std::string s1, std::string s2);
};

#endif