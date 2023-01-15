/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:05:01 by cudoh             #+#    #+#             */
/*   Updated: 2023/01/07 20:44:54by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Contact.hpp"

uint8_t Contact::_cnt_instance = 0;
Contact::Contact(void)
	: _p_nbr(""), _d_secret(""), _f_name(""), _l_name(""), _n_name("")
{
    std::cout << "call default constructor - Contact" << std::endl;
    std::cout << "Created contact instance - " << _cnt_instance << std::endl;
    _cnt_instance++;
}



Contact::Contact(std::string p, std::string, std::string d, std::string f, \
				std::string l, std::string n)
	: _p_nbr(p), _d_secret(d), _f_name(f), _l_name(l), _n_name(n)
{
    std::cout << "Call parametric constructor - Contact" << std::endl;
}



Contact::Contact(Contact const &C)
{
    *this = C;
    std::cout << "call copy constructor - Contact" << std::endl;
}



Contact::~Contact(void)
{
    std::cout << "Contact is destroyed" << std::endl;

    _cnt_instance--;
    std::cout << (int)(_cnt_instance) << " instance" << std::endl;
}


Contact &Contact::operator=(Contact const &C)
{
    std::cout << "call copy assignement Operator called" << std::endl;
    memcpy((void *)this, (void *)&C, sizeof(Contact));
    return (*this);
}

bool    Contact::setNameStrict(std::string msg, std::string &name)
{
    name = "";
    bool    result = false;

    while (name == "")
    {
        std::cout << std::endl << msg;
        std::getline(std::cin, name);
        if (name != "")
        {
            result = isNameCharsAlpha(name);
            if (result == false)
            {
                std::cout << "ERROR: Name characters must be alphabets" \
				<< std::endl;
                sleep(CONTACT_DELAY);
                name = "";
                continue ;
            }
            else
            {
                break ;
            }
        }
    }
    return (result);
}

void Contact::setFirstName(void)
{
    std::string name = "";
    bool    result = false;

    result = setNameStrict("Enter first name: ", name);
    _f_name = (result = true) ? name : "";
    return ;
}



void Contact::setLastName(void)
{
    std::string name = "";
    bool    result;

    result = false;
    result = setNameStrict("Enter last name: ", name);
    _l_name = (result = true) ? name : "";
    return ;
}



void Contact::setNickName(void)
{
    std::string  name;

    name = "";
    while (name == "")
    {
        std::cout << std::endl << "Enter nickname: ";
        std::getline(std::cin, name);
        if (name != "")
        {
            _n_name = name;
            break ;    
        }
    }
    return ;
}



void Contact::setPhoneNbr(void)
{
    std::string phone_nbr = "";
    bool    result = false;

    while (phone_nbr == "")
    {
        std::cout << std::endl << "Enter phone number: ";
        std::getline(std::cin, phone_nbr);
        if (phone_nbr != "")
        {
            result = isNumCharsNumeric(phone_nbr);
            if (result == false)
            {
                std::cout << "ERROR: phone number characters must be numeric"\
				 << std::endl;
                sleep(CONTACT_DELAY);
                phone_nbr = "";
                continue ;
            }
            else
            {
                break ;
            }
        }
    }
    _p_nbr = phone_nbr;
    return ;
}

void Contact::setDarkSecret(void)
{
    std::string  secret;

    secret = "";
    while (secret == "")
    {
        std::cout << std::endl << "Enter darkest secret: ";
        std::getline(std::cin, secret);
        if (secret != "")
        {
            _d_secret = secret;
            break ;    
        }
    }
    return ;
}

void	Contact::setCntInst(uint8_t cnt)
{
	Contact::_cnt_instance = cnt;
}

std::string	Contact::getFirstName(void) const
{
	return (_f_name);
}

std::string	Contact::getLastName(void) const
{
	return (_l_name);
}

std::string	Contact::getNickName(void) const
{
	return (_n_name);
}

std::string	Contact::getPhoneNbr(void) const
{
	return (_p_nbr);
}

std::string	Contact::getDarkSecret(void) const
{
	return (_d_secret);
}


uint8_t		Contact::getCntInst(void)
{
	return (Contact::_cnt_instance);
}

void    Contact::printContactDetails(void) const
{
    std::cout << "first name: " << _f_name << std::endl;
    std::cout << "last name: " << _l_name << std::endl;
    std::cout << "nickname: " << _n_name << std::endl;
    std::cout << "phone number: " << _p_nbr << std::endl;
    std::cout << "darkest secret: " << _d_secret << std::endl;
}

bool    Contact::isNameCharsAlpha(std::string c_name) const
{
    bool        result;
    uint32_t    idx;

    result = true;
    idx = 0;
    while (c_name[idx] != '\0')
    {
        result = isalpha(c_name[idx]);
        if (result == false)
        {
            break ;
        }
        idx++;
    }
    return (result);
}

bool    Contact::isNumCharsNumeric(std::string phone_nbr) const
{
    bool        result;
    uint32_t    idx;

    result = true;
    idx = 0;
    while (phone_nbr[idx] != '\0')
    {
        result = isdigit(phone_nbr[idx]);
        if (result == false)
        {
            break ;
        }
        idx++;
    }
    return (result);
}
