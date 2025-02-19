/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:15:04 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/02/19 10:34:32 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	main_menu(char *input)
{
	char	*line;

	main_menu_content();
	main_menu_instruct(input);
	ft_printf("\n\n" HCYN "▖▞▙▗" DEF "\t\t\t\t\t\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▖▞▙▗ \t\t\t\t\t\t ▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▚▛▘▜▝▞▟▙▘▖▞▙▗▚▛▘▜▝▞▟▛▙▘▖▞▙▗▞▙▗▚"
				"▛▘▜▝▞▟▙▘▖▞▙▗▟▙▘▖▞▙▗▚▛▘" DEF "\n\n\t");
	ft_printf(YEL "HIT " CYN "__ENTER__" YEL " TO START THE GAME ..." DEF);
	line = get_next_line(1);
	free(line);
	ft_printf("\n\n\n" DEF);
}

void	main_menu_content(void)
{
	ft_printf(YEL "\n\n\tEAGERNESS ENTERTAINMENT PRESENTS ...\n\n" DEF);
	ft_printf("\n" HCYN "▚▛▘▜▝▞▟▙▘▖▞▙▗▚▛▘▜▝▞▟▛▙▘▖▞▙▗▞▙▗▚"
				"▛▘▜▝▞▟▙▘▖▞▙▗▟▙▘▖▞▙▗▚▛▘" DEF);
	ft_printf("\n" HCYN "▖▞▙▗ \t\t\t\t\t\t ▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▖▞▙▗" DEF "\t\t\t\t\t\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▖▞▙▗\t" DEF);
	ft_printf(GRN "› OUR " YEL "BRAND NEW" GRN " HANDHELD: " BLK CYNB " EAGN " DEF);
	ft_printf("\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▖▞▙▗" DEF "\t\t\t\t\t\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▖▞▙▗\t" DEF);
	ft_printf(GRN "› try it out now with our\t" DEF);
	ft_printf("\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▖▞▙▗\t" DEF);
	ft_printf(GRN "  first (and only) game \t" DEF);
	ft_printf("\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▖▞▙▗" DEF "\t\t\t\t\t\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▖▞▙▗" DEF "\t\t\t\t\t\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▖▞▙▗\t" DEF);
	ft_printf(BLK GRNB "› COLLECTATRON 3000 \t\t" DEF);
	ft_printf("\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▖▞▙▗" DEF "\t\t\t\t\t\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▖▞▙▗ \t\t\t\t\t\t ▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▚▛▘▜▝▞▟▙▘▖▞▙▗▚▛▘▜▝▞▟▛▙▘▖▞▙▗▞▙▗▚"
				"▛▘▜▝▞▟▙▘▖▞▙▗▟▙▘▖▞▙▗▚▛▘" DEF);
}

void	main_menu_instruct(char *input)
{
	ft_printf("\n\n\n\n" HCYN "▚▗▛▘\t" DEF);
	ft_printf(GRN "› you're a " CYN "flying sd card reader" GRN "  " DEF);
	ft_printf("\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▚▛▘▗\t" DEF);
	ft_printf(GRN "  sent to collect valuable " YEL "SDCARDS" DEF);
	ft_printf("\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n\n\n" HCYN "▚▗▛▘\t" DEF);
	ft_printf(GRN "› escape with them through the" YEL " VENT" DEF);
	ft_printf("\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n\n\n" HCYN "▚▗▛▘\t" DEF);
	ft_printf(GRN "› TO MOVE, USE " CYN "__WASD__\t\t" DEF);
	ft_printf("\t " HCYN "▖▞▙▗" DEF);
	ft_printf("\n" HCYN "▚▛▘▗\t" DEF);
	ft_printf(GRN "  or " CYN "__ARROW KEYS__ \t\t" DEF);
	ft_printf("\t " HCYN "▖▞▙▗" DEF);
	ft_printf(YEL "\n\n\t› input map: " CYN "%s" DEF, input);
}

void	exit_message(int type)
{
	if (type == 10)
	{
		ft_printf(YEL "\tend of game yippe\n\n" DEF);
	}
	else
	{
		ft_printf(YEL "\thope you return!!\n\n" DEF);
	}
}
