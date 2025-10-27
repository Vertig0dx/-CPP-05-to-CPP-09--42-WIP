/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:57:33 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/09/16 17:00:48 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinChecker::BitcoinChecker( std::string	infile ) : _csvInfile("data.csv"){

	std::cout << "Standard constructor called, using file " << infile << std::endl;
}

BitcoinChecker::BitcoinChecker( const BitcoinChecker &other ){

	std::cout << "Copy constructor called." << std::endl;
	*this = other;
}

BitcoinChecker &BitcoinChecker::operator=( const BitcoinChecker &other ){

	std::cout << "Overloaded Operator detected, following case instructions." << std::endl;
	if (this != &other)
		this->_dateValueRatio = other._dateValueRatio;
	return (*this);
}

BitcoinChecker::~BitcoinChecker( void ){

		std::cout << "Destructor called." << std::endl;
}

void BitcoinChecker::verifyInfile( std::ifstream &infile, const std::string &filename ){
	
	infile.open(filename.c_str());
	if (!infile.is_open()) // if the config file cannot be opened/doesn't exist, throw this error.
		throw BitcoinChecker::InvalidInfileException();
	if (!infile.good())
	{
		infile.close();
		throw BitcoinChecker::InvalidInfileException();
	}
	if (infile.is_open() && infile.peek() == EOF)
	{
		infile.close();
		throw BitcoinChecker::InvalidInfileException();
	}
}

void BitcoinChecker::convertValue( std::ifstream &infile ){

	bool								value_found = false;
	float								year;
	float								month;
	float								day;
	float								value;
	size_t								separator_position;
	size_t								first_dash;
	size_t								second_dash;
	std::string							line;
	std::string							date_position;
	std::string							value_position;
	std::string							year_str;
	std::string							month_str;
	std::string							day_str;
	std::string							separator;
	std::stringstream					stream;
	std::stringstream					test_stream;
	std::map<std::string, float>		csv_database;

	csv_database = BitcoinChecker::getMap();
	while (std::getline(infile, line))
	{
		value_found = false;
		separator_position = line.find(" | ");
		if (separator_position == std::string::npos || line.find(" | ", separator_position + 1) != std::string::npos)
		{
			std::cout << "Invalid format or multiple separators." << std::endl;
			continue;
		}
		date_position = line.substr(0, separator_position);
		value_position = line.substr(separator_position + 3);
		first_dash = date_position.find('-');
		second_dash = date_position.find('-', first_dash + 1);
		if (first_dash == std::string::npos || second_dash == std::string::npos || date_position.find('-', second_dash + 1) != std::string::npos)
		{
			std::cout << "Invalid date format" << std::endl;
			continue;
		}
		year_str = date_position.substr(0, first_dash);
		month_str = date_position.substr(first_dash + 1, second_dash - first_dash - 1);
		day_str = date_position.substr(second_dash + 1);
		test_stream.clear();
		test_stream.str(year_str);
		test_stream >> year;
		if (test_stream.fail() || year < 2000 || year > 3000)
		{
			std::cout << "Invalid year input." << std::endl;
			continue ;
		}
		test_stream.clear();
		test_stream.str(month_str);
		test_stream >> month;
		if (test_stream.fail() || month < 1 || month > 12)
		{
			std::cout << "Invalid month input." << std::endl;
			continue ;
		}
		test_stream.clear();
		test_stream.str(day_str);
		test_stream >> day;
		if (test_stream.fail()|| day < 1 || day > 31)
		{
			std::cout << "Invalid day input." << std::endl;
			continue ;
		}
		test_stream.clear();
		test_stream.str(value_position);
		test_stream >> value;
		if (test_stream.fail() || value < 0 || value > 1000)
		{
			std::cout << "Invalid value input." << std::endl;
			continue ;
		}
		//check if date exists
		for (std::map<std::string, float>::iterator it = this->_dateValueRatio.begin(); it != this->_dateValueRatio.end(); ++it){
			if (it->first == date_position)
			{
				std::cout << "Value for " << it->first << " : " << (value * it->second) << std::endl;
				value_found = true;
				break ;
			}
		}
		if (value_found == false)
		{
			std::map<std::string, float>::iterator it = csv_database.upper_bound(date_position);
			
			if (it != csv_database.begin())
			{
				--it;
				std::cout << "Value for closest lower date " << it->first << " is: " << (it->second * value) << std::endl;
			}
			else
				std::cout << "No records up to and including this date." << std::endl;
			//seek closest past date
			//for (std::map<std::string, float>::iterator it = this->_dateValueRatio.begin(); it != this->_dateValueRatio.end(); ++it){
				//convert map key into str? into stream?
			/* size_t map_first_dash = it->first.find('-');
			float map_year = atof(it->first.substr(it->first.find('-')).c_str());
			float map_month = atof(it->first.substr(it->first.find('-', map_first_dash + 1)).c_str());
			float map_day = atof(it->first.substr(it->first.rfind('-')).c_str()); */
		}
	}
}

void BitcoinChecker::setDateValueRatio( void ){
	
	float							value;
	std::string						line;
	std::string						date;
	std::string						value_str;
	std::stringstream				stream;
	std::stringstream				value_stream;
	std::map<std::string, float>	map;
	
	if (!this->_csvInfile.is_open())
		throw BitcoinChecker::InvalidCSVException();
	std::getline(this->_csvInfile, line); // skip the header in the CSV file
	while (std::getline(this->_csvInfile, line))
	{
		stream.clear();
		stream.str(line);
		if (std::getline(stream, date, ',') && std::getline(stream, value_str, ',')){
			value_stream.clear();
			value_stream.str(value_str);
			value_stream >> value;
			map.insert(std::pair<std::string, float>(date, value));
		}
	}
	this->_csvInfile.close();
	this->_dateValueRatio = map;
}

const std::map<std::string, float> &BitcoinChecker::getMap( void ) const{

	return _dateValueRatio;
}