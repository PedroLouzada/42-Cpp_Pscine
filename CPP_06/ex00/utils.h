/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:46:37 by pbongiov          #+#    #+#             */
/*   Updated: 2026/07/30 15:59:04 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "ScalarConverter.hpp"
# include <climits>
# include <cfloat>

enum types
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    ERR
};

void convertChar(char& c, int& i, float& f, double& d, const std::string& arg);
void convertInt(char& c, int& i, float& f, double& d, const std::string& arg);
void convertFloat(char& c, int& i, float& f, double& d, const std::string& arg);
bool isChar(const std::string& arg);
bool isInt(const std::string& arg);
bool isFloat(const std::string& arg);
bool isDouble(const std::string& arg);
void printFloatException(const std::string& arg);
void printDoubleException(const std::string& arg);

#endif