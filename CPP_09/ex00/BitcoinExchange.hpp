/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 11:01:38 by pbongiov          #+#    #+#             */
/*   Updated: 2026/09/07 17:02:10 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <fstream>
# include <climits>

class BitcoinExchange : public std::multimap<std::string, std::string>
{
    private:
        std::map<std::string, std::string> _data;
        void initMap(std::ifstream& file, std::string& line);
        void initDatabase(std::ifstream& dataFile);
        
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        bool parseFile(const std::string& fileName);
        bool convertCoin(std::multimap<std::string, std::string>::iterator& input);
        void printValue();

};

#endif