/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:04:20 by cudoh             #+#    #+#             */
/*   Updated: 2023/01/14 19:38:41 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H
# include <stdlib.h>
# include <stdio.h>
# include <iostream>
# include <stdint.h>
# include <string.h>
# include <string>
# include <unistd.h>
# define  CONTACT_DELAY (2)

class Contact
{
	private:
        std::string		_p_nbr;
        std::string		_d_secret;
        std::string		_f_name;
        std::string		_l_name;
        std::string		_n_name;
        static uint8_t	_cnt_instance;

	public:
        Contact(void);
		Contact(std::string p, std::string, std::string d, std::string f, \
				std::string l, std::string n);
        Contact(Contact const &C);
        ~Contact(void);
        
        Contact         &operator=(Contact const &C);
        bool    	    setNameStrict(std::string msg, std::string &name);
        void    	    setFirstName(void);
        void    	    setLastName(void);
        void    	    setNickName(void);
        void    	    setPhoneNbr(void);
        void    	    setDarkSecret(void);
		static void	    setCntInst(uint8_t cnt);
		std::string	    getFirstName(void) const;
		std::string	    getLastName(void) const;
		std::string	    getNickName(void) const;
		std::string	    getPhoneNbr(void) const;
		std::string	    getDarkSecret(void) const;
		static uint8_t  getCntInst(void);
        void    	    printContactDetails(void) const;
        bool    	    isNameCharsAlpha(std::string c_name) const;
        bool    	    isNumCharsNumeric(std::string phone_nbr) const;
};
#endif
