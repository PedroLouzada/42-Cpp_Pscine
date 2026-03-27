/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 22:12:15 by pbongiov          #+#    #+#             */
/*   Updated: 2026/03/27 20:27:37 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

void replaceContent(std::ifstream& inFile, std::ofstream& outFile, std::string replace, std::string src)
{
    size_t pos;
    std::string line;
    std::string buff;

    while (std::getline(inFile, line))
    {
        while ((pos = line.find(replace)) != std::string::npos)
        {
            buff = line.substr(pos + replace.size(), line.size() - pos - replace.size());
            line = line.substr(0, pos);
            line.append(src);
            line.append(buff);
            pos += src.size(); 
        }
        outFile << line << "\n";
    }
    
    outFile.close();
    inFile.close();
}

int main(int ac, char **av)
{
    if (ac != 4)
        return (std::cerr << "Wrong number of arguments" << std::endl, 1);
        
    std::string fileName(av[1]);
    std::string s1(av[2]);
    std::string s2(av[3]);

    if (fileName.empty() || s1.empty())
        return (std::cerr << "FileName and s1 cannot be empty" << std::endl, 1);
    std::ifstream inFile(fileName.c_str());
    if (!inFile.is_open())
        return (std::cerr << "Error opening the file" << std::endl, 1);
        
    fileName.append(".replace");
    std::ofstream outFile(fileName.c_str());
    if (!outFile.is_open())
        return (std::cerr << "Error opening the file" << std::endl, 1);
    
    replaceContent(inFile, outFile, s1, s2);
}