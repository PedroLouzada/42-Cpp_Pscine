/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 18:22:35 by pbongiov          #+#    #+#             */
/*   Updated: 2026/03/23 10:49:16 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
    private:
        std::string _firstname;
        std::string _lastname;
        std::string _nickname;
        std::string _number;
        std::string _darkestSecret;
    
    public:
    
        void SetName(std::string _firstname, std::string _lastname, std::string _nickname);
        void Set_number(std::string number);
        void SetSecret(std::string darkestSecret);

        std::string Get_firstname();
        std::string Get_lastname();
        std::string Get_nickname();
        std::string Get_number();
        std::string GetSecret();
};

#endif