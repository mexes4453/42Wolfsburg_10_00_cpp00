/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:04:49 by cudoh             #+#    #+#             */
/*   Updated: 2023/01/08 00:26:51y cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

uint8_t PhoneBook::_cnt_phonebook = 0;
uint8_t PhoneBook::_idx_entry = 0;
uint8_t PhoneBook::_state = PB_STATE_EMPTY;
PhoneBook::PhoneBook(void)
{
    std::cout << "call default constructor - PhoneBook" << std::endl;
    std::cout << "created Phonebook instance - " << _cnt_phonebook << std::endl;
    (this->_cnt_phonebook)++; 
}



PhoneBook::PhoneBook(uint8_t entry_size) : _entry_size(entry_size)
{
    std::cout << "call parametric constructor - PhoneBook" << std::endl;
}



PhoneBook::PhoneBook(PhoneBook const &P)
{
    std::cout << "call copy constructor - PhoneBook" << std::endl;
	*this = P;
}



PhoneBook   &PhoneBook::operator=(PhoneBook const &P)
{
    std::cout << "call copy assignment constructor - PhoneBook" << std::endl;
    memcpy((void *)this, (void *)&P, sizeof(PhoneBook));
    return (*this);
}



PhoneBook::~PhoneBook(void)
{
    (_cnt_phonebook)--; 
    std::cout << _cnt_phonebook << std::endl;
    std::cout << "Phonebook instance destroyed" << std::endl;
}



uint8_t PhoneBook::add_entry(void)
{
    uint8_t result = 0;

    _directory[_idx_entry].setFirstName();
    _directory[_idx_entry].setLastName();
    _directory[_idx_entry].setNickName();
    _directory[_idx_entry].setPhoneNbr();
    _directory[_idx_entry].setDarkSecret();
    std::cout << std::endl << std::endl << "Contact entry -> SUCCESSFUL" << std::endl;
    _idx_entry = ((_idx_entry + 1) % MAX_ENTRIES);
    wait_usr_inp();
    result = OK;
    PhoneBook::_state = PB_STATE_NOT_EMPTY;
    return (result);
}



uint8_t PhoneBook::search_entry(void)
{
    int         idx_option = 0;
    uint8_t     result = OK;
    std::string idx_str = "";
    uint8_t     idx_max = 0;

    if (this->isDirEmpty() == false)
        return (result);
    while (idx_str == "") 
    {
        system("clear");
        this->print_header();
        idx_max = this->show_entries();
        std::cout << std::endl;
        std::cout << "To view entry details, enter index nbr or enter '0' to return: ";
        std::getline(std::cin, idx_str);
        if (this->isSearchEntryOptionValid(idx_str, idx_max, idx_option) == true)
            this->_directory[idx_option].printContactDetails();
		else if (idx_str == "0")
			break ;
		else
		{
			idx_str = "";
			std::cout << "ERROR!!! - Invalid Input!" << std::endl;
		}
        this->wait_usr_inp();
    }
    return (result);
}



bool PhoneBook::isSearchEntryOptionValid(std::string usr_opt_str, \
                        uint8_t entry_cnt, int &usr_opt_int)
{
    bool    result = false;
	
	for (size_t x=0; usr_opt_str[x] != '\0'; x++)
	{
		if (!isdigit(usr_opt_str[x]))
		{
			return (result);
		}
	}
    if (usr_opt_str == "" || usr_opt_str == "0")
	{
		return (result);
	}
    else if (atoi(usr_opt_str.c_str()) > entry_cnt)
    {
        usr_opt_str = "";
        std::cout << "Invalid entry index. Please check input" << std::endl;
    }
    else
    {
        usr_opt_int = atoi(usr_opt_str.c_str()) - 1;
        result = true;
    }
    return (result);
}



void    PhoneBook::print_entry_data(std::string data)
{
    uint8_t idx = 0;

    if (data.size() <= PB_COL_WIDTH)
    {
        std::cout << std::right << std::setw(PB_COL_WIDTH) << data;
    }
    else
    {
        while (idx < (PB_COL_WIDTH - 1))
        {
            std::cout << data[idx];
            idx++;
        }
        std::cout << '.';
    }
    return ;
}



void    PhoneBook::print_header(void)
{
    std::cout << std::right << std::setw(PB_COL_WIDTH) << "index";
    std::cout << '|';
    std::cout << std::right << std::setw(PB_COL_WIDTH) << "first name";
    std::cout << '|';
    std::cout << std::right << std::setw(PB_COL_WIDTH) << "last name";
    std::cout << '|';
    std::cout << std::right << std::setw(PB_COL_WIDTH) << "nickname";
    std::cout << std::endl;
    return ;

}



uint8_t    PhoneBook::show_entries(void)
{
    uint8_t 	idx = 0;
	std::string	data = "";
    
    while (idx < MAX_ENTRIES)
    {
		data = _directory[idx].getFirstName();
        if (data == "")
        {
            break ;
        }
        else
        {
            std::cout << std::right << std::setw(PB_COL_WIDTH) << (int)(idx + 1); 
            std::cout << "|";
            print_entry_data(this->_directory[idx].getFirstName());
            std::cout << "|";
            print_entry_data(this->_directory[idx].getLastName());
            std::cout << "|";
            print_entry_data(this->_directory[idx].getNickName());
            std::cout << std::endl;
        }
        idx++;
    }
    return (idx);
}



uint8_t    PhoneBook::wait_usr_inp(void) const
{
    std::string  usr_inp;
    uint8_t result;

    usr_inp = PROMPT_HOLDER;
    result = 0;
    while (usr_inp == PROMPT_HOLDER)
    {
        std::cout << std::endl << "Press 'Enter' to continue: ";
        std::getline(std::cin, usr_inp);
        if (usr_inp == "")
        {
            result = OK;
            break ;
        }
        else
        {
            usr_inp = PROMPT_HOLDER;
        }
    }
    return (result);
}



bool    PhoneBook::isDirEmpty(void) const
{
    bool    result = true;
    if (this->_state == PB_STATE_EMPTY)
    {
        std::cout << std::endl << "!!! --- NO Entries --- !!!" << std::endl;
        this->wait_usr_inp();
        result = false;
    }
    return (result);
}



void PhoneBook::setCntPhoneBook(uint8_t counter)
{
    PhoneBook::_cnt_phonebook = counter;
}


void PhoneBook::setIdxEntry(uint8_t idx_entry)
{
    PhoneBook::_idx_entry = idx_entry;
}


void PhoneBook::setState(uint8_t state)
{
    PhoneBook::_state = state;
}


uint8_t PhoneBook::getCntPhoneBook(void)
{
    return (PhoneBook::_cnt_phonebook);
}


uint8_t PhoneBook::getIdxEntry(void)
{
    return (PhoneBook::_idx_entry);
}


uint8_t PhoneBook::getState(void)
{
    return (PhoneBook::_state);
}


uint8_t PhoneBook::displayMenu(void)
{
    uint8_t     option = PB_OPTION_UNKNOWN;
    std::string option_str = "";

    system("clear");
    while (option == PB_OPTION_UNKNOWN)
    {
        std::cout << std::endl << std::endl;
        std::cout << "----------- PHONEBOOK DIRECTORY -------------" << std::endl;
        std::cout << std::endl;
        std::cout << "Type 'ADD'    : To save new contact" << std::endl;
        std::cout << "Type 'SEARCH' : To display a specific contact" << std::endl;
        std::cout << "Type 'EXIT'   : To exit application" << std::endl;
        std::cout << std::endl;
        std::cout << "Please enter command: ";
        std::getline(std::cin, option_str);
        if (option_str == "ADD")
        {
            option = PB_OPTION_ADD;
            break;
        }
        else if (option_str == "SEARCH")
        {
            option = PB_OPTION_SEARCH;
            break;
        }
        else if (option_str == "EXIT")
        {
            option = PB_OPTION_EXIT;
            break;
        }
        else
        {
            std::cout << std::endl;
            std::cout << "Invalid Option. Please try again" << std::endl;
            sleep(DELAY);
            system("clear");
        }
    }
    return (option);
}


uint8_t    PhoneBook::startUp(void)
{
    uint8_t option = PB_OPTION_UNKNOWN;

    while (true)
    {
        option = displayMenu();
        switch (option)
        {
        case PB_OPTION_ADD:
            add_entry();
            break;
        case PB_OPTION_SEARCH:
            search_entry();
            break;
        case PB_OPTION_EXIT:
            std::cout << std::endl << "Exiting application..." << std::endl;
            sleep(DELAY);
            system("clear");
            return (PB_EXIT);
        case PB_OPTION_UNKNOWN:
        default:
            std::cout << "Unknown menu option" << std::endl;
            break;
        }
    }
    return (PB_EXIT);

}