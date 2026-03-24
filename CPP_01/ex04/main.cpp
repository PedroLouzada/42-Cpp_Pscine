/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 22:12:15 by pbongiov          #+#    #+#             */
/*   Updated: 2026/03/24 23:34:49 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    (void)av;
    if (ac != 4)
        return (std::cerr << "Wrong number of arguments" << std::endl, 1);
    
    std::string fileName(av[1]);
    std::string s1(av[2]);
    std::string s2(av[3]);

    std::ifstream inFile(fileName.c_str());
    if (!inFile.is_open())
        return (std::cerr << "Error opening the file" << std::endl, 1);
        
    fileName.append(".replace");
    std::ofstream outFile(fileName.c_str());
    if (!outFile.is_open())
        return (std::cerr << "Error opening the file" << std::endl, 1);
    
    outFile << inFile.rdbuf();
    
    std::string line;
    while (std::getline(outFile, line))
}