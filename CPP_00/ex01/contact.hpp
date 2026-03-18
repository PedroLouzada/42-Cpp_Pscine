/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 18:22:35 by pbongiov          #+#    #+#             */
/*   Updated: 2026/03/18 19:53:58 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string number;
        std::string darkestSecret;
    
    public:
        void SetName(std::string firstName, std::string lastName, std::string nickname);
        void SetNumber(std::string number);
        void SetSecret(std::string darkestSecret);

        std::string GetFirstName();
        std::string GetLastName();
        std::string GetNickName();
        std::string GetNumber();
        std::string GetDarkestSecret();
};

#endif