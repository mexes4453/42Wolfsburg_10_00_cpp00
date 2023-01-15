/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 23:08:29 by cudoh             #+#    #+#             */
/*   Updated: 2023/01/08 23:22:52 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/* Function prototype */
void    ft_usr_speak(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else if (argc > 1)
	{
        ft_usr_speak(argc, argv);
	}
	return (0);
}


/**
 * @brief
 * This function prints all alpha characters passed in command line argument
 * in block letters. 
 * 
 * @param argc 
 * @param argv 
 */
void    ft_usr_speak(int argc, char *argv[])
{
	int	idx = 1;
	int	chr = 0;

    while (idx < argc)
    {
        while (argv[idx][chr] != '\0')
        {
            if (islower(argv[idx][chr]))
                std::cout << (char)toupper(argv[idx][chr]);
            else
                std::cout << argv[idx][chr];
            chr++;
        }
        idx++;
        chr = 0;
    }
    std::cout << std::endl;
}
