/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:57:15 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/05/28 18:22:12 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <cstdlib>
#include <string>
#include <stack>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <map>

class BitcoinChecker{

	public:

	BitcoinChecker											( std::string	infile );
	BitcoinChecker											( const BitcoinChecker	&other );
	BitcoinChecker	&operator=								( const BitcoinChecker	&other );
	~BitcoinChecker											( void );

	void								verifyInfile		( std::ifstream &infile, const std::string &filename );
	void								convertValue		( std::ifstream	&infile );
	void								setDateValueRatio	( void );
	const std::map<std::string, float>	&getMap				( void ) const;
	

	class			InvalidCSVException : public std::exception{

		public:

		const char* what() const throw(){

			return "Empty/invalid CSV database file.";
		}
	};

	class			InvalidInfileException : public std::exception{

		public:

		const char* what() const throw(){

			return "Empty/invalid file.";
		}
	};

	class			InvalidFormatException : public std::exception{

		public:

		const char* what() const throw(){

			return "Invalid line format, please use format date | value .";
		}
	};

	class			InvalidDateException : public std::exception{

		public:

		const char* what() const throw(){

			return "Invalid date, please use format Year-Month-Day.";
		}
	};
	
	class			InvalidRatioException : public std::exception{

		public:

		const char* what() const throw(){

			return "Bitcoin exchange ratio must be a number between 0 and 1000.";
		}
	};

	private:

	std::map<std::string, float>			_dateValueRatio;
	std::ifstream							_csvInfile;

};

#endif
