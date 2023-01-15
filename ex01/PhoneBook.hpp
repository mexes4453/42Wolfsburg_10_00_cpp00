/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:04:30 by cudoh             #+#    #+#             */
/*   Updated: 2023/01/15 12:13:05 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <stdlib.h>
# include <stdio.h>
# include <iostream>
# include <iomanip>
# include <unistd.h>
# include <string>
# include "Contact.hpp"
# define MAX_ENTRIES (8)
# define MIN_ENTRY_STR ("1")
# define MAX_ENTRY_STR ("8")
# define PROMPT_HOLDER ("wait")
# define OK (1)
# define DELAY (2)
# define PB_STATE_EMPTY (0)
# define PB_STATE_NOT_EMPTY (1)
# define PB_COL_WIDTH (10)
# define PB_OPTION_UNKNOWN (0)
# define PB_OPTION_ADD (1)
# define PB_OPTION_SEARCH (2)
# define PB_OPTION_EXIT (3)
# define PB_EXIT (0)

class PhoneBook
{
    private:
        Contact         _directory[MAX_ENTRIES];
        uint8_t         _entry_size;
    	static uint8_t	_cnt_phonebook;
    	static uint8_t	_idx_entry; 
		static uint8_t	_state;
        
    public:
        PhoneBook(void);
        PhoneBook(uint8_t entry_size);
        PhoneBook(PhoneBook const &P);
        ~PhoneBook(void);

        PhoneBook       &operator=(PhoneBook const &P);
		uint8_t         add_entry(void);
		uint8_t         search_entry(void);
		void	        print_entry_data(std::string data);
		bool	        isSearchEntryOptionValid(std::string usr_opt_str, \
                        uint8_t entry_cnt, int &usr_opt_int);
		void	        print_header(void);
		uint8_t	        show_entries(void);
        static void     setCntPhoneBook(uint8_t counter);
        static void     setIdxEntry(uint8_t idx_entry);
        static void     setState(uint8_t state);
        static uint8_t  getCntPhoneBook(void);
        static uint8_t  getIdxEntry(void);
        static uint8_t  getState(void);
		uint8_t	        wait_usr_inp(void) const;
		bool	        isDirEmpty(void) const;
        uint8_t         displayMenu(void);
        uint8_t         startUp(void);
};

#endif
